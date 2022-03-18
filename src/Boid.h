#ifndef BOIDS_H
#define BOIDS_H

#include <Eigen/Dense>


class Boid {
public:
	Eigen::Vector3f p;
	Eigen::Vector3f v;
	Eigen::Vector3f a;
	Eigen::Vector3f color;

	Eigen::Vector3f origin_ax = {0, 0, 1};
	Eigen::Vector3f ax;

	float t;

	// Constructor
	Boid();
	// Destructor
	~Boid();

	void draw();
	void move();
};


#endif  // BOIDS_LIB_SAMPLE_CLASS_H_
