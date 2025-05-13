#include <iostream>
#include <utility>
#include <vector>
#include <queue>

using namespace std;

// 上下左右
int dir[4][2] = {-1,0, 1,0, 0,-1, 0,1};
bool isLand;

void dfs(vector<vector<int>> &graph, int x, int y){
    graph[x][y] = 2;

    for(int i=0;i<4;i++){
        int nX = x + dir[i][0];
        int nY = y + dir[i][1];
        if(nX < 0 || nX >= graph.size() || nY < 0 || nY >= graph[0].size()) continue;
        if(graph[nX][nY] == 1)
            dfs(graph, nX, nY);
    }

}

int main(){
    int n,m;
    // n行 m列
    cin >> n >> m;
    vector<vector<int>> graph(n, vector<int>(m,0));
    
    // 初始化图
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> graph[i][j];
        }
    }
    // 第一列和最后一列 排除这些岛屿
    for(int i=0;i<n;i++){
        if(graph[i][0] == 1) dfs(graph,i,0);
        if(graph[i][m-1] == 1) dfs(graph,i,m-1);
    }

    // 第一行和最后一行 排除这些岛屿
    for(int i=0;i<n;i++){
        if(graph[0][i] == 1) dfs(graph,0,i);
        if(graph[n-1][i] == 1) dfs(graph,n-1,i);
    }
    
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(graph[i][j] == 2){
                graph[i][j] = 1;
            }else if(graph[i][j] == 1){
                graph[i][j] = 0;
            }
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout << graph[i][j] << " ";
        }
        cout << endl;
    }


    return 0;
}