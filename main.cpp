/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <vector>
#include <string>

struct Task {
    std::string name;
    std::string description;
};

class TaskTracker {
private:
    std::vector<Task> tasks;

public:
    void addTask(const Task& task) {
        tasks.push_back(task);
        std::cout << "Task added successfully.\n";
    }

    void displayTasks() {
        if (tasks.empty()) {
            std::cout << "No tasks to display.\n";
        } else {
            std::cout << "Tasks:\n";
            for (const Task& task : tasks) {
                std::cout << "Name: " << task.name << "\n";
                std::cout << "Description: " << task.description << "\n";
                std::cout << "------------------------\n";
            }
        }
    }
};

int main() {
    TaskTracker taskTracker;

    while (true) {
        std::cout << "Task Tracker Menu:\n";
        std::cout << "1. Add Task\n";
        std::cout << "2. Display Tasks\n";
        std::cout << "3. Exit\n";
        std::cout << "Enter your choice: ";

        int choice;
        std::cin >> choice;

        switch (choice) {
            case 1: {
                Task task;
                std::cout << "Enter task name: ";
                std::cin.ignore();
                std::getline(std::cin, task.name);
                std::cout << "Enter task description: ";
                std::getline(std::cin, task.description);
                taskTracker.addTask(task);
                break;
            }
            case 2:
                taskTracker.displayTasks();
                break;
            case 3:
                std::cout << "Exiting program.\n";
                return 0;
            default:
                std::cout << "Invalid choice. Please enter a valid option.\n";
        }
    }

    return 0;
}
