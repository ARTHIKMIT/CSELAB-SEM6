#include<stdio.h>
#include<mpi.h>
#include<string.h>

int main(int argc, char *argv[]){
    int ierr,rank,size;
    char word[100];
    MPI_Status status;
    MPI_Init(&argc,&argv);
    MPI_Comm_size(MPI_COMM_WORLD,&size);
    MPI_Comm_rank(MPI_COMM_WORLD,&rank);

   

    if(rank==0){
         printf("enter the word: ");
    scanf("%s",word);
        MPI_Ssend(word,strlen(word)+1,MPI_CHAR,1,1,MPI_COMM_WORLD);
        MPI_Recv(word,100,MPI_CHAR,1,0,MPI_COMM_WORLD,&status);
        printf("the toggled string is: %s",word);
    }

    else {
                MPI_Recv(word,100,MPI_CHAR,0,1,MPI_COMM_WORLD,&status);
                // printf("the recieved word is: %s\n",word);

                for (int i = 0; word[i] != '\0'; i++) {
                    if(word[i]>='a'&& word[i]<='z'){
                        word[i]=word[i]-32;
                    }
                        else if(word[i]>='A' && word[i]<='Z'){
                        word[i]=word[i]+32;

                    }
         }

                 MPI_Ssend(word,strlen(word)+1,MPI_CHAR,0,0,MPI_COMM_WORLD);



}
MPI_Finalize();
}