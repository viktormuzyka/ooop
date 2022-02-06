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
	int n;
	int pi[100000];
	cin >> n;
	cin.ignore();
	for (int i = 0; i < n; i++) {
		cin >> pi[i];
		cin.ignore();
	}
	sort(pi, pi + n);
	int abs_m=10000001;
	for (int i = 0; i < n-1; i++) {
		if (abs(pi[i]-pi[i+1])<abs_m) {
			abs_m=abs(pi[i]-pi[i+1]);
		}
	}
	// Write an answer using cout. DON'T FORGET THE "<< endl"
	// To debug: cerr << "Debug messages..." << endl;

	cout << abs_m << endl;
}
