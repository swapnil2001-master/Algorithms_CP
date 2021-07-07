// Problem: A. Timofey and a tree
// Contest: Codeforces - Codeforces Round #395 (Div. 1)
// URL: https://codeforces.com/problemset/problem/763/A
// Memory Limit: 256 MB
// Time Limit: 2000 ms
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
vector <ll> graph[200005];

vector <ll> color(200005);
map<pair<ll,ll>,bool> m;

bool colordfs(ll cn,ll pn){
	if(m.find({cn,pn})!=m.end()){return m[{cn,pn}];}
	//cout<<" "<<" "<<cn<<" "<<pn<<endl;
	bool okk = true;
	for(auto u :graph[cn]){
		if(u==pn){continue;}
		else{
		if(color[u]!=color[cn]){
			m[{cn,pn}] = false;
			return false;}
		else{okk &= colordfs(u,cn);}
        }
	}
	m[{cn,pn}] = okk;
	return okk;
}

bool cdfs(ll cn,ll pn){
	bool mok = true;
	for(auto u :graph[cn]){
		if(u==pn){continue;}
		else {
			mok &= colordfs(u,cn);
		}
	}
	return mok;
}


 int main(){
    ios::sync_with_stdio(false);
  	cin.tie(0);
 	ll n;
 	cin>>n;

 	vector <pair<ll,ll>> edgelist;
 	rep(i,n-1){
 		ll a,b;
 		cin>>a>>b;
 		graph[a].pb(b);
 		graph[b].pb(a);
 		edgelist.pb({a,b});
 	}
 	
 	rep(i,n){cin>>color[i+1];}
 	bool ok = false;
 	int root = 1;
 
 	rep(i,n){
 		
 	    if(cdfs(i+1,0)){ok = true;root =i+1;break;}
 		
 		
 		
 	}

 	
 	if(!ok){
 		cout<<"NO"<<endl;
 	}
 	else{
 		cout<<"YES"<<endl;
 		cout<<root<<endl;
 	}
     }
//
//my code ends here
//--------------------------------------------
 