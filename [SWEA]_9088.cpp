#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int t,n,k;
    
    scanf("%d",&t);
    for(int tc=1; tc<=t; ++tc){
        int temp;
        int MIN=10000;
        int MAX=0;
        int ans=0;
        int dias[10001]={0,};
        scanf("%d %d", &n, &k);
        for(int i=0; i<n; ++i){
            scanf("%d",&temp);
            dias[temp] += 1;
            MIN = min(MIN, temp);
            MAX = max(MAX, temp);
        }

        for(int i=MIN; i<=MAX; ++i){
            if(dias[i] == 0) continue;
            temp = 0;
            for(int j=i; j<=min(MAX, i+k); ++j){
                temp += dias[j];
            }
            ans = max(ans, temp);
        }
        printf("#%d %d\n",tc,ans);
    }   

    return 0;
}
