
#include <iostream>
#include <string>
#include <list>
#include <ctime>

class TodoItem {
private:
    int id;
    std::string description;
    bool completed;

public:
    TodoItem() : id(0), description(""), completed(false) {}
    ~TodoItem() = default;

    bool create(std::string new_description) {
        id = rand() % 100 + 1;
        description = new_description;
        return true;
    }

    int getId() { return id; }
    std::string getDescription() { return description; }
    bool isCompleted() { return completed; }

    void setCompleted(bool val) { completed = val; }
};

int main()
{
    char input_option;
    int input_id;
    std::string input_description;
    std::string version = "v1.0";
    std::list<TodoItem> todoItems;
    std::list<TodoItem>::iterator it;

    srand(time(NULL));

    todoItems.clear();

   // TodoItem test;
    //test.create("testbed");
    //todoItems.push_back(test);

    while (1) {
        system("cls");
        std::cout << "Todo Lister - " << version << std::endl;
        std::cout << std::endl << std::endl;

        for (it = todoItems.begin(); it != todoItems.end(); it++) {

            std::string completed = it->isCompleted() ? "done" : "not done";

            std::cout << it->getId() << " | " << it->getDescription() << " | "
                << completed << std::endl;
        }

        if (todoItems.empty()) {
            std::cout << "Begin your todo journey! \n" << std::endl;
        }

        std::cout << std::endl;

        std::cout << "[a]dd a new Todo" << std::endl;
        std::cout << "[c]omplete a Todo" << std::endl;
        std::cout << "[q]uit" << std::endl;
        std::cout << "\nWhat do you want to do? ";

        std::cin >> input_option;

        if (input_option == 'q') {
            std::cout << "\nCome back soon!" << std::endl;
            break;
        }
        else if (input_option == 'a') {
            std::cout << "Add a new description: ";
            std::cin.clear();
            std::cin.ignore();
            std::getline(std::cin, input_description);

            TodoItem newItem;
            newItem.create(input_description);
            todoItems.push_back(newItem);
        }
        else if (input_option == 'c') {
            std::cout << "Enter id of the completed Todo: " << std::endl;
            std::cin >> input_id;

            for (it = todoItems.begin(); it != todoItems.end(); it++) {

                if (input_id == it->getId()) {
                    it->setCompleted(true);
                    break;
                }
            }

        }

    }
    
    return 0;
}

