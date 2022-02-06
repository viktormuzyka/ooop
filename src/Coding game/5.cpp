#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string binary( char x) {
	unsigned char mask=64;
	string s;
	for(int i=0; i<7; i++) {
		s.push_back((x&mask)>0 ? '1':'0');
		mask=mask>>1;
	}
	return s;
}
void add_symb(long long start, long long key, string &ans) {
	if (start%2==1) {
		ans += "0 ";
	} else {
		ans += "00 ";
	}
	for(long long i=0; i<key; i++) {
		ans+="0";
	}
	ans+=" ";
}

int main() {
	string l;
	string a;
	string ans="";
	bool flag=true;
	long long start=1,k=0,i=0;
	char x;
	while(cin >> x) {
		l+=binary(x);
	}
	cout << binary(' ') << endl;
	while ( i<l.length() ) {
		while(flag and l[i]=='1')  {
			if(l[i]=='1') {
				k++;
				i++;
			} else  flag=false;
		}

		if (k!=0) add_symb(start, k, ans);
		k=0;
		start++;
		flag=true;
		while(flag and l[i]=='0') {
			if(l[i]=='0') {
				k++;
				i++;
			} else  flag=false;
		}

		if (k!=0) add_symb(start, k, ans);
		k=0;
		start++;
		flag=true;

	}
	ans.resize(ans.length()-1);
	cout << ans << endl;
	return 0;
}
