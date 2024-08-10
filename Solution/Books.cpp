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
veci a(N,0);
int n;
int t;
void setIO(string s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

void solve(){
	//code here	
	cin>>n>>t;
	rep(i,1,n+1){int ele; cin>>ele; a[i]=ele;}
	int i=1;
	int ans= 0;
	int j=1;
	ll cur = 0;
	while(j<=n && i<=n){
		while(j<=n){
			cur += a[j];
			if(cur>t){cur-=a[j];break;}
			j++;
		}
		ans = max(ans, j-i);
		cur-=a[i];
		i++;
	}
	cout<<ans<<endl;
}
int main(){
	//setIO("hps");
	ios_base::sync_with_stdio(0);
	cin.tie(0);//making cin faster
	clock_t start = clock();
	solve();
	double duration = ((double) clock() - start) / (double) CLOCKS_PER_SEC;
	//cout << "\nTime: " << fixed << setprecision(20) << duration*1000<< " ms" << endl;
}
