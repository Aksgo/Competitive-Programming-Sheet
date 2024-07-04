#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define l long
#define veci vector<int>
#define pii pair<int,int>
int main(){
	int t;
	cin>>t;
	while(t--){
		int n; string s;
		cin>>n>>s;
		int countU = 0;
		for(int i=0; i<n;i++){
			if(s[i]=='U'){countU++;}
		}
		if(countU&1){cout<<"Yes";}
		else{cout<<"No";}
		cout<<endl;
	}
}
