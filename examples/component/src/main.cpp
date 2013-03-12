#include "engine.h"
#include "cmp.h"

using namespace Polymorphic;

int main (int argc, char* argv[]) {
    CMP h;

    Engine::SetViewport(600, 400);
    Engine::Run(&h);
    return 0;
}
