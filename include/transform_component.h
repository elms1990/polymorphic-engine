/*
 *  File: transform_component.h
 *  Last Updated: 07/12/2013
 *  Coded By: Erick Luis Moraes de Sousa
 *  Contact: elms1990 (at) gmail.com
 */

#ifndef __TRANSFORM_COMPONENT_H__
#define __TRANSFORM_COMPONENT_H__

#include "game_component.h"

using Polymorphic::GameComponent;

namespace Polymorphic {
    
    class TransformComponent : public GameComponent {
        public:
            TransformComponent();

            float X;
            float Y;
            float Z;

            float Rotation;
            
            float ScaleX;
            float ScaleY;
    };

}

#endif
