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

string pathFound(pair<int, int> A, pair<int, int> B, vector<vector<int> >& distance){
    int x = A.first;
    int y = A.second;
    int dis = distance[x][y];
    int n = distance.size();
    int m = distance[0].size();
    string ans = "";
    
    while(dis > 0){
        for(int k = 0; k<4; k++){
            int tempx = x + dx[k];
            int tempy = y + dy[k];
            if(isValid(tempx, tempy, n, m)){
                if(distance[tempx][tempy] == dis - 1){
                    ans += map[k];
                    x = tempx;
                    y = tempy;
                    dis--;
                    break;
                }
            }
        }
    }
    
    return ans;
}

void bfs(vector<vector<bool> >& visited, vector<vector<int> >& distance, pair<int, int> A, pair<int, int> B,
vector<vector<char> >& room){
    int n = visited.size();
    int m = visited[0].size();
    visited[B.first][B.second] = true;
    distance[B.first][B.second] = 0;
    
    queue<pair<int, int> > q;
    q.push(make_pair(B.first, B.second));

    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        int dis = distance[x][y];
        
        for(int k = 0; k<4; k++){
            int tempx = x + dx[k];
            int tempy = y + dy[k];

            if(isValid(tempx, tempy, n, m)){
                if(!visited[tempx][tempy]){
                    visited[tempx][tempy] = true;
                    if(room[tempx][tempy] == 'A'){
                        distance[tempx][tempy] = 1 + dis;
                        return;
                    }
                    if(room[tempx][tempy] == '.'){
                        distance[tempx][tempy] = 1 + dis;
                        q.push(make_pair(tempx, tempy));
                    }
                }
            }
        }
    }

    return;
}

int main(){
    int n, m;
    cin>> n>> m;

    vector<vector<bool> > visited(n, vector<bool>(m, false));

    vector<vector<int> > distance(n, vector<int>(m, -1));
    vector<vector<char> > room(n, vector<char>(m));
    pair<int, int> A, B;
    
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            cin>>room[i][j];
            if(room[i][j] == 'A')
                A = make_pair(i, j);
                
            if(room[i][j] == 'B')
                B =make_pair(i, j);
        }
    }

    bfs(visited, distance, A, B, room);
    //cout<<distance[A.first][A.second]<<endl;
    if(distance[A.first][A.second] == -1)
        cout<<"NO";
    else{
        string temp = pathFound(A, B, distance);
        cout<<"YES"<<endl;
        cout<<temp.length()<<endl;
        cout<<temp<<endl;
    }
    return 0;
}