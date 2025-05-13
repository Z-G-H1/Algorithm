#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int dir[4][2] = {-1,0, 1,0, 0,-1, 0,1};
int area;
void dfs(const vector<vector<int>> &graph, vector<vector<bool>> &visited, int x, int y){
    area++;
    visited[x][y] = true;
    for(int i=0;i<4;i++){
        int nX = x + dir[i][0];
        int nY = y + dir[i][1];
        if(nX < 0 || nX >= graph.size() || nY < 0 || nY >= graph[0].size()) continue;
        if(!visited[nX][nY] && graph[nX][nY] == 1){
            dfs(graph, visited, nX, nY);
        }
    }
}

int main(){

    int m, n;
    cin >> n >> m;

    int res = 0;

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
                area = 0;
                dfs(graph,visited,i,j);
                res = max(res, area);
            }
        }
    }
    cout << res;
    return 0;
}