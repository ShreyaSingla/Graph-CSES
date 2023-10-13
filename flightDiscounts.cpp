#include <iostream>
#include <math.h>
#include <bits/stdc++.h>
#include <vector>
#include <queue>
#include <utility>
#include <set>
#define ll long long int
using namespace std;

int main(){
    int n, m;
    cin>> n>> m;

    vector<vector<pair<ll, ll>>> adjList(n+1);
    
    for(int i = 0; i<m; i++){
        ll a, b, dist;
        cin>>a>>b>>dist;
        adjList[a].push_back(make_pair(b, dist));
        //adjList[b].push_back(make_pair(a, dist));
    }
    
    vector<ll> distancesWithHalf(n+1, -1);
    vector<ll> distancesWithoutHalf(n+1, -1);
    
    set<tuple<ll, ll, bool>> s;
    
    s.insert({0, 1, true});
    s.insert({0, 1, false});
    
    distancesWithHalf[1] = 0;
	distancesWithoutHalf[1] = 0;
	
    while(!s.empty()){
        auto itr = *(s.begin());
		ll dist, node;
		bool flag;
		tie(dist, node, flag) = itr;
        s.erase(itr);
        //cout<<s.size()<<endl;
        for(auto adjPair: adjList[node]){
            ll adjNode = adjPair.first;
            ll distNode = adjPair.second;
			
			if(flag){
				if(distancesWithHalf[adjNode] == -1){
					distancesWithHalf[adjNode] = dist + distNode;
					s.insert({distancesWithHalf[adjNode], adjNode, true});
				}else if(distancesWithHalf[adjNode] > dist + distNode){
					s.erase({distancesWithHalf[adjNode], adjNode, true});
					distancesWithHalf[adjNode] = dist + distNode;
					s.insert({distancesWithHalf[adjNode], adjNode, true});
				}
            }else{
				if(distancesWithoutHalf[adjNode] == -1){
					distancesWithoutHalf[adjNode] = dist + distNode;
					s.insert({distancesWithoutHalf[adjNode], adjNode, false});
				}else if(distancesWithoutHalf[adjNode] > dist + distNode){
					s.erase({distancesWithoutHalf[adjNode], adjNode, false});
					distancesWithoutHalf[adjNode] = dist + distNode;
					s.insert({distancesWithoutHalf[adjNode], adjNode, false});
				}	
				distNode = distNode/2;
				if(distancesWithHalf[adjNode] == -1){
					distancesWithHalf[adjNode] = dist + distNode;
					s.insert({distancesWithHalf[adjNode], adjNode, true});
				}else if(distancesWithHalf[adjNode] > dist + distNode){
					s.erase({distancesWithHalf[adjNode], adjNode, true});
					distancesWithHalf[adjNode] = dist + distNode;
					s.insert({distancesWithHalf[adjNode], adjNode, true});
				}
			}
        }
    }
    
    cout<<min(distancesWithHalf[n], distancesWithoutHalf[n])<<endl;
    return 0;
}