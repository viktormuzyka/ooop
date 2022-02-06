#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include<bits/stdc++.h>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/

int main() {
	int n; // Number of elements which make up the association table.
    bool flag=false;
	cin >> n;
	cin.ignore();
	int q; // Number Q of file names to be analyzed.
	cin >> q;
	cin.ignore();
	string mime;
	string *ext = new string[n]; // file extension
	string *mt = new string[n];
	for (int i = 0; i < n; i++) {
		cin >> ext[i] >> mt[i]; cin.ignore();
        transform(ext[i].begin(), ext[i].end(), ext[i].begin(), ::tolower);
	}
	for (int i = 0; i < q; i++) {
        flag=true;
        mime="";
		string fname;
		getline(cin, fname); // One file name per line.
		int k = fname.length();
        for(int j=0; j<k; j++){
            if(fname[j]=='.') {
                int start=j+1;
                while(fname[start]=='.'){
                    start++;
                }
                for(int jj=start;jj<k;jj++){
                    mime+=fname[jj];
                }
                break;
            }
        }
        transform(mime.begin(), mime.end(), mime.begin(), ::tolower);
		for(int z=0; z<n; z++) {
			if(mime==ext[z]) {
			    cout << mt[z] <<endl;
                flag=false;
			    break;
			}
		}
        if (flag) cout << "UNKNOWN" << endl;
	}

	// Write an answer using cout. DON'T FORGET THE "<< endl"
	// To debug: cerr << "Debug messages..." << endl;


	// For each of the Q filenames, display on a line the corresponding MIME type. If there is no corresponding type, then display UNKNOWN.
}
