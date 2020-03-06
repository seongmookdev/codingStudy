#include <iostream>
#include <algorithm>

using namespace std;

int N,cnt;
int map[26][26];
bool visited[26][26];
int result[1001];

const int dy[] = {+1,0,-1,0};
const int dx[] = {0,+1,0,-1};

void dfs(int y, int x){
    visited[y][x] = true;
    result[cnt]++;
    
    for(int dir=0; dir<4; ++dir){
        int ny = y + dy[dir];
        int nx = x + dx[dir];
        
        if(ny<0 || ny>= N || nx<0 || nx>=N) continue;
              
        if(visited[ny][nx]==false && map[ny][nx]==1){
            dfs(ny, nx);
        }
    }
}

int main(){
    
    scanf("%d", &N);
    for(int y=0; y<N; ++y){
        for(int x=0; x<N; ++x){
                scanf("%1d",&map[y][x]);
        }
    }
    
    for(int y=0; y<N; ++y){
        for(int x=0; x<N; ++x){
            if(visited[y][x]==false && map[y][x]==1){
                dfs(y, x);
                cnt++;
            }
        }
    }
    
    printf("%d\n",cnt);
    sort(result, result+cnt);
    for(int i=0; i<cnt; ++i) printf("%d\n",result[i]);
    
    return 0;
}
