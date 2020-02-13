#include <iostream>
using namespace std;

int n, ans, sum;
int g[101];
bool used[101]={false,};
bool D[10001]={false,};

int main(){
    int t;
    scanf("%d",&t);
    for(int tc=1; tc<=t; ++tc){
        scanf("%d",&n);
        for(int i=0; i<n; ++i){
            scanf("%d",&g[i]);
            sum += g[i];
        }
        D[0] = true;
        for(int i=0; i<n; ++i){
            for(int j=sum; j>=0; --j){
                if(D[j]){
                    D[j + g[i]]=true;
                }
            }
        }

        int ans=0;
        for(int i=0; i<=10000; ++i){
            if(D[i]) ans++;
        }
        
        printf("#%d %d\n",tc,ans);
        
    }

    return 0;
}
