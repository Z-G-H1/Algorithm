#include <iostream>
#include <utility>
#include <vector>
#include <queue>

using namespace std;

// 上下左右
int dir[4][2] = {-1,0, 1,0, 0,-1, 0,1};
bool first;
bool second;

void dfs(const vector<vector<int>> &graph,vector<vector<bool>> &visited, int x, int y){
    if(x == 0 || y == 0) first = true;
    if(x == graph.size()-1 || y == graph[0].size()-1) second = true;
    if( first && second ) return;
    visited[x][y] = true;
    for(int i=0;i<4;i++){
        int nx = x + dir[i][0];
        int ny = y + dir[i][1];
        if(nx < 0 || nx >= graph.size() || ny < 0 || ny >= graph[0].size()) continue;
        if(!visited[nx][ny] && graph[nx][ny] <= graph[x][y] ){
            // 可以流过去
            dfs(graph, visited, nx, ny);
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

    vector<vector<int>> res;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            first = false; second = false;
            visited =  vector<vector<bool>>(n,vector<bool>(m,false));
            dfs(graph, visited, i, j);
            if(first && second){
                res.push_back({i,j});
            }
        }
    }
    for(int i=0;i<res.size();i++){
        cout << res[i][0] << " " << res[i][1] << endl;
    }
    return 0;
}