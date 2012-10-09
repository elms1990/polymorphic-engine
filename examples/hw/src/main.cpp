#include "engine.h"
#include "hw.h"

using namespace Polymorphic;

int main (int argc, char* argv[]) {
    HW h;

    Engine::SetAttribute(WINDOW_WIDTH, 600);
    Engine::SetAttribute(WINDOW_HEIGHT, 400);
    Engine::Run(&h);
    return 0;
}
