#include "TicTacToe.h"

char board[9] = { ' ',' ',' ',' ',' ',' ',' ',' ',' ' };

void get_computer_choice() {
	srand(time(0));
	int choice;
	do {
		choice = rand() % 10;
	} while (board[choice] != ' ');
	board[choice] = 'O';
}

void get_x_player_choice() {
	while (true) {
		cout << "Select Your Position (1-9): ";
		int choice;
		cin >> choice;
		choice--;
		if (choice < 0 || choice>8) {
			cout << "Error: Please Select Your Choice From (1-9)" << endl;
		}
		else if (board[choice] != ' ') {
			cout << "Error: Please Select An Empty Position" << endl;
		}
		else {
			board[choice] = 'X';
			break;
		}
	}
}

int countMove(char symbol) {
	int total = 0;
	for (int i = 0; i < 9; i++) {
		if (board[i] == symbol) {
			total += 1;
		}
	}
	return total;
}

char result() {
	//kiem tra hang ngang
	if (board[0] == board[1] && board[1] == board[2] && board[0] != ' ')
		return board[0];
	if (board[3] == board[4] && board[4] == board[5] && board[3] != ' ')
		return board[3];
	if (board[6] == board[7] && board[7] == board[8] && board[6] != ' ')
		return board[6];
	//kiem tra hang doc
	if (board[0] == board[3] && board[3] == board[6] && board[0] != ' ')
		return board[0];
	if (board[1] == board[4] && board[4] == board[7] && board[1] != ' ')
		return board[1];
	if (board[2] == board[5] && board[5] == board[8] && board[2] != ' ')
		return board[2];
	//kiem tra hang cheo
	if (board[0] == board[4] && board[4] == board[8] && board[0] != ' ')
		return board[0];
	if (board[2] == board[4] && board[4] == board[6] && board[2] != ' ')
		return board[2];
	//all of the cases above return 'O'
	if (countMove('X') + countMove('O') < 9)
		return 'C'; //continue
	else
		return 'D'; //draw
}

void showBoard() { //ve ban co
	cout << "These Are The Locations For You To Enter" << endl << endl;
	cout << "   1  |   2  |   3" << endl;
	cout << "      |      |   " << endl;
	cout << "--------------------" << endl;
	cout << "   4  |   5  |   6" << endl;
	cout << "      |      |   " << endl;
	cout << "--------------------" << endl;
	cout << "   7  |   8  |   9" << endl;
	cout << "      |      |   " << endl;

	cout << endl << endl;
	cout << "   " << "   |   " << "   |   " << endl;
	cout << "   " << board[0] << "  |   " << board[1] << "  |   " << board[2] << endl;
	cout << "   " << "   |   " << "   |   " << endl;
	cout << "--------------------" << endl;
	cout << "   " << "   |   " << "   |   " << endl;
	cout << "   " << board[3] << "  |   " << board[4] << "  |   " << board[5] << endl;
	cout << "   " << "   |   " << "   |   " << endl;
	cout << "--------------------" << endl;
	cout << "   " << "   |   " << "   |   " << endl;
	cout << "   " << board[6] << "  |   " << board[7] << "  |   " << board[8] << endl;
	cout << "   " << "   |   " << "   |   " << endl;
}

void manVsComputer(string userId) {
	string player_name = userId;
	while (true) {

		showBoard();
		if (countMove('X') == countMove('O')) {
			cout << player_name << "'s Turn " << "(X)" << endl;
			get_x_player_choice();

		}
		else {
			get_computer_choice();
		}
		char winner = result();
		if (winner == 'X') {
			system("cls");
			showBoard();
			cout << player_name << " Won The Game." << endl;
			break;
		}
		else if (winner == 'O') {
			system("cls");
			showBoard();
			cout << "Computer Won The Game." << endl;
			break;
		}
		else if (winner == 'D') {
			system("cls");
			showBoard();
			cout << "It Is A Draw." << endl;
			break;
		}
		system("cls");
	}
}

void gameRun(string userId) {
playAgain:
	cout << endl;
	cout << "____WELCOME TO TIC TAC TOE____" << endl << endl;
	cout << "Rules For Tic Tac Toe:" << endl;
	cout << "-The game is played on a grid that's 3 squares by 3 squares" << endl;
	cout << "-You are X, the computer is O. Players take turns putting their marks in empty squares" << endl;
	cout << "(X Will Go First)" << endl;
	cout << "-The first player to get 3 marks in a row (up, down, across, or diagonally) is the winner" << endl;
	cout << "-When all 9 squares are full, the game is over. If no player has 3 marks in a row, the game ends in a tie." << endl << endl;
	cout << "Now Let's Start This Game, Shall We?" << endl;
	manVsComputer(userId);
	cout << "DO YOU WANT TO PLAY AGAIN?" << endl;
	cout << "If Yes, Enter Y (or y)" << endl;
	cout << "If No, Enter N (or n)" << endl;
	char play;
	cin >> play;
	while (play != 'Y' && play != 'y' && play != 'N' && play != 'n') {
		cout << "Error: It Is Not A Valid Answer, Please Try Again" << endl;
		cin >> play;
	}
	if (play == 'Y' || play == 'y') {
		for (int stt = 0; stt < 9; stt++) {
			board[stt] = ' ';
		}
		system("cls");
		goto playAgain;
	}
	else if (play == 'N' || play == 'n') {
		system("cls");
		cout << "The Game Is Over" << endl;
		cout << "Thank You For Playing" << endl;
		return;
	}
}