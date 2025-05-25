#include "Core.hpp"
#include "ApplicationWindow.hpp"
#include <yaml-cpp/yaml.h>

int main()
{
    auto config = YAML::LoadFile("../config.yaml");
    MainConfig m = MainConfig::fromYAML(config);

    ApplicationWindow app(m);
    app.init();
    Core core;
    core.init(m);
    core.start();
    while (!WindowShouldClose()) {
        core.tick();
        app.draw(core.getState());
    }
}