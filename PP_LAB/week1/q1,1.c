#include<stdio.h>
#include<mpi.h>
#include<math.h>

int main(int argc, char *argv[]){
    int ierr,rank,size,x=2,res;
    ierr=MPI_Init(&argc,&argv);
    MPI_Comm_size(MPI_COMM_WORLD,&size);
    MPI_Comm_rank(MPI_COMM_WORLD,&rank);
    printf("Processor %d of %d: Hello World\n",rank,size);

    res=pow(x,rank);
    printf("pow(x,rank) is :%d",res);

    if(rank%2==0)
    printf("hello");
    else
    printf("world");

    return 0;
    ierr=MPI_Finalize();
}
