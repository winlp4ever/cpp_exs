#include <iostream>
// mytests

#include <mpich/mpi.h>
#include <random>
#include <time.h>

/* this func generates fix-sized arr of random numbers
*/
void genRandomArr(double* arr, const int& size, std::default_random_engine& gen) {
    std::normal_distribution<double> N(0, 1);
    for (int i = 0; i < size; i++) {
        *(arr + i) = N(gen);
    }
}

int main(int argc, char** argv) {
    MPI_Init(&argc, &argv);

    const int root = 0;
    int size, rank;
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    // Haa! C++ has lambdas functions, too
    auto pr = [](double* a, const int& size) {
        std::cout << "[ ";
        for (int i = 0; i < size; i++) {
            std::cout << *(a + i) << " ";
        }
        std::cout << "]" << std::endl;
    };
    // Also, this is the only way to write local functions (function in function) in c++

    double* a, * b, * c;
    double locala, localb;
    if (rank == root) {
        a = new double[size];
        b = new double[size];
        c = new double[size];

        std::default_random_engine generator;
        generator.seed(time(NULL));

        genRandomArr(a, size, generator);
        genRandomArr(b, size, generator);
        
        pr(a, size);
        pr(b, size);     
    }

    MPI_Scatter(a, 1, MPI_DOUBLE, &locala, 1, MPI_DOUBLE, root, MPI_COMM_WORLD);
    MPI_Scatter(b, 1, MPI_DOUBLE, &localb, 1, MPI_DOUBLE, root, MPI_COMM_WORLD);
    
    double localc = locala + localb;

    MPI_Gather(&localc, 1, MPI_DOUBLE, c, 1, MPI_DOUBLE, root, MPI_COMM_WORLD);

    if (rank == root) {
        pr(c, size);
        delete a, b, c;
    }

    MPI_Finalize();
}