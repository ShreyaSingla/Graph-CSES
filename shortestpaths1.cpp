#include <iostream>
#include <math.h>
#include <vector>
#include <queue>
#include <utility>
#include <set>
#define ll long long int
using namespace std;

int main(){
    int n, m;
    cin>> n>> m;

    vector<vector<pair<ll, ll> > > adjList(n+1);
    
    for(int i = 0; i<m; i++){
        ll a, b, dist;
        cin>>a>>b>>dist;
        adjList[a].push_back(make_pair(b, dist));
        //adjList[b].push_back(make_pair(a, dist));
    }
    
    vector<ll> distances(n+1, -1);
    
    set<pair<ll, ll> > s;
    
    s.insert(make_pair(0, 1));
    
    distances[1] = 0;

    while(!s.empty()){
        auto itr = *(s.begin());
        ll dist = itr.first;
        ll node = itr.second;
        s.erase(itr);
        //cout<<s.size()<<endl;
        for(auto adjPair: adjList[node]){
            ll adjNode = adjPair.first;
            ll distNode = adjPair.second;
            if(distances[adjNode] == -1){
                distances[adjNode] = dist + distNode;
                s.insert(make_pair(distances[adjNode], adjNode));
            }else if(distances[adjNode] > dist + distNode){
                s.erase(make_pair(distances[adjNode], adjNode));
                distances[adjNode] = dist + distNode;
                s.insert(make_pair(distances[adjNode], adjNode));
            }
        }
    }
    
    for(int i = 1; i<=n; i++)
        cout<<distances[i]<<" ";
    cout<<endl;
    return 0;
}