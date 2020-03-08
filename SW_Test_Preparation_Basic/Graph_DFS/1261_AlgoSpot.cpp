#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int N,M;
int map[101][101];
int broken[101][101];

const int dy[] = {+1, 0, -1, 0};
const int dx[] = {0, +1, 0, -1};

priority_queue<pair<int,pair<int, int>>> pq;

int main(){
    scanf("%d %d",&N, &M);
    memset(broken,-1, sizeof(broken));
    
    for(int y=0; y<M; ++y){
        for(int x=0; x<N; ++x){
            scanf("%1d", &map[y][x]);
        }
    }
    
    // 우선 순위 큐에 {벽을 부순 숫자, {좌표1, 좌표2}}
    // 즉, (좌표1, 좌표2)까지 이동하기 위해 부순 벽돌수를 저장
    
    pq.push({0,{0,0}});
    
    while(!pq.empty()){
        int broken_cnt = -pq.top().first;
        int y = pq.top().second.first;
        int x = pq.top().second.second;
        pq.pop();
        
        if(broken[y][x] != -1) continue;
        
        broken[y][x] = broken_cnt;
        
        for(int dir=0; dir<4; ++dir){
            int ny = y+dy[dir];
            int nx = x+dx[dir];
            
            if(ny<0 || ny>=M || nx<0 || nx>=N) continue;
            
            if(broken[ny][nx]==-1){
                if(map[ny][nx]==1){
                    pq.push({-(broken_cnt+1),{ny, nx}});
                }
                else{
                    pq.push({-broken_cnt, {ny, nx}});
                }
            }
        }
        
    }
    
    printf("%d\n",broken[M-1][N-1]);
    
    return 0;
}
