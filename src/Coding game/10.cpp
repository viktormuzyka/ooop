#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/

int main()
{
    int w;
    int h;
    int k=0,len_x,len_y;
    int count_x;
    int count_y;
    cin >> w >> h >> count_x >> count_y; cin.ignore();
    int * x = new int[w];
    int * y = new int[h];
    x[0]=0;
    y[0]=0;
    for (int i = 1; i <= count_x; i++) {
        cin >> x[i]; cin.ignore();
    }
    for (int i = 1; i <= count_y; i++) {
        cin >> y[i]; cin.ignore();
    }
    x[count_x+1]=w;
    y[count_y+1]=h;
    for(int i=0; i<=count_x; i++){
    	for(int j=i+1; j<=count_x+1; j++){
    		len_x=abs(x[i]-x[j]);
    		//cout << "len x: "<<len_x << endl;
    		for(int y1=0; y1<=count_y; y1++){
    			for(int y2=y1+1; y2<=count_y+1; y2++){
    				len_y=abs(y[y1]-y[y2]);
    				if (len_x==len_y) k++;
    				//cout << "k: "<<k << endl;
				}    			
			}
		}
	}
    // Write an answer using cout. DON'T FORGET THE "<< endl"
    // To debug: cerr << "Debug messages..." << endl;

    cout << k << endl;
}
