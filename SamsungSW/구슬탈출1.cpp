#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

struct INFO{
    int ry, rx, by, bx, count;
};
INFO start;

char map[11][11];
bool visited[11][11][11][11];

const int dy[] = {+1, 0, -1, 0};
const int dx[] = {0, +1, 0, -1};

int bfs(){
    int ret = 0;
    queue<INFO> q;
    q.push(start);
    visited[start.ry][start.rx][start.by][start.bx] = true;
    
    
    while(!q.empty()){
        INFO cur = q.front(); q.pop();
        if(cur.count > 10) break;
        if(map[cur.ry][cur.rx] == 'O' && map[cur.by][cur.bx] != 'O'){
            ret = 1;
            break;
        }
                
        for(int dir=0; dir<4; ++dir){
            int next_ry = cur.ry;
            int next_rx = cur.rx;
            int next_by = cur.by;
            int next_bx = cur.bx;
            
            while(1){
                if(map[next_ry][next_rx] != '#' && map[next_ry][next_rx] != 'O'){
                    next_ry += dy[dir];
                    next_rx += dx[dir];
                }
                else{
                    if(map[next_ry][next_rx] == '#'){
                        next_ry -= dy[dir];
                        next_rx -= dx[dir];
                    }
                    break;
                }
            }
            
            while(1){
                if(map[next_by][next_bx] != '#' && map[next_by][next_bx] != 'O'){
                    next_by += dy[dir];
                    next_bx += dx[dir];
                }
                else{
                    if(map[next_by][next_bx] == '#'){
                        next_by -= dy[dir];
                        next_bx -= dx[dir];
                    }
                    break;
                }
            }
            
            if(map[next_ry][next_rx] == map[next_by][next_bx]){
                int red_dist = abs(next_ry-cur.ry) + abs(next_rx-cur.rx);
                int blue_dist = abs(next_by-cur.by) + abs(next_bx-cur.bx);
                
                if(red_dist > blue_dist){
                    next_ry -= dy[dir];
                    next_rx -= dx[dir];
                }
                else{
                    next_by -= dy[dir];
                    next_bx -= dx[dir];
                }
            }
            
            if(visited[next_ry][next_rx][next_by][next_bx] == false){
                visited[next_ry][next_rx][next_by][next_bx] = true;
                INFO next;
                next.ry = next_ry;
                next.rx = next_rx;
                next.by = next_by;
                next.bx = next_bx;
                next.count = cur.count + 1;
                q.push(next);
            }
        }
    }
    
    return ret;
}

int main(){
    
    int N, M;
    scanf("%d %d", &N, &M);
    for(int y=0; y<N; ++y){
        for(int x=0; x<M; ++x){
            scanf(" %1c",&map[y][x]);
            
            if(map[y][x] == 'R'){
                start.ry = y;
                start.rx = x;
            }
            if(map[y][x] == 'B'){
                start.by = y;
                start.bx = x;
            }
        }
    }
    
    start.count = 0;
    int ret = bfs();
    printf("%d\n", ret);
    
    return 0;
}
