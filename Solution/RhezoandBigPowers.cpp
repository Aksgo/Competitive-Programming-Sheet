#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll binExp(ll a, ll b, int m){
	ll ans = 1;
	while(b){
		if(b&1)
			{ans = (ans*a)%m;}
		a = (a*a)%m;
		b>>=1;
	}
	return ans;
}
int main(){
	ll a;
	string b;
	cin>>a>>b;
	int m = 1e9 + 7;
	ll bm = 0;
	for(int i=0; i<b.size(); ++i){
		bm = ((bm*10)%(m-1) + (b[i]-'0')%(m-1))%(m-1);
	}
	bm += m-1;
	ll ans = binExp(a,bm,m);
	cout<<ans;
}
