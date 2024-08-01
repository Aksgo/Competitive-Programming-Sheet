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
void setIO(string s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}
void solve(){
	//code here	
	int n;
	cin>>n;
	veci pf(n+1,0);
	rep(i,1,n+1){
		char c;
		cin>>c;
		pf[i]=pf[i-1]+c-'0';
	}
	unordered_map<int, int> m;
	m[0]=1;
	ll ans=0;
	rep(i,1,n+1){
		int diff = pf[i]-i;
		ans+=m[diff];
		m[diff]++;
	}
	cout<<ans<<endl;
}
int main(){
	//setIO("hps");
	ios_base::sync_with_stdio(0);
	clock_t start = clock();
	int t;
	cin>>t;
	while(t--)
		solve();
	double duration = ((double) clock() - start) / (double) CLOCKS_PER_SEC;
	//cout << "\nTime: " << fixed << setprecision(20) << duration*1000<< " ms" << endl;
}
