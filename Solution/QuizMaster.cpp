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

const int N = 1e5 + 10;
veci di[N];
void precomp(){
	rep(i,1,N){
		for(int j=i; j<N; j+=i){
			di[j].pb(i);
		}
	}
}
void solve(){
	//code here
	int count = 0, ans = INT_MAX;
	int n,m;
	cin>>n>>m;
	veci a(n);
	rep(i,0,n)cin>>a[i];
	veci fre(m+5, 0);
	sort(a.begin(), a.end());
	int i=0, j=0;
	rep(i,0,n){
		while(j<n && count!=m){
			for(auto f : di[a[j]]){
				if(f>m)
					break;
				if(fre[f]==0)
				{
					count++;
				}
				fre[f]++;
			}
			j++;
		}
		if(count==m){
			ans = min(ans, a[j-1]-a[i]);
		}
		for(auto x : di[a[i]]){
			if(x>m)
				break;
			fre[x]--;
			if(fre[x]==0)
			{
				count--;
			}	
		}
	}
	if(ans==INT_MAX)ans=-1;
	cout<<ans<<endl;
}


int main(){
	//setIO("");
	ios_base::sync_with_stdio(0);
	cin.tie(0);//making cin faster
	cout.tie(0);
	clock_t start = clock();
	int t;
	cin>>t;
	precomp();
	while(t--)
		solve();
	double duration = ((double) clock() - start) / (double) CLOCKS_PER_SEC;
	//cout << "\nTime: " << fixed << setprecision(20) << duration*1000<< " ms" << endl;
}
