#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> res;
vector<int > path;

void dfs(const vector<vector<int>> &graph, vector<int> &used, int s, int m){
    if(s == m){
        res.push_back(path);
        return ;
    }
    for(int i=1;i<graph.size();i++){
        if(graph[s][i] == 1 && used[i] == 0){
            used[i] = 1;
            path.push_back(i);
            dfs(graph,used,i,m);
            used[i] = 0;
            path.pop_back();
        }
    }
    
}


int main(){
    // m个节点， n条边
    int m,n;
    cin >> m >> n;

    vector<vector<int >> graph(m+1, vector<int>(m+1,0));

    vector<int > used(m,0);

    for(int i=0;i<n;i++){
        int a,b;
        cin >> a >> b;
        graph[a][b] = 1;
    }

    res.clear();
    path.clear();
    path.push_back(1);
    dfs(graph,used,1,m);
    
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

