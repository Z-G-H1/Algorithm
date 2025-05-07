#include <iostream>
#include <utility>
#include <vector>
#include <queue>

using namespace std;
int area;
int dir[4][2] = {-1,0, 1,0, 0,-1, 0,1};

void bfs(const vector<vector<int>> &graph,vector<vector<bool>> &visited, int x, int y){
    queue<pair<int, int>> que;
    que.push({x,y});
    visited[x][y] = true;
    while(!que.empty()){
        area++;
        pair<int, int> cur = que.front(); que.pop();
        for(int i=0;i<4;i++){
            int nx = cur.first + dir[i][0];
            int ny = cur.second + dir[i][1];
            if(nx < 0 || nx >= graph.size() || ny < 0 || ny >= graph[0].size()) continue;
            if(!visited[nx][ny] && graph[nx][ny] == 1){
                que.push({nx,ny});
                visited[nx][ny] = true;
            }
        }
    }
}

int main(){
    int m, n;
    cin >> m >> n;
    int res = 0;
    vector<vector<int>> graph(m, vector<int>(n,0));
    vector<vector<bool>> visited(m, vector<bool>(n,0));
    vector<vector<bool>> visited2(m, vector<bool>(n,0));



    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin >> graph[i][j];
        }
    }

    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(graph[i][j] == 0){
                area = 0;
                graph[i][j] = 1;
                bfs(graph,visited,i,j);
                graph[i][j] = 0;
                res = max(area, res);
                visited = vector<vector<bool>>(m, vector<bool>(n,0));
            }else{
                area = 0;
                bfs(graph,visited2,i,j);
                res = max(area, res);
            }
        }
    }

    cout << res;
    return 0;
}