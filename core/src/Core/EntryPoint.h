#pragma once

#if defined(STATS_WINDOWS)
#elif defined(STATS_LINUX)
#elif defined(STATS_MACOS)
#error unsuported as of yet...
#else
#error unsuported...
#endif

#if defined(STATS_DEBUG)
#elif defined(STATS_RELEASE)
#elif defined(STATS_DIST)
#endif

namespace StatTracker {

	extern Core::App* CreateApp(int argc, char** argv);

	int Main(int argc, char** argv) {
		Core::Log::Init();

		while (Core::App::IsRunning) {
			Core::App* app = CreateApp(argc, argv);
			
			app->Run();
			
			delete app;
		}

		return 0;
	}
}

#if defined(STATS_WINDOWS) && defined(STATS_DIST)

#include <Windows.h>

int APIENTRY WinMain(HINSTANCE hInst, HINSTANCE hInstPrev, PSTR cmdline, int cmdshow) {
	return StatTracker::Main(__argc, __argv);
}

#else

int main(int argc, char** argv) {
	return StatTracker::Main(argc, argv);
}

#endif // 0
