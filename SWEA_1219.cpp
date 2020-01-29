#include <stdio.h>
#include <iostream>
#include <stack>
using namespace std;

int arr[100][2] = {0,};

int dfs(int n, int way){

    if(arr[n][way] == 99) return 1;
    if(arr[n][way] == 0) return 0;
        
    if(dfs(arr[n][way], 0)) return 1;
    return dfs(arr[n][way], 1);
}

int main(){

    int T = 10;
    int ret = 0;
    while(T--){
        int n, m;
        scanf("%d %d", &n, &m);
        for(int i=0; i<m; ++i){
            int a, b;
            scanf("%d %d", &a, &b);
            if(arr[a][0] != 0){
                arr[a][1] = b;
                continue;
            }
            arr[a][0] = b;
        }

        ret = dfs(0, 0);
        printf("#%d %d\n",n, ret);
    }

    return 0;
}
