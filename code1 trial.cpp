#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

class ToDoList {
private:
    vector<string> tasks;

public:
    void addTask(string task) {
        tasks.push_back(task);
    }

    void viewTasks() {
        if (tasks.empty()) {
            cout << "No tasks to display." << endl;
        } else {
            cout << "To-Do List:" << endl;
            for (int i = 0; i < tasks.size(); i++) {
                cout << "\t";
                cout << i + 1 << ". " << tasks[i] << endl;
            }
        }
    }

    void deleteTask(int index, string fileName) {
        if (index < 1 || index > tasks.size()) {
            cout << "Invalid index. Please enter a valid index number." << endl;
        } else {
            tasks.erase(tasks.begin() + index - 1);
            cout << "Task deleted successfully." << endl;

            ofstream file(fileName);
            for(int i = 0 ; i < tasks.size() ; i++)
                {
                    file << tasks[i] <<endl;
                }
        }
    }

    void clearList(){
        tasks.clear();
    }
};


int main() {

    //system("color 70");


    ToDoList myList;
    string line;
    string fileName = "code alpha task 1.txt";
    fstream file(fileName);

    if (!file) {
        cerr << "Error: unable to open file." << endl;
        return 1;
    }

    while (getline(file, line)) {
        // Process each line
        myList.addTask(line);
    }
    file.close();
    


    int choice;
    string task;

    while (true) {
        cout << "\n";
        cout << "________________________________________________" << endl;
        cout << "________________________________________________" << endl;
        cout << "\n";
        cout << "1. Add task \t 2. View tasks \t 3. Delete task \t 4. Clear \t 5. Exit" << endl;
        cout << "\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cout << "\n";
        ofstream file2;
        switch (choice) {
            case 1:
                file2.open("code alpha task 1.txt",ios_base::app);
                cout << "Enter task: ";
                cin.ignore();
                getline(cin, task);
                myList.addTask(task);
                file2 << task << "\n";
                file2.close();

                break;
            case 2:
                myList.viewTasks();
                break;
            case 3:
                cout << "Enter index number of task to delete: ";
                cin >> choice;
                myList.deleteTask(choice, fileName);
                break;
            case 4:
                file2.open("code alpha task 1.txt");
                myList.clearList();
                file2.close();
                break;
            case 5:
                exit(0);
                file2.close();
            default:
                cout << "Invalid choice. Please enter a number between 1 and 4." << endl;
        }
    }

    return 0;
}