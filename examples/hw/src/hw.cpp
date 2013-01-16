#include "hw.h"
#include "engine.h"

using namespace Polymorphic;

HW::HW() {
    hello = NULL;
    def = NULL;
}

HW::~HW() {

}

int HW::Initialize() {
    def = Engine::cmanager.LoadFont("default", "fonts/def.TTF", 32); 
    hello = new TextBuffer(def, "Hello World, Polymorphic Engine!!!");
    return 0;
}

void HW::Update(int deltaTime) {
}

void HW::Render() {
    Engine::graphics.DrawText(hello, 30, 30);
}

void HW::Shutdown() {
}
