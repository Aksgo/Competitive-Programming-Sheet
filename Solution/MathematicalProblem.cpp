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
	string s;
	cin>>s;
	if(n==2){
		int x = s[0]-'0';
		int y = s[1]-'0';
		cout<<x*10 + y<<endl;return;	
	}
	if(n>3){
		rep(i,0,n){
			if(s[i]=='0'){
				cout<<0<<endl;return;
			}
		}
	}
	ll sum = 0;

	rep(i,0,n){
		if(s[i]!='1'){
			sum += s[i]-'0';
		}
	}
	if(n==3){
		if(s[0]=='0' ||s[2]=='0'){cout<<0<<endl;return;}
	}
	int i = 0;
	ll ans = 1000;
	while(i<n-1){
		ll ss = sum;
		int x = s[i]-'0';
		int y = s[i+1]-'0';
		if(x!=1){ss-=x;}
		if(y!=1){ss-=y;}
		int num = x*10 + y;
		if(ss==0 || num!=1)
			ss += num;
		ans = min(ans, ss);
		i++;
	}
	cout<<ans<<endl;
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
