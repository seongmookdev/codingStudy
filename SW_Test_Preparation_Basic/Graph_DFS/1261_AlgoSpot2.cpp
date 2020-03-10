#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int N, M, Answer;
int map[101][101];
int broken[101][101];

const int dy[] = {+1, 0, -1, 0};
const int dx[] = {0, +1, 0, -1};

void bfs(int y, int x){
    queue<pair<int, int>> q;
    q.push(make_pair(y,x));
    broken[y][x] = 0;
    
    while(!q.empty()){
        int y = q.front().first;
        int x = q.front().second;
        q.pop();
        
        for(int dir=0; dir<4; ++dir){
            int ny = y + dy[dir];
            int nx = x + dx[dir];
            
            if(ny<0 || ny>=M || nx<0 || nx>=N) continue;
            
            
            if(map[ny][nx]==1){
                if(broken[ny][nx] > broken[y][x]+1){
                    broken[ny][nx] = broken[y][x]+1;
                    q.push(make_pair(ny, nx));
                }
            }
            
            else if(map[ny][nx]==0){
                if(broken[ny][nx] > broken[y][x]){
                    broken[ny][nx] = broken[y][x];
                    q.push(make_pair(ny, nx));
                }
            }
        }
    }
}

int main(){
    
    scanf("%d %d", &N, &M);
    for(int y=0; y<M; ++y){
        for(int x=0; x<N; ++x){
            scanf("%1d", &map[y][x]);
            broken[y][x] = 98765432;
        }
    }
    
    bfs(0, 0);

    printf("%d\n", broken[M-1][N-1]);
    
    return 0;
}
