#include <iostream>
#include <math.h>

using namespace std;

int main(){
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);

    int first;
    int second;
    int third;
    int fourth;

    first = (a+b)%c;
    second = (a%c+b%c)%c;
    third = (a*b)%c;
    fourth = (a%c*b%c)%c;

    printf("%d\n",first);
    printf("%d\n",second);
    printf("%d\n",third);
    printf("%d\n",fourth);
}
