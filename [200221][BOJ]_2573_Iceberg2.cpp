#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cstring>

using namespace std;

int N, M;
int map[301][301];
bool visited[301][301];

const int dy[] = {+1, 0, -1, 0};
const int dx[] = {0, +1, 0, -1};

void melt(void){
    int remap[301][301];
    for(int y=0; y<N; ++y){
        for(int x=0; x<M; ++x){
            remap[y][x] = map[y][x];
        }
    }

    for(int y=1; y<N-1; ++y){
        for(int x=1; x<M-1; ++x){
            if(remap[y][x]){
                int cnt = 0;
                for(int dir=0; dir<4; ++dir){
                    int ny = y+dy[dir];
                    int nx = x+dx[dir];

                    if(remap[ny][nx] == 0) cnt++;
                }
                map[y][x] = max(remap[y][x]-cnt, 0);
            }
        }
    }
}

void dfs(int y, int x){
    visited[y][x] = true;

    for(int dir=0; dir<4; ++dir){
        int ny = y + dy[dir];
        int nx = x + dx[dir];

        if(ny<1 || ny>=N-1 || nx<1 || nx>=M-1) continue;
        if(visited[ny][nx]==false && map[ny][nx]){
            dfs(ny, nx);
        }
    }

}

int main(){

    scanf("%d %d", &N, &M);
    for(int y=0; y<N; ++y){
        for(int x=0; x<M; ++x){
            scanf("%d",&map[y][x]);
        }
    }

    int year=0;
    while(1){
        memset(visited, false, sizeof(visited));
        bool result = false;
        int cnt=0;
        for(int y=1; y<N-1; ++y){
            for(int x=1; x<M-1; ++x){
                if(map[y][x] && visited[y][x] == false){
                    cnt++;
                    printf("cnt==%d\n",cnt);
                    if(cnt == 2){
                        result = true;
                        break;
                    }
                    dfs(y, x);
                }
            }
        }

        if(result){
            printf("2\n");
            break;
        }
        if(cnt == 0){
            printf("3\n");
            year = 0;
            break;
        }

        melt();
        year++;
    }

    printf("%d\n", year);
    return 0;
}
