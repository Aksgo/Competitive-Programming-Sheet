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
const int N = 1e5 + 10;
void setIO(string s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}
void solve(){
	//code here	
	int n,k;
	cin>>n>>k;
	string s;
	cin>>s;
	int p = -1, ct = 0;
	rep(i,0,n){
		ct++;
		if(i==n-1 || s[i]!=s[i+1]){
			if(ct==k)ct=0;
			else{
				if(ct>k){p=i-k;}
				else{p=i;}
				break;
			}
		}
	}
	if(p==-1){cout<<n<<endl;return;}
	else if(p==n-1){cout<<-1<<endl;return;}
	string a = s.substr(0,p+1);
	string b = s.substr(p+1, n-p-1);
	reverse(a.begin(), a.end());
	s=b+a;
	ct = 1;
	rep(i,1,n+1){
		if(i==n || s[i]!=s[i-1]){
			if(ct!=k){cout<<-1<<endl;return;}
			ct=0;
		}
		ct++;
	}
	cout<<++p<<endl;
}
int main(){
	//setIO("hps");
	ios_base::sync_with_stdio(0);
	cin.tie(0);//making cin faster
	clock_t start = clock();
	int t;
	cin>>t;
	while(t--)
		solve();
	double duration = ((double) clock() - start) / (double) CLOCKS_PER_SEC;
	//cout << "\nTime: " << fixed << setprecision(20) << duration*1000<< " ms" << endl;
}
