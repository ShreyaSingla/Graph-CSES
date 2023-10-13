#include <iostream>
#include <math.h>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

bool dfs(int node, int par, vector<vector<int>>& adjList, vector<int>& colour, vector<bool>& vis, vector<int>& parent)
{
    vis[node] = 1;
    parent[node] = par;
    colour[node] = 1;
    
    for (auto child : adjList[node])
    {
        if (child != par && colour[child] == 1)
        {
            vector<int> res;
            int x = node;
            while (x != child)
            {
                res.push_back(x);
                x = parent[x];
            }
            res.push_back(x);
            res.push_back(res[0]);
            cout << res.size() << "\n";
            for (auto x : res)
                cout << x << " ";
            exit(0);
            return true;
        }
        else if (child != par && colour[child] == 0)
        {
            bool temp = dfs(child, node, adjList, colour, vis, parent);
            if (temp == true)
            {
                vector<int> res;
                int x = parent[child];
                while (parent[x] != child)
                {
                    res.push_back(x);
                    x = parent[x];
                }
                cout << res.size() << "\n";
                for (auto x : res)
                    cout << x << " ";
                exit(0);
                return true;
            }
        }
    }
    colour[node] = 2;
    return false;
}

int main(){
    int n, m;
    cin>>n>>m;
    
    vector<vector<int> > adjList(n+1);
    vector<bool> vis(n+1, false);
    vector<int> colour(n+1, 0);
    vector<int> parent(n+1, 0);
    
    for(int i = 0; i<m; i++){
        int a, b;
        cin>>a>>b;
        adjList[a].push_back(b);
        adjList[b].push_back(a);
    }
    
    for(int i = 1; i<=n; i++){
        if(vis[i])
            continue;
        dfs(i, 0, adjList, colour, vis, parent);
    }

    cout<<"IMPOSSIBLE"<<endl;
    return 0;
}