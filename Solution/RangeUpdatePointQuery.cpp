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
void setIO(string s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}
void solve(){
	//code here	
	int n,q;
	cin>>n>>q;
	set<int> s;
	veci a(n);
	rep(i,0,n){
		cin>>a[i];
		if(a[i]>9){s.insert(i);}
	}
	while(q--){
		int ch;
		cin>>ch;
		if(ch==2){int ind;cin>>ind;cout<<a[ind-1]<<endl;continue;}
		int l,r;
		cin>>l>>r;
		l--;r--;
		int lc = l;
		while(!s.empty()){
			auto ind = s.lb(lc);
			if(ind==s.end() || *ind > r){break;}
			int dsum  = 0;
			int ele = a[*ind];
			while(ele){
				dsum+=ele%10;
				ele/=10;
			}
			int val = *ind;
			a[*ind]=dsum;
			lc = *ind+1;
			if(dsum>9){s.insert(*ind);}
			else{s.erase(ind);}	
		}
	}
}
int main(){
	//setIO("hps");
	ios_base::sync_with_stdio(0);
	clock_t start = clock();
	int t;
	cin>>t;
	while(t--)
		solve();
	double duration = ((double) clock() - start) / (double) CLOCKS_PER_SEC;
	//cout << "\nTime: " << fixed << setprecision(20) << duration*1000<< " ms" << endl;
}
