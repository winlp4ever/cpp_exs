#include "Molecule.h"
#include <iostream>
#include <cstdlib>
#include <limits>

unsigned long monteCarlo(unsigned long e, std::vector<Boule> mol,
		double BB[3][2]) {
	// TODO: complete this function
	unsigned long ePrime = 0;

	// my code
	unsigned int s = 0;
	srand(s);
	unsigned long i = 0;
	while (i < e) {
		double rand_p[3];
		randomPoint(rand_p, BB);
		for (auto it = mol.begin(); it != mol.end(); it++) {
			if (it->contains(rand_p)) {
				ePrime++;
				break;
			}
		}
		i++;
	}
	// ---

	return ePrime;
}

int main(int argc, char **argv) {
	if (argc != 3) {
		std::cerr << "Usage : " << argv[0]
			<< " e moleculefile (where e = # Monte Carlo trials)"
			<< std::endl;
		return 1;
	}

	const long e = atol(argv[1]);
	if (e <= 0) {
		std::cerr << "Argument must be an integer > 0" << std::endl;
		return 1;
	}

	// In the spirit of reproducibility, explicit initialisation of seed
	srand(0);

	// Load molecule.
	std::vector<Boule> molecule = readMolecule(argv[2]);
	// Bounding box.
	double BB[3][2];
	boundingBox(BB, molecule);

	// Compute volume.
	unsigned long ePrime = monteCarlo(e, molecule, BB);
	// TODO: compute correct volume.
	// double vol = -1.0;
	double vol_box = (BB[0][1] - BB[0][0]) * (BB[1][1] - BB[1][0]) * (BB[2][1] - BB[2][0]);
	double vol = vol_box * ePrime / (double) e;
	// Set maximal precision when printing doubles.
	std::cout.precision(std::numeric_limits<double>::digits10 + 1);
	std::cout << "volume : " << vol << std::endl;

	return 0;
}
