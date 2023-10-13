#include <iostream>
#include <math.h>
#include <vector>
#include <queue>

using namespace std;

class DisjointSet{
    vector<int> size, parent;
    
    public:
        DisjointSet(int n){
            size.resize(n+1, 0);
            parent.resize(n+1, 0);
            for(int i = 0; i<=n; i++)
                parent[i] = i;
        }
        
        int findUPar(int node){
            if(node == parent[node])
                return node;
            
            return parent[node] = findUPar(parent[node]);
        }
        
        int UnionBySize(int u, int v){
            int pu = findUPar(u);
            int pv = findUPar(v);
            
            if(pu == pv)
                return 0;
                
            if(size[pu] < size[pv]){
                parent[pu] = pv;
                size[pv] += size[pu];
            }else{
                parent[pv] = pu;
                size[pu] += size[pv];
            }
            return 1;
        }
};

int main(){
    int n, m;
    cin>>n>>m;
    
    vector<vector<int> > adjList(n+1);
    DisjointSet ds(n);
    
    for(int i = 0; i<m; i++){
        int a, b;
        cin>>a>>b;
        ds.UnionBySize(a, b);
    }
    
    int ans = 0;
    vector<pair<int, int> > roads;
    
    for(int i = 1; i<=n; i++){
        int temp = ds.UnionBySize(1, i);
        if(temp == 1){
            ans++;
            roads.push_back(make_pair(1, i));
        }
    }
    
    cout<<ans<<endl;
    for(int i = 0; i<ans; i++){
        cout<<roads[i].first<<" "<<roads[i].second<<endl;
    }
    return 0;
}