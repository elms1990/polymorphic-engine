#include "engine.h"
using namespace Polymorphic;

int Engine::elapsed = 0;
bool Engine::SDL_INIT = false;
bool Engine::SDL_IMG = false;
bool Engine::SDL_TTF = false;
bool Engine::SDL_MIXER = false;
bool Engine::LOG = false;
bool Engine::initialized = false;
GameIF* Engine::game = NULL;
EngineAttributes Engine::eat = { 800, 600, false, 60 };

/* Modules */
Graphics Engine::graphics;
Keyboard Engine::keyboard;
Mouse Engine::mouse;
ContentManager Engine::cmanager;
Log Engine::log;

void Engine::Shutdown() {
    cmanager.Shutdown();
    keyboard.Shutdown();
    mouse.Shutdown();
    graphics.Shutdown();

    if (SDL_MIXER) {
        log.LogMessage("Warn", "Shutting down SDL_Mixer");
        Mix_AllocateChannels(0);
        Mix_CloseAudio();
        Mix_Quit();
    }

    if (SDL_IMG) {
        log.LogMessage("Warn", "Shutting down SDL_Image");
        IMG_Quit();
    }

    if (SDL_TTF) {
        log.LogMessage("Warn", "Shutting down SDL_TTF");
        TTF_Quit();
    }

    if (SDL_INIT) {
        log.LogMessage("Warn", "Shutting down SDL");
        SDL_Quit();
    }

    if (LOG) {
        log.Shutdown();
    }

    initialized = false;
}

void Engine::Update(int deltaTime) {
    keyboard.Update();
    mouse.Update();
    game->Update(deltaTime);
}

void Engine::Render() {
    game->Render();
}

int Engine::Initialize() {
    if (initialized)
        return 0;

    /* Initializes Log System */
    log.Initialize("log.txt");
    log.LogMessage("Starting", "Initializing SDL...");

    if (log.Initialized()) {
        LOG = true;
    }

    /* Initializes SDL2 libs and dependencies */
    if (SDL_Init(SDL_INIT_AUDIO | SDL_INIT_VIDEO) < 0) {
        log.LogMessage("Error", "SDL2 error. Could not initialize lib.");
        Shutdown();
        return -1;
    }

    SDL_INIT = true;

    if (TTF_Init() == -1) {
        log.LogMessage("Error", "Font system could not be initialized.");
        Shutdown();
        return -1;
    }
    SDL_TTF = true;

    if (IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG) == -1) {
        log.LogMessage("Error", "Image loader could not be initialized.");
        Shutdown();
        return -1;
    }
    SDL_IMG = true;

    if (Mix_Init(MIX_INIT_MP3) == -1 || Mix_OpenAudio(22050, AUDIO_S16, 2, 4096) == -1) {
        log.LogMessage("Error", "Sound system could not be initialized.");
        Shutdown();
        return -1;
    }
    SDL_MIXER = true;
    log.LogMessage("Success", "SDL successfully started.");

    if (graphics.Initialize() == -1) {
        log.LogMessage("Error", "Graphics system could not be initialized.");
        Shutdown();
        return -1;
    }
    
    cmanager.Initialize();

    /* Set Up Input Manager */
    log.LogMessage("Starting", "Starting Input System...");
    keyboard.Initialize();
    mouse.Initialize();

    log.LogMessage("Success", "Input system successfully started.");

    //mixer
    Mix_AllocateChannels(DEFAULT_MIX_NUMCHAN);
    initialized = true;

    return 0;
}

void Engine::Run(GameIF *gi) {
    game = gi; 

    //Engine initialize
    if (Initialize() != 0)
        return;

    if (game->Initialize() != 0)
        return;

    int deltaT = 0;
    Timer t;

    SDL_Event e;

    /* GAME LOOP */
    while(true) {
        t.Start();

        /* Clear Screen */
        graphics.Clear();

        /*fix this... must poll all events...*/
        if (SDL_PollEvent(&e)) {
            if (e.type == SDL_QUIT) {
                break;
            }
        }

        elapsed = deltaT;

        /* UPDATE GAME STUFF HERE */
        Update(deltaT);

        /* DRAW STUFF HERE */
        Render();

        /* Swap buffers and update screen */
        graphics.Flush();
        
        /* Cap the fps */
        if (t.GetTicks() < (1000.f/eat.fps)) {
            SDL_Delay((1000.f/eat.fps) - t.GetTicks());
        }

        deltaT = t.GetTicks();
    }

    game->Shutdown();

    /* Shutdown everything and release remaining resources */
    Shutdown();
}

bool Engine::Initialized() {
    return initialized;
}

EngineAttributes Engine::GetAttributes() {
    return eat;
}

void Engine::SetViewport(int width, int height) {
    if (width > 0 && height > 0) {
        eat.width = width;
        eat.height = height;
    }
}

void Engine::StartOnFullScreen(bool b) {
    eat.fullscreen = b;
}

void Engine::SetFrameRateCap(int fps) {
    if (fps > 0)
        eat.fps = fps;
}

int Engine::GetElapsedTime() {
    return elapsed;
}
