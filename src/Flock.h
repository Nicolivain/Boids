#ifndef FLOCK_H
#define FLOCK_H

#include "Boid.h"
#include "Target.h"
#include "Predator.h"
#include <vector>


class Flock {
public:
	
	int n = 10;
	std::vector<Boid> boids;
	// Eigen::Matrix<float, n, n> dist;
	Eigen::Vector3f c;
	Eigen::Vector3f v;

	// Constructor
	Flock();
	// Destructor
	~Flock();

	void draw();
	void move(float);

	void compute_flock_c();
	void compute_flock_v();
	void compute_dist_matrix();

	Target target;
	Predator pred;

	
};

#endif 
