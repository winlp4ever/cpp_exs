#include <iostream>
#include <cmath>
#include <limits>

#include <mpich/mpi.h>

static const double PI = 3.141592653589793238462643;

int main(int argc, char** argv) {
    int rank, size;

    MPI_Init (&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    // pour afficher tout double a precision maximale:
    std::cout.precision(std::numeric_limits<double>::digits10 + 1);

    while (true) {
        double pi;
        int n;

        if (rank == 0) {
            std::cout
                << "Entrez le nb d'intervalles (ou un entier < 1 pour quitter)"
                << std::endl;
            std::cin >> n;
        }

        MPI_Bcast (&n, 1, MPI_INT, 0, MPI_COMM_WORLD);

        if (n < 1)
            break;
        
        double h = 1.0 / (double) n;
        double sum = 0.0;
        for (int i = rank; i < n; i += size) {
            double x = h * ((double) i + 0.5);
            sum += (4.0 / (1.0 + x * x));
        }
        double mypi = h * sum;

        MPI_Reduce (&mypi, &pi, 1, MPI_DOUBLE, MPI_SUM, 0, MPI_COMM_WORLD);

        if (rank == 0) {
            std::cout << "pi est approche par " << pi << ", l'erreur est de " 
                << std::abs(pi - PI) << std::endl;
        }
    }
    MPI_Finalize();
}