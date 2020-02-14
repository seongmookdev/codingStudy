#include <iostream>
#include <algorithm>

using namespace std;

int map[26][26];
int visited[26][26];
int result[1010];
int cnt;
int n;

const int dy[] = {+1, 0, -1, 0};
const int dx[] = {0, +1, 0, -1};

void dfs(int y, int x){
    visited[y][x] = 1;
    result[cnt]++;

    for(int dir=0; dir<4; ++dir){
        int ny = y + dy[dir];
        int nx = x + dx[dir];

        if(ny<0 || ny>=n || nx<0 || nx>=n) continue;

        for(int y=0; y<n; ++y){
            for(int x=0; x<n; ++x){
                if(visited[ny][nx]==0 && map[ny][nx]==1){
                    dfs(ny,nx);
                }
            }
        }
    }   
}


int main(){
    
    scanf("%d",&n);
    for(int y=0; y<n; ++y){
        for(int x=0; x<n; ++x){
            scanf("%1d",&map[y][x]);
        }
    }

    for(int y=0; y<n; ++y){
        for(int x=0; x<n; ++x){
            if(visited[y][x]==0 && map[y][x]==1){
                dfs(y,x);
                cnt++;
            }
        }
    }
    printf("%d\n",cnt);
    sort(result, result+cnt);
    for(int i=0; i<cnt; ++i) printf("%d\n",result[i]);
}
