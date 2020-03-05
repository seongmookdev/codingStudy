#include <iostream>

int N, M;
int arr[9];
bool visited[9];

void func(int count, int min){
    if(count == M){
        for(int i=0; i<M; ++i){
            printf("%d ",arr[i]);
        }
        printf("\n");
        return;
    }

    for(int i=min; i<=N; ++i){
        if(!visited[i]){
            visited[i]=true;
            arr[count] = i;
            func(count+1, i+1);
            visited[i]=false;
        }
        
    }
}

int main(){

    scanf("%d %d",&N, &M);

    func(0, 1);
       

    return 0;
}
