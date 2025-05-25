#pragma once
#include <fstream>
#include "Robot.hpp"

using RobotPtr = std::shared_ptr<Robot>;

class Logger final{
private:
    std::ofstream logFile;

public:
    ~Logger();
    Logger(const std::string& filename);
    void logTick(int tickNumber, const std::vector<RobotPtr>& robots);
};