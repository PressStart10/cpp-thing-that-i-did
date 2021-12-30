#include <iostream>
#include <unistd.h>
#include <stdlib.h>
#include "h.h"
#define NC "\e[0m"
#define RED "\e[0;31m"
#define GRN "\e[0;32m"
using namespace std;
bool help2 = true;
bool gethelp(){
	return help2;
}
void givehelp(bool a){
	help2 = a;
}
string icon2 = "";
//█ (for referince)
//22 charachters long
std::string blocks = "";
std::string under = "______________________";
string doi;
bool done = false;
int ad(){
	blocks += "████████";
	if (!under.empty()){
        under.pop_back();
		under.pop_back();
		under.pop_back();
		under.pop_back();
		under.pop_back();
		under.pop_back();
		under.pop_back();
		under.pop_back();
	}
}
string cuurent = "boot manager";
string loadtex[] = {"[[" + cuurent + ":startup]]", "[[executing...]]", "[[executing...]]", "[[executing...]]", "[[..done..]]", "[[load started]]", "[[loading...]]","[[loading...]]","[[loading...]]", "[[..done..]]", "[[completed]]"};
void redef(string a){
	cuurent = a;
	string loadtex[] = {"[[" + cuurent + ":startup]]", "[[executing...]]", "[[exicuting...]]", "[[executing...]]", "[[..done..]]", "[[load started]]", "[[loading...]]","[[loading...]]","[[loading...]]", "[[..done..]]", "[[completed]]"};
}
void clear(){
	system("clear");
}
int load(){
	cout<<GRN;
	for(int i = 0; i < 3; i += 1){
		cout << "########################## \n";
		cout << "#  entering BOOT_MANAGER # \n";
		cout << "#       please wait      # \n";
		cout << "#                        # \n";
		cout << "# " << blocks << under << " # \n";
		cout << "########################## \n \n";
		sleep(1);
		system("clear");
		ad();
	}
	for(int x = 0; x < sizeof(loadtex)/sizeof(*loadtex); x++){
		cout << loadtex[x] << "\n";
		sleep(1);
	}
	cout<<NC;
	sleep(1);
	clear();
}
int main() {
	if(done == false){
		system("clear");
		load(); // ['_']
	}
	done = true;
	while(true){
		clear();
		icon2 = getic();
		cout << icon2 << endl << "do: \n icon \n exit" << endl << ">>";
		cin >> doi;
		cout << NC;
		if(doi == "icon"){
			help2 = true;
			faced();
		}
		if(doi == "exit"){
			clear();
			return 0;
		}
	}
}
int back(){
	main();
}