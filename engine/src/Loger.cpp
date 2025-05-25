#include "Logger.hpp"

Logger::Logger(const std::string& filename)
{
    logFile.open(filename, std::ios::out);
    if (!logFile.is_open())
    {
        throw std::runtime_error("Failed to open log file: " + filename);
    }
}

Logger::~Logger()
{
    if (logFile.is_open())
    {
        logFile.close();
    }
}

void Logger::logTick(int tickNumber, const std::vector<RobotPtr>& robots)
{
    logFile << "Tick: " << tickNumber << "\n";
    for (const auto& robot : robots)
    {
        auto robotLog = robot->getLog();
        logFile << "Robot ID: " << robotLog.id
                << " | Position: (" << robotLog.position.x << ", " << robotLog.position.y << ")"
                << " | State: " << robotLog.state;
        if (robotLog.state == "Idle")
        {
            logFile << " | Task: None";
        }
        else
        {
            logFile << " | Task: " << robotLog.act_task.id;
        
            logFile << " | Destination: (" 
                    << robotLog.destination.x << ", " << robotLog.destination.y << ")";
        }
        logFile << "\n";
    }
    logFile << "------------------------------------------\n";
}
