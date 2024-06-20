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
int n, x;

bool check(int mid, veci &a){
	ll vol = n*1LL*mid;
	ll sum = 0;
	rep(i,0,n){
		sum += min(mid, a[i]);
	}
	return x>=(vol-sum);
}
void solve(){
	//code here
	int t;
	cin>>t;
	while(t--){
		cin>>n>>x;
		veci a;
		rep(i,0,n){
			int ele;
			cin>>ele;
			a.pb(ele);
		}
		int l = 0;
		int h = 2e9+1;
		int mid;
		while(h-l>1){
			mid = l + (h-l)/2;
			if(check(mid,a)){
				l=mid;
			}
			else{h=mid-1;}
		}
		if(check(h,a)){
			cout<<h<<endl;
		}
		else{cout<<l<<endl;}
	}
}
int main(){
	ios_base::sync_with_stdio(0);
	clock_t start = clock();
	solve();
	double duration = ((double) clock() - start) / (double) CLOCKS_PER_SEC;
	//cout << "\nTime: " << fixed << setprecision(20) << duration*1000<< " ms" << endl;
}
