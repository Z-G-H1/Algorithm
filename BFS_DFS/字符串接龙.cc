#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <queue>

using namespace std;

int main(){
    int n;
    string beginStr, endStr, str;
    cin >> n ;
    cin >> beginStr >> endStr ;

    unordered_set<string> set;

    for(int i=0;i<n;i++){
        cin >> str;
        set.insert(str);
    }

    // 记录strSet里的字符串是否被访问过，同时记录路径长度
    unordered_map<string, int> map; // 记录的字符串，路径长度

    queue<string> que;
    que.push(beginStr);

    map.insert(pair<string, int>(beginStr, 1));

    while(!que.empty()){
        string word = que.front();
        que.pop();
        int t = map[word];
        // 判断word能去的位置
        for(int i=0;i<word.size();i++){
            // 替换word中的每个字母
            string newWord = word;
            
            for(int j=0;j<26;j++){
                newWord[i] = j + 'a';
                // 在set中能找到，且在map中找不到
                if( map.find(newWord) == map.end()  &&  set.find(newWord) != set.end()){
                    // 存在字符串
                    que.push(newWord);

                    map.insert(pair<string, int>(newWord,t+1));
                }
                if(newWord == endStr){
                        cout << t+1 << endl;
                        return 0;
                }
            }
        }
    }
    cout << 0 << endl;
    return 0;
}