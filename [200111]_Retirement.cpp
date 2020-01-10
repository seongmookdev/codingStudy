#include<stdio.h>
#include<algorithm>
using namespace std;

int n;
int T[15], P[15];
int cache[15];

int solve(int day){

    if(day>n) return -12920222;
    if(day==n) return 0;

    int& ret = cache[day];                  //값이 계속 업데이트 되어야 하니까 ref
    if(ret != -1)     return ret;           //이전에 구했으면 그 값을 return
    ret = max(solve(day+1), solve(day+T[day])+P[day]);
    
    return ret;
}

int main(){

    scanf("%d",&n);
    for(int i=0; i<n; ++i){
        scanf("%d %d",&T[i], &P[i]);
        cache[i] = -1;
    }

    int ret = solve(0);
    printf("%d\n",ret);
    return 0;
}
