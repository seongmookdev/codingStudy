#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int N, M;
char map[51][51];
int waterMap[51][51];
bool visited[51][51];

const int dy[] = {+1, 0, -1, 0};
const int dx[] = {0, +1, 0, -1};

pair<int, int>SP, EP;
queue<pair<int, int>> WQ;

void makeWater(){
    while(!WQ.empty()){
        int y = WQ.front().first;
        int x = WQ.front().second;
        WQ.pop();
        
        for(int dir=0; dir<4; ++dir){
            int ny = y + dy[dir];
            int nx = x + dx[dir];
            
            if(ny<0 || ny>=N || nx<0 || nx>=M) continue;
            
            if(map[ny][nx] == '.'){
                if(waterMap[ny][nx] > waterMap[y][x]+1){
                    waterMap[ny][nx] = waterMap[y][x]+1;
                    WQ.push(make_pair(ny, nx));
                }
            }
        }
    }
}

void move(){
    queue<pair<pair<int, int>, int>> q;
    q.push(make_pair(make_pair(SP.first, SP.second), 0));
    
    while(!q.empty()){
        int y = q.front().first.first;
        int x = q.front().first.second;
        int cnt = q.front().second;
        q.pop();
        
        if(y == EP.first && x == EP.second){
            printf("%d\n", cnt);
            return;
        }
        
        for(int dir=0; dir<4; ++dir){
            int ny = y + dy[dir];
            int nx = x + dx[dir];
            
            if(ny<0 || ny>=N || nx<0 || nx>=M) continue;
            
            if(visited[ny][nx]==false && map[ny][nx] != 'X' && waterMap[ny][nx] > cnt+1){
                visited[ny][nx] = true;
                q.push(make_pair(make_pair(ny, nx), cnt+1));
            }
        }
    }
    printf("KAKTUS\n");
}

int main(){
    
    scanf("%d %d", &N, &M);
    for(int y=0; y<N; ++y){
        for(int x=0; x<M; ++x){
            waterMap[y][x] = 999;
        }
    }
    
    for(int y=0; y<N; ++y){
        for(int x=0; x<M; ++x){
            scanf(" %1c", &map[y][x]);
            
            if(map[y][x] == 'S'){
                SP.first = y;
                SP.second = x;
            }
            
            else if(map[y][x] == 'D'){
                EP.first = y;
                EP.second = x;
            }
            
            else if(map[y][x] == '*'){
                waterMap[y][x] = 0;
                WQ.push(make_pair(y, x));
            }
        }
    }
    
    makeWater();
    move();
}
