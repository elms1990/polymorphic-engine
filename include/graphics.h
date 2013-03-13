/*
 *  File: graphics.h
 *  Last Updated: 09/08/2012
 *  Coded By: Erick Luis Moraes de Sousa
 *  Contact: elms1990 (at) gmail.com
 */

#ifndef __GRAPHICS_H__
#define __GRAPHICS_H__

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include "resource.h"
#include "rectanglef.h"
#include "color.h"
#include "text_buffer.h"
#include <string>

using std::string;

namespace Polymorphic {

    class Graphics {
        public:
            Graphics();
            ~Graphics();

            /* @name: Draw
             * @descr: Adds the texture to the drawing batch.
             * @params:
             *      @src: Source texture.
             *      @src_boundary: Texture' region to be drawn.
             *      @dest_boundary: Region in the screen to draw.
             * @return: Nothing.
             */
            void Draw(Texture* src, Rectanglef src_boundary, Rectanglef dest_boundary);
            
            /* @name: Draw
             * @descr: Adds the texture to the drawing batch.
             * @params:
             *      @src: Source texture.
             *      @src_boundary: Texture' region to be drawn.
             *      @dest_x: X coord in the screen.
             *      @dest_y: Y coord in the screen.
             * @return: Nothing.
             */
            void Draw(Texture* src, Rectanglef src_boundary, float dest_x, float dest_y);

            /* @name: Draw
             * @descr: Adds the texture to the drawing batch.
             * @params:
             *      @src: Source texture.
             *      @dest_x: X coord in the screen.
             *      @dest_y: Y coord in the screen.
             * @return: Nothing.
             */
            void Draw(Texture* src, float dest_x, float dest_y);

            /* @name: DrawText
             * @descr: Adds the text to the drawing batch. Uses default layer
             * (layer = 0) when drawing.
             * @params:
             *      @font: Font that will be used to draw.
             *      @text: Message that will be displayed.
             *      @dest_x: X coord in the screen.
             *      @dest_y: Y coord in the screen.
             *      @color: Message color.
             * @return: Nothing.
             */
            void DrawText(TextBuffer* t, float x, float y);

            /* @name: SetWindowTitle
             * @descr: Changes the Window title.
             * @params:
             *      @text: New window title.
             * @return: Nothing.
             */
            void SetWindowTitle(string text);

            /* @name: ResizeWindow.
             * @descr: Resizes the window.
             * @params:
             *      @new_w: New window width.
             *      @new_h: New window height.
             *      @full_screen: Toggles on/off full
             * screen mode.
             * @return: True whether resized correctly.
             * False otherwise.
             */
            bool ResizeWindow(int new_w, int new_h, bool full_screen);

            /* @name: Flush
             * @descr: Updates the screen, displaying recently
             * drawn objects.
             * @params: None.
             * @return: Nothing.
             */
            void Flush();
            
            /* @name: Clear
             * @descr: Clears the screen.
             * @params: None.
             * @return: Nothing.
             */
            void Clear();

            void SetRenderColor(Color c);

            /* @name: Initialize
             * @descr: Start up the Rendering engine;
             * @params: None.
             * @return: Returns 0 if successfully set up.
             * Returns any non-zero value, otherwise.
             */           
            int Initialize();

            void Shutdown();

            int GetWidth();
            int GetHeight();
            int GetViewportWidth();
            int GetViewportHeight();

        private:
            friend Texture* Texture::CreateTextureFromImage(Image *img);
            SDL_Window *window;
            SDL_Renderer *renderer;
            int width;
            int height;

            //scale factors base on default screen dimensions
            float sw;
            float sh;

            /* @name: CreateContext
             * @descr: Creates a new Window.
             * @params:
             *      @w: Window width;
             *      @h: Window height;
             *      @fscreen: Switch to full screen mode.
             * @return: Zero if success. Non-zero, otherwise.
             */
            int CreateContext(int w, int h, bool fscreen);
    };
}
#endif /* __GRAPHICS_H__ */
