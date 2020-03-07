//
//  main.cpp
//  MazeSearch.cpp
//
//  Created by SEONGMOOK LIM on 2020/03/07.
//  Copyright © 2020 SEONGMOOK LIM. All rights reserved.
//

#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int N, M, cnt;
int map[101][101];
int visited[101][101];


const int dy[] = {+1, 0, -1, 0};
const int dx[] = {0, +1, 0, -1};
int res = 1000000;

void bfs(int y, int x){
    queue<pair<int, int>>q;
    q.push(make_pair(y, x));
    visited[y][x]=1;
 
    while(!q.empty()){
        y = q.front().first;
        x = q.front().second;
        q.pop();
        
        for(int dir=0; dir<4; ++dir){
            int ny = y+dy[dir];
            int nx = x+dx[dir];
            
//            if(ny==N-1 && nx==M-1) break;
            
            if(ny<0 || ny>=N || nx<0 || nx>=M) continue;
            
            if(visited[ny][nx]==0 && map[ny][nx]==1){
                q.push(make_pair(ny,nx));
                visited[ny][nx]=visited[y][x]+1;
            }
            //else if(visited[ny][nx]==0) visited[ny][nx] = -1;
        }
    }
}

int main(){
    
    scanf("%d %d",&N, &M);
    for(int y=0; y<N; ++y){
        for(int x=0; x<M; ++x){
            scanf("%1d",&map[y][x]);
        }
    }

    bfs(0, 0);
    
    printf("%d\n",visited[N-1][M-1]);
}
