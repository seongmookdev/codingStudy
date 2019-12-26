#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>

using namespace std;

// Stack에 들어가면 방문한것으로 판단
// 해당 위치를 True로 해준다.

void dfs(int start, vector<int>graph[], bool check[]){

    stack<int> s;
    s.push(start);
    check[start] = true;
    printf("%d", start);

    while(!s.empty()){
        int current_node = s.top();
        s.pop();

        for(int i=0; i<graph[current_node].size(); i++){

            int next_node = graph[current_node][i];
            if(check[next_node] == false){
                printf("%d", next_node);
                check[next_node] = true;
                //s.push(current_node);
                s.push(next_node);
                //break;
            }
        }
    }
}

int main(){
    int n, m, start;
    cin >> n >> m >> start;

    vector<int> graph[n+1];
    bool check [n+1];
    fill(check, check+n+1, false);

    for(int i=0; i<m; i++){
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    for(int i=1; i<=n ; i++){
        sort(graph[i].begin(), graph[i].end());
    }

    dfs(start, graph, check);
    printf("\n");
}
