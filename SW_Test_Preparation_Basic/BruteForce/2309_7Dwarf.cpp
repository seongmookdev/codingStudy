#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX = 9;
int sum=0;
vector<int> dwarfHeight;

void snowWhite(){
    for(int i=0; i<MAX; ++i){
        for(int j=i+1; j<MAX; ++j){
            if(sum-dwarfHeight[i]-dwarfHeight[j] == 100){
                for(int k=0; k<9; ++k){
                    if(k != i && k!=j){
                        printf("%d\n",dwarfHeight[k]);
                    }
                }
                return;
            }
        }
    }
}

int main(){

    for(int i=0; i<MAX; ++i){
        int temp;
        scanf("%d", &temp);
        dwarfHeight.push_back(temp);
        sum += temp;
    }

    sort(dwarfHeight.begin(), dwarfHeight.end());

    snowWhite();

    return 0;
}
