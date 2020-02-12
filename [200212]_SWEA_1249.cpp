//URL: https://swexpertacademy.com/main/code/problem/problemDetail.do

#include<stdio.h>
#include<queue>
#include<algorithm>
#include<iostream>
using namespace std;

int n;
int map[100][100];
int dist[100][100];
const int dy[] = {+1,0,-1,0};
const int dx[] = {0,+1,0,-1};


void bfs(){
    printf("bfs\n");

    queue<pair<int,int>> q;
    q.push(make_pair(0,0));

    while(!q.empty()){

        int y = q.front().first;
        int x = q.front().second;
        q.pop();

        for(int dir=0; dir<4; ++dir){
            int ny = y + dy[dir];
            int nx = x + dx[dir];
        
            if(ny<0 || ny>=n || nx<0 || nx>=n){
                continue;
            } 

            int ndist = map[ny][nx] + dist[y][x];

            if(ndist < dist[ny][nx]){
                q.push(make_pair(ny,nx));
                dist[ny][nx] = ndist;
            }
        }
    }
    return;
}

int main(){

    int t;
    scanf("%d",&t);
    for(int tc=1; tc<=t; ++tc){
        scanf("%d",&n);
        for(int i=0; i<n; ++i){
            for(int j=0; j<n; ++j){
                scanf("%1d",&map[i][j]);
                dist[i][j] = 9999999;
            }
        }
        dist[0][0] = 0;
        bfs();
        printf("#%d %d\n",tc,dist[n-1][n-1]);
    }
    return 0;
}
