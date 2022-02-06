#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/

int main() {
	int n; // the number of temperatures to analyse
	int temp=5527;
	cin >> n;
	cin.ignore();
	for (int i = 0; i < n; i++) {
		int t; // a temperature expressed as an integer ranging from -273 to 5526
		cin >> t;
		cin.ignore();

		if (abs(t)<abs(temp)) {
			temp=t;
		} else if(abs(t)==abs(temp) and t>temp) {
			temp=t;
		}
	}


// Write an answer using cout. DON'T FORGET THE "<< endl"
// To debug: cerr << "Debug messages..." << endl;
	if (temp==5527) {
		temp=0;
	}
	cout << temp << endl;
}
