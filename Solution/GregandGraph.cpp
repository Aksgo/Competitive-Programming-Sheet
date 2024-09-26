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
const long long MOD  = 1e9 + 7;
const long long MOD1 = 998244353;
const int N = 1e3;
ll dist[N][N];
int main(){
	int n;
	cin>>n;
	rep(i,1,n+1){
		rep(j,1,n+1){
			cin>>dist[i][j];
		}
	}
	veci rem(n);
	rep(i,0,n){cin>>rem[i];}
	reverse(rem.begin(), rem.end());
	vector<ll> ans;
	for(int ind = 0; ind<n; ind++){
		int k = rem[ind];
		rep(i,1,n+1){
			rep(j,1,n+1){
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
			}
		}
		ll sum = 0;
		rep(i,0,ind+1){
			rep(j,0,ind+1){if(i==j){continue;}sum+=dist[rem[i]][rem[j]];}
		}
		ans.pb(sum);
	}
	reverse(ans.begin(), ans.end());
	for(auto ele:ans){cout<<ele<<" ";}
}
