#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define l long
#define veci vector<int>
#define pii pair<int,int>
#define rep(i,st,n) for(int i=st; i<n; i++)
#define ceil(x,y) (x+y-1)/y//least integer function
#define sz(x) (int)(x).size()
#define PI 3.141592653589793238 
#define ull unsigned long long
#define pb push_back
#define pp pop_back
#define IM INT_MAX
#define IN INT_MIN
#define lb lower_bound
#define ub upper_bound
void findPrimes(vector<int> &Primes){
	ll n = sz(Primes);
	for(ll i=2; i<n; ++i){
		if(Primes[i]){
			for(ll j=2*i; j<n; j=j+i){
				Primes[j]=0;
			}
		}
	}
}
const int N = 1e6 + 10;
veci a(N,1);
void solve(){
	//code here	
	int n;
	cin>>n;
	findPrimes(a);
	unordered_set<ll> st;
	rep(i,2,N){
		if(a[i]==1)
			st.insert(i*1LL*i);
	}
	rep(i,0,n){
		ll ele;
		cin>>ele;
		if(st.find(ele)!=st.end()){cout<<"YES";}
		else{cout<<"NO";}
		cout<<endl;
	}
}



int main(){
	ios_base::sync_with_stdio(0);
	clock_t start = clock();
	solve();
	double duration = ((double) clock() - start) / (double) CLOCKS_PER_SEC;
	//cout << "\nTime: " << fixed << setprecision(20) << duration*1000<< " ms" << endl;
}
