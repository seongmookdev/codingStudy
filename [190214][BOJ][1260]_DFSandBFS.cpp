#include <iostream>
#include <queue>
using namespace std;

int n,m,start;
int mat[1001][1001];
int visited[1001];

void bfs(int start){
    queue<int> q;
    q.push(start);
    visited[start] = 0;

    while(!q.empty()){
        int next = q.front(); q.pop();
        printf("%d ",next);
        
        for(int i=1; i<=n; ++i){
            if(visited[i]==1 && mat[next][i]==1){
                q.push(i);
                visited[i] = 0;
            }
        }
    }
}

void dfs(int start){
    visited[start]=1;
    printf("%d ",start);
    for(int i=1; i<=n; ++i){
        if(visited[i]==0 && mat[start][i]==1){
            dfs(i);
        }
    }
}

int main(){

    scanf("%d %d %d", &n, &m, &start);
    for(int i=0; i<m; ++i){
        int u, v;
        scanf("%d %d",&u, &v);
        mat[u][v]=mat[v][u]=1;
    }

    dfs(start);
    printf("\n");
    bfs(start);

}

