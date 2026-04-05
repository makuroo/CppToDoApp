#pragma once
#include <string>

class Task {
private:
    std::string title;
    bool isCompleted;

public:
    Task(const std::string& title);
    void markAsCompleted();
    bool getCompletionStatus() const;
    std::string getTitle() const;
};