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
	cin >> n;
	cin.ignore();
	int c;
	cin >> c;
	cin.ignore();
	int *cost = new int[n];
	int *rez = new int[n];
	int sum=0,sum_c=0,count_n=n;
	sum_c=c;
	for (int i = 0; i < n; i++) {
		cin >> cost[i];
		cin.ignore();
		sum+=cost[i];
	}
	if (sum<c) {
		cout <<"IMPOSSIBLE" <<endl;
	} else {
		sort(cost,cost+n);
		for(int i=0; i<n; i++) {
			if (cost[i]<=c/count_n and i!=n-1) {
				rez[i]=cost[i];
				c-=rez[i];
				count_n--;
			} else {
				rez[i]=c/count_n;
				c-=rez[i];
				count_n--;
			}
		}
		if (c!=0) {
			rez[n-1]+=c;
		}
		for(int i=0; i<n; i++) {
			cout << rez[i] << endl;
		}

	}

	// Write an answer using cout. DON'T FORGET THE "<< endl"
	// To debug: cerr << "Debug messages..." << endl;

//	cout << "IMPOSSIBLE" << endl;
}
