#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define veci vector<int>
#define pii pair<int,int>
#define rep(i,n) for(int i=0; i<n; i++)
int main(){
	int t;
	cin>>t;
	while(t--){
		int lw, r;
		cin>>lw>>r;
		int i=0;
		while(true){
			if((1<<i)>r){break;}
			i++;
		}
		cout<<i-1<<endl;
	}

}
