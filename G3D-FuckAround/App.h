#ifndef App_H
#define App_H
#include <G3DAll.h>
#include "Player.h"

class App : public GApp {
protected:
	void main();
public:
	SkyRef sky;
	class Player player;
	class GCamera camera;

	App(const GAppSettings& settings) : GApp(settings) {}
};
#endif