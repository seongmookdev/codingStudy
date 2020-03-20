/*
URL: https://www.acmicpc.net/problem/3055

문제
사악한 암흑의 군주 이민혁은 드디어 마법 구슬을 손에 넣었고, 그 능력을 실험해보기 위해 근처의 티떱숲에 홍수를 일으키려고 한다. 이 숲에는 고슴도치가 한 마리 살고 있다. 고슴도치는 제일 친한 친구인 비버의 굴로 가능한 빨리 도망가 홍수를 피하려고 한다.

티떱숲의 지도는 R행 C열로 이루어져 있다. 비어있는 곳은 '.'로 표시되어 있고, 물이 차있는 지역은 '*', 돌은 'X'로 표시되어 있다. 비버의 굴은 'D'로, 고슴도치의 위치는 'S'로 나타내어져 있다.

매 분마다 고슴도치는 현재 있는 칸과 인접한 네 칸 중 하나로 이동할 수 있다. (위, 아래, 오른쪽, 왼쪽) 물도 매 분마다 비어있는 칸으로 확장한다. 물이 있는 칸과 인접해있는 비어있는 칸(적어도 한 변을 공유)은 물이 차게 된다. 물과 고슴도치는 돌을 통과할 수 없다. 또, 고슴도치는 물로 차있는 구역으로 이동할 수 없고, 물도 비버의 소굴로 이동할 수 없다.

티떱숲의 지도가 주어졌을 때, 고슴도치가 안전하게 비버의 굴로 이동하기 위해 필요한 최소 시간을 구하는 프로그램을 작성하시오.

고슴도치는 물이 찰 예정인 칸으로 이동할 수 없다. 즉, 다음 시간에 물이 찰 예정인 칸으로 고슴도치는 이동할 수 없다. 이동할 수 있으면 고슴도치가 물에 빠지기 때문이다. 

입력
첫째 줄에 50보다 작거나 같은 자연수 R과 C가 주어진다.

다음 R개 줄에는 티떱숲의 지도가 주어지며, 문제에서 설명한 문자만 주어진다. 'D'와 'S'는 하나씩만 주어진다.

출력
첫째 줄에 고슴도치가 비버의 굴로 이동할 수 있는 가장 빠른 시간을 출력한다. 만약, 안전하게 비버의 굴로 이동할 수 없다면, "KAKTUS"를 출력한다.

예제 입력 1 
3 3
D.*
...
.S.
예제 출력 1 
3
예제 입력 2 
3 3
D.*
...
..S
예제 출력 2 
KAKTUS
예제 입력 3 
3 6
D...*.
.X.X..
....S.
예제 출력 3 
6
예제 입력 4 
5 4
.D.*
....
..X.
S.*.
....
예제 출력 4 
4
*/

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
