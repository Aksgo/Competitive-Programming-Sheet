#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define l long
#define veci vector<int>
#define pii pair<int,int>
#define rep(i,n) for(int i=0; i<n; i++)
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		vector<int> a(n);
		vector<int> b(n+1);
		ll ans=0;
		for(int i=0; i<n; ++i){
			cin>>a[i];
		}
		for(int i=0; i<n+1; ++i){
			cin>>b[i];
		}
		int lr = b[n];
		bool valid = false;
		int mini = INT_MAX;
		for(int i=0; i<n; i++){
			int aa = a[i];
			int bb = b[i];
			ans+=abs(aa-bb);
			if((lr>=aa && lr<=bb)||(lr<=aa && lr>=bb)){mini=1;}
			else{mini = min(min(abs(aa-lr),abs(bb-lr))+1,mini);}
		}
		ans+=mini;
		cout<<ans<<endl;
	}
}
