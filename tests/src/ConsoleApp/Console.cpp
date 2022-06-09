#define CATCH_CONFIG_MAIN
#include "catch2/catch_test_macros.hpp"

#include "Core/ConsoleApp.h"
#include "Core/Log.h"

#include <vector>
#include <memory>

class TestLayer : public StatTracker::Core::Layer {
public:
    void OnAttach() override {
    }

    void OnUpdate() override {
    }

    void OnDetach() override {
    }
};

StatTracker::Core::App* CreateConsole(std::vector<std::shared_ptr<StatTracker::Core::Layer>> layers = {}) {
    StatTracker::Core::App* app = new StatTracker::Core::ConsoleApp();
    
    for (const auto& lay : layers) {
        app->PushLayer(lay);
    }

    return app;
}

auto checkAndCloseConsole = [](StatTracker::Core::App* app) {
    REQUIRE(app->IsRunning);
    app->IsRunning = false;
    REQUIRE(!app->IsRunning);
};

TEST_CASE("Create Console", "ConsoleApp") {
    StatTracker::Core::App* app = CreateConsole();
    app->IsRunning = true;
    checkAndCloseConsole(app);
    delete app;
}

TEST_CASE("Creating Console + adding layer", "ConsoleApp") {
    StatTracker::Core::App* app = CreateConsole({
        std::make_shared<StatTracker::Core::Layer>(TestLayer()),
    });
    app->IsRunning = true;
    checkAndCloseConsole(app);
    delete app;
}