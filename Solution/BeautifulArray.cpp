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
int nxt(){
	int x;
	cin>>x;
	return x;
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
	int n = nxt();
	int k = nxt();
	int ct = n%2;
	veci inp(n);
	rep(i,0,n){cin>>inp[i];}
	sort(inp.begin(), inp.end());
	map<int, veci> mp;
	rep(i,0,n){
		int ele = inp[i]%k;
		mp[ele].pb(inp[i]/k);
	}
	ll op = 0;
	for(auto &p : mp){
		auto &a = p.ss;
		if(a.size()%2!=0 && (ct--)==0){
			cout<<-1<<endl;return;
		}
		int siz = a.size();
		if(siz%2==0){
			for(int i=0; i<siz; i+=2){
				op += (a[i+1]-a[i]);
			}
		}else{
			vector<ll> pf(siz,0);
			vector<ll> sf(siz,0);
			if(siz==1){continue;}
			pf[1] = a[1]-a[0];
			for(int i=3; i<siz; i+=2){
				pf[i] = pf[i-2] + a[i] - a[i-1];
			}
			sf[siz-2] = a[siz-1] - a[siz-2];
			for(int i = siz-4; i>0; i-=2){
				sf[i] = sf[i+2] + a[i+1] - a[i];
			}	
			ll ans = INT_MAX;
			for(int i=0;i<siz; i+=2){
				ll temp = 0;
				if(i>0){temp += pf[i-1];}
				if(i<siz-1){temp+=sf[i+1];}
				ans = min(temp, ans);
			}
			op+=ans;
		}
	}
	cout<<op<<endl;
}



int main(){
	//setIO("");
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
