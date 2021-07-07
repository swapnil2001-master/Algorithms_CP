// Problem: C. Checkposts
// Contest: Codeforces - Codeforces Round #244 (Div. 2)
// URL: https://codeforces.com/problemset/problem/427/C
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
 
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define mod 1000000007
#define rep(i,n) for (ll i = 0; i < n; i++)
#define  pb push_back
#define ysno(ok) if(ok){cout<<"YES"<<endl;}else{cout<<"NO"<<endl;}
#define maxn  100009

ll n,m;
ll a[maxn];

vector <ll> graph[maxn];
vector <ll> rgraph[maxn];
vector <ll> st;
vector <bool> visited(maxn,0);

void dfs(vector <ll> graph[],ll i){
	if(!visited[i]){
  	visited[i] = 1;
  	for(auto u:graph[i]){
  		dfs(graph,u);
  	}
  	visited[i] = 2;
  	st.pb(i);
  }
  	
}

ll mini ;

ll cost = 0;
ll ways = 1;

map <ll,ll> mp;

void sfs(vector <ll> rgraph[],ll u){
	if(!visited[u]){
		visited[u] = true;
		//cout<<a[u-1]<<" "<<mini<<" "<<u<<endl;
		if(mini>=a[u-1]){mini = a[u-1];mp[mini]++;}
		for(auto c : rgraph[u]){
			sfs(rgraph,c);
		}
	}
	else{return;}
}


 int main(){
    ios::sync_with_stdio(false);
  cin.tie(0);
    cin>>n;

    rep(i,n){
    	cin>>a[i];
    }
    cin>>m;
    rep(i,m){
    	ll x,y;
    	cin>>x>>y;
    	graph[x].pb(y);
    	rgraph[y].pb(x);
    }
    for(ll i=1;i<=n;i++){
    	if(!visited[i]){
    		 dfs(graph,i);
    	}
    }
    
     reverse(st.begin(),st.end());
     rep(i,visited.size()){visited[i]=0;}
     for(auto u : st){
     	if(!visited[u]){
        mini = 10000000000;
     	sfs(rgraph,u);
     	cost += mini;
     	ways = ((ways%mod)*(mp[mini]%mod))%mod;
     	mp.clear();
     	}
     	
     }
    cout<<cost<<" "<<ways<<endl;
     
     }
     
 