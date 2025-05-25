#include "ActivePointsConfig.hpp"
#include <iostream>
ActivePointsConfig ActivePointsConfig::fromYAML(const YAML::Node &node)
{
    try
    {
        ActivePointsConfig r;
        r.id = node["id"].as<int>();
        auto posNode = node["position"];
        r.position.x = posNode[0].as<int>(0);
        r.position.y = posNode[1].as<int>(0);
        return r;
    }
    catch (const YAML::Exception &e)
    {
        throw std::runtime_error("Failed to load robot config: " + std::string(e.what()));
    }
}

ActivePointsConfigList ActivePointsConfigList::fromYAML(const YAML::Node &root)
{
    ActivePointsConfigList list;
    if (!root["active_points"])
        return list;

    for (const auto &node : root["active_points"])
    {
        list.points.push_back(ActivePointsConfig::fromYAML(node));
    }
    return list;
}
