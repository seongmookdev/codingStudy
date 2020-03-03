//URL: https://www.acmicpc.net/problem/11724
//REF: https://jaimemin.tistory.com/637//U

#include <iostream>
#include <vector>
using namespace std;

const int MAX = 1000+1;

int M, N;
vector<int>graph[MAX];
bool visited[MAX];

void dfs(int node){
    visited[node] = true;

    for(int i=0; i<graph[node].size(); ++i){
        int next = graph[node][i];
        if(!visited[next]) dfs(next);
    }
}

int main(){

    scanf("%d %d", &N, &M);
    for(int i=0; i<M; ++i){
        int u, v;
        scanf("%d %d", &u, &v);

        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    int cnt = 0;
    for(int i=1; i<N+1; ++i){
        if(!visited[i]){
            dfs(i);
            cnt++;
        }
    }

    printf("%d\n",cnt);
    return 0;
}
