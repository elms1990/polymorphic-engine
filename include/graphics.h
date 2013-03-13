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

            /* @name: SetWindowSize
             * @descr: Sets the window size.
             * @params:
             *      @w: New window width.
             *      @h: New window height.
             * @return: Nothing.
             */
            void SetWindowSize(int w, int h);

            /* @name: SetWindowFullscreen
             * @descr: Enables/Disable fullscreen
             * mode.
             * @params:
             *      @fs: True for enabling fullscreen
             * mode and false for disabling.
             * @return: 0 if window mode was successfuly
             * changed. -1 on error.
             */
            int SetWindowFullscreen(bool fs);

            /* @name: SetViewportSize
             * @descr: Sets the window viewport.
             * @params:
             *      @w: Viewport width.
             *      @h: Viewport height.
             * @return: Nothing.
             */
            void SetViewportSize(int w, int h);

            /* @name: SetWindowIcon
             * @descr: Changes the window icon.
             * @params:
             *      @img: A pointer to an image.
             * @return: Nothing.
             */
            void SetWindowIcon(Image *img);

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

            /* @name: Clear
             * @descr: Clears the screen.
             * @params: None.
             * @return: Nothing.
             */
            void SetRenderColor(Color c);

            /* @name: Initialize
             * @descr: Start up the Rendering engine;
             * @params: None.
             * @return: Returns 0 if successfully set up.
             * Returns any non-zero value, otherwise.
             */           
            int Initialize();

            /* @name: Shutdown
             * @descr: Shuts down the rendering system
             * destroying the game window.
             * @params: None.
             * @return: Nothing.
             */
            void Shutdown();

            /* @name: GetWidth
             * @descr: Get window width.
             * @params: None.
             * @return: Window width in pixels.
             */
            int GetWidth();

            /* @name: GetHeight
             * @descr: Get window height.
             * @params: None.
             * @return: Window height in pixels.
             */
            int GetHeight();

            /* @name: GetViewportWidth
             * @descr: Get the logical window
             * width.
             * @params: None.
             * @return: Logical size in pixels.
             */
            int GetViewportWidth();

            /* @name: GetViewportHeight
             * @descr: Get the height from the logical
             * window.
             * @params: None.
             * @return: Logical size in pixels.
             */
            int GetViewportHeight();

        private:
            friend Texture* Texture::CreateTextureFromImage(Image *img);
            SDL_Window *window;
            SDL_Renderer *renderer;
            int width;
            int height;

            //window scaling factors.
            //window_size/viewport_size
            float sw;
            float sh;

            //viewport width/height
            int vw;
            int vh;
            bool fs;

            /* @name: CreateContext
             * @descr: Creates a new Window.
             * @params:
             *      @w: Window width;
             *      @h: Window height;
             * @return: Zero if success. Non-zero, otherwise.
             */
            int CreateContext(int w, int h);
    };
}
#endif /* __GRAPHICS_H__ */
