#include "Menu.h"

void login(int count, string& userId, string password, string id, string pass,bool &check) {
	system("cls");
	count = 0;
	cout << "Please enter the username and password:" << endl;
	cout << "USERNAME: ";
	cin >> userId;
	cout << "PASSWORD: ";
	cin >> password;
	ifstream fin;
	fin.open("data.txt");
	if (fin.is_open()) {
		while (fin >> id >> pass) {
			for (int i = 0; id[i] != '\0'; i++) {
				id[i] = id[i] - 2;
			}//key for decryption is 2 that is subtracted to the ASCII value
			for (int i = 0; pass[i] != '\0'; i++) {
				pass[i] = pass[i] - 5;
			}//key for decryption is 5 that is subtracted to the ASCII value
			if (id == userId && pass == password) {
				count = 1;
				system("cls");
				break;
			}
		}
	}
	fin.close();
	if (count == 1) {
		cout << userId << endl;
		cout << "Successful Login!" << endl;
		check = true;
		return;
	}
	else {
		cout << "Unsuccessful Login!" << endl;
		cout << "Please check your username and password" << endl;
		check = false;
		return;
	}
}

void registration(string userId, string password, string id, string pass) {

	system("cls");
	cout << "Input the username: ";
	cin >> userId;
	cout << "Input the password: ";
	cin >> password;
	ifstream fin;
	fin.open("data.txt");

	if(fin.is_open()) { //check if username already exists
		while (fin >> id) {
			for (int i = 0; id[i] != '\0'; i++) {
				id[i] = id[i] - 2;
			}//key for decryption is 2 that is subtracted to the ASCII value
			if (userId == id) {
				cout << "This name already exists" << endl;
				cout << "Please consider a new username" << endl;
				fin.close();
				return;
			}
			fin >> pass;
		}
	}
	fin.close();


	for (int i = 0; userId[i] != '\0'; i++) {
		userId[i] = userId[i] + 2;
	}//key for encryption is 2 that is added to the ASCII value
	for (int i = 0; password[i] != '\0'; i++) {
		password[i] = password[i] + 5;
	}//key for encryption is 5 that is added to the ASCII value
	ofstream fout;
	fout.open("data.txt", ios::app);
	fout << userId << endl;
	fout << password << endl;
	system("cls");
	cout << "Registration Successful!" << endl;
	fout.close();

}

void forgot(int count, string userId, string id, string pass) {
	count = 0;
	system("cls");
	cout << "Did you forgot the password?" << endl;
	ifstream fin;
	cout << "Enter the Username which you remember: ";
	cin >> userId;
	fin.open("data.txt");
	while (fin >> id >> pass) {
		for (int i = 0; id[i] != '\0'; i++) {
			id[i] = id[i] - 2;
		}//key for decryption is 2 that is subtracted to the ASCII value
		for (int i = 0; pass[i] != '\0'; i++) {
			pass[i] = pass[i] - 5;
		}//key for decryption is 5 that is subtracted to the ASCII value
		if (id == userId) {
			count = 1;
			break;
		}
	}
	fin.close();
	if (count == 1) {
		cout << "Your account is found!" << endl;
		cout << "Your password is: " << pass;
		cout << endl;
	}
	else {
		cout << "Sorry, Your account is not found!" << endl;
	}
}