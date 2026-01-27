/* 2). Write a program to implement brute-force string matching. Analyze its time
efficiency. */

#include <stdio.h>
#include <string.h>

void stringMatch(char mainStr[], char subStr[]){
	int n1 = strlen(mainStr), n2 = strlen(subStr), opCount = 0, flag = 1;;
	for(int i=0; i<n1-n2+1; i++){
		flag = 1;
		for(int j=0; j<n2; j++){
			++opCount;
			if (mainStr[i+j] != subStr[j]){
				flag = 0;
				break;
			}
		} if (flag){
			printf("Sub Str Found\n");
			break;
		}
	} if (!flag)
		printf("Sub Str not Found\n");
	printf("Op count is %d \n",opCount);
}

int main(){
	char mainStr[20];
	char subStr[5];
	printf("Main : ");
	scanf("%s", mainStr);
	printf("Sub : ");
	scanf("%s", subStr);
	printf("Main %s \nSub %s \n",mainStr, subStr);
	stringMatch(mainStr, subStr);
}