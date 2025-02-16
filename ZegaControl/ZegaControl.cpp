// ZegaControl.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include "XZega.h"
using namespace std;
int main()
{
	map<int, double> dataline;
	double ratio;
	Alator machina;
	machina.setFile("residentZegaOne.raw");
	
	dataline = machina.getFrom(5);

	cout << "Delta1 = " << dataline[0] << endl;
	cout << "Delta2 = " << dataline[1] << endl;
	cout << "Delta3 = " << dataline[2] << endl;
	cout << "ZegaValue = " << dataline[3] << endl;

	Disector aniz;
	aniz.compose(dataline[0], dataline[1], dataline[2], dataline[3]);
	ratio = aniz.getRatio();
	cout << "Bon a " << ratio << "%" << endl;

	aniz.displayOkay();
	aniz.create_csv_brain();

	/*cout << "5 IS PAIR: " << is_pair(5.0) << endl;
	cout << "4 IS PAIR: " << is_pair(4.0) << endl;

	cout << "heuristic 7: " << heuristic_prime(7) << endl;
	cout << "heuristic 4: " << heuristic_prime(4) << endl;
	cout << "heuristic 8: " << heuristic_prime(8) << endl;
	cout << "heuristic 17: " << heuristic_prime(17) << endl;
	*/

    cout << "Is Okay\n"; 
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
