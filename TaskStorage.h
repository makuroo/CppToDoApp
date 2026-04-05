#pragma once

#include <fstream>
#include <string>
#include <vector>
#include "Task.h"

class TaskStorage
{
private:
    static constexpr const char* FILENAME_STRING = "tasks.txt"; 
public:
    static std::vector<Task> loadTasksFromFile();
    static void saveTasksToFile(const std::vector<Task>& tasks, const std::string& filename);
};
