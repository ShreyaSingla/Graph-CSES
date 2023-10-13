#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main(){
    int n, m;
    cin>>n>>m;

    vector<vector<int> > adjList(n+1);
    vector<int> dependencies(n + 1, 0);

    for(int i = 0; i < m; i++){
        int a, b;
        cin>>a>>b;
        adjList[a].push_back(b);
        dependencies[b]++;
    }

    vector<int> ans;
    queue<int> q;

    for(int i = 1; i<=n; i++){
        if(dependencies[i] == 0){
            q.push(i);
            ans.push_back(i);
        }
    }

    while(!q.empty()){
        int node = q.front();
        q.pop();

        for(auto it: adjList[node]){
            dependencies[it]--;
            if(dependencies[it] == 0){
                ans.push_back(it);
                q.push(it);
            }
        }
    }

    if(ans.size() < n){
        cout<<"IMPOSSIBLE"<<endl;
    }else{
        for(int i = 0; i<n; i++)
            cout<<ans[i]<<" ";
            
        cout<<endl;
    }

    return 0;
}