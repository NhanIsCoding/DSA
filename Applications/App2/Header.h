#ifndef _HEADER_H_
#define _HEADER_H_

#include<iostream>
#include<string>

using namespace std;

struct Node {
    string question;
    string guess;
    Node* yesAnswer, * noAnswer;
};

void gameRun(Node* root);


#endif