#pragma once

#include <iostream>
#include "TaskStorage.h"
#include "Task.h"
#include <vector>

class TaskHandler
{
private:
    std::vector<Task> tasks;
    TaskStorage* taskStorage;
public:
    TaskHandler(/* args */);
    ~TaskHandler();
    void addTask(const std::string& title);
    void displayAllTasks() const;
    void displayCompletedTasks() const;
    void displayIncompletedTasks() const;
    void deleteTask(int index);
    void markAsComplete(int index);
    std::vector<Task> getAllTasks() const;
};