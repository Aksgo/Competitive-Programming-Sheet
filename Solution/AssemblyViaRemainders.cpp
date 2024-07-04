#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define l long
#define veci vector<int>
#define pii pair<int,int>
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		vector<int> a(n+1,0);
		vector<int> ans(n+1,0);
		ans[1]=501;
		for(int i=2; i<=n; i++){
			cin>>a[i];
			ans[i]=a[i]+ans[i-1];
		}
		for(int i=1; i<=n; i++){
			cout<<ans[i]<<" ";
		}
		cout<<endl;
	}
}
