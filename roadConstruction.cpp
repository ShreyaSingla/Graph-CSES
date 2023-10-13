#include <iostream>
#include <vector>
#include <algorithm>

#define ll long long int
using namespace std;

class DisJointSet{
    vector<int> size;
    vector<int> parent;

    public:
        DisJointSet(int n){
            size.resize(n + 1, 1);
            parent.resize(n + 1);

            for(int i = 0; i<=n; i++)
                parent[i] = i;
        }

        int findUPar(int node){
            if(parent[node] == node)
                return node;
            
            return parent[node] = findUPar(parent[node]);
        }

        int unionNodes(int pu, int pv, int maxi){
            if(pu == pv)
                return maxi;

            if(size[pu] <= size[pv]){
                size[pv] += size[pu];
                maxi = max(maxi, size[pv]);
                parent[pu] = pv;
            }else{
                size[pu] += size[pv];
                maxi = max(maxi, size[pu]);
                parent[pv] = pu;
            }
            
            return maxi;
        }
};

int main(){
    int n, m;
    cin>>n>>m;

    DisJointSet* ds = new DisJointSet(n);

    int separates = n;
    int maxi = 1;

    for(int i = 0; i<m; i++){
        int u, v;
        cin>>u>>v;

        int pu = ds->findUPar(u);
        int pv = ds->findUPar(v);

        if(pu == pv){
            cout<<separates<<" "<<maxi<<endl;
        }else{
            maxi = ds->unionNodes(pu, pv, maxi);
            separates--;
            cout<<separates<<" "<<maxi<<endl;
        }
    }

    return 0;
}