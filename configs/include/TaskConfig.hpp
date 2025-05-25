#include <yaml-cpp/yaml.h>
#pragma once

class TaskConfig final
{
private:

public:
    TaskConfig(int id, int beginPointId, int endPointId, int beginPointTime, int endPointTime) 
        : id(id), beginPointId(beginPointId), endPointId(endPointId) {}

    static TaskConfig fromYAML(const YAML::Node& node);
    int id;
    int beginPointId, endPointId;
    int beginPointTime, endPointTime;

};

class TaskConfigList {
public:
    std::vector<TaskConfig> tasks;

    static TaskConfigList fromYAML(const YAML::Node& root);
};