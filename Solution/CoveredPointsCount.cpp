#include <bits/stdc++.h>
using namespace std;
#define ll long long
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
#define ff first
#define ss second
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

void solve(){
	//code here
	int n;
	cin>>n;
	vector<pair<ll,ll>> a;
	rep(i,0,n){
		ll x,y;
		cin>>x>>y;
		pair<ll,ll> p1 = {x,0};
		pair<ll,ll> p2 = {y,1};
		a.pb(p1);
		a.pb(p2);
	}
	sort(a.begin(), a.end());
	int ct = 0;
	vector<ll> ans(n+1, 0);
	rep(i, 0, 2*n-1){
		auto p1 = a[i];
		auto p2 = a[i+1];
		if(p1.ss==0)ct++;
		else ct--;
		ll diff = p2.ff - p1.ff;
		ll ex = p2.ss - p1.ss;
		ans[ct] += (diff + ex);
	}
	rep(i,1,n+1){
		cout<<ans[i]<<" ";
	}
}

int main(){
	//setIO("");
	ios_base::sync_with_stdio(0);
	cin.tie(0);//making cin faster
	clock_t start = clock();
	int t=1;
	//cin>>t;
	while(t--)
		solve();
	double duration = ((double) clock() - start) / (double) CLOCKS_PER_SEC;
	//cout << "\nTime: " << fixed << setprecision(20) << duration*1000<< " ms" << endl;
}
