#ifndef FLOCK_H
#define FLOCK_H

#include "Boid.h"
#include <vector>

class Flock {
public:
	
	int n;
	std::vector<Boid> boids;

	Eigen::Vector3f c;
	Eigen::Vector3f v;

	// Constructor
	Flock();
	// Destructor
	~Flock();


	void draw();
	void move();

	void compute_flock_c();
	void compute_flock_v();

	Eigen::Vector3f rule_cohesion(Boid);
	Eigen::Vector3f rule_separation(Boid);
	Eigen::Vector3f rule_alignement(Boid);

};

#endif 
