//URL: https://www.acmicpc.net/problem/1012

#include <iostream>
#include <cstring>

int n, m, k;
int map[51][51];
bool visited[51][51];

const int dy[] = {+1, 0, -1, 0};
const int dx[] = {0, +1, 0, -1};

void dfs(int y, int x){
    visited[y][x] = true;
    
    for(int dir=0; dir<4; ++dir){
        int ny = y + dy[dir];
        int nx = x + dx[dir];
        
        if(ny<0 || ny>=n || nx<0 || nx>=m) continue;
        
        if(visited[ny][nx]==false && map[ny][nx] == 1){
            visited[ny][nx] = true;
            dfs(ny, nx);
        }
    }
    
}

int main(){
    
    int tc=0;
    int cnt=0;
    scanf("%d", &tc);
    for(int i=1; i<=tc; ++i){
        memset(map, 0, sizeof(map));
        memset(visited, false, sizeof(visited));
        cnt = 0;
        scanf("%d %d %d", &m, &n, &k);
        
        for(int i=0; i<k; ++i){
            int x, y;
            scanf("%d %d", &x, &y);
            map[y][x] = 1;
        }
        
        for(int y=0; y<n; ++y){
            for(int x=0; x<m; ++x){
                if(visited[y][x]==false && map[y][x] == 1){
                    dfs(y, x);
                    cnt++;
                }
            }
        }
        printf("%d\n", cnt);
    }
    
    return 0;
}
