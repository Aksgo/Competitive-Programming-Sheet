#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define veci vector<int>
#define pii pair<int,int>
#define rep(i,st,n) for(int i=st; i<n; i++)
#define sz(x) (int)(x).size()
#define PI 3.141592653589793238 
#define ull unsigned long long
#define pb push_back
#define pp pop_back
#define IM INT_MAX
#define IN INT_MIN
#define lb lower_bound
#define ub upper_bound
const long long MOD  = 1e9 + 7;
const long long MOD1 = 998244353;
int nxt(){
	int x;cin>>x;return x;
}
ll nxl(){
	ll x;cin>>x;return x;
}
struct ch{
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};
void setIO(string s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

void solve(){
	//code here
	int n,m;
	cin>>n>>m;
	priority_queue<int> atc;
	priority_queue<int> def;
	priority_queue<int> st;
	ll ats = 0;
	rep(i,0,n){
		string s;
		int x;
		cin>>s>>x;
		if(s=="ATK"){
			atc.push(-x);
			st.push(-x);
			ats+=x;
		}
		else{
			def.push(-x);
		}
	}
	veci a(m);
	rep(i,0,m){
		cin>>a[i];
	}
	sort(a.begin(), a.end());
	int j = m-1;
	ll a1 = 0;
	while(j>=0 && !atc.empty()){
		if(a[j]>=(-1*atc.top())){
			a1 += a[j]+atc.top();
			atc.pop();
			j--;
		}
		else{break;}
	}

	int i = 0;
	veci done(m,0);
	while(!def.empty()){
		int fd = 0;
		while(i<m){
			if(!done[i] && a[i]>(-def.top())){
				done[i] = 1;
				fd = 1;
				def.pop();
				break;
			}
			i++;
		}
		if(!fd){
			cout<<a1;return;
		}
	}
	j = 0;
	ll su = 0;
	rep(i,0,m){
		if(!done[i]){su+=a[i];}
	}
	while(!st.empty()){
		int fd = 0;
		while(j<m){
			if(!done[j] && a[j]>=(-st.top())){
				done[j] = 1;
				fd=1;
				st.pop();
				break;
			}
			j++;
		}
		if(!fd){cout<<a1;return;}
	}
	cout<<max(a1, su-ats);
}	


int main(){
	//setIO("");
	ios_base::sync_with_stdio(0);
	cin.tie(0);//making cin faster
	clock_t start = clock();
	int t = 1;
	//cin>>t;
	while(t--)	
		solve();
	double duration = ((double) clock() - start) / (double) CLOCKS_PER_SEC;
	//cout << "\nTime: " << fixed << setprecision(20) << duration*1000<< " ms" << endl;
}
