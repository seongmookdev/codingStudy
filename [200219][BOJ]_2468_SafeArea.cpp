//URL: https://www.acmicpc.net/problem/2468
#include <iostream>
#include <algorithm>
#include <cstring> //memset

using namespace std;

const int dy[] = {+1, 0, -1, 0};
const int dx[] = {0, +1, 0, -1};

int area[101][101];
int temp[101][101];
bool visited[101][101];
int N;

void copy(int depth){
    for(int y=0; y<N; ++y){
        for(int x=0; x<N; ++x){
            if(area[y][x] > depth) temp[y][x] = area[y][x];
        }
    }   
}

void dfs(int y, int x){

    visited[y][x] = true;

    for(int dir=0; dir<4; ++dir){
        int ny = y + dy[dir];
        int nx = x + dx[dir];

        if(ny<0 || ny>=N || nx<0 || nx>=N) continue;

        if(!visited[ny][nx] && temp[ny][nx]) dfs(ny, nx);
    }
}


int main(){

    scanf("%d", &N);
    for(int y=0; y<N; ++y){
        for(int x=0; x<N; ++x){
            scanf("%d", &area[y][x]);
        }
    }

    int MAX = 0;
    for(int y=0; y<N; ++y){
        for(int x=0; x<N; ++x){
            if(MAX<area[y][x]) MAX=area[y][x];
        }
    }    

    int result = 1;

    for(int depth=1; depth<=MAX; depth++){
        memset(visited, false, sizeof(visited));
        memset(temp, 0, sizeof(temp));
        copy(depth);    //area --> temp

        int cnt=0;
        for(int y=0; y<N; ++y){
            for(int x=0; x<N; ++x){
                if(!visited[y][x] && temp[y][x]){
                    dfs(y,x);
                    cnt++;
                }
            }
        }
        printf("cnt=%d\n",cnt);
        result = max(result, cnt);
    }

    printf("%d\n",result);

    return 0;
}
