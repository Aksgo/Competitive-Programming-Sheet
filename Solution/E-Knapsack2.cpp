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

ll dp[100005][103];
ll w,n;
ll we[103];
const ll INF = 1e12+7;
ll val[103];
ll func(int ind , int v){
	if(v==0){return 0;}
	if(ind<0){return INF;}
	if(dp[v][ind]!=-1){return dp[v][ind];}
	ll ans =  INF;
	ans = min(ans, func(ind-1,v));
	if(v-val[ind]>=0){
		ans = min(ans,func(ind-1, v-val[ind])+we[ind]);
	}
	dp[v][ind] = ans;
	return ans;
}
void solve(){
	//code here
	cin>>n>>w;
	memset(dp, -1,sizeof(dp));
	ll s=0;
	rep(i,0,n){
		cin>>we[i]>>val[i];
		s+=val[i];
	}
	for(int i = s; i>=0; i--){
		ll ans = func(n-1,i);
		if(ans<=w){cout<<i;break;}
	}
}

int main(){
	//setIO("");
	ios_base::sync_with_stdio(0);
	cin.tie(0);//making cin faster
	clock_t start = clock();
	int t = 1;
	//cin>>t;
	while(t--)	
		solve();
	double duration = ((double) clock() - start) / (double) CLOCKS_PER_SEC;
	//cout << "\nTime: " << fixed << setprecision(20) << duration*1000<< " ms" << endl;
}
