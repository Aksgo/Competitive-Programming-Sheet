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
	string s;
	cin>>s;
	int n = s.size();
	vector<veci> a(n+1, vector<int>(26,0));
	rep(i,0,n){
		a[i+1][s[i]-'a']++;
	}
	rep(i,1,n+1){
		rep(j,0,26){
			a[i][j]+=a[i-1][j];
		}
	}
	int q;
	cin>>q;
	while(q--){
		int l , r;
		cin>>l>>r;
		int ct = 0;
		rep(i, 0, 26){
			if(	a[r][i]-a[l-1][i] > 0)ct++;
		}
		if(l==r || ct>=3 || s[r-1]!=s[l-1]){cout<<"Yes\n";}
		else{cout<<"No\n";}
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
