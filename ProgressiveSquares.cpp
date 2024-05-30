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
		int n,c,d;
		cin>>n>>c>>d;
		multiset<ll> st;
		ll mine = 1e10;
		for(int i=0; i<n*n; i++){
			ll ele;
			cin>>ele;
			mine = min(mine, ele);
			st.insert(ele);
		}
		vector<vector<int>> mat(n+1, vector<int>(n+1,0));
		mat[1][1]=mine;
		for(int i=1; i<=n; i++){
			if(i!=1){mat[i][1]=mat[i-1][1]+c;}
			for(int j=2; j<=n; j++){
				mat[i][j] = mat[i][j-1] + d;
				auto it = st.find(mat[i][j]);
				if(it!=st.end()){st.erase(it);}
			}
			auto it = st.find(mat[i][1]);
			if(it!=st.end()){st.erase(it);}
		}
		if(st.size()>0){cout<<"NO"<<endl;}
		else{cout<<"YES"<<endl;}
	}
}
