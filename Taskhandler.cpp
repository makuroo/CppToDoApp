#include <iostream>
#include <vector>
#include "Task.h"
#include "TaskHandler.h"
#include "TaskStorage.h"
#include "Utilities.h"
#include <limits>

void TaskHandler::addTask(const std::string &title)
{
    Task newTask(title);
    tasks.push_back(newTask);
    std::cout << "Task \"" << title << "\" added successfully!" << std::endl;
    taskStorage->saveTasksToFile(tasks, "tasks.txt");
    getchar(); // Wait for user input before clearing the screen
    Utilities::clearScreen();
}

void TaskHandler::displayAllTasks() const
{
    Utilities::clearScreen();
    
    std::cout << "Tasks:" << std::endl;
    for (size_t i = 0; i < tasks.size(); ++i)
    {
        std::cout << i << ". " << tasks[i].getTitle()
                  << (tasks[i].getCompletionStatus() ? " [Completed]" : "")
                  << std::endl;
    }
}

void TaskHandler::displayCompletedTasks() const
{
    Utilities::clearScreen();
    ;
    std::vector<Task> completedTask;
    for (size_t i = 0; i < tasks.size(); ++i)
    {
        if (tasks[i].getCompletionStatus())
        {
            completedTask.emplace_back(tasks[i]);
        }
    }

    for (size_t i = 0; i < completedTask.size(); i++)
    {
        std::cout << i << ". " << completedTask[i].getTitle()
                  << (completedTask[i].getCompletionStatus() ? " [Completed]" : "")
                  << std::endl;
    }
}

void TaskHandler::displayIncompletedTasks() const
{
    Utilities::clearScreen();
    ;
    std::vector<Task> incompleteTasks;
    for (size_t i = 0; i < tasks.size(); ++i)
    {
        if (!tasks[i].getCompletionStatus())
        {
            incompleteTasks.emplace_back(tasks[i]);
        }
    }

    for (size_t i = 0; i < incompleteTasks.size(); i++)
    {
        std::cout << i << ". " << incompleteTasks[i].getTitle()
                  << (incompleteTasks[i].getCompletionStatus() ? " [Completed]" : "")
                  << std::endl;
    }
}

void TaskHandler::deleteTask(int index)
{
    if (index >= 0 && index < tasks.size())
    {
        tasks.erase(tasks.begin() + index);
        std::cout << "Task deleted successfully!" << std::endl;
        taskStorage->saveTasksToFile(tasks, "tasks.txt");
        getchar();
        Utilities::clearScreen();
    }
    else
    {
        std::cout << "Invalid index. Please try again." << std::endl;
    }
}

void TaskHandler::markAsComplete(int index)
{
    for (size_t i = 0; i < tasks.size(); i++)
    {
        if (i == index)
        {
            tasks[i].markAsCompleted();
            taskStorage->saveTasksToFile(tasks, "tasks.txt");
            std::cout << "Task marked as completed!" << std::endl;
            break;
        }
    }
}

std::vector<Task> TaskHandler::getAllTasks() const
{
    return this->tasks;
}

TaskHandler::TaskHandler(/* args */)
{
    taskStorage = new TaskStorage;
    tasks = taskStorage->loadTasksFromFile();
}

TaskHandler::~TaskHandler()
{
    tasks.clear();
    free(taskStorage);
}