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
int ans;

void dfs(int y, int x){

    visited[y][n]=1;
    printf("\n");
    for(int y=0; y<n; ++y){
        for(int x=0; x<m; ++x){
            printf("%d ",visited[y][x]);
        }
        printf("\n");
    }
    result[cnt]++;

    if(cnt == 1){
        printf("%d",result[0]);        
        return;
    }

    for(int dir=0; dir<4; ++dir){

        int ny = y + dy[dir];
        int nx = x + dx[dir];
        int pos_cnt=0;
        int pos[4]={0,};

        if(ny<0 || ny>=n || nx<0 || nx>=m) continue;

        pos[0] = backup[ny-1][nx];
        pos[1] = backup[ny+1][nx];
        pos[2] = backup[ny][nx-1];
        pos[3] = backup[ny][nx+1];
        for(int i=0; i<4; ++i){
            if(pos[i] == 0) pos_cnt++;
        }

        for(int y=0; y<n; ++y){
            for(int x=0; x<m; ++x){
                if(visited[ny][nx]==0 && backup[ny][nx]!=0){
                    backup[ny][nx] -= pos_cnt;
                    if(backup[ny][nx]<=0) backup[ny][nx] = 0;
                    dfs(ny, nx);
//                    visited[ny][nx]=1;
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

    /*
    for(int y=0; y<n; ++y){
        for(int x=0; x<m; ++x){
            printf("%d ",backup[y][x]);
        }
        printf("\n");
    }
    */

    for(int y=0; y<n; ++y){
        for(int x=0; x<m; ++x){
            if(visited[y][x]==0 && backup[y][x]!=0){
                dfs(y,x);
                cnt++;
            }
        }
    }

    return 0;
}
