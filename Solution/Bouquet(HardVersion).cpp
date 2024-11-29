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
const long long MOD  = 1e9 + 7;
const long long MOD1 = 998244353;
int nxt(){
	int x;cin>>x;return x;
}
ll nxl(){
	ll x;cin>>x;return x;
}
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
	ll n,m;
	cin>>n>>m;
	vector<ll> a(n);
	vector<ll> b(n);
	rep(i,0,n){
		cin>>a[i];
	}
	rep(i,0,n){
		cin>>b[i];
	}
	vector<pair<ll,ll>> p(n);
	rep(i,0,n){
		p[i] = {a[i],b[i]};
	}
	sort(p.begin(),p.end());
	ll ans = 0;
	for(auto &ele:p){
		ll t3 = min(ele.second, m/ele.first);
		ans = max(ans, ele.first*t3);
	}

	rep(i,0,n-1){
		if(p[i].first+1!=p[i+1].first)continue;
		ll cost = m;
		ll t1 = min(p[i].second, cost/p[i].first);
		cost -= (p[i].first*t1);
		ll t2 = min(p[i+1].second, cost/p[i+1].first);
		cost -= (p[i+1].first*t2);
		ll conv = min({t1, p[i+1].second-t2, cost});
		cost -= conv;
		ans = max(ans, m-cost);
	}
	cout<<ans<<endl;
}

int main(){
	//setIO("");
	ios_base::sync_with_stdio(0);
	cin.tie(0);//making cin faster
	clock_t start = clock();
	int t = 1;
	cin>>t;
	while(t--)	
		solve();
	double duration = ((double) clock() - start) / (double) CLOCKS_PER_SEC;
	//cout << "\nTime: " << fixed << setprecision(20) << duration*1000<< " ms" << endl;
}
