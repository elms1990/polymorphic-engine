/*
 *  File: engine.h
 *  Last Updated: 19/08/2012
 *  Coded By: Erick Luis Moraes de Sousa
 *  Contact: elms1990 (at) gmail.com
 */

#ifndef __ENGINE_H__
#define __ENGINE_H__

/* Engine includes */
#include "content_manager.h"
#include "game_if.h"
#include "graphics.h"
#include "input_state.h"
#include "keyboard.h"
#include "keys.h"
#include "log.h"
#include "mouse.h"
#include "rectanglef.h"
#include "resource.h"
#include "text_buffer.h"
#include "timer.h"

/* SDL includes */
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>

namespace Polymorphic {

    typedef struct _eattrib {
        int width;
        int height;
        bool fullscreen;
        int fps;
    } EngineAttributes;

    class Engine {
        public:
            /* @name: Run
             * @descr: Starts running the engine and
             * its modules.
             * @params: None.
             * @return: Nothing.
             */
            static void Run(GameIF* gi);

            /* @name: Initialized
             * @descr: Checks whether or not the engine was
             * successfully initialized.
             * @params: None.
             * @return: Nothing.
             */
            static bool Initialized();

            /* @name: SetViewport
             * @descr: Sets the viewport size.
             * @params:
             *      @width: viewport's width.
             *      @height: viewport's height.
             * @return: Nothing.
             */
            static void SetViewport(int width, int height);

            /* @name: StartOnFullScreen
             * @descr: Enable/Disable the window initializing in fullscreen
             * mode.
             * @params: 
             *      b: Flag to enable/disable fullscreen mode.
             * @return: Nothing.
             */
            static void StartOnFullScreen(bool b);

            /* @name: SetFrameRateCap
             * @descr: Sets the frame rate upper limit.
             * @params:
             *      fps: non-zero positive integer value.
             *      Default is 60 fps.
             * @return: Nothing.
             */
            static void SetFrameRateCap(int fps);

            /* @name: GetAttributes
             * @descr: Retrieves the engine settings.
             * @params: None.
             * @return: Struct containing the engine's
             * objects.
             */
            static EngineAttributes GetAttributes();

            /* Engine modules */
            static Graphics graphics;
            static Keyboard keyboard;
            static Mouse mouse;
            static ContentManager cmanager;
            static Log log;

            static int GetElapsedTime();

        private:
            static int Initialize();
            static void Update(int deltaTime);
            static void Render();
            static void Shutdown();

            static EngineAttributes eat;
            static bool SDL_INIT;
            static bool SDL_IMG;
            static bool SDL_TTF;
            static bool SDL_MIXER;
            static bool LOG;
            static bool initialized;
            static int elapsed;

            static GameIF *game;
    };

}
#endif /* __ENGINE_H__ */
