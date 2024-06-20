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
void solve(){
	//code here
	int tc;
	cin>>tc;
	while(tc--){
		int n;
		string s;
		cin>>n>>s;
		reverse(s.begin(), s.end());
		vector<ll> a(n,-1);
		ll ans = 0;
		int j=0;
		rep(i,0,n){
			while(j<n){
				if(s[j]=='0')
					{s[j]='1';
					break;}
				j++;
			}
			if(j==n){break;}
			ans += (j-i);
			a[i]=ans;
		}
		rep(i,0,n){cout<<a[i]<<" ";}
		cout<<endl;
	}
}
int main(){
	ios_base::sync_with_stdio(0);
	clock_t start = clock();
	solve();
	double duration = ((double) clock() - start) / (double) CLOCKS_PER_SEC;
	//cout << "\nTime: " << fixed << setprecision(20) << duration*1000<< " ms" << endl;
}
