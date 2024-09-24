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
	int n,m,k;
	cin>>n>>m>>k;
	vector<veci> a(n,vector<int>(m,0));
	vector<veci> pf(n+1, vector<int>(m+1, 0));
	rep(i,0,n){
		rep(j,0,m){
			cin>>a[i][j];
		}
	}
	int tot = k*k;
	ll dif = 0;
	rep(i,1,n+1){
		string s;
		cin>>s;
		rep(j,1,m+1){
			char c=s[j-1];
			if(c=='1'){
				dif+=a[i-1][j-1];
			}
			else{dif-=a[i-1][j-1];}
			pf[i][j] = pf[i-1][j] + pf[i][j-1] - pf[i-1][j-1] + (c-'0');

		}
	}
	if(dif==0){cout<<"YES"<<endl;return;}
	int ans = 0;
	rep(i,0,n-k+1){
		rep(j,0,m-k+1){
			int ct = pf[i+k][j+k] + pf[i][j] - pf[i][j+k] - pf[i+k][j];
			int gc = abs(tot - 2*ct);
			ans = __gcd(gc,ans);
		}
	}
	if(ans==0 || dif%ans != 0){
		cout<<"NO"<<endl;
	}
	else{
		cout<<"YES"<<endl;
	}
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
	//double duration = ((double) clock() - start) / (double) CLOCKS_PER_SEC;
	//cout << "\nTime: " << fixed << setprecision(20) << duration*1000<< " ms" << endl;
}
