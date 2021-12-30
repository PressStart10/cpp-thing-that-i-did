#include <iostream>
#include <unistd.h>
#include "h.h"
#include <stdlib.h>
#define NC "\e[0m"
#define RED "\e[0;31m"
#define GRN "\e[0;32m"
#define exit "exit"
using namespace std;
bool help = true;
string face[] = {" up \n down \n left \n right \n normal \n custom \n exit \n help[show this]", "['_']", "['>']", "['<']", "['^']", "['v']"};
int x = 1;
string in = "";
string icon = "['_']";
string getic(){
	return icon;
}
// 5 parts {1 - 5}
int faced(){
	bool e = false;
	help = gethelp();
	givehelp(false);
	string temp = "";
	system("clear");
	cout << icon << endl << endl;
	if(help == true)
		cout << face[0] << endl;
	help = false;
	cin >> in;
	if(in == "up"){
		icon = face[4];
		faced();
	}
	else if (in == "down"){
		icon = face[5];
		faced();
	}
	else if(in == "left"){
		icon = face[3];
		faced();
	}
	else if(in == "right"){
		icon = face[3 - 1];
		faced();
	}
	else if(in == "normal"){
		icon = face[1];
		faced();
	}
	else if(in == "help"){
		givehelp(true);
		faced();
	}
	else if(in == "custom"){
		clear();
		cout << "[   ]" << endl << " ^^^ " << endl << " ";
		cin >> temp;
		if(temp.length() < 3){
			e = true;
			while(e){
				clear();
				cerr << RED"ERR: character underflow" GRN<< endl;
				string tempr;
				cout << "continue[y/n] ";
				cin >> tempr;
				if(tempr == "y"){
					cout << NC;
					e = false;
					faced();
				}
				else if(tempr == "n"){
					clear();
					cout << NC;
					return 0;
				}
			}
		}
		else if(temp.length() > 3){
			e = true;
			while(e){
				clear();
				cerr << RED "ERR: character overflow" GRN<< endl;
				string tempr;
				cout << "continue[y/n] ";
				cin >> tempr;
				if(tempr == "y"){
					cout << NC;
					e = false;
					faced();
				}
				else if(tempr == "n"){
					clear();
					cout << NC;
					return 0;
				}
			}
		}
		else{
			cout << GRN "succes" NC << endl;
			icon = "[" + temp + "]";
			faced();
		}
	}
	else if(in == exit){
		system("clear");
		back();
	}
	else{
		system("clear");
		faced();
	}
}