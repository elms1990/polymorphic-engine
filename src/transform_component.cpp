/*
 *  File: transform_component.cpp
 *  Last Updated: 07/12/2013
 *  Coded By: Erick Luis Moraes de Sousa
 *  Contact: elms1990 (at) gmail.com
 */

#include "transform_component.h"

using Polymorphic::TransformComponent;

TransformComponent::TransformComponent() :
    GameComponent("Transform") {
    X = 0.f;
    Y = 0.f;
    Z = 0.f;

    Rotation = 0.f;

    ScaleX = 1.f;
    ScaleY = 1.f;
}
