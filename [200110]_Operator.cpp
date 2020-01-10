#include<stdio.h>

int n;
int number[11];
int op[4];
int ret_min = 0x7fffffff, ret_max = ret_min*-1;

void dfs(int result, int count){
    if(count == n-1){
        if(ret_min > result){
            ret_min = result;
        }
        if(ret_max < result){
            ret_max = result;
        }
        return;
    }

    for(int i=0; i<4; ++i){
        if(op[i] != 0){
            --op[i];
            if(i==0){
                dfs(result+number[count+1], count+1);
            }
            else if(i==1){
                dfs(result-number[count+1], count+1);
            }
            else if(i==2){
                dfs(result*number[count+1], count+1);
            }
            else if(i==3){
                dfs(result/number[count+1], count+1);
            }
            ++op[i];
        }
    }
}


int main(){

    scanf("%d",&n);
    for(int i=0; i<n; ++i){
        scanf("%d",&number[i]);
    }

    for(int i=0; i<n; ++i){
        scanf("%d",&op[i]);
    }

    dfs(number[0], 0);

    printf("%d %d",ret_max, ret_min);

    return 0;
}
