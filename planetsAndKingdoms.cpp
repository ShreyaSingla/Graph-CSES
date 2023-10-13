#include <iostream>
#include <vector>
#include <stack>
using namespace std;

void dfs(int node, vector<int>& vis, vector<vector<int> >& adjList, stack<int>& st){
    vis[node] = 1;
    for(auto it: adjList[node]){
        if(!vis[it])
            dfs(it, vis, adjList, st);
    }
    st.push(node);
}

void dfs2(int node, int parent, vector<vector<int> >& adjListReverse, vector<int>& vis, vector<int>& component){
    vis[node] = 1;
    component[node] = parent;

    for(auto it: adjListReverse[node]){
        if(!vis[it])
            dfs2(it, parent, adjListReverse, vis, component);
    }

    return;
}

int main(){ 
    int n, m;
    cin>>n>>m;

    vector<int> vis(n+1, 0);

    vector<vector<int> > adjList(n+1), adjListReverse(n+1);

    for(int i = 0; i<m; i++){
        int a, b;
        cin>>a>>b;
        adjList[a].push_back(b);
        adjListReverse[b].push_back(a);
    }

    stack <int> st;

    for(int i = 1; i<=n; i++){
        if(!vis[i])
            dfs(i, vis, adjList, st);
    }

    for(int i = 0; i<=n; i++)   
        vis[i] = 0;

    int scc = 0;
    vector<int> component(n+1, 0);

    while(!st.empty()){
        int node = st.top();
        st.pop();
        if(!vis[node]){
            scc++;
            dfs2(node, scc, adjListReverse, vis, component);
        }
    }

    cout<<scc<<endl;

    for(int i = 1; i<=n; i++)
        cout<<component[i]<<" ";
    cout<<endl;
    return 0;
}