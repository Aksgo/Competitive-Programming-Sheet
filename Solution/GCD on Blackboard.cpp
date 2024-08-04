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
	veci a(n);
	rep(i,0,n){cin>>a[i];}
	veci fp(n+1);
	veci bp(n+1);
	fp[0]=0;
	bp[n]=0;
	rep(i,0,n){
		fp[i+1]=__gcd(fp[i],a[i]);
	}
	for(int i=n-1; i>=0; --i){
		bp[i] = __gcd(bp[i+1], a[i]);
	}
	int maxg = 0;
	rep(i,0,n){
		//cout<<fp[i]<<" "<<bp[i]<<endl;
		maxg = max(__gcd(fp[i],bp[i+1]), maxg);
	}
	cout<<maxg<<endl;
}



int main(){
	ios_base::sync_with_stdio(0);
	clock_t start = clock();
	solve();
	double duration = ((double) clock() - start) / (double) CLOCKS_PER_SEC;
	//cout << "\nTime: " << fixed << setprecision(20) << duration*1000<< " ms" << endl;
}
