#include <bits/stdc++.h>

using namespace std;

void dfs(const vector<list<int>> &graph, vector<bool>&visited, int key){
    visited[key] = true;

    // for(int i=1;i<=graph[key].size();i++){
    //     int t = graph[key].front();
    //     graph[key]
    //     if(!visited[t]){
    //         dfs(graph, visited, t);
    //     }
    // }
    list<int> keys = graph[key];
    for(auto k : keys ){
        if( !visited[k] )
            dfs(graph, visited, k);
    }
}


int main(){
    int n,k;
    cin >> n >> k;

    vector<list<int>> graph(n+1);
    vector<bool> visited(n+1, 0);
    for(int i=0;i<k;i++){
        int a,b;
        cin >> a >> b;
        graph[a].push_back(b);
    }

    dfs(graph,visited,1);


    for(int i=1;i<=n;i++){
        if(!visited[i]){
            cout << i << endl;
            cout << -1 << endl;
            return 0;
        }
    }

    cout << 1 << endl;
}