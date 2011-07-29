#include <iostream>
#include <fstream>
#include <string>
#include <unistd.h>
#include <sys/types.h>


using namespace std;

int adder();

int main()
{
	if (getuid() != 0) {
		cout << "Please rerun this script as su by typing \"sudo addhost\"\n" << endl;
	}
	else {
		adder();
	}
	return 0;
}

		
int adder()
{

	ofstream myfile;
	string url;

	myfile.open("/etc/hosts", ios::app);
	cout << "Enter the address you wish to kill: " << endl;
	cin >> url;
	myfile << "127.0.0.1\t" << url << "\n";
	myfile.close();
	cout << "Added " << url << " to your hosts file.\n";

	return 0;
}

