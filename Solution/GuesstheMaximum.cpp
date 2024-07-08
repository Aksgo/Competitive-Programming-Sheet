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

bool check(int mid, veci &a){
	int n = a.size();
	rep(i,0,n-1){
		int m = max(a[i],a[i+1]);
		if(m<=mid){return false;}
	}
	return true;
}
void solve(){
	//code here
	int n;
	cin>>n;
	veci a(n);
	rep(i,0,n){
		cin>>a[i];
	}
	int l = 0;
	int h = (int)1e9;
	int mid;
	while(h-l>1){
		mid = l + (h-l)/2;
		if(check(mid,a)){
			l=mid;
		}
		else{
			h=mid-1;
		}
	}
	if(check(h, a)){cout<<h<<endl;}
	else{cout<<l<<endl;}

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
