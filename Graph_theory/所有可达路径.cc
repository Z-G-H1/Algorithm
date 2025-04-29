#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> res;
vector<int > path;

void dfs(const vector<vector<int>> &graph, int s, int m){
    if(s == m){
        res.push_back(path);
        return ;
    }
    for(int i=1;i<graph.size();i++){
        if(graph[s][i] == 1){
            path.push_back(i);
            dfs(graph,i,m);
            path.pop_back();
        }
    }
    
}


int main(){
    // m个节点， n条边
    int m,n;
    cin >> m >> n;

    vector<vector<int >> graph(m+1, vector<int>(m+1,0));


    for(int i=0;i<n;i++){
        int a,b;
        cin >> a >> b;
        graph[a][b] = 1;
    }

    res.clear();
    path.clear();
    path.push_back(1);
    dfs(graph,1,m);
    
    if (res.size() == 0) cout << -1 << endl;
    for(auto &v : res){
        for(int i=0;i<v.size();i++){
            cout << v[i] ;
            if(i != v.size()-1){
                cout << " ";
            }
        }
        cout << endl;
    }

    return 0;
    
}

