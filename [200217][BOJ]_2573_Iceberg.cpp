#include <stdio.h>
#include <algorithm>
#include <iostream>
using namespace std;

int n, m,cnt;
int map[301][301];
int backup[301][301];
int visited[301][301];
int result[101];

const int dy[] = {+1, 0, -1, 0};
const int dx[] = {0, +1, 0, -1};

void map_update(){

    int pos_cnt=0;
    int pos[4]={0,};
    for(int y=1; y<n-1; ++y){
        for(int x=1; x<m-1; ++x){
            pos[0] = map[y-1][x];
            pos[1] = map[y+1][x];
            pos[2] = map[y][x-1];
            pos[3] = map[y][x+1];
        
            for(int i=0; i<4; ++i){
                if(pos[i] == 0) pos_cnt++;
            }
            backup[y][x] -= pos_cnt;
            if(backup[y][x] <0) backup[y][x] = 0;
            pos_cnt=0;
        }
    }
    /*
    printf("\n");
    for(int y=0; y<n; ++y){
        for(int x=0; x<m; ++x){
            printf("%d ",backup[y][x]);
        }
    printf("\n");
    }*/

    for(int y=1; y<n-1; ++y){
        for(int x=1; x<m-1; ++x){
            map[y][x] = backup[y][x];
        }
    }        
}

void dfs(int y, int x){

    map_update();
    visited[y][x] = 1;
    
    for(int dir=0; dir<4; ++dir){
        int ny = y + dy[dir];
        int nx = x + dx[dir];

        if(ny<0 || ny >= n || nx<0 || nx>=0) continue;

        for(int y=0; y<n; ++y){
            for(int x=0; x<m; ++x){
                if(visited[ny][nx]==0 && backup[ny][nx]!=0){
                    dfs(ny,nx);
                }
            }
        }
    }
}

int main(){

    scanf("%d %d", &n, &m);
    for(int y=0; y<n; ++y){
        for(int x=0; x<m; ++x){
            scanf("%d", &map[y][x]);
            backup[y][x] = map[y][x];
        }
    }

    for(int y=0; y<n; ++y){
        for(int x=0; x<m; ++x){
            if(visited[y][x]==0 && backup[y][x]!=0){
                dfs(y,x);
                cnt++;
                printf("%d\n",cnt);
            }
        }
    }
    return 0;
}
