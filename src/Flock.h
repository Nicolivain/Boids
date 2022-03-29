#ifndef FLOCK_H
#define FLOCK_H

#include "Boid.h"
#include "Target.h"
#include "Predator.h"
#include <vector>


class Flock {
public:
	
	int n = 20;

	std::vector<Boid> boids;
	
	Eigen::Matrix<float, 20, 20> dist;
	float dist_treshold = 1.5;

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

	int reorder_boids(int, std::vector<Boid>);

	Target target;
	Predator pred;

	
};

#endif 
