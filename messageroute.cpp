#include <iostream>
#include <math.h>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

int main(){
    int n, m;
    cin>>n>>m;
    
    vector<vector<int> > adjList(n+1);
    vector<int> distance(n+1, -1);
    
    distance[1] = 1;
    queue<int> q;
    q.push(1);
    
    for(int i = 0; i<m; i++){
        int a, b;
        cin>>a>>b;
        adjList[a].push_back(b);
        adjList[b].push_back(a);
    }
    
    vector<int> ans;
    
    while(!q.empty()){
        int node = q.front();
        int dis = distance[node];
        if(node == n){
            break;
        }
        q.pop();
        for(auto adjNode: adjList[node]){
            if(distance[adjNode] == -1){
                distance[adjNode] = dis+1;
                q.push(adjNode);
            }else if(distance[adjNode] > dis + 1){
                distance[adjNode] = dis + 1;
                q.push(adjNode);
            }
        }
    }
    
    if(distance[n] == -1)
        cout<<"IMPOSSIBLE"<<endl;
    else{
        cout<<distance[n]<<endl;
        
        stack<int> st;
        st.push(n);
        while(st.top() != 1){
            int node = st.top();
            int dis = distance[node];
            for(int i = 0; i<adjList[node].size(); i++){
                if(distance[adjList[node][i]] == dis - 1){
                    st.push(adjList[node][i]);
                    break;
                }
            }
        }
        
        while(!st.empty()){
            cout<<st.top()<<" ";
            st.pop();
        }
        
        cout<<endl;
    } 
    
    return 0;
}