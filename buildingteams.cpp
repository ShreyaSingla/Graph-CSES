#include <iostream>
#include <math.h>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

bool assigning(int i, vector<int>& team, vector<vector<int>>& adjList){
    team[i] = 1;
    queue<int> q;
    q.push(i);
    
    while(!q.empty()){
        int node = q.front();
        int t = team[node];
        int otherTeam = 2;
        if(t == 2)
            otherTeam = 1;
        q.pop();
        
        for(auto adjNode: adjList[node]){
            if(team[adjNode] == 0){
                team[adjNode] = otherTeam;
                q.push(adjNode);
            }else if(team[adjNode] == t)
                return false;
        }
    }
    
    return true;
}

int main(){
    int n, m;
    cin>>n>>m;
    
    vector<vector<int> > adjList(n+1);
    vector<int> team(n+1, 0);
    
    for(int i = 0; i<m; i++){
        int a, b;
        cin>>a>>b;
        adjList[a].push_back(b);
        adjList[b].push_back(a);
    }
    
    queue<int> q;
    
    for(int i = 1; i<=n; i++){
        if(team[i] == 0){
            if(assigning(i, team, adjList))
                continue;
            else{
                cout<<"IMPOSSIBLE"<<endl;
                return 0;
            }
        }
    }
    
    for(int i = 1; i<=n; i++)
        cout<<team[i]<<" ";
    cout<<endl;
    return 0;
}