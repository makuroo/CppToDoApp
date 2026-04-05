#include "Task.h"

Task::Task(const std::string& title) : title(title), isCompleted(false) {}

void Task::markAsCompleted(){
    isCompleted = true;
}

std::string Task::getTitle() const{
    return title;
}

bool Task::getCompletionStatus() const{
    return isCompleted;
}