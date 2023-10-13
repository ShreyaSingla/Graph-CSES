#include <iostream>
#include <math.h>
#include <vector>
#include <queue>
#include <utility>
#include <set>
#define ll long long int
using namespace std;

int tunnels(int node, vector<vector<ll>>& adjList, vector<bool>& vis, vector<ll>& coins){
    vis[node] = true;
    ll temp = coins[node];
    ll ans = temp;
    for(auto adjNode: adjList[node]){
        if(!vis[adjNode]){
            vis[adjNode] = true;
            int val = tunnels(adjNode, adjList, vis, coins);
            ans = max(ans, temp + val);
            vis[adjNode] = false;
        }
    }
    //cout<<node<<" "<<ans<<endl;
    return ans;
}

int main(){
    int n, m;
    cin>>n>>m;
    
    vector<ll> coins(n+1, 0);
    
    for(int i = 1; i<=n; i++){
        cin>>coins[i];
    }

    vector<vector<ll>> adjList(n+1);
    vector<bool> vis(n+1, false);
    
    for(int i = 0; i<m; i++){
        ll a, b;
        cin>>a>>b;
        adjList[a].push_back(b);
    }
    
    int ans = 0;
    
    for(int i = 1; i<=n; i++){
        if(!vis[i]){
            int coin = tunnels(i, adjList, vis, coins);
            ans = max(ans, coin);
        }
    }
    
    cout<<ans<<endl;
    return 0;
}