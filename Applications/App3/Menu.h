#ifndef _HEADER_H_
#define _HEADER_H_

#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <random>
using namespace std;
int main();
void login(int count, string& userId, string password, string id, string pass,bool& check);
void registration(string userId, string password, string id, string pass);
void forgot(int count, string userId, string id, string pass);




#endif