#include <iostream>
#include <queue>
using namespace std;

int n, m, start;
int mat[1001][1001];
bool visited[1001];

void bfs(int start){
    queue<int> q;

    q.push(start);
    visited[start] = false;

    while(!q.empty()){
        start = q.front(); q.pop();
        printf("%d ", start);
        for(int i=1; i<=n; ++i){
            if(visited[i] && mat[start][i]==1){
                q.push(i);
                visited[i] = false;
            }
        }
    }
}

void dfs(int start){

    visited[start] = true;
    printf("%d ", start);

    for(int i=1; i<=n; ++i){
        if(!visited[i] && mat[start][i] == 1){
            dfs(i);
        }
    }

}

int main(){

    scanf("%d %d %d", &n, &m, &start);
    int u, v;
    for(int i=0; i<m; ++i){
        scanf("%d %d",&u, &v);
        mat[u][v] = mat[v][u] = 1;
    }

    dfs(start);
    printf("\n");
    bfs(start);

    return 0;
}
