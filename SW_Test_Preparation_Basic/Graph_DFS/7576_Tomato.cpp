#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int N, M, cnt;
int map[1001][1001];
bool visited[1001][1001];

struct col{
    int y;
    int x;
};
queue<col> q;

const int dy[] = {+1, 0, -1, 0};
const int dx[] = {0, +1, 0, -1};

int bfs(){
    
    int ans=1;
    while(!q.empty()){
        long s = q.size();
        for(int i=0; i<s; ++i){
            col c1 = q.front();
            int y = c1.y;
            int x = c1.x;
            q.pop();
            
            if(visited[y][x]==true) continue;
            else visited[y][x] = true;
            
            for(int dir=0; dir<4; ++dir){
                int ny = y+dy[dir];
                int nx = x+dx[dir];
                
                if(ny<0 || ny>=M || nx<0 || nx>=N) continue;
                else if(map[ny][nx]==-1) continue;
                else if(map[ny][nx]==0){
                    q.push({ny, nx});
                    map[ny][nx]=1;
                    cnt--;
                }
                if(cnt==0) return ans;
            }
        }
        ans++;
    }
    return -1;
}

int main(){
    scanf("%d %d", &N, &M);
    for(int y=0; y<M; ++y){
        for(int x=0; x<N; ++x){
            scanf("%d", &map[y][x]);
            if(map[y][x]==1) q.push({y,x});
            else if(map[y][x]==0) cnt++;
        }
    }
    if(cnt==0){
        printf("%d\n",0);
        return 0;
    }
    printf("%d\n",bfs());
    
    return 0;
}
