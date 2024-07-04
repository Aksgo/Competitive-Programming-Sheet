#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define l long
#define veci vector<int>
#define pii pair<int,int>
ll sumof(ll num){
	ll ans  = 0;
	while(num>0){
		ans += num%10;
		num=num/10;
	}
	return ans;
}
int main(){
	ll num;
	cin>>num;
	ll maxi = num;
	ll temp = num;
	ll p  = 10;
	ll pq=1;
	while(num>0){
		int digit = num%10;
		num=num/10;
		if(num==0){break;}
		temp = (num-1)*p + 9*pq;
		if(sumof(temp)>sumof(maxi)){maxi=temp;}
		pq+=p;
		p*=10;
	}
	cout<<maxi;
}
