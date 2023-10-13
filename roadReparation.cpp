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

        void unionNodes(int u, int v){
            int pu = findUPar(u);
            int pv = findUPar(v);

            if(pu == pv)
                return;

            if(size[pu] <= size[pv]){
                size[pv] += size[pu];
                parent[pu] = pv;
            }else{
                size[pu] += size[pv];
                parent[pv] = pu;
            }

            return;
        }
};

int main(){
    int n, m;
    cin>>n>>m;

    DisJointSet* ds = new DisJointSet(n);

    vector<vector<int> > roads;

    for(int i = 0; i<m; i++){
        int a, b, c;
        cin>>a>>b>>c;
        vector<int> temp;
        temp.push_back(c);
        temp.push_back(a);
        temp.push_back(b);
        roads.push_back(temp);
    }

    sort(roads.begin(), roads.end());

    ll cost = 0;
    int separates = n;

    for(int i = 0; i<m; i++){
        int wt = roads[i][0];
        int u = roads[i][1];
        int v = roads[i][2];

        int pu = ds->findUPar(u);
        int pv = ds->findUPar(v);

        if(pu == pv)
            continue;
        
        separates--;
        ds->unionNodes(u, v);
        cost += (ll)wt;
    }

    if(separates > 1){
        cout<<"IMPOSSIBLE"<<endl;
    }else{
        cout<<cost<<endl;
    }

    return 0;

}