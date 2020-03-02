//URL: https://www.acmicpc.net/problem/11724

#include <iostream>
#include <stdio.h>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

void dfs(int start, vector<int>graph[], bool check[]){
    check[start] = true;
    
}


int main(){

    int n, m, start;
    scanf("%d %d", &n, &m);
    vector<int>graph[n+1];
    bool check[n+1];

    for(int i=0; i<m; ++i){
        int u, v;
        scanf("%d %d", &u, &v);
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    for(int i=1; i<=n; ++i){
        sort(graph[i].begin(), graph[i].end());
    }

    dfs(start, graph, check);

    return 0;
}
