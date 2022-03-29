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
	int i;
	for (i=0; i<n; i++){

		Eigen::Vector3f rd_init_p = {(float)(rand())/RAND_MAX, (float)(rand())/RAND_MAX, (float)(rand())/RAND_MAX};
		Eigen::Vector3f rd_init_v = {(float)(rand())/RAND_MAX, (float)(rand())/RAND_MAX, (float)(rand())/RAND_MAX};

		boids.push_back(Boid(alpha * 4 * rd_init_p + (1-alpha) * fixed_init_p, alpha * rd_init_v + (1-alpha) * fixed_init_v));
	}

	target = Target();	
	pred = Predator();
}

Flock::~Flock() {
}

void Flock::draw()
{
	int i; 
	for (i=0; i<n; i++){
		boids[i].draw();
	}
	pred.draw();
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
	Eigen::Vector3f a; 
	compute_dist_matrix();
	
	for (int i=0; i<n; i++){
		std::vector<Boid> nb;
		std::copy(boids.begin(), boids.end(), std::back_inserter(nb));
		int cpt = reorder_boids(i, nb);
		//std::cout<<cpt<<std::endl;

		a = boids[i].rule_cohesion(nb, cpt);
		a = a + boids[i].rule_alignement(nb, cpt);
		a = a + boids[i].rule_separation(nb, cpt);
		a = a + target.get_aim_acceleration(boids[i]);
		a = a + 0.3 * (boids[i].p - pred.p);
		boids[i].update_speed(a, dt);
		//target.reorient_speed(boids[i]);

		boids[i].move(dt);
	}
	compute_flock_c();
	pred.update_speed(c, dt);
	pred.move(dt);
	target.update(c);
}

void Flock::compute_flock_c(){
	c = {0, 0, 0};
	for (int i=0; i<n; i++){
		c = c + boids[i].p;
	}
	c = c / n;
}

void Flock::compute_flock_v(){
	v = {0, 0, 0};
	for (int i=0; i<n; i++){
		v = v + boids[i].p;
	}
	v = v / n;
}

void Flock::compute_dist_matrix(){
	for (int i=0; i<n; i++){
		for (int j=0; j<n; j++){
		dist(i,j) = sqrt((boids[i].p-boids[j].p).dot(boids[i].p-boids[j].p));
		}
	}
}

int Flock::reorder_boids(int i, std::vector<Boid> nb){
	int cpt = -1;
	for (int j=0; j<n; j++){
		if(dist(i,j)<=dist_treshold){
			cpt++;
			std::swap(nb[j], nb[cpt]);
		}
	}
	return cpt;
}