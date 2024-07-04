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
		int n,k;
		cin>>n>>k;
		if(n==1){
			cout<<k<<endl;
			continue;
		}
		int num = 0,i=0;
		while(true){
			if((1<<i)>k){break;}
			num=1<<i;
			i++;
		}
		vector<int> a(n,0);
		num--;
		a[0]=num;
		a[1]=k-num;
		for(auto &ele : a){
			cout<<ele<<" ";
		}
		cout<<endl;
	}
}
