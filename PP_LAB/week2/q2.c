#include<stdio.h>
#include<mpi.h>

int main(int argc, char *argv[]){
    int ierr,rank,size;
    int num[100];
    MPI_Status status;
    MPI_Init(&argc,&argv);
    MPI_Comm_size(MPI_COMM_WORLD,&size);
    MPI_Comm_rank(MPI_COMM_WORLD,&rank);
    int i;
   

    if(rank==0){
        
         for (i = 1; i <size ; i++)
         {
          MPI_Send(&i,1,MPI_INT,i,1,MPI_COMM_WORLD);
         }
         
        
        // MPI_Recv(word,100,MPI_CHAR,1,0,MPI_COMM_WORLD,&status);
    
    }

    else {
                MPI_Recv(&i,1,MPI_INT,0,1,MPI_COMM_WORLD,&status);
                printf("%d of %d receives,the recieved number is: %d\n",rank,size,i);

        //         for (int i = 0; word[i] != '\0'; i++) {
        //             if(word[i]>='a'&& word[i]<='z'){
        //                 word[i]=word[i]-32;
        //             }
        //                 else if(word[i]>='A' && word[i]<='Z'){
        //                 word[i]=word[i]+32;

        //             }
        //  }

                //  MPI_Ssend(word,strlen(word)+1,MPI_CHAR,0,0,MPI_COMM_WORLD);



}
MPI_Finalize();
}