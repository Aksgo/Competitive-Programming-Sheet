#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define l long
#define veci vector<int>
#define pii pair<int,int>
#define rep(i,n) for(int i=0; i<n; i++)
#define ceil(x,y) (x+y-1)/y//least integer function
#define sz(x) (int)(x).size()
#define PI 3.141592653589793238 
#define ull unsigned long long
#define ll long long
#define pb push_back
#define pp pop_back
#define IM INT_MAX
#define IN INT_MIN
#define lb lower_bound
#define ub upper_bound
void solve(){
	//code here
	int t;
	cin>>t;
	while(t--){
		int n,m;
		cin>>n>>m;
		ll lo = max(n-m, 0), hi = n+m;
		int len = hi-lo+1;
		ll ans = 0;
		for(int i=0; i<31; i++){
			int ct = 1<<i;
			if(lo/ct != hi/ct){
				ans|=ct;
			}
			else{
				if((lo/ct)&1){
					ans|=ct;
				}
			}
		}
		cout<<ans<<endl; 
	}
}
int main(){
	ios_base::sync_with_stdio(0);
	clock_t start = clock();
	solve();
	double duration = ((double) clock() - start) / (double) CLOCKS_PER_SEC;
	//cout << "Time: " << fixed << setprecision(20) << duration*1000<< " ms" << endl;
}
