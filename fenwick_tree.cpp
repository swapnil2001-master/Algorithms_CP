#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define mod 1000000009
#define rep(i,n) for (ll i = 0; i < n; i++)
#define  pb push_back
#define mp make_pair

ll maxn = 200005;
vector <ll> bintree(maxn+1,0);
ll n;
void maketree(ll a[]){
	rep(i,n+1){
		if(i>0){a[i] += a[i-1];}
	}
	for(ll i=1;i<=n;i++){
		ll k = i&(-i);
		bintree[i] = a[i]-a[i-k];
	}	
}

ll sum(ll k){
	ll s =0;
	while(k>=1){
		cout<<k<<" "<<bintree[k]<<endl;
		s += bintree[k];
		k -= k&(-k);
	}
	return s;
}

void add(ll k,ll x){
	while(k<=n){
		bintree[k] += x;
		k += k&-k;
	}
}

ll summer(ll b,ll a){
	return sum(a)-sum(b-1);
}

 int main(){
    ios::sync_with_stdio(false);
  cin.tie(0);
  cin>>n;
  ll a[n+1];
  a[0] = 0;
  rep(i,n){
  	cin>>a[i+1];
  }
  maketree(a);
 
 
     }
     
 