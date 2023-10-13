#include <algorithm>
#include <iostream>
#include <vector>
#include <set>
#define ll long long int
using namespace std;

void dfs(vector<vector<ll>>&g, vector<bool>&s, ll u) {
  s[u] = 1;
  for(auto v:g[u])
    if (!s[v])
      dfs(g, s, v);
} 

int main() {
	ll n, m;
	cin>>n>>m;
	vector<vector<ll>> a(n+1);
	vector<vector<ll>> b(n+1);
	vector<vector<ll>> edges;
	
	for(int i = 0; i<m; i++){
		ll u, v, w;
		cin>>u>>v>>w;
		vector<ll> edge;
		edge.push_back(u);
		edge.push_back(v);
		edge.push_back(-1*w);
		edges.push_back(edge);
		a[u].push_back(v);
		b[v].push_back(u);
	}
	
	vector<bool> vis(n+1, false);
	vector<bool> vis1(n+1, false);
	
	dfs(a, vis, 1);
	dfs(b, vis1, n);
	
	vector<ll> dist(n+1, 1e18);
	dist[1] = 0;
	bool flag = 0;
	
	for(int i = 0; i<n-1; i++){
		for(auto it: edges){
			ll u = it[0];
			ll v = it[1];
			ll w = it[2];
			
			if(dist[u] + w < dist[v])
					dist[v] = dist[u] + w;
		}
	}
	
	for(auto it: edges){
		ll u = it[0];
		ll v = it[1];
		ll w = it[2];
		
		if(dist[u] + w < dist[v] && vis[u] && vis1[v]){
			cout<<-1<<endl;
			return 0;
		}
		
	}
	cout<<-1*dist[n]<<endl;
	return 0;
}