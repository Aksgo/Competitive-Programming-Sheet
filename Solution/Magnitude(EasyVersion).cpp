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
const int N = 1e5 + 10;
void setIO(string s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

void solve(){
	//code here	
	int n;
	cin>>n;
	vector<ll> a(n+1);
	ll summ  = 0;
	rep(i,0,n){
		cin>>a[i];
		summ+=a[i];
	}
	summ=abs(summ);
	a[n]=LLONG_MAX;
	ll ans = 0;
	ll m = 0;
	rep(i,0,n){
		m +=a[i];
		ans+=a[i];
		ans = max(ans, abs(m));
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
