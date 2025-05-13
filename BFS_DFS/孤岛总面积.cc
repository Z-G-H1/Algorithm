#include <iostream>
#include <utility>
#include <vector>
#include <queue>

using namespace std;

// 上下左右
int dir[4][2] = {-1,0, 1,0, 0,-1, 0,1};
int res;
bool isLand;
int area;

void bfs(const vector<vector<int>> &graph, vector<vector<bool>> &visited, int x, int y){
    if(x == 0 || x == graph.size()-1 || y == 0 || y == graph[0].size()-1){
        isLand = false;
        return;
    }
    queue<pair<int, int>> que;
    que.push({x,y});
    visited[x][y] = true;
    while(!que.empty()){
        pair<int,int> cur = que.front();
        que.pop();area++;
        int curX = cur.first;
        int curY = cur.second;
        for(int i=0;i<4;i++){
            int nX = curX + dir[i][0];
            int nY = curY + dir[i][1];
            if(nX < 0 || nX >= graph.size() || nY < 0 || nY >= graph[0].size()) continue;
            if(!visited[nX][nY] && graph[nX][nY] == 1){
                if(nX == 0 || nX == graph.size()-1 || nY == 0 || nY == graph[0].size()-1){
                    isLand = false;
                }
                que.push({nX,nY});
                visited[nX][nY] = true;
            }
        }
    }
}

int main(){
    int n,m;
    // n行 m列
    cin >> n >> m;
    vector<vector<int>> graph(n, vector<int>(m,0));
    vector<vector<bool>> visited(n, vector<bool>(m,false));
    
    // 初始化图
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> graph[i][j];
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(!visited[i][j] && graph[i][j] == 1){
                area = 0;
                isLand = true;
                bfs(graph, visited, i, j);
                if(isLand) 
                    res += area;
            }
        }
    }


    cout << res;
    return 0;
}