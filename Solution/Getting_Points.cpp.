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
int n,l,t,nt;
ll p;
bool check(int mid){
	ll sc = 0;
	int lon = n-mid;
	sc = (lon*1LL*l) + min(2*lon, nt)*1LL* t;
	return sc>=p;
}
void solve(){
	//code here
	int tc;
	cin>>tc;
	while(tc--){
		cin>>n>>p>>l>>t;
		nt = ceil(n,7);
		int lo=0,hi = n, mid;
		while(hi-lo>1){
			mid = lo + (hi-lo)/2;
			if(check(mid)){
				lo=mid;
			}
			else{hi=mid-1;}
		}
		if(check(hi)){cout<<hi<<endl;}
		else{cout<<lo<<endl;}
	}
}
int main(){
	ios_base::sync_with_stdio(0);
	clock_t start = clock();
	solve();
	double duration = ((double) clock() - start) / (double) CLOCKS_PER_SEC;
	//cout << "\nTime: " << fixed << setprecision(20) << duration*1000<< " ms" << endl;
}
