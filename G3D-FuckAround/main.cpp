#define SDL_MAIN_HANDLED

#include <G3DAll.h>
#include "App.h"
#include "Demo.h"

void App::main() {
    renderDevice->setCaption("Oikmo gaem");
    setDebugMode(true);
    debugController.setActive(true);

    // Load objects here
    sky = Sky::create(renderDevice, dataDir + "sky/");

    Demo(this).run();
}

#undef main

int main(int argc, char *argv[]) {
    GAppSettings settings;
    settings.window.width = 800;
    settings.window.height = 600;

    App(settings).run();
    return 0;
}