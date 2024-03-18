#include "Header.h"

int main() {
    string id;
    string name;
    string birth;
    bool gender;
    bool status;
    Node* root = NULL;
    Node* p = root;
    int n = 0;
    int choice;
    if (is_file_exist("employee.txt") == true) {
        Loadfile(root, n);
        cout << "File employee.txt is found and loaded" << endl;
        printInorder(root);
    }
    else {
        cout << "File employee.txt does not exist" << endl;
    }
    while (true) {
        cout << "1.Allow user create a new employee info and insert this item with all its associated data to BST" << endl;
        cout << "2.Find an employee by his/hers unique code, and support updating of the employee info if found" << endl;
        cout << "3.List all employees in lexicographic order of their names" << endl;
        cout << "4.List all staffs that is still working" << endl;
        cout << "5.Delete an employee info given by its code" << endl;
        cout << "6.Delete all non-working employees or Save all employees' info in file employee.txt" << endl;
        cout << "7.Exit the program" << endl;
        cout << "Your choice: ";
        cin >> choice;
        switch (choice) {

        case 1://Name can have spaces
            cout << "Input the employee's id: ";
            cin >> id;
            cout << "Input the employee's name: ";
            cin.ignore();
            getline(cin, name);
            cout << "Input the employee's birthday: ";
            cin >> birth;
            do {
                cout << "Input the employee's gender (0 is Female,1 is Male): ";
                cin >> gender;
                if (gender != 0 && gender != 1) {
                    cout << "Please input 0 or 1 for gender!" << endl;
                }
            } while (gender != 0 && gender != 1);
            do {
                cout << "Input the employee's status (0 is Working,1 is Quitted): ";
                cin >> status;
                if (status != 0 && status != 1) {
                    cout << "Please input 0 or 1 for status!" << endl;
                }
            } while (status != 0 && status != 1);
            root = insertNode(root, id, name, birth, gender, status);
            n++;
            cout << "The node is added!" << endl;
            break;
        case 2:
            cout << "Input the id to find the employee: ";
            cin >> id;
            p = findNode(root, id);
            if (p == NULL) {
                cout << "This id does not exist!" << endl;
            }
            else {
                cout << "Found: " << p->id << " " << p->name << " " << p->birth << " ";
                if (p->gender == 0) {
                    cout << "Female ";
                }
                else {
                    cout << "Male ";
                }
                if (p->status == 0) {
                    cout << "Working" << endl;
                }
                else {
                    cout << "Quitted" << endl;
                }
                cout << "Do yout want to update this employee info?" << endl;
                cout << "Input 1 if yes, input any key if no: ";
                cin >> choice;
                if (choice == 1) {
                    cout << "Input this employee's id: ";
                    cin >> id;
                    cout << "Input this employee's name: ";
                    cin.ignore();
                    getline(cin, name);
                    cout << "Input this employee's birthday: ";
                    cin >> birth;
                    do {
                        cout << "Input the employee's gender (0 is Female,1 is Male): ";
                        cin >> gender;
                        if (gender != 0 && gender != 1) {
                            cout << "Please input 0 or 1 for gender!" << endl;
                        }
                    } while (gender != 0 && gender != 1);
                    do {
                        cout << "Input this employee's status (0 is Working,1 is Quitted): ";
                        cin >> status;
                        if (status != 0 && status != 1) {
                            cout << "Please input 0 or 1 for status!" << endl;
                        }
                    } while (status != 0 && status != 1);
                    root = deleteNode(root, p->name);
                    root = insertNode(root, id, name, birth, gender, status);
                    cout << "The employee's info has been updated!" << endl;
                }
            }
            break;
        case 3:
            cout << "List of employees: " << endl;
            printInorder(root);
            break;
        case 4:
            cout << "Working employees: " << endl;
            printWorkStaff(root);
            break;
        case 5:
            cout << "Input the id to delete: ";
            cin >> id;
            p = findNode(root, id);
            if (p == NULL) {
                cout << "This id does not exist!" << endl;
            }
            else {
                cout << "Found: " << p->id << " " << p->name << " " << p->birth << " ";
                if (p->status == 0) {
                    cout << "Working" << endl;
                }
                else {
                    cout << "Quitted" << endl;
                }
                root = deleteNode(root, p->name);
                n--;
                cout << "This node is deleted!" << endl;
            }
            break;
        case 6:
            do {
                cout << "Input 1 if you want to delete quitted employees, 2 if you want to save a file: ";
                cin >> choice;
                if (choice != 1 && choice != 2) {
                    cout << "Please input again!" << endl;
                }
            } while (choice != 1 && choice != 2);
            if (choice == 1) {
                p = root;
                deleteQuitStaff(root, p);
                n = nodeCount(root);
                cout << "All Quitted employees info are deleted!" << endl;
            }
            if (choice == 2) {
                Savefile(root, n);
                cout << "The file is saved!" << endl;
            }
            break;

        case 7:
            cout << "Thank you for using the program, goodbye";
            return 0; //stop the program;
        }
        cin.clear();
        cout << "Do you want to continue using the operations?" << endl;
        cout << "Input 1 if yes, or input any key if no: ";
        cin >> choice;
        if (choice != 1) {
            cout << "Thank you and good bye" << endl;
            break;
        }
        else {
            system("cls"); //reset the screen 
        }
    }

    return 0;
}