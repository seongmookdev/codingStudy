//UTL: https://jaimemin.tistory.com/653
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int N,M, cnt;
int map[301][301];
int backup[301][310];
int melt_count;
bool visited[301][301];

const int dy[] = {+1, 0, -1, 0};
const int dx[] = {0, +1, 0, -1};

void dfs(int y, int x){
    visited[y][x] = true;

    for(int dir=0; dir<4; ++dir){
        int ny = y + dy[dir];
        int nx = x + dx[dir];

        if(ny<0 || ny>=N || dx<0 || nx>=N) continue;

        if(!visited[ny][nx] && backup[y][x]){
            dfs(ny, nx);
        }
    }
}

void melt(){

    int pos[4]={0,};
    int pos_count=0;
    for(int y=0; y<N; ++y){
        for(int x=0; x<M; ++x){
           pos[0] = map[y+1][x];
           pos[1] = map[y][x+1];
           pos[2] = map[y-1][x];
           pos[3] = map[y][x-1];

            for(int i=0; i<4; ++i)
               if(pos[i]==0) pos_count++;
       }
    } 
    

    for(int y=0; y<N; ++y){
        for(int x=0; x<M; ++x){
            map[y][x] -= pos_count;        
            if(backup[y][x]<0) backup[y][x]=0;
            map[y][x] = backup[y][x];
        }
    }

    printf("\n");    
    for(int y=0; y<N; ++y){
        for(int x=0; x<M; ++x){
            printf("%d ",backup[y][x]);
        }
        printf("\n");
    }    
    printf("\n");    

    melt_count++;
}

int main(){

    scanf("%d %d",&N, &M);
    for(int y=0; y<N; ++y){
        for(int x=0; x<M; ++x){
            scanf("%d",&map[y][x]);
            backup[y][x] = map[y][x];
        }
    }

    int j=3;
    while(j--){
        memset(visited, false, sizeof(visited));
        melt();
        cnt = 0;
        for(int y=0; y<N; ++y){
            for(int x=0; x<M; ++x){
                if(!visited[y][x] && backup[y][x]){
                    dfs(y, x);
                    cnt++;
                }
            }
        }
        /*
        if(cnt >= 2){
            printf("%d\n",melt_count);
        }
        else if(cnt == 1){
            printf("%d\n",0);
        }*/
    }                
   
    return 0;
}
