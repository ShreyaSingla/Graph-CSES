#include <iostream>
#include <vector>
#include <algorithm>
#include <stack> 

#define ll long long int
using namespace std;

void dfs(int node, vector<int>& vis, vector<vector<int> >& adjList, stack<int>& st){
    vis[node] = 1;
    for(auto i: adjList[node]){
        if(!vis[i])
            dfs(i, vis, adjList, st);
    }

    st.push(node);
}

void dfs3(int node, vector<int>& vis, vector<vector<int> >& adjListReverse){
    vis[node] = 1;
    for(auto it: adjListReverse[node]){
        if(!vis[it])
            dfs3(it, vis, adjListReverse);
    }
    return;
}

int main(){
    int n, m;
    cin>>n>>m;

    vector<vector<int> > adjList(n+1);
    vector<int> vis(n+1, 0);

    for(int i = 0; i<m; i++){
        int u, v;
        cin>>u>>v;
        adjList[u].push_back(v);
    }

    // Step 1: Traverse the graph, recording the order in which the elements occur
    stack <int> st;

    for(int i = 1; i<=n; i++){
        if(!vis[i])
            dfs(i, vis, adjList, st);
    }

    // Step 2: Reverse the graph

    vector<vector<int> > adjListReverse(n+1);
    for(int i = 1; i<=n; i++){
        vis[i] = 0;
        for(auto it: adjList[i])
            adjListReverse[it].push_back(i);
    }

    // Step 3: find SCC

    int scc = 0;
    vector<int> unique;

    while(!st.empty()){
        int node = st.top();
        st.pop();
        if(!vis[node]){
            scc++;
            unique.push_back(node);
            dfs3(node, vis, adjListReverse);
        }
    }

    if(scc == 1)
        cout<<"YES"<<endl;
    else{
        cout<<"NO"<<endl;
        cout<<unique[1]<<" "<<unique[0]<<endl;
    }

    return 0;
}

