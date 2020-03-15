#include <iostream>
#include <queue>

using namespace std;

int N,M;
int MAP[1001][1001];
bool VISITED[1001][1001][2];

const int dy[] = {+1, 0, -1, 0};
const int dx[] = {0, +1, 0, -1};

int bfs(){
    
    queue<pair<pair<int, int>, pair<int, int>>> q;
    q.push(make_pair(make_pair(0,0),make_pair(0,1)));   //y, x, B, cnt
    VISITED[0][0][0] = true;
        
    while(!q.empty()){
        int y = q.front().first.first;
        int x = q.front().first.second;
        int b = q.front().second.first;
        int cnt = q.front().second.second;
        q.pop();
        
        if(y == N-1 && x == M-1) return cnt;
        
        for(int dir=0; dir<4; ++dir){
            int ny = y + dy[dir];
            int nx = x + dx[dir];
            
            if(ny<0 || ny>=N || nx<0 || nx>=M) continue;
            
            if(MAP[ny][nx] == 1 && b == 0){
                VISITED[ny][nx][b+1] = true;
                q.push(make_pair(make_pair(ny, nx),make_pair(b+1, cnt+1)));
            }
            else if(VISITED[ny][nx][b] == false && MAP[ny][nx] == 0){
                VISITED[ny][nx][b] = true;
                q.push(make_pair(make_pair(ny, nx), make_pair(b, cnt+1)));
            }
        }
        
        
    }
    
    
    
    return -1;
}

int main(){
    
    scanf("%d %d", &N, &M);
    for(int y=0; y<N; ++y){
        for(int x=0; x<M; ++x){
            scanf("%1d", &MAP[y][x]);
        }
    }
    
    printf("%d\n", bfs());
    
    return 0;
}
