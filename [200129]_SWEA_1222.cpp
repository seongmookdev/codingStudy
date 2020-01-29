//URL: https://swexpertacademy.com/main/learn/course/lectureProblemViewer.do
//REF: https://ddoublej.tistory.com/223

#include <stdio.h>

int main(){
    
    for(int t=1; t<=10; t++){

        int n;
        scanf("%d",&n);

        int sum=0;
        for(int i=0; i<n; i++){
            if(i%2==0){
                int temp = 0;
                scanf("%d", &temp);
                sum += temp;
            }
            else{
                char temp = 0;
                scanf("%c", &temp);
            }
        }
        printf("#%d %d\n",t, sum);
    }


    return 0;
}
