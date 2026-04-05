#pragma once

#include <string>
#include <vector>
#include "Task.h"
#include "TaskStorage.h"
#include "TaskHandler.h"

class Menu {
private:
    TaskHandler* taskHandler;
public:
    Menu();
    void showMenu();
    void showDisplayMenu();
    void displayTasks() const;
    void executeChoice(int choice);
    void executeDisplayChoice(int choice) const;
};