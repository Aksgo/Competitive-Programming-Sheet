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
const long long MOD  = 1e9 + 7;
const long long MOD1 = 998244353;
struct ch {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};
void setIO(string s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

void findPrimes(vector<int> &Primes){
	ll n = Primes.size();
	for(ll i=2; i<n; ++i){
		if(Primes[i]){
			for(ll j=2*i; j<n; j=j+i){
				Primes[j]=0;
			}
		}
	}
}

void solve(){
	//code here	
	ll s1, s2, t1, t2;
	cin>>s1>>s2;
	cin>>t1>>t2;
	ll d = abs(t2-s2);
	if(s2&1){
		s1 = s1 - !(s1%2);
	}
	else{
		s1 = s1 - (s1%2);
	}
	ll le = s1 - d;
	ll ri = s1 + d + 1;
	if(t1>=le && t1<=ri){
		cout<<d;
	}
	else{
		if(t1<le){
			ll dif = le-t1;
			dif = dif + (dif%2);
			d += dif/2;
			cout<<d;
		}
		if(t1>ri){
			ll dif = t1-ri;
			dif = dif + (dif%2);
			d += dif/2;
			cout<<d;
		}
	}
}



int main(){
	//setIO("");
	ios_base::sync_with_stdio(0);
	cin.tie(0);//making cin faster
	clock_t start = clock();
	solve();
	double duration = ((double) clock() - start) / (double) CLOCKS_PER_SEC;
	//cout << "\nTime: " << fixed << setprecision(20) << duration*1000<< " ms" << endl;
}
