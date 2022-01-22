
#include <bits/stdc++.h>
using namespace std;


struct segment_tree{
	
	int size;
	vector <long long> sums;
	
	void init(int n){
		size = 1;
		while(size < n){size *= 2;}
		sums.assign(2*size,0);
	}
	
	void build(vector <int> &a, int node, int lx, int rx){
		
		if(rx-lx == 1){
			if(lx < (int)a.size()){
				sums[node] = a[lx];
				
			}
			return;
		}
		int m = (lx+rx)/2;
		build(a,2*node+1,lx,m);
		build(a,2*node+2,m,rx);
		
		sums[node] = sums[2*node+1]+sums[2*node+2];
	}
	
	void build(vector <int> &a){
		build(a,0,0,size);
	}
	
	void set(int i,int v, int node, int lx, int rx){
		if(rx-lx == 1){
			sums[node] = v;
			return; 
		}
		int m = (lx+rx)/2;
		if(i < m){
			set(i,v,2*node+1,lx,m);
		}
		else{
			set(i,v,2*node+2,m,rx);
		}
		
		sums[node] = sums[2*node+1]+sums[2*node+2];
	}
	
	void set(int i, int v){
		set(i,v,0,0,size);
	}
	
	long long sum(int l,int r,int node, int lx, int rx){
		
		if(lx >= r || l >= rx){return 0;}
		if(lx >= l && rx <= r){return sums[node];}
		
		int m = (lx+rx)/2;
		long long s1 = sum(l,r,2*node+1,lx,m);
		long long s2 = sum(l,r,2*node+2,m,rx);
		return s1+s2;
	}
	
	long long sum(int l, int r){
		return sum(l,r,0,0,size);
	}
};

 int main(){
    ios::sync_with_stdio(false);
  cin.tie(0);
  
  int n,q;
  cin>>n>>q;
  vector <int> a(n);
  for(int i = 0; i < n; i+=1){cin>>a[i];}
  
  segment_tree str;
  str.init(n);
  str.build(a);
  
  while(q--){
  	int type;
  	cin>>type;
  	if(type == 1){
  		int i,v;
  		cin>>i>>v;
  		str.set(i,v);
  	}
  	else {
  		int l,r;
  		cin>>l>>r;
  		cout<<str.sum(l,r)<<endl;
  	}
  }
 

     }
