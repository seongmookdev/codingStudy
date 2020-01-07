#include <stdio.h>
#include <algorithm>
#include <queue>
using namespace std;

struct POSI{
    int y, x;
};

int n, l, r;
int map[50][50];

void create_area(int sy, int sx, int status[][50], int index, int& count, int& sum){
    int visited[50][50] = {0, };

    const int dy[] = {0, 0, -1, +1};
    const int dx[] = {-1, +1, 0, 0};

    queue<POSI>q;
    POSI head;
    head.y = sy;
    head.x = sx;
    visited[sy][sx] = 1;
    q.push(head);

    while(!q.empty()){
        POSI cur = q.front(); q.pop();

        status[cur.y][cur.x] = index;
        ++count;
        sum+= map[cur.y][cur.x];

        for(int dir=0; dir<4; ++dir){
            POSI next;
            next.y = cur.y + dy[dir];
            next.x = cur.x + dx[dir];
            
            if(next.y<0 || next.y>=n || next.x<0 || next.x>=n){
                continue;
            }

            int delta = abs(map[cur.y][cur.x] - map[next.y][next.x]);
            if(visited[next.y][next.x] == 0 && l <= delta&&delta<=r){
                visited[next.y][next.x] = 1; 
                q.push(next);
            }
        }
    }
}

int main(){

    scanf("%d %d %d", &n, &l, &r);
    for(int y = 0; y<n; ++y){
        for(int x=0; x<n; ++x){
            scanf("%d", &map[y][x]);
        }
    }

    int ret = 0;
    bool is_update = true;
    while(is_update){
        is_update = false;

        int status[50][50] = {0,};
        int area_index = 0;
        int count[2501] = {0,};
        int sum[2501] = {0,};
        for (int y=0; y<n; ++y){
            for(int x=0; x<n; ++x){
                if(status[y][x] == 0){
                    ++area_index;
                    create_area(y, x, status, area_index, count[area_index], sum[area_index]);
                }

            }
        }
        for(int y=0;  y<n; ++y){
            for(int x=0; x<n; ++x){
                int index = status[y][x]; // status에 있는 나라가 몇번째인지
                int avg = sum[index]/count[index];
                if(map[y][x] != avg){           //인구이동을 하지 않았으면
                    map[y][x] = avg;            //인구이동
                    is_update = true;
                }
            }
        }
        if(is_update)
        {
            ++ret;
        }
    }
    printf("%d\n", ret);
    return 0;
}

