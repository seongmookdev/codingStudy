#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

void dfs(int start, vector<int>graph[], bool check[]){
    check[start] = true;
    printf("%d ", start);

    for(int i=0; i<graph[start].size(); ++i){
        int next = graph[start][i];
        if(check[next] == false){
            dfs(next, graph, check);
        }
    }
}

void bfs(int start){
    queue<int>q;
    q.push(start);
    while(!q.empty()){
        int temp = q.front(); q.pop();
        printf("%d",temp);
    }
}

int main(){

    int n=0, m=0, start=0;
    scanf("%d %d %d",&n, &m, &start);

    vector<int>graph[n+1];
    bool check[n+1] = {false, };
    
    for(int i=0; i<m; ++i){
        int u, v;
        scanf("%d %d",&u, &v);

        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    for(int i=1; i<=n; ++i){
        sort(graph[i].begin(), graph[i].end());
    }

    dfs(start, graph, check);
    printf("\n");

    return 0;
}
