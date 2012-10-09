/*
 *  File: engine.h
 *  Last Updated: 19/08/2012
 *  Coded By: Erick Luis Moraes de Sousa
 *  Contact: elms1990 (at) gmail.com
 */

#ifndef __ENGINE_H__
#define __ENGINE_H__

/* Engine includes */
#include "actor_if.h"
#include "addons.h"
#include "content_manager.h"
#include "game_if.h"
#include "graphics.h"
#include "input_state.h"
#include "keyboard.h"
#include "keys.h"
#include "log.h"
#include "math_helper.h"
#include "mouse.h"
#include "object_if.h"
#include "rectanglef.h"
#include "resource.h"
#include "text_buffer.h"
#include "timer.h"

/* SDL includes */
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>
#include <SDL_opengl.h>

namespace Polymorphic {

    typedef enum {
        //window initial width
        WINDOW_WIDTH,
        //window initial height
        WINDOW_HEIGHT,
        //start on fscreen mode
        WINDOW_FSCREEN
    } EngineParam;

    typedef struct _eattrib {
        int width;
        int height;
        bool fullscreen;
    } EngineAttributes;

    class Engine {
        public:
            /* @name: Run
             * @descr: Starts running the engine and
             * its modules.
             * @params: None.
             * @return: Nothing.
             */
            static void Run(GameInterface* gi);

            /* @name: Initialized
             * @descr: Checks whether or not the engine was
             * successfully initialized.
             * @params: None.
             * @return: Nothing.
             */
            static bool Initialized();

            /* @name: RegisterAddOn
             * @descr: Registers a game addon. Automatically
             * calls the addon methods.
             * @params:
             *      @mod: pointer to module object.
             * @return: nothing.
             */
            static void RegisterAddOn(AddOn *mod);
            
            /* @name: UnregisterAddOn
             * @descr: Unregisters a game module.
             * @params:
             *      @name: module name.
             * @return: nothing.
             */
            static void UnregisterAddOn(const char *name);

            /* @name: SetAttribute
             * @descr: Sets a game engine setting.
             * This is useful for initializing the
             * engine with a desired parater set.
             * @params:
             *      @param: Setting to be updated;
             *      @value: New setting's value.
             * @return: nothing.
             */
            static void SetAttribute(EngineParam param, int value);

            /* @name: SetAttribute
             * @descr: Sets a game engine setting.
             * This is useful for initializing the
             * engine with a desired parater set.
             * @params:
             *      @e: Struct containing engine settings;
             * @return: nothing.
             */
            static void SetAttribute(EngineAttributes e);

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

        private:
            static int Initialize();
            static void Update(int deltaTime);
            static void Render(int deltaTime);
            static void Shutdown();

            static EngineAttributes eat;
            static bool SDL_INIT;
            static bool SDL_IMG;
            static bool SDL_TTF;
            static bool SDL_MIXER;
            static bool LOG;
            static bool initialized;
            static SDL_Surface *opt_icon;

            static GameInterface *game;
    };

}
#endif /* __ENGINE_H__ */
