#include "engine.h"
#include "hw.h"

using namespace Polymorphic;

int main (int argc, char* argv[]) {
    HW h;

    Engine::SetViewport(600, 400);
    Engine::Run(&h);
    return 0;
}
