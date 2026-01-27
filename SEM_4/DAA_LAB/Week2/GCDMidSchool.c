/*
2) Write a program to find GCD using middle school method and analyze its time 
efficiency.
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int findMin(int a, int b){
    return (a<b)?a:b;
}

int count = 0;

int findPrimeNumbers(int a, int *arr){
    //Get all prime numebers upto a
    int k=0;
    for (int i=2; i<=a; i++){
        ++count;
        if (a%i == 0){
            arr[k] = i;
            a = a/arr[k];
            k++;
        }
    }
    for (int i=0; i<k; i++)
        printf(" %d ",arr[i]);
    return k;
}

int gcd(int a, int b, int k, int*arr){
    
    //bool flag = true;
    int gcd = 1;
    int i = 0;
    while (i<k) {
        ++count;
        if (a%arr[i] == 0 && b%arr[i]==0){
            gcd *= arr[i];
            a /= arr[i];
            b /= arr[i];
        }
        else i++;
    }
    return gcd;
}

int main(){
    int a,b;

    printf("Enter Number 1 : ");
    scanf("%d",&a);
    printf("Enter Number 2 : ");
    scanf("%d",&b);

    int m = findMin(a, b);
    int *arr = calloc(m, sizeof(int));
    int k = findPrimeNumbers(m,arr);
    int Gcd = gcd(a,b, k, arr);
    printf("GCD is %d, OpCount %d",Gcd, count);
    return 0;
}