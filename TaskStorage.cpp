#include <fstream>
#include <iostream>
#include <vector>
#include "Task.h"
#include "TaskStorage.h"

void TaskStorage::saveTasksToFile(const std::vector<Task> &tasks, const std::string &filename)
{
    std::ofstream file(filename);
    if (file.is_open())
    {
        for (const auto &task : tasks)
        {
            if (task.getCompletionStatus())
            {
                file << task.getTitle() << ",1" << std::endl;
            }
            else
            {
                file << task.getTitle() << ",0" << std::endl;
            }
        }
        file.close();
    }
    else
    {
        std::cout << "Could not open file: " << filename << std::endl;
    }
}

std::vector<Task> TaskStorage::loadTasksFromFile()
{
    std::vector<Task> loadedTasks;
    std::ifstream file(TaskStorage::FILENAME_STRING);

    if (file.is_open())
    {
        std::string line;
        while (std::getline(file, line))
        {
            if (line.empty())
                continue; // Skip empty lines
            bool isCompleted = false;
            size_t commaPos = line.find_last_of(',');
            if (commaPos != std::string::npos)
            {
                std::string status = line.substr(commaPos + 1);
                line = line.substr(0, commaPos); // Extract the title
                isCompleted = (status == "1");
            }
            Task task(line);
            if (isCompleted)
            {
                task.markAsCompleted();
            }
            loadedTasks.push_back(task);
        }
        file.close();
    }
    else
    {
        std::cout << "Could not open file: " << TaskStorage::FILENAME_STRING << std::endl;
    }
    return loadedTasks;
}