#include <iostream>
#include <math.h>
#include <vector>
#include <queue>

using namespace std;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1,  0, -1};

bool isValid(int x, int y, int n, int m){
    if(x >= 0 && x <n && y >= 0 && y <m)
        return true;
    return false;
}

void bfs(vector<vector<bool> >& isRoom, vector<vector<bool> >& visited, int i, int j){
    int n = isRoom.size();
    int m = isRoom[0].size();
    visited[i][j] = true;
    queue<pair<int, int> > q;
    q.push(make_pair(i, j));

    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for(int k = 0; k<4; k++){
            int tempx = x + dx[k];
            int tempy = y + dy[k];

            if(isValid(tempx, tempy, n, m)){
                if(isRoom[tempx][tempy] && !visited[tempx][tempy]){
                    visited[tempx][tempy] = true;
                    q.push(make_pair(tempx, tempy));
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

    vector<vector<bool> > isRoom(n, vector<bool>(m, false));

    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            char ch;
            cin>>ch;
            if(ch == '.')
                isRoom[i][j] = true;
        }
    }

    int num = 0;

    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            if(isRoom[i][j] && !visited[i][j]){
                num++;
                bfs(isRoom, visited, i, j);
            }
        }
    }

    cout<<num;
    return 0;
}