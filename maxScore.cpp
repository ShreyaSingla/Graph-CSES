#include <algorithm>
#include <iostream>
#include <vector>
#define ll long long int
using namespace std;

int main() {
	ll n, m;
	cin>>n>>m;
	ll negval = -1e9 - 1;
	vector<vector<ll>> edges(m);
	
	for(int i = 0; i<m; i++){
		vector<ll> edge(3);
		for(int j = 0; j<3; j++)
			cin>>edge[j];
		edges[i] = edge;
	}
	
	vector<ll> distance(n + 1, negval);
	distance[1] = 0;
	
	for(int i = 0; i<n-1; i++){
		for(auto it: edges){
			ll u = it[0];
			ll v = it[1];
			ll w = it[2];
			
			if(distance[u] != negval && distance[u] + w > distance[v]){
				distance[v] = distance[u] + w;
			}
		}
	}
	
	for(auto it: edges){
		ll u = it[0];
		ll v = it[1];
		ll w = it[2];
		if(v == n || v == 1 || u == 1|| u == n){
			if(distance[u] != negval && distance[u] + w > distance[v]){
				cout<<-1<<endl;
				return 0;
			}
		}
	}
	
	cout<<distance[n]<<endl;
	return 0;
}