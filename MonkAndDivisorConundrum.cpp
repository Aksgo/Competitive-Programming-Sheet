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
void findPrimes(vector<bool> &Primes){
	ll n = sz(Primes);
	for(ll i=2; i<n; ++i){
		if(Primes[i]){
			for(ll j=2*i; j<n; j=j+i){
				Primes[j]=false;
			}
		}
	}
}
const int N = 2e5 + 10;
vector<int> a(N,0);
void solve(){
	//code here	
	int n;
	cin>>n;
	unordered_map<int, int> m;
	rep(i,0,n){
		int ele;
		cin>>ele;
		m[ele]++;
	}
	rep(i,1,N){
		for(int j=i; j<N; j+=i){
			a[i]+=m[j];
		}
	}
	int t;
	cin>>t;
	while(t--){
		ll p, q;
		cin>>p>>q;
		ll lcm = (p*q)/__gcd(p,q);

		ll lc = (lcm>=N)?0:lcm;
		cout<<a[p]+a[q]-a[lc]<<endl;
	}
}



int main(){
	ios_base::sync_with_stdio(0);
	clock_t start = clock();
	solve();
	double duration = ((double) clock() - start) / (double) CLOCKS_PER_SEC;
	//cout << "\nTime: " << fixed << setprecision(20) << duration*1000<< " ms" << endl;
}
