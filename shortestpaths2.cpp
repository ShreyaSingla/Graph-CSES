#include <algorithm>
#include <iostream>
#include <vector>
#define ll long long int
using namespace std;

int main() {
	ll n, m, q;
	cin>>n>>m>>q;
	
	vector<vector<ll>> distance(n, vector<ll>(n, -1));
	
	for(int i = 0; i<m; i++){
		ll a, b, c;
		cin>>a>>b>>c;

        if(distance[a-1][b-1] == -1){
            distance[a-1][b-1] = c;
            distance[b-1][a-1] = c;
        }else{
            distance[a-1][b-1] = min(c, distance[a-1][b-1]);
            distance[b-1][a-1] = min(c, distance[b-1][a-1]);
        }
	}
	
	for(int i = 0; i<n; i++)
		distance[i][i] = 0;
		
	for(int k = 0; k<n; k++){
		for(int i = 0; i<n; i++){
			for(int j = 0; j<n; j++){
				if(distance[i][k] != -1 && distance[k][j] != -1 && distance[i][j] != -1)	
					distance[i][j] = min(distance[i][j], distance[i][k] + distance[k][j]);
				else if(distance[i][k] != -1 && distance[k][j] != -1 && distance[i][j] == -1)
					distance[i][j] = distance[i][k] + distance[k][j];
			}
		}
	}
	
	for(int i = 0; i<q; i++){
		ll a, b;
		cin>>a>>b;
		cout<<distance[a-1][b-1]<<endl;
	}
	
	return 0;
}