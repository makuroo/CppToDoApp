#include "Menu.h"
#include "Utilities.h"
#include <iostream>
#include <limits>
#include <fstream>

Menu::Menu(){
    this->taskHandler = new TaskHandler();
}

void Menu::showMenu()
{
    int choice = 0;

    while (choice != -1)
    {
        std::cout << "==========================" << std::endl;
        std::cout << "Welcome to the To-Do List App!" << std::endl;
        std::cout << "==========================" << std::endl;
        std::cout << "Menu:" << std::endl;
        std::cout << "1. Add Task" << std::endl;
        std::cout << "2. Display Tasks" << std::endl;
        std::cout << "3. Delete Task" << std::endl;
        std::cout << "4. Mark Task as Completed" << std::endl;
        std::cout << "-1. Exit" << std::endl;
        std::cout << "==========================" << std::endl;
        std::cout << "Enter your choice: ";
        if (!(std::cin >> choice))
        {
            std::cin.clear();                                                   // clear the fail state
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // flush bad input
            std::cout << "Invalid input. Please enter a number." << std::endl;
            continue;
        }
        executeChoice(choice);
    }
}

void Menu::displayTasks() const
{
    int choice = -1;
    while (choice != 4)
    {
        std::cout << "Choose dsiplay options: " << std::endl;
        std::cout << "1. Display all" << std::endl;
        std::cout << "2. Display completed tasks" << std::endl;
        std::cout << "3. Display incompleted tasks" << std::endl;
        std::cout << "4. Back" << std::endl;

        if (!(std::cin >> choice))
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid option. Please enter valid choice";
        }
        executeDisplayChoice(choice);
    }

    std::cout << "Press Enter to return to the menu...";
    // Clear the input buffer before waiting for user input
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin.get(); // Wait for user input before clearing the screen

    // both cin.ignore and cin.get are used to handle the input buffer correctly.
    // cin.ignore is used to clear any remaining input in the buffer, while cin.get waits for the user to press Enter before proceeding.
    // This ensures that the program doesn't skip the waiting step due to leftover input in the buffer.

    Utilities::clearScreen();
}


void Menu::executeChoice(int choice)
{
    Utilities::clearScreen();; // Clear the console (use "clear" for Unix-based systems)
    switch (choice)
    {
    case 1:
    {
        std::string title;
        std::cout << "Enter task title: ";
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::getline(std::cin, title);
        taskHandler->addTask(title);
        break;
    }
    case 2:
        displayTasks();
        break;
    case 3:
    {
        int index;
        std::cout << "Enter task index to delete: ";
        if (!(std::cin >> index))
        {
            std::cin.clear();                                                   // clear the fail state
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // flush bad input
            std::cout << "Invalid input. Please enter a number." << std::endl;
            break;
        }

        taskHandler->deleteTask(index);
        break;
    }
    case 4:
    {
        int index = -1;
        std::cout << "Enter task index to mark as completed: ";
        if (!(std::cin >> index))
        {
            std::cin.clear();                                                   // clear the fail state
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // flush bad input
            std::cout << "Invalid input. Please enter a number." << std::endl;
            break;
        }
        taskHandler->markAsComplete(index);
        break;
    }
    case -1:
        break;
    default:
        std::cout << "Invalid choice. Please try again." << std::endl;
    }
}

void Menu::executeDisplayChoice(int choice) const
{
    switch (choice)
    {
    case 1:
        taskHandler->displayAllTasks();
        break;
    case 2:
        taskHandler->displayCompletedTasks();
        break;
    case 3:
        taskHandler->displayIncompletedTasks();
        break;
    case 4:
        break;
    default:
        std::cout << "Invalid choice. Please try again." << std::endl;
    }
    
}

