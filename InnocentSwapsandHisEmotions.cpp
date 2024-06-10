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
int binExp(ll a , ll b, ll m){
	a = a%m;
	int ans = 1;
	while(b){
		if(b&1){
			ans = (ans*1LL*a)%m;
		}
		a=(a*1LL*a)%m;
		b>>=1;
	}
	return ans;

}
const int N = 1e6 + 10;
int fact[N];
void solve(){
	//code here	
	int t;
	cin>>t;
	int m = 1e9+ 7;
	
	fact[0]=1;
	rep(i,1,N){
		fact[i]=(fact[i-1]*1LL*i)%m;
	}
	while(t--){
		int n,k;
		cin>>n>>k;
		int ans = fact[n];
		ans = (ans * 1LL * binExp(2,k,m)) % m;
		ll den = fact[k]*1LL*fact[n-k];
		ans = (ans * 1LL * binExp(den, m-2, m))%m;
		cout<<ans<<endl;
	}
}



int main(){
	ios_base::sync_with_stdio(0);
	clock_t start = clock();
	solve();
	double duration = ((double) clock() - start) / (double) CLOCKS_PER_SEC;
	//cout << "\nTime: " << fixed << setprecision(20) << duration*1000<< " ms" << endl;
}
