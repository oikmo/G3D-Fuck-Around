#ifndef DEMO_H
#define DEMO_H
#include <G3DAll.h>

class Demo : public GApplet {
public:

    // Add state that should be visible to this applet.
    // If you have multiple applets that need to share
    // state, put it in the App.

    class App* app;

    Demo(App* _app) : GApplet( _app), app(_app) {};

    virtual void init();

    virtual void doLogic();

    virtual void doSimulation(SimTime dt);

    virtual void doGraphics();

    virtual void cleanup();

};
#endif