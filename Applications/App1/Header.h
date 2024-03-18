#ifndef _HEADER_H_
#define _HEADER_H_

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

struct Node {
    string id;
    string name;
    string birth;
    bool gender; //0: is Female, 1: is Male
    bool status; //0: The employee is still working for the company, 1: The employee has quitted the job
    int height;
    Node* left;
    Node* right;
};

bool is_file_exist(string fileName);
int height(Node* N);
int max(int a, int b);
Node* newNode(string id, string name, string birth, bool gender, bool status);
Node* rightRotate(Node* y);
Node* leftRotate(Node* x);
Node* insertNode(Node* node, string id, string name, string birth, bool gender, bool status);
void Loadfile(Node*& root, int& n);
void printInorder(struct Node* node);
Node* findNode(Node* node, string key);
Node* minValueNode(Node* node);
Node* deleteNode(Node* root, string key);
void printWorkStaff(Node* node);
void deleteQuitStaff(Node* root, Node* p);
int nodeCount(Node* root);
void printFileInorder(struct Node* node, ofstream& fout);
void Savefile(Node* root, int n);



#endif