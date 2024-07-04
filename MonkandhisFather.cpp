#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main() {
	int t;
	cin>>t;
	while(t--){
		ll p;
		cin>>p;
		int sb = 0;
		while(p){
			if(p&1){sb++;}
			p>>=1;
		}
		cout<<sb<<endl;
	}
}
