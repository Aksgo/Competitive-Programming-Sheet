#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define veci vector<int>
#define pii pair<int,int>
#define rep(i,st,n) for(int i=st; i<n; i++)
#define ceil(x,y) (x+y-1)/y//least integer function
#define PI 3.141592653589793238 
#define ull unsigned long long
#define pb push_back
#define pp pop_back
#define IM INT_MAX
#define IN INT_MIN
#define lb lower_bound
#define ub upper_bound
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
	veci nona;
	int n = s.size();
	rep(i, 0, n){
		if(s[i]!='a')nona.pb(i);
	}
	int sz = nona.size();
	if(sz==0){cout<<n-1<<endl;return;}
	veci psbl_len;
	int len = 1;
	while(len*len<=sz){
		if(sz%len==0){
			psbl_len.pb(len);
			if(len*len!=sz)psbl_len.pb(sz/len);
		}
		len++;
	}
	int l=nona[0];
    int r=n-1-nona[sz-1];
    ll ans = 0;
	for(int cl : psbl_len){
		int mn = n;
		string s1 = s.substr(nona[0], nona[cl-1]-nona[0]+1);
		int ok = 1;
		for(int ind = cl ; ind<sz; ind+=cl){
			string s2 = s.substr(nona[ind], nona[ind+cl-1]-nona[ind]+1);
			if(s1!=s2){
				ok=0;break;
			}
			mn = min(mn, nona[ind]-nona[ind-1]-1);
		}
		if(!ok)continue;
		rep(x, 0, min(l,mn)+1){
			int y = min(r, mn-x);
			ans += y+1;
		}

	}
	cout<<ans<<endl;
}

int main(){
	//setIO("hps");
	ios_base::sync_with_stdio(0);
	cin.tie(0);//making cin faster
	clock_t start = clock();
	int t;
	cin>>t;
	while(t--)
		solve();
	double duration = ((double) clock() - start) / (double) CLOCKS_PER_SEC;
	//cout << "\nTime: " << fixed << setprecision(20) << duration*1000<< " ms" << endl;
}
