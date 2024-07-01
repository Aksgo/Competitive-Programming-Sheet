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
int ct = 0;

void solve(){
	//code here
	int n,k;
	cin>>n>>k;
	veci a(n+1,0);
	rep(i,1,n+1){
		cin>>a[i];
	}
	ll m1=0, m2=1;
	swap(a[1],a[k]);
	rep(i,2,n+1){
		if(a[i]>a[1])break;
		m1++;
	}
	swap(a[1],a[k]);
	rep(i,1,k+1){
		if(a[i]>a[k]){swap(a[i],a[k]);k=i;break;}
	}
	if(k==1){m2--;}
	rep(i,k+1,n+1){
		if(a[i]>a[k])break;
		m2++;
	}
	cout<<max(m1,m2)<<endl;
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
