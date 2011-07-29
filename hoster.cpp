#include <iostream>
#include <fstream>
#include <string>
#include <unistd.h>
#include <sys/types.h>


using namespace std;

int adder();

int main()
{
	
	//first test to see if the command was run as root/sudo
	//this is only necessary because you need root to edit files in /etc
	if (getuid() != 0) {
		cout << "Please rerun this script as su by typing \"sudo addhost\"\n" << endl;
	}
	
	//that was easy enough. now hand this to the function below
	else {
		adder();
	}
	return 0;
}

		
int adder()
{

	ofstream myfile;
	string url;
	// open the hosts file. ios app appends the text to the end of the file, so you don't overwrite anything
	// you should change /etc/hosts to anything else for testing purposes if you just want to see if it works
	myfile.open("/etc/hosts", ios::app);
	cout << "Enter the address you wish to kill: " << endl;
	cin >> url;
	myfile << "127.0.0.1\t" << url << "\n";
	// done, now we close the file
	myfile.close();
	
	// verbose positive reinforcement
	cout << "Added " << url << " to your hosts file.\n";

	return 0;
}

