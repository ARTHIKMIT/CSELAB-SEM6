/*
1) Write a program to find GCD using consecutive integer checking method and   
analyze its time efficiency.
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int findMin(int a, int b){
    return (a<b)?a:b;
}

int gcd(int a, int b){
    int t = findMin(a, b);
    //bool flag = true;
    int count = 0;
    while (true) {
        count++;
        if (a%t == 0){
            if (b%t == 0){
                printf(" COUNT (%d) ", count);
                return t;
            }
            else t--;
        }
        else t--;

    }
}

//OR for(t=min(), i>=1, t--)

int main(){
    int a,b;
    printf("Enter Number 1 : ");
    scanf("%d",&a);
    printf("Enter Number 2 : ");
    scanf("%d",&b);
    printf("GCD is %d",gcd(a,b));
    return 0;
}