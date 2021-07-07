
#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
 
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define mod 1000000009
#define rep(i,n) for (ll i = 0; i < n; i++)
#define  pb push_back
#define mp make_pair
#define ysno(ok) if(ok){cout<<"YES"<<endl;}else{cout<<"NO"<<endl;}
#define testloop ll t;cin>>t;while(t--)
//
//extra_functions 
ll MOD = 1000000007;
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
ll add(ll a,ll b){return ((a%MOD)+(b%MOD))%MOD;}
ll mul(ll a,ll b){return ((a%MOD)*(b%MOD))%MOD;}
ll sub(ll a,ll b){return ((a%MOD)-(b%MOD)+MOD)%MOD;}
ll binpow(ll x, ll y){ll z = 1;while(y){if(y & 1) z = mul(z, x);x = mul(x, x);y >>= 1;}return z;}

// 
// my code starts here
//--------------------------------------------
ll dp[105][105];

ll calc(ll n,ll k){
	if(k==0){return 0;}
	else if(dp[n][k]){return dp[n][k];}
	else{
		ll ans = 0;
		if(k>=n){
			ans = add(ans,1);
			rep(i,n-1){
				ans =add(ans, calc(i+1,k));
			}
		}
		else{
			
			rep(i,k){
				ans = add(ans, calc(n-(i+1),k));
			}
			
		}
		dp[n][k] = ans;
		return ans;
	}
}

 int main(){
    ios::sync_with_stdio(false);
  	cin.tie(0);
  	ll n,k,d;
  	cin>>n>>k>>d;
  	rep(i,105){rep(j,105){dp[i][j]=0;}}
  	ll ans = sub(calc(n,k),calc(n,d-1));
 	cout<<ans<<endl;

     }
//
//my code ends here
//--------------------------------------------
 