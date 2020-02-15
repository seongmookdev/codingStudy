#include <iostream>
using namespace std;

int n, m, k;

int map[51][51];
int visited[51][51];

const int dy[]={+1, 0, -1, 0};
const int dx[]={0, +1, 0, -1};

void dfs(int y, int x){

    visited[y][x]=1;

    for(int dir=0; dir<4; ++dir){
        int ny = y + dy[dir];
        int nx = x + dx[dir];

        if(ny<0 || ny>=n || nx<0 || nx>=m) continue;
        for(int y=0; y<m; ++y){
            for(int x=0; x<n; ++x){
                if(visited[ny][nx]==0 && map[ny][nx]==1){
                    dfs(ny, nx);
                    visited[ny][nx]=1;
                }
            }
        }
    }
    
}

int main(){

    int t;
    scanf("%d",&t);
    for(int tc=1; tc<=t; ++tc){
        
        scanf("%d %d %d",&n, &m, &k);
        for(int i=0; i<k; ++i){
            int a, b;
            scanf("%d %d",&a, &b);
            map[a][b] = 1;
        }
        int cnt=0;
        for(int y=0; y<m; ++y){
            for(int x=0; x<n; ++x){
                if(visited[y][x]==0 && map[y][x]==1){
                    dfs(y,x);
                    cnt++;
                }
            }
        }
        printf("%d\n",cnt);
    }   
    return 0;
}
