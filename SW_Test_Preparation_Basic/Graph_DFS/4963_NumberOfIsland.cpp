#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int N, M, cnt;
int map[51][51];
bool visited[51][51];

const int dy[] = {-1, -1, -1, 0, 0, +1, +1, +1};
const int dx[] = {-1, 0, +1, -1, +1, -1, 0, +1};

void dfs(int y, int x){
    visited[y][x] = true;
    
    for(int dir=0; dir<8; ++dir){
        int ny = y+dy[dir];
        int nx = x+dx[dir];
        
        if(ny<0 || ny>=M || nx<0 || nx>=N) continue;
        if(visited[ny][nx]==false && map[ny][nx]==1)        dfs(ny, nx);
    }
    
    
}

int main(){
    
    while(1){
    
        scanf("%d %d", &N, &M);
        if(N==0 && M==0) break;
        
        memset(visited, false, sizeof(visited));
        memset(map, 0, sizeof(map));
        cnt = 0;
        
        for(int y=0; y<M; ++y){
            for(int x=0; x<N; ++x){
                scanf("%d", &map[y][x]);
            }
        }
        
        for(int y=0; y<M; ++y){
            for(int x=0; x<N; ++x){
                if(visited[y][x]==false && map[y][x]==1){
                    dfs(y,x);
                    cnt++;
                }
            }
        }
        printf("%d\n",cnt);
    }
    return 0;
}
