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
		string s;
		cin>>s;
		int n = s.size();
		int ind=n;
		for(int i=0; i<n; i++){
			if(s[i]=='1'){ind = i;break;}
		}
		ll ans = 0;
		for(int iter = ind+1; iter<n; iter++){
			if(s[iter]=='0'){
				ans+=(iter-ind+1);
				ind++;
			}
		}
		cout<<ans<<endl;
	}
}
