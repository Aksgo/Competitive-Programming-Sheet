//problem link:
//https://codeforces.com/problemset/problem/1853/B
//Solution
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
		ll n,k;
		cin>>n>>k;
		ll ans = 0;
		ll x,y;
		ll z=n;
		ll nc = n;
		n++;
		while(n--){
			ll y = n;
			bool valid = true;
			for(int i=2; i<k; i++){
				x = z-y;
				//cout<<z<<" "<<y<<" "<<x<<":"; 
				z=y;
				if(x>y){valid = false;break;}
				if(min(x,y)<0){valid =false; break;}
				y=x;
			}
			//cout<<"\n||||||||"<<endl;
			z = nc;
			if(valid){ans++;}
		}
		cout<<ans<<endl;
	}
}
