//URL: https://www.acmicpc.net/problem/

#include <iostream>
#include <queue>

using namespace std;

const int INF = 100001;
int N, K;
int dist[INF+1];

void bfs(){
    queue<int> q;
    q.push(N);
    
    while(!q.empty()){
        int x = q.front(); q.pop();
        if(x == K){
            printf("%d\n",dist[x]);
            return;
        }
               
        for(int nx : {2*x, x-1, x+1}){
            if(nx<0 || nx>INF) continue;
            if(dist[nx]) continue;
            q.push(nx);
            if(nx == 2*x)
                dist[nx] = dist[x];
            else{
                dist[nx] = dist[x] + 1;
            }
        }
    }
}

int main(){
    
    scanf("%d %d", &N, &K);
    bfs();
    return 0;
}
