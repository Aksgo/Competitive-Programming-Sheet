#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main() {
	int c;
	cin>>c;
	int bit_ct = (int)log2(c)+1;
	int a=0, b=0;
	int num = 1<<(bit_ct+1);
	ll ans = -1;
	for(int mask = 0; mask<num ; ++mask){
		a = c^mask;
		int ct_a = (int)log2(a) + 1;
		if(ct_a > bit_ct)continue;
		ans =max(ans , a*1LL*mask);
	}
	cout<<ans;
}
