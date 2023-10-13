#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#define ll long long int 

using namespace std;

bool bellmanFord(int i, vector<vector<ll> >& edges, vector<ll>& dist, vector<ll>& par){
    dist[i] = 0;
	ll f;
	int n = dist.size() - 1;
    int m = edges.size();

	for(int j = 0; j<n; j++){
		f = 0;
		for(int i = 0; i<m; i++){
			ll u = edges[i][0];
			ll v = edges[i][1];
			ll wt = edges[i][2];
			
			if(dist[u] != 1e10 && dist[u] + wt < dist[v]){
				dist[v] = dist[u] + wt;
				par[v] = u;
				f = v;
                //cout<<j<<" "<<f<<endl;
			}
		}
	}
	
	if(f == 0){
		return false;
	}
    vector<int> cycle;
    int node = f;
    cout<<"YES"<<endl;

    set<int> s;

    while(s.find(node) == s.end()){
        s.insert(node);
        cycle.push_back(node);
        node = par[node];
        //cout<<"here"<<node<<" "<<par[node]<<endl;
    }
    cycle.push_back(node);

    reverse(cycle.begin(), cycle.end());
    for(int i = 0; i<cycle.size(); i++)
        cout<<cycle[i]<<" ";

    return true;
}

int main(){
	ll n, m;
	cin>>n>>m;
	
	vector<vector<ll> > edges(m);
	vector<bool> exists(n+1, false);

    int flag = -1;

	for(int i = 0; i<m; i++){
		ll a, b, c;
		cin>>a>>b>>c;
		vector<ll> temp;
		temp.push_back(a);
		temp.push_back(b);
		temp.push_back(c);
		edges[i] = temp;

        if(a != b)
            exists[a] = true;
        
        if(a == b && c < 0){
            flag = a;
        }
	}

    if(flag != -1){
        cout<<"YES"<<endl;
        cout<<flag<<" "<<flag<<endl;
        return 0;
    }
	
	vector<ll> dist(n+1, 1e10);
	vector<ll> par(n+1, 0);

    for(int i = 1; i<=n; i++){
        if(dist[i] == 1e10 && exists[i]){
            bool temp = bellmanFord(i, edges, dist, par);
            if(temp)
                return 0;
        }
    }
	
	cout<<"NO"<<endl;
	return 0;
}

