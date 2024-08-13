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
	ll n;
	cin>>n;
	veci digits;
	while(n){
		digits.pb(n%10);
		n/=10;
	}
	int s = digits.size();
	if(digits[s-1]!=1){cout<<"NO"<<endl;return;}
	int carry = 0;
	bool flag = true;
	rep(i,0,s-1){
		int ele = digits[i]+10-carry;
		if(ele<10 || ele>18){
			flag = false;break;
		}
		carry=1;
	}
	cout<<(flag?"YES":"NO")<<endl;
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
