#ifndef BOIDS_H
#define BOIDS_H

#include <vector>
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
	float max_speed = 4;

	// Constructor
	Boid();
	Boid(Eigen::Vector3f,  Eigen::Vector3f);
	// Destructor
	~Boid();

	void draw();
	void move(float);
	void update_speed(Eigen::Vector3f, float);
	void cap_speed();

	Eigen::Vector3f rule_cohesion(std::vector<Boid>, int);
	Eigen::Vector3f rule_separation(std::vector<Boid>, int);
	Eigen::Vector3f rule_alignement(std::vector<Boid>, int);

	Eigen::Vector3f compute_flock_c(std::vector<Boid>, int);
	Eigen::Vector3f compute_flock_v(std::vector<Boid>, int);

};


#endif  // BOIDS_LIB_SAMPLE_CLASS_H_
