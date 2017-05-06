#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
	string test;
	ofstream outfile;
	ifstream inputfile;
	outfile.open("file2.dat", ios::out | ios::trunc );
	//outfile << "Hi from c++\n";
	inputfile.open("encrypt.dat", ios::in );


	int x;
	if (inputfile.is_open())
	{
		while(getline(inputfile,test))
		{
			cout << test << endl;
			for(int counter = 0; counter < test.length(); counter++)
			{
				test[counter] -= 1;
			}
			cout << test << endl;
			outfile << test << endl;
		}
	}
//	inputfile >> test;
//	cout << test;

	inputfile.close();
	outfile.close();
	cin >> x;
}