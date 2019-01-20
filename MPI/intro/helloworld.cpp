#include <iostream>
#include <mpich/mpi.h>

int main(int argc, char** argv) {
    // Initialize the MPI environment
    MPI_Init(&argc, &argv);

    // Get the number of processors
    int np;
    MPI_Comm_size(MPI_COMM_WORLD, &np);

    // get the rank of the process
    int id;
    MPI_Comm_rank(MPI_COMM_WORLD, &id);

    // get the name of the processor
    char processor_name[MPI_MAX_PROCESSOR_NAME];
    int name_len;
    MPI_Get_processor_name(processor_name, &name_len);

    std::cout << "process " << processor_name << " rank " << id << "/" << np << " devices" << std::endl;
    printf("funny though \n");

    // finalize the mpi environment
    MPI_Finalize();
}