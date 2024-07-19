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

ll LCM(ll a , ll b){
	int gc = __gcd(a,b);
	ll ans = (a*b)/gc;
	return ans;
}

void solve(){
	//code here	
	int n;
	cin>>n;
	veci k(n);
	rep(i,0,n){cin>>k[i];}
	ll lcm  = k[0];
	rep(i,1,n){
		lcm = LCM(k[i],lcm);
	}
	veci ans(n);
	rep(i,0,n){
		ans[i] = (lcm/k[i]);
	}
	ll sum = accumulate(ans.begin(), ans.end(),0);
	if(lcm<=sum){cout<<-1<<endl;return;}
	for(auto &ele : ans){
		cout<<ele<<" ";
	}
	cout<<endl;
}



int main(){
	ios_base::sync_with_stdio(0);
	clock_t start = clock();
	int t;
	cin>>t;
	while(t--)
		solve();

	double duration = ((double) clock() - start) / (double) CLOCKS_PER_SEC;
	//cout << "\nTime: " << fixed << setprecision(20) << duration*1000<< " ms" << endl;
}
