#include "App.h"

namespace StatTracker::Core {
	App* CreateApp(int argc, char** argv);
	bool App::IsRunning = true;
}