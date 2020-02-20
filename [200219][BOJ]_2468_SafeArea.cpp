#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int N;
int map[101][101];
int backup[101][101];
bool visited[101][101];
int MAX;

const int dy[] = {+1, 0, -1, 0};
const int dx[] = {0, +1, 0, -1};

int copy(int depth){
    for(int y=0; y<N; ++y){
        for(int x=0; x<N; ++x){
            if(map[y][x] > depth)
            backup[y][x] = map[y][x];
        }
    }
}

void dfs(int y, int x){

    visited[y][x] = true;

    for(int dir=0; dir<4; ++dir){
        int ny = y + dy[dir];
        int nx = x + dx[dir];

        if(ny<0 || ny>=N || nx<0 || nx>=N) continue;

        if(!visited[ny][nx] && backup[ny][nx]) dfs(ny, nx);
    }
}

int main(){
    scanf("%d",&N);

    for(int y=0; y<N; ++y){
        for(int x=0; x<N; ++x){
            scanf("%d",&map[y][x]);
        }
    }

    for(int y=0; y<N; ++y){
        for(int x=0; x<N; ++x){
            if(MAX<map[y][x]){
                MAX = map[y][x];
            }
        }
    }
    int result=1;

    for(int depth=1; depth<=MAX; ++depth){
        memset(visited, false, sizeof(visited));
        memset(backup, 0, sizeof(backup));
        copy(depth);
        int cnt=0;
        for(int y=0; y<N; ++y){
            for(int x=0; x<N; ++x){
                if(!visited[y][x] && backup[y][x]){
                    dfs(y,x);
                    cnt++;
                }
                
            }
        }
        result = max(result, cnt);
    } 

/*
    printf("\n");
    for(int y=0; y<N; ++y){
        for(int x=0; x<N; ++x){

            printf("%d ",map[y][x]);
        }
        printf("\n");
    }
*/
    
    printf("%d\n",result);

    return 0;
}
