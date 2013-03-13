#include "fps_component.h"
#include <stdio.h>
#include "engine.h"

using namespace Polymorphic;

FpsComponent::FpsComponent() : Component("FPS") {
}

FpsComponent::~FpsComponent() {

}

void FpsComponent::Initialize() {
    tb.SetDisplayFont(Engine::cmanager.LoadFont("default", "font/def.TTF"));
}

void FpsComponent::Execute() {
    char buf[25];
    sprintf(buf, "%.f", 1000.f/Engine::GetElapsedTime());
    tb.SetDisplayText(buf);
    Engine::graphics.DrawText(&tb, 75.f, 75.f);
}
