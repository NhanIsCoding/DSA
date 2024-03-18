#include "Header.h"

int main() {
    Node* root = NULL;
    root = new Node();
    root->question = "";
    root->guess = "tiger";
    root->yesAnswer = NULL;
    root->noAnswer = NULL;
    gameRun(root);
    cout << "Thank you for playing the game, goodbye" << endl;
    return 0;
}