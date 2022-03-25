#include <iostream>
#include <GL/glut.h>
#include "Flock.h"
#include "Boid.h"


//BOID
Flock::Flock() {
	//boids = new vector();

	int i;
	n = 10;
	for (i=0; i<n; i++){
		boids.push_back(Boid());
	}
	
}

Flock::~Flock() {
}

void Flock::draw()
{
	int i; 
	for (i=0; i<n; i++){
		boids[i].draw();
	}

}

void Flock::move()
{
	int i; 
	for (i=0; i<n; i++){
		boids[i].move();
	}
}

void Flock::compute_flock_c(){
	int i;
	c = {0, 0, 0};
	for (i=0; i<n; i++){
		c = c + boids[i].p;
	}
	c = c / n;
}

void Flock::compute_flock_v(){
	int i;
	v = {0, 0, 0};
	for (i=0; i<n; i++){
		v = v + boids[i].p;
	}
	v = v / n;
}

Eigen::Vector3f Flock::rule_cohesion(Boid b) {
	return 0.01 * (c - b.p);
}

Eigen::Vector3f Flock::rule_alignement(Boid b) {
	return 0.2 * (v - b.v);
}

Eigen::Vector3f Flock::rule_separation(Boid b) {
	int min_dist = 10000000;
	int min_boid_idx = -1;
	int i;
	int dist;
	Eigen::Vector3f current_d;
	for (i=0; i<n; i++){
		current_d = b.p - boids[i].p;
		dist = current_d.dot(current_d);
		if (dist == 0) {		 // si boids[i] == b
			continue;
		}
		if (dist < min_dist){
			min_dist = dist;
			min_boid_idx = i;
		}
	}

	return 0.5 * (b.p - boids[min_boid_idx].p);
}