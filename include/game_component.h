/*
 *  File: game_component.h
 *  Last Updated: 07/12/2013
 *  Coded By: Erick Luis Moraes de Sousa
 *  Contact: elms1990 (at) gmail.com
 */

#ifndef __GAME_COMPONENT_H__
#define __GAME_COMPONENT_H__

#include <string>

using std::string;

namespace Polymorphic {
    
    class GameComponent {
        public:
            GameComponent(string id);
            virtual ~GameComponent();

            void SetId(string id);
            string GetId();

            virtual void Initialize();
            virtual void Update(float timeStep);
            virtual void Render();
            virtual void Shutdown();

        private:
            string mId;
    };
}

#endif /* __GAME_COMPONENT_H__ */
