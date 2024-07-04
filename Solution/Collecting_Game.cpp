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
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		vector<pii> a(n+1);
		a[0]={0,0};
		vector<ll> p(n+1,0);
		veci ar(n+1);
		rep(i,1,n+1){
			int ele;
			cin>>ele;
			a[i]={ele,i};
		}
		sort(a.begin(), a.end());
		rep(i,1,n+1){
			p[i]=a[i].first+p[i-1];
		}
		rep(i,1,n+1){
			int ele = a[i].first;
			int ans = i-1;
			int l = i+1, h=n, mid;
			ll pre = p[i];
			while(l<=h){
				mid = l+(h-l)/2;
				if((a[mid].first)<=pre){
					pre=p[mid];
					l=mid+1;
					h=n;
					ans=mid-1;
				}
				else{h=mid-1;}
			}
			ar[a[i].second]=ans;
		}
		rep(i,1,n+1){cout<<ar[i]<<" ";}
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
