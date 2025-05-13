#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <utility>
#include <vector>
#include <queue>
#include <map>
#include <unordered_set>
/**
    优化思路：
        第一步：遍历图，记录每个岛屿的大小，并编号，使用map记录 <编号，面积>
        第二步：遍历图，将0变为1，看如果有相邻的岛屿，加起来
 */
using namespace std;
int area;
int dir[4][2] = {-1,0, 1,0, 0,-1, 0,1};
int key = 2;
unordered_map<int, int> map1;
unordered_set<int> set;

void bfs(vector<vector<int>> &graph,vector<vector<bool>> &visited, int x, int y){
    queue<pair<int, int>> que;
    que.push({x,y});
    visited[x][y] = true;
    while(!que.empty()){
        area++;
        pair<int, int> cur = que.front(); que.pop();
        int index;
        for(int i=0;i<4;i++){
            int nx = cur.first + dir[i][0];
            int ny = cur.second + dir[i][1];
            if(nx < 0 || nx >= graph.size() || ny < 0 || ny >= graph[0].size()) continue;
            if(!visited[nx][ny] && graph[nx][ny] == 1){
                que.push({nx,ny});
                visited[nx][ny] = true;
                graph[nx][ny] = key;
            }else if ( graph[nx][ny] > 1){
                set.insert(graph[nx][ny]);
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



    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin >> graph[i][j];
        }
    }

    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(!visited[i][j] && graph[i][j] == 1){
                bfs(graph, visited, i, j);
                graph[i][j] = key;
                map1[key] = area;
                key++;
                res = max(res ,area);
                area = 0;
            }
        }
    }

    int t = 1;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(graph[i][j] == 0){
                t = 1;
                set.clear();
                bfs(graph, visited, i, j);
                for(auto it = set.begin();it!=set.end();it++){
                    t += map1[*it];
                }
                res = max(res, t);
            }
        }
    }

    cout << res;
    return 0;
}