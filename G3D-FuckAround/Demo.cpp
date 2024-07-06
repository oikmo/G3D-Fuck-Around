#include <G3DAll.h>
#include "App.h"
#include "Demo.h"
#include "Player.h"
#include "Entity.h"

Array<struct Entity> entityList;

BoxEntity ent(Vector3(0, 0, 0), Vector3(10, 1, 10));

void Demo::init() {
    app->player.init(app);
    entityList.append(ent);

}

void Demo::cleanup() {
    //Entity::entityList.clear();
}

void Demo::doSimulation(SimTime dt) {
    // Add physical simulation here
    app->player.move(dt);
}

void Demo::doLogic() {
    if (app->userInput->keyPressed(SDLK_ESCAPE)) {
        // Even when we aren't in debug mode, quit on escape.
        endApplet = true;
        app->endProgram = true;
    }

    // Add other key handling here
}

void Demo::doGraphics() {

    LightingParameters lighting(G3D::toSeconds(11, 00, 00, AM));
    app->renderDevice->setProjectionAndCameraMatrix(app->player.getCamera().getG3DCamera());

    // Cyan background
    app->renderDevice->setColorClearValue(Color3(.1, .5, 1));

    app->renderDevice->clear(app->sky.isNull(), true, true);
    if (app->sky.notNull()) {
        app->sky->render(lighting);
    }

    app->renderDevice->enableLighting();
    app->renderDevice->setLight(0, GLight::directional(lighting.lightDirection, lighting.lightColor));
    app->renderDevice->setAmbientLightColor(lighting.ambient);

    Draw::axes(CoordinateFrame(Vector3(0, 0, 0)), app->renderDevice);
    //Draw::box(Box(Vector3(0,0,0),Vector3(15,0.5,15)), app->renderDevice, Color4(1,1,1,1));
    ent.render(app->renderDevice);

    app->renderDevice->disableLighting();

    if (app->sky.notNull()) {
        app->sky->renderLensFlare(lighting);
    }
}