#include <iostream>
#include <math.h>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1,  0, -1};
char map[4] = {'D', 'R', 'U', 'L'};

bool isValid(int x, int y, int n, int m){
    if(x >= 0 && x <n && y >= 0 && y <m)
        return true;
    return false;
}

bool pathFound(pair<int, int> A, vector<vector<int> >& distanceMonsters, vector<vector<char>>& room, string& ans, int dis, vector<vector<bool>> & visited){
    int x = A.first;
    int y = A.second;
    visited[x][y] = true;
    int n = distanceMonsters.size();
    int m = distanceMonsters[0].size();
    //cout<<x<<" "<<y<<" "<<distanceMonsters[x][y]<<endl;
    if(distanceMonsters[x][y] != -1){
        if(distanceMonsters[x][y] <= dis)
            return false;
    }
    
    if(x == 0 || x == n-1 || y == 0 || y == m-1){
        return true;
    }
    
     
    //cout<<x<<" "<<y<<endl;
    for(int k = 0; k<4; k++){
        int tempx = x + dx[k];
        int tempy = y + dy[k];
        if(isValid(tempx, tempy, n, m) && room[tempx][tempy] == '.' && !visited[tempx][tempy]){
            //cout<<tempx<<" "<<tempy<<endl;
            visited[tempx][tempy] = true;
            ans += map[k];
            bool t = pathFound({tempx, tempy}, distanceMonsters, room, ans, dis + 1, visited);
            if(t)
                return true;
            ans = ans.substr(0, ans.size() - 1);
            visited[tempx][tempy] = false;
        }
    }
    
    return false;
}

void distanceUpdates(vector<vector<int>>& distanceMonsters, vector<vector<char>>& room, vector<pair<int,int>>& monsterlocations){
    queue<pair<int, int>> q;
    int n = distanceMonsters.size();
    int m = distanceMonsters[0].size();
    
    for(int i = 0; i<monsterlocations.size(); i++){
        int x = monsterlocations[i].first;
        int y = monsterlocations[i].second;
        if(distanceMonsters[x][y] != 0){
            distanceMonsters[x][y] = 0;
            q.push({x, y});
        }
    }
    
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        int dis = distanceMonsters[x][y];
        q.pop();
        for(int k = 0; k<4; k++){
            int tempx = x + dx[k];
            int tempy = y + dy[k];
            if(isValid(tempx, tempy, n, m) && (room[tempx][tempy] == '.' || room[tempx][tempy] == 'A')){
                if((distanceMonsters[tempx][tempy] == -1) || (distanceMonsters[tempx][tempy] > 1 + dis)){
                    distanceMonsters[tempx][tempy] = 1 + dis;
                    q.push({tempx, tempy});
                }
            }
        }
    }
    
    return;
}

int main(){
    int n, m;
    cin>> n>> m;

    vector<vector<int> > distanceMonsters(n, vector<int>(m, -1));
    vector<vector<char> > room(n, vector<char>(m));
    pair<int, int> A;
    vector<pair<int, int>> monsterlocations;
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            cin>>room[i][j];
            if(room[i][j] == 'A')
                A = make_pair(i, j);
                
            if(room[i][j] == 'M')
                monsterlocations.push_back({i, j});
        }
    }
 
    distanceUpdates(distanceMonsters, room, monsterlocations);
    // for(int i = 0; i<n; i++){
    //     for(int j = 0; j<m; j++){
    //         cout<<distanceMonsters[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    
    //cout<<distance[A.first][A.second]<<endl;
    string ans;
    bool temp = pathFound(A, distanceMonsters, room, ans, 0, visited);
    
    if(!temp)
        cout<<"NO"<<endl;
    else{
        cout<<"YES"<<endl;
        cout<<ans.length()<<endl;
        cout<<ans<<endl;
    }
    
    return 0;
}