#include <iostream>
#include <stdio.h>
#include <queue>
using namespace std;

int arr[15]={0,};
int k;
int count;
vector<int> v;

void dfs(int pos){

    if(v.size()==6){
        for(int i=0; i<v.size(); ++i){
            printf("%d ",v[i]);
        }
        printf("\n");
        return;
    }

    for(int i=pos; i<k; ++i){
        v.push_back(arr[i]);
        dfs(i+1);
        v.pop_back();
    }
}

int main(){

    while(1){
        scanf("%d",&k);
        if(k==0) break;

        for(int i=0; i<k; ++i){
            scanf("%d",&arr[i]);
        }
        dfs(0);

        printf("\n");
    }    
    

    return 0;
}
