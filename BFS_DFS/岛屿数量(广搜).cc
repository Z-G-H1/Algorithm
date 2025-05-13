#include <iostream>
#include <utility>
#include <vector>
#include <queue>

using namespace std;

int cnt;
int dir[4][2] = {-1,0, 1,0, 0,-1, 0,1};

void bfs(const vector<vector<int>> &graph, vector<vector<bool>> &visited, int x, int y){
    queue<pair<int, int>> que;
    que.push({x,y});
    visited[x][y] = true;
    cnt++;
    while(!que.empty()){
        pair<int, int> cur = que.front(); que.pop();
        int curX = cur.first;
        int curY = cur.second;
        for(int i=0;i<4;i++){
            int nextX = curX + dir[i][0];
            int nextY = curY + dir[i][1];
            // 下标越界
            if(nextX < 0 || nextX >= graph.size() || nextY < 0 || nextY >= graph[0].size()) continue;
            if(!visited[nextX][nextY] && graph[nextX][nextY] == 1){
                que.push({nextX,nextY});
                visited[nextX][nextY] = true;
            }
        }
    }
}

int main(){
    int m, n;
    cin >> n >> m;
    vector<vector<int>> graph(n, vector<int>(m,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> graph[i][j];
        }
    }

    vector<vector<bool>> visited(n, vector<bool>(m,false));

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(!visited[i][j] && graph[i][j] == 1){
                // cout << "进入bfs:" << i+1 << j+1 << endl;
                bfs(graph,visited,i,j);
            }
        }
    }
    cout << cnt;
    return 0;
}