#include "TaskConfig.hpp"

TaskConfig TaskConfig::fromYAML(const YAML::Node& node)
{   
    try
    {
        int id = node["id"].as<int>();
        int beginPointId = node["from"].as<int>(0);
        int endPointId = node["to"].as<int>(0);
        int beginPointTime = node["wait_ticks_a"].as<int>(0);
        int endPointTime = node["wait_ticks_b"].as<int>(0);
        return TaskConfig(id, beginPointId, endPointId, beginPointTime, endPointTime);
    }
    catch(const YAML::Exception& e)
    {
        throw std::runtime_error("Failed to load task config: " + std::string(e.what()));
    }
}

TaskConfigList TaskConfigList::fromYAML(const YAML::Node &root)
{
    TaskConfigList list;
    if (!root["tasks"]) return list;

    for (const auto& node : root["tasks"]) {
        list.tasks.push_back(TaskConfig::fromYAML(node));
    }
    return list;
}