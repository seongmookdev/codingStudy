//URL: https://www.acmicpc.net/problem/
//REF: https://rebas.kr/656

#include <iostream>
#include <queue>

using namespace std;

const int INF = 100001;
int N, K;
int dist[INF];

void bfs(){
    queue<int> q;
    q.push(N);
    
    while(!q.empty()){
        int x = q.front();
        q.pop();
    
        if(x == K){
            printf("%d\n",dist[x]);
            break;
        }
        
        for(int nx : {x+1, x-1, x*2}){
            if(nx<0 || nx>=INF) continue;
            if(dist[nx]) continue;
            q.push(nx);
            dist[nx] = dist[x] + 1;
        }
    }
    
}

int main(){
    
    scanf("%d %d", &N, &K);
    bfs();
    return 0;
}
