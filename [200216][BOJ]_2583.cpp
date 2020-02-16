#include <iostream>
#include <stdio.h>
#include <algorithm>

using namespace std;

int n, m, k;
int map[101][101];
int visited[101][101];
int cnt;
int result[10001];

const int dy[]={+1, 0, -1, 0};
const int dx[]={0, +1, 0, -1};

void dfs(int y, int x){

    visited[y][x] = 1;
    result[cnt]++;
    
    for(int dir=0; dir<4; ++dir){
        int ny = y + dy[dir];
        int nx = x + dx[dir];

        if(ny<0 || ny>=n || nx<0 || nx>=m) continue;

        for(int y=0; y<n; ++y){
            for(int x=0; x<m; ++x){
                if(visited[ny][nx]==0 && map[ny][nx]==0){
                    dfs(ny, nx);
//                    visited[ny][nx]=1;
                }
            }
        }
    }
    
}

int main(){

    scanf("%d %d %d",&n, &m, &k);
    int x1, y1, x2, y2;
    for(int i=0; i<k; ++i){
        scanf("%d %d %d %d",&x1, &y1, &x2, &y2);
        for(int y=y1; y<y2; ++y){
            for(int x=x1; x<x2; ++x){
                map[y][x] = 1;               
            }
        }
    }

    for(int y=0; y<n; ++y){
        for(int x=0; x<m; ++x){
            printf("%d ",map[y][x]);
        }
        printf("\n");
    }

    for(int y=0; y<n; ++y){
        for(int x=0; x<m; ++x){
            if(visited[y][x]==0 && map[y][x]==0){
                dfs(y,x);
                cnt++;
            }
        }
    }

    printf("%d\n",cnt);
    sort(result, result+cnt);
    for(int i=0; i<cnt; ++i) printf("%d ",result[i]);
    

    return 0;
}
