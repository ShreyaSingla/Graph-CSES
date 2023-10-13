#include <iostream>
#include <math.h>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>

using namespace std;

const int MAX = 1e5 + 1;

vector<int> vis(MAX, 0);
vector<int> par(MAX, 0);
int start = 0, finish = 0;

void dfs(int node, vector<vector<int> >& adjList){
    vis[node] = 1;

    for(auto it: adjList[node]){
        if(vis[it] == 0){
            par[it] = node;
            dfs(it, adjList);
            if(start != 0)
                return;
        }else if(vis[it] == 1){
            start = it;
            finish = node;
            return;
        }
    }
    vis[node] = 2;
    return;
}

int main(){
    int n, m;
    cin>>n>>m;

    vector<vector<int> > adjList(n+1);

    for(int i = 0; i<m; i++){
        int a, b;
        cin>>a>>b;
        adjList[a].push_back(b);
    }

    for(int i = 1; i<=n && !start; i++){
        if(vis[i] == 0){
            dfs(i, adjList);
            //cout<<i<<endl;
        }
    }

    if(start == 0)
        cout<<"IMPOSSIBLE"<<endl;
    else{
        vector<int> cycle;
        cycle.push_back(start);
        for(int i = finish; i != start; i = par[i])
            cycle.push_back(i);

        cycle.push_back(start);
        reverse(cycle.begin(), cycle.end());
        cout<<cycle.size()<<endl;
        for(int i = 0; i<cycle.size(); i++)
            cout<<cycle[i]<<" ";
        cout<<endl;
    }
    return 0;
}