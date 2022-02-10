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
	int w;
	cin >> w;
	cin.ignore();
	int h;
	cin >> h;
	cin.ignore();
	int k=0;
	int *arr =new int[w*h];
	for(int i=0; i<w*h; i++) {
		arr[i]=0;
	}
	string t;
	getline(cin, t);
	//cout << ((int)'9'-48) <<endl;
	for(int i=0; i<t.length(); i++) {
		if(t[i]!=' ' or i==t.length()-1) {
			int z = ((int)t[i]-48);
			//cout <<"z"<<i<<" "<<z <<endl;
			arr[k]=10*arr[k]+z;
			if (i==t.length()-1) k++;
		} else {
			k++;
		}
	}
	for(int i=0; i<k; i++) {
		//cout << arr[i] << endl;
	}
	int start=0,count=0;
	// Write an answer using cout. DON'T FORGET THE "<< endl"
	// To debug: cerr << "Debug messages..." << endl;
	for(int i=0; i<h; i++) {
		cout <<"|";
		for(int j=1; j<=w; j++) {
			if (arr[start]==0){
				start++;
			}
			if (start%2==0 ) {
				cout << "*";
				count++;
				if (count==arr[start]) {
					start++;
					count=0;
				}
			}
			else if (start==k){
				break;
			}
			else if (start%2==1) {
				cout <<" ";
				count++;
				if(count==arr[start]) {
					start++;
					count=0;
				}
			}
			else if (start==k){
				break;
			}
		}
	cout <<"|";
	cout << endl;
}
}
