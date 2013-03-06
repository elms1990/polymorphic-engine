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
    tex = Texture::CreateTextureFromImage(Engine::cmanager.LoadImage("block", "block.png"));
    hello = new TextBuffer(def, "Hello World, Polymorphic Engine!!!");
    return 0;
}

void HW::Update(int deltaTime) {
}

void HW::Render() {
    int x , y ;

    for (y = 0; y < 300; y += 75) {
        for (x = 0; x < 300; x += 75) {
            Engine::graphics.Draw(tex,Rectanglef(0,0,
                        tex->GetWidth(), tex->GetHeight()), Rectanglef(x, y, tex->GetWidth(), tex->GetHeight()));
        }
    }

    Engine::graphics.DrawText(hello, 121, 121);
}

void HW::Shutdown() {
}
