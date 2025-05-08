#include <iostream>
#include <vector>

using namespace std;


int cir;
int dir[4][2] = {-1,0, 1,0, 0,-1, 0,1};

void dfs(const vector<vector<int>> &graph, vector<vector<bool>> &visited, int x, int y){
    visited[x][y] = true;
    for(int i=0;i<4;i++){
        int nx = x + dir[i][0];
        int ny = y + dir[i][1];
        if(nx < 0 || nx >= graph.size() || ny < 0 || ny >= graph[0].size()){
            cir++;
            continue;
        }
        if(graph[nx][ny] == 1){
            if(!visited[nx][ny])
                dfs(graph, visited, nx, ny);
        }else if(graph[nx][ny] == 0){
            cir++;
        }
    }
}

int main(){
    int m,n;
    cin >> m >> n;

    vector<vector<int>> graph(m, vector<int>(n,0));
    vector<vector<bool>> visited(m, vector<bool>(n,0));


    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin >> graph[i][j];
        }
    }

    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(!visited[i][j] && graph[i][j] == 1){
                dfs(graph, visited, i, j);
            }
        }
    }

    cout << cir << endl;
    return 0;
}