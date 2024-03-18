#include "Menu.h"
#include "TicTacToe.h"

int main() {
	int choice;
	bool check;
	int count = 0;
	string userId, password, id, pass;
	while (true) {
		cout << endl;
		cout << "WELCOME TO THE LOGIN PAGE" << endl;
		cout << "Please choose a operation based on this menu: " << endl;
		cout << "1.Account Login" << endl;
		cout << "2.Account Register" << endl;
		cout << "3.Forgot Password" << endl;
		cout << "4.Exit the program" << endl;
		cout << "Please enter your choice: ";
		cin >> choice;
		cout << endl;

		switch (choice) {
		case 1:
			while (true) {
				login(count, userId, password, id, pass,check);
				if (check == true) {
					gameRun(userId);
					return 0;
				}
				if (check == false) {
					do {
						cout << "Input 0 to login again" << endl;
						cout << "Input 1 to return to THE LOGIN PAGE" << endl;
						cout << "Your choice: ";
						cin >> choice;
						if (choice != 0 && choice != 1) {
							cout << "Invalid Input!" << endl;
						}
					} while (choice != 0 && choice != 1);
					if (choice == 1) {
						break;
					}
				}
			}
			break;
		case 2:
			registration(userId, password, id, pass);
			break;
		case 3:
			forgot(count, userId, id, pass);
			break;
		case 4:
			cout << "Thank you for using the program, goodbye" << endl;
			return 0;
		default:
			system("cls");//clear screen
			cout << "Please input again (1 to 4)" << endl;
			main();
		}
	}
}