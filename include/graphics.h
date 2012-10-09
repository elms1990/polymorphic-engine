/*
 *  File: graphics.h
 *  Last Updated: 09/08/2012
 *  Coded By: Erick Luis Moraes de Sousa
 */

#ifndef __GRAPHICS_H__
#define __GRAPHICS_H__

#include <SDL.h>
#include <SDL_ttf.h>
#include <SDL_opengl.h>
#include "resource.h"
#include "rectanglef.h"
#include "color.h"
#include "text_buffer.h"

namespace Polymorphic {

    class Graphics {
        public:

            /* Default Constructor */
            Graphics();

            /* Default Destructor */
            ~Graphics();

            /* @name: Draw
             * @descr: Draw a texture on the screen.
             * @params:
             *      @src: Source texture.
             *      @src_boundary: Texture' region to be drawn.
             *      @dest_boundary: Region in the screen to draw.
             * @return: Nothing.
             */
            void Draw(Texture* src, Rectanglef src_boundary, Rectanglef dest_boundary);
            
            /* @name: Draw
             * @descr: Draw a texture on the screen.
             * @params:
             *      @src: Source texture.
             *      @src_boundary: Texture' region to be drawn.
             *      @dest_x: X coord in the screen.
             *      @dest_y: Y coord in the screen.
             * @return: Nothing.
             */
            void Draw(Texture* src, Rectanglef src_boundary, float dest_x, float dest_y);

            /* @name: Draw
             * @descr: Draw a texture on the screen.
             * @params:
             *      @src: Source texture.
             *      @dest_x: X coord in the screen.
             *      @dest_y: Y coord in the screen.
             * @return: Nothing.
             */
            void Draw(Texture* src, float dest_x, float dest_y);

            /* @name: DrawText
             * @descr: Draw a text message on the screen.
             * @params:
             *      @font: Font that will be used to draw.
             *      @text: Message that will be displayed.
             *      @dest_x: X coord in the screen.
             *      @dest_y: Y coord in the screen.
             *      @color: Message color.
             * @return: Nothing.
             */
            void DrawText(Font* font, const char* text, int x, int y, Color color);

            /* @name: DrawText
             * @descr: Draw a text message on the screen.
             * @params:
             *      @font: Font that will be used to draw.
             *      @text: Message that will be displayed.
             *      @dest_x: X coord in the screen.
             *      @dest_y: Y coord in the screen.
             *      @color: Message color.
             * @return: Nothing.
             */
            void DrawText(TextBuffer* t, int x, int y);

            /* @name: SetWindowTitle
             * @descr: Changes the Window title.
             * @params:
             *      @text: New window title.
             * @return: Nothing.
             */
            void SetWindowTitle(const char* text);

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
             * @descr: Clears the screen. The color can be
             * set by using SetClearColor method.
             * @params: None.
             * @return: Nothing.
             */
            void Clear();

            /* @name: SetClearColor
             * @descr: Sets the screen cleaning color.
             * @params:
             *      @c: New screen color.
             * @return: Nothing.
             */
            void SetClearColor(Color c);
 
            /* @name: Initialize
             * @descr: Start up the Rendering engine;
             * @params: None.
             * @return: Returns 0 if successfully set up.
             * Returns any non-zero value, otherwise.
             */           
            int Initialize();

            GLuint LoadShader(const char* path);

            //Getters
            int GetWidth() { return width; }
            int GetHeight() { return height; }

        private:
            Color c;
            SDL_Surface* scr;
            int width;
            int height;

            //scale factors base on default screen dimensions
            float sw;
            float sh;

            /* @name: CreateContext
             * @descr: Creates a new OpenGL context.
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
