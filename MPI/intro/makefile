EXECS=mpi_hello_world mpi_pi_calcul testExercice3 testExercice4
MPICC?=mpic++
CC=g++

all: ${EXECS}

mpi_hello_world: helloworld.cpp
	${MPICC} -o mpi_hello_world helloworld.cpp

mpi_pi_calcul: picalcul.cpp
	${MPICC} -o mpi_pi_calcul picalcul.cpp

testExercice3: Molecule-seq.o MonteCarloSequentiel.cpp
	${CC} Molecule-seq.o MonteCarloSequentiel.cpp -o testExercice3

testExercice4: Molecule-dist.o MonteCarloDistrib.cpp
	${MPICC} Molecule-dist.o MonteCarloDistrib.cpp -o testExercice4

Molecule-seq.o: Molecule.h Molecule.cpp
	${CC} -c Molecule.cpp -o Molecule-seq.o

Molecule-dist.o: Molecule.h Molecule.cpp
	${MPICC} -c Molecule.cpp -o Molecule-dist.o

clean:
	rm -f ${EXECS} Molecule-seq.o Molecule-dist.o