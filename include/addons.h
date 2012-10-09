/*
 *  File: addons.h
 *  Last Updated: 09/08/2012
 *  Coded By: Erick Luis Moraes de Sousa
 *  Contact: elms1990 (at) gmail.com
 */

#ifndef __ADDONS_H__
#define __ADDONS_H__

namespace Polymorphic {

    class AddOn {
        public:

            /* Constructor */
            AddOn(const char *name);

            /* Default Destructor */
            virtual ~AddOn();

            /* @name: Initialize
             * @descr: Initialize an AddOn.
             * @params: None.
             * @return: Returns 0 if successfully set up.
             * Non-zero value, otherwise.
             */
            virtual int Initialize();

            /* @name: Update
             * @descr: Updates the AddOn state.
             * @params: 
             *      @deltaTime: Time elapsed since last update.
             * @return: Nothing.
             */
            virtual void Update(int deltaTime);

            /* @name: Render
             * @descr: Method used to render objects
             * on the screen.
             * @params:
             *      @deltaTime: Time elapsed since last update.
             * @return: Nothing.
             */
            virtual void Render(int deltaTime);

            /* @name: Shutdown
             * @descr: Shuts down this AddOn, calling clean
             * up routines.
             * @params: None.
             * @return: Nothing.
             */
 
            virtual void Shutdown();

            // Getter
            const char *GetName();

        private:
            const char *name;
    };

}
#endif /* __addons_H__ */
