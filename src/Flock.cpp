#include <iostream>
#include <GL/glut.h>
#include "Flock.h"
#include "Boid.h"


//BOID
Flock::Flock() {


	float alpha = 0.1;  // part of randomness in init
	Eigen::Vector3f fixed_init_p = {0, 0, 0};
	Eigen::Vector3f fixed_init_v = {1, 1, 1};

	// we initialize the boids in the flock constructor
	n = 50;
	int i;
	for (i=0; i<n; i++){

		Eigen::Vector3f rd_init_p = {(float)(rand())/RAND_MAX, (float)(rand())/RAND_MAX, (float)(rand())/RAND_MAX};
		Eigen::Vector3f rd_init_v = {(float)(rand())/RAND_MAX, (float)(rand())/RAND_MAX, (float)(rand())/RAND_MAX};

		boids.push_back(Boid(alpha * 4 * rd_init_p + (1-alpha) * fixed_init_p, alpha * rd_init_v + (1-alpha) * fixed_init_v));
	}

	target = Target();	
}

Flock::~Flock() {
}

void Flock::draw()
{
	int i; 
	for (i=0; i<n; i++){
		boids[i].draw();
	}

	target.draw();

	// draw the center of mass of the flock
	/*
	glPushMatrix();
	glTranslatef(c[0],c[1],c[2]);
	glColor3f(255, 0, 0);
	//glRotatef(t, ax[0] , ax[1], ax[2]);
	glutSolidCube(0.3);
	glPopMatrix();
	*/
}

void Flock::move(float dt)
{
	int i;
	Eigen::Vector3f a; 
	for (i=0; i<n; i++){
		a = rule_cohesion(boids[i]);
		a = a + rule_alignement(boids[i]);
		a = a + rule_separation(boids[i]);
		a = a + target.get_aim_accelaration(boids[i]);
		boids[i].update_speed(a, dt);
		boids[i].move(dt);
	}
	target.update(c);
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
	compute_flock_c();
	return 0.1 * (c - b.p);
}

Eigen::Vector3f Flock::rule_alignement(Boid b) {
	compute_flock_v();
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

	return 1 * (b.p - boids[min_boid_idx].p);
}