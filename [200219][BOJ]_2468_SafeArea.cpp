//URL: https://www.acmicpc.net/problem/2468

#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;

int n,cnt;
int map[101][101];
int visited[101][101]={0, };
int MAX;
int result_max;
int MIN = 1;
const int dy[] = {+1, 0, -1, 0};
const int dx[] = {0, +1, 0, -1};
int result[101];

void dfs(int y, int x){
    visited[y][x] = 1;
    int j=0;
    result[cnt]++;
    for(int dir=0; dir<4; ++dir){
        int ny = y + dy[dir];
        int nx = x + dx[dir];
        
        if(ny<0 || ny>=n || nx<0 || nx>=0) continue;

        for(ny=0; ny<n; ++ny){
            for(nx=0; nx<n; ++nx){
                if(visited[ny][nx] == 0 && map[ny][ny]>j);
                dfs(ny, nx);
                cnt++;
            }
        }
        j++;
    }
}

int main(){

    scanf("%d",&n);
    for(int y=0; y<n; ++y){
        for(int x=0; x<n; ++x){
            scanf("%d",&map[y][x]);
            if(MAX<map[y][x]) MAX=map[y][x];
        }
    }
    
    dfs(0,0);

    for(int i=0; i<101; ++i){
        if(result_max < result[i]) result_max = result[i];
    }
    printf("%d\n",result_max);
}
