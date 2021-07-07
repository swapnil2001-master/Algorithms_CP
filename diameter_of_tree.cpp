// Problem: F. Spiders
// Contest: Codeforces - School Regional Team Contest, Saratov, 2011
// URL: https://codeforces.com/problemset/problem/120/F
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)


#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
 
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define mod 1000000009
#define rep(i,n) for (ll i = 0; i < n; i++)
#define  pb push_back
#define all(v) v.begin(),v.end()
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
vector <ll> graph[200];
int f[200];int g[200];int di ;

void dfs(ll cn ,ll pn){
	vector <int> fval;
	
	for(auto u : graph[cn]){
		if(u==pn){continue;}
		else{
			dfs(u,cn);
			fval.pb(f[u]);
		}
	}
	sort(all(fval));
	f[cn] = 0;
	if(fval.size()>0){f[cn] = 1;f[cn]+=fval.back();}
	
	
	if(fval.size()>=2)
         {g[cn] = 2 + fval.back() + fval[fval.size()-2];}
         
         di = max(di,max(f[cn],g[cn]));
	
}


 int main(){
    ios::sync_with_stdio(false);
  	cin.tie(0);
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
 	ll n;
 	cin>>n;
 	ll ans = 0;
 	while(n--){
 		rep(i,200){graph[i].clear();g[i]=0;f[i]=0;di =0;}
 		ll nodes;
 		cin>>nodes;
 		rep(i,nodes-1){
 			ll a,b;
 			cin>>a>>b;
 			graph[a].pb(b);
 			graph[b].pb(a);
 		}
 		dfs(1,0);
 		
 		ans += di;
 	}
 	cout<<ans<<endl;

     }
//
//my code ends here
//--------------------------------------------
 