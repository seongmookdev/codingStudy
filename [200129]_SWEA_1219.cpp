#include <stdio.h>
#include <iostream>
#include <string.h>

using namespace std;

int arr[100][2] = {0,};

int dfs(int n, int way){

    if(arr[n][way] == 99){
        return 1;
    }
    if(arr[n][way] == 0){
        return 0;
    }
    if(dfs(arr[n][way], 0)){
        return 1;
    };
    return dfs(arr[n][way], 1);
}


int main(){

    for(int t=1; t<=10; t++){
        int count = 0;
        int n = 0;
        scanf("%d %d", &count, &n);
        
        for(int i = 0; i<n; i++){
            int a, b;
            scanf("%d %d", &a, &b);
            if(arr[a][0] != 0){
                arr[a][1] = b;
            }
            else{
                arr[a][0] = b;
            }
            
            
        }
        printf("#%d %d\n",count, dfs(0,0));
        memset(arr, 0, sizeof(arr));
    }

    return 0;
}
