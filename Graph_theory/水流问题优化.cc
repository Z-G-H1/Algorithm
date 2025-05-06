#include <iostream>
#include <utility>
#include <vector>
#include <queue>

using namespace std;

// 上下左右
int dir[4][2] = {-1,0, 1,0, 0,-1, 0,1};

void dfs(const vector<vector<int>> &graph,vector<vector<bool>> &visited, int x, int y){

    visited[x][y] = true;
    for(int i=0;i<4;i++){
        int nx = x + dir[i][0];
        int ny = y + dir[i][1];
        if(nx < 0 || nx >= graph.size() || ny < 0 || ny >= graph[0].size()) continue;
        if(!visited[nx][ny] && graph[nx][ny] >= graph[x][y] ){
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
    vector<vector<bool>> first(n, vector<bool>(m,false));
    vector<vector<bool>> second(n, vector<bool>(m,false));

    
    // 初始化图
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> graph[i][j];
        }
    }

    // 从第一边界出发
    // 注意n 和 m 的区别
    for(int i=0;i<n;i++){
        dfs(graph,first,i,0);
        dfs(graph,second,i,m-1);
    }
    // 从第二边界出发
    for(int i=0;i<m;i++){
        dfs(graph,first,0,i);
        dfs(graph,second,n-1,i);
    }


    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(first[i][j] && second[i][j])
                cout << i << " " << j << endl;
        }
    }
    return 0;
}