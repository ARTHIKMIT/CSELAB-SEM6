/*
1) Write a program to implement Horspool’s algorithm for String Matching and 
find the number of key comparisons in successful search and unsuccessful search.
*/

#include<stdio.h>

#define ALPHABET_SIZE 256  // Number of possible characters (extended ASCII)

int opCount = 0;

void createBadShiftTable(int shiftTable[], char pattern[], int m){
    for (int i = 0; i < ALPHABET_SIZE; i++)
        shiftTable[i] = m;  // Default shift = length of the pattern

    // Set the shift for characters that appear in the pattern
    for (int i = 0; i < m - 1; i++)
        shiftTable[(unsigned char) pattern[i]] = m - i - 1;
}

int horspool(char text[], char pattern[], int shiftTable[], int n, int m){
  int i = m-1; //Starting from last char of pattern
  while(i<n-1){
    int k = 0;
    while(k<m && text[i-k]==pattern[m-1-k]){
      opCount++;
      k++;
    }
    if (k==m)
      return i-m+1;
    else{
      opCount++;
      printf("Not matching char : %c ", text[i-k]);
      printf("Shift : %d \n", shiftTable[(unsigned char) text[i-k]]);
      i += shiftTable[(unsigned char) text[i]];//- k;
      printf("INDEX I %d ", i); 
    }
  }
  return -1;
}

int main(){
    int n, m;
    /*
    printf("Enter the number of Elements in the Text : ");
    scanf("%d",&n);

    char arr[n];
    printf("Enter the Elements : ");
    for(int i = 0; i < n; i++)
      scanf("%c",&arr[i]);
    
    printf("Enter the number of Elements in the Pattern : ");
    scanf("%d",&n);

    char subStr[m];
    printf("Enter the Elements : ");
    for(int i = 0; i < m; i++)
      scanf("%c",&subStr[i]);
    */
    char arr[] = "JIN_SAW_ME_IN_A_BARBER SHOP";
    n = sizeof(arr)/sizeof(arr[0]) - 1;

    char subStr[] = "SARBER";
    m = sizeof(subStr)/sizeof(subStr[0]) - 1;

    int shiftTable[ALPHABET_SIZE];
    createBadShiftTable(shiftTable, subStr, m);
    
    int pos = horspool(arr, subStr, shiftTable, n, m);
    if (pos != -1)
      printf("Found the sub string at %d ", pos);
    else printf("Sub string not found.");
    printf("\nIt took %d Comparisions.", opCount);
    return 0;
}