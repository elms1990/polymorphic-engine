/*
 *  File: graphics.h
 *  Last Updated: 09/08/2012
 *  Coded By: Erick Luis Moraes de Sousa
 *  Contact: elms1990 (at) gmail.com
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
#include <list>

using std::list;

namespace Polymorphic {

    #define MAX_LAYERS (6)
    #define HIDDEN_LAYER (-1)

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
             *      PS: The dest_boundary Z value acts like the layer value and
             * follow the layer indexing rule: The values may range from 0 to 5.
             * The -1 value is also acceptable, except it won't draw anything
             * on the screen.
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
             *      @layer: layer that the object will be drawn. The layer
             * values ranges are [0,5]. The -1 value is also valid, but
             * won't draw the object on the screen.
             * @return: Nothing.
             */
            void Draw(Texture* src, float dest_x, float dest_y, int layer);

            /* @name: Draw
             * @descr: Adds the texture to the drawing batch. Uses the default
             * layer when drawing(layer = 0).
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

            /* @name: DrawText
             * @descr: Adds the text to the drawing batch.
             * @params:
             *      @font: Font that will be used to draw.
             *      @text: Message that will be displayed.
             *      @dest_x: X coord in the screen.
             *      @dest_y: Y coord in the screen.
             *      @layer: layer where the text will be displayed.
             *      @color: Message color.
             * @return: Nothing.
             */
            void DrawText(TextBuffer* t, float x, float y, int layer);

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

            /* @name: DrawBatch
             * @descr: Draws every enqueued object to the
             * screen.
             * @params: None.
             * @return: Nothing.
             * PS: Should only be called by the engine internals.
             */
            void DrawBatch();

            //Getters
            int GetWidth() { return width; }
            int GetHeight() { return height; }

        private:
            typedef struct _dunit {
                GLuint id;
                Rectanglef src;
                Rectanglef dst;
            } DrawableUnit;

            Color c;
            SDL_Surface* scr;
            int width;
            int height;

            list<DrawableUnit> batch[MAX_LAYERS];

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
