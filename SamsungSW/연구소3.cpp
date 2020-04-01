#include <iostream>
#include <queue>
#include <vector>
#include <cstring>

using namespace std;

int map[50][50];
int dist[50][50];
bool sel[10];

int n, m, k;
int ans = 1e9;
struct INFO {
    int y;
    int x;
};

vector<INFO> virus;
queue<INFO> q;

const int dy[] = {+1, 0, -1, 0};
const int dx[] = {0, +1, 0, -1};

void bfs(){
    
    int infect = 0, times = 0;
    while(!q.empty()){
        int y = q.front().y;
        int x = q.front().x;
        q.pop();

        for(int dir=0; dir<4; ++dir){
            int ny = y+dy[dir];
            int nx = x+dx[dir];

            if(ny<0 || ny>=n || nx<0 || nx>=n) continue;

            if(map[ny][nx] != 1 && dist[ny][nx] == -1){
                dist[ny][nx] = dist[y][x] + 1;
                if(map[ny][nx] == 0){
                    infect += 1;
                    times = dist[ny][nx];
                }
                q.push({ny, nx});
            }
        }
    }
    if(infect == k && ans > times)    ans = times;
}

void dfs(int idx, int cnt, int size){
    if(cnt == m){
        memset(dist, -1, sizeof(dist));
        for(int i=0; i<size; ++i){
            if(sel[i]){
                q.push({virus[i].y, virus[i].x});           //VIRUS 위치를 큐에 넣기
                dist[virus[i].y][virus[i].x] = 0;           //Virus 위치를 0으로
            }
        }
        bfs();     //M개 뽑았으면 거기서 확산시킬 때까지의 시간 구하기.
        return;
    }

    for(int i=idx; i<size; ++i){
        if(!sel[i]){      //선택되지 않으면,
            sel[i] = true;
            dfs(i+1, cnt+1, size);
            sel[i] = false;
        }
        
    }
}

int main(){

    scanf("%d %d", &n, &m);
    for(int y=0; y<n; ++y){
        for(int x=0; x<n; ++x){
            scanf("%d", &map[y][x]);
            if(map[y][x] == 2) virus.push_back({y, x});
            if(map[y][x] == 0) k += 1;
        }
    }

    dfs(0, 0, virus.size());                  //VIRUS 개수 중에서 M개 뽑기
    printf("%d\n", ans==1e9 ? -1 : ans);
    //printf("%d\n", ans);
    return 0;
}
