#include "Header.h"

void gameRun(Node* root) { //there are 2 endings after guessing
    int end1 = 0; //learning a new animal ending
    int end2 = 0; //correctly guesses animal ending
    cout << "WELCOME TO THE ANIMAL GUESSING GAME!" << endl;
    cout << "Press Enter when you are ready to play" << endl;
    cout << "Waiting..." << endl;
    while (end1 == 0 && end2 == 0) {
        cin.ignore();
        cout << "Think of an animal, we will try to guess it" << endl;
        Node* temp = root;
        char answer;
        string name, q;
        while (true) {
            if (temp->question == "") {
                cout << "\nWere you thinking about " << temp->guess;
                cout << "\n(y or n): ";
                cin >> answer;

                if (answer == 'y' || answer == 'Y') {
                    end2 = 1;
                    break;
                }
                else {
                    Node* newYesAnswer=NULL, * newNoAnswer=NULL;
                    newYesAnswer = new Node();
                    newNoAnswer = new Node();

                    newYesAnswer->yesAnswer = NULL;
                    newYesAnswer->noAnswer = NULL;

                    newNoAnswer->yesAnswer = NULL;
                    newNoAnswer->noAnswer = NULL;

                    cin.ignore();
                    cout << "\nWhat animal it was?" << endl;
                    cout << "It was a: ";
                    getline(cin, name); //add new animal to the guesses
                    cout << "\nA question that can be used to distinguish that animal?\n";
                    getline(cin, q); //add question for the new animal

                    temp->question = q;

                    cout << "\nWhat would be its answer to identify it as " << name;
                    cout << "\nenter y for Yes and n for No: "; //yes or no for the new question to guess the animal
                    cin >> answer;
                    if (answer == 'y' || answer == 'Y') {
                        //yes->guesses the new animal
                        newYesAnswer->guess = name;
                        newNoAnswer->guess = temp->guess;
                    }
                    else {
                        //no->=guesses the new animal
                        newNoAnswer->guess = name;
                        newYesAnswer->guess = temp->guess;
                    }

                    temp->yesAnswer = newYesAnswer;
                    temp->noAnswer = newNoAnswer;
                    end1 = 1;
                    break;
                }
            }
            else {
                cout << "\n" << temp->question;
                cout << "\nEnter y for Yes and n for No: ";
                cin >> answer;
                if (answer == 'y' || answer == 'Y')
                    temp = temp->yesAnswer;
                else
                    temp = temp->noAnswer;
            }
        }
        if (end1 == 1) {//play again if new animal was learned, or end the game
            cout << "\nDo you want to play again.. (y/n) : ";
            cin >> answer;
            if (answer == 'y' || answer == 'Y')
                end1 = 0;
        }

        if (end2 == 1) {// play again if animal was guessed, or end the game
            cout << "\nHooray! We guessed it right...\n";
            cout << "\nDo you want to play again.. (y/n) : ";
            cin >> answer;
            if (answer == 'y' || answer == 'Y')
                end2 = 0;
        }
    }
}