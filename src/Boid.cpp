#include <iostream>
#include <GL/glut.h>
#include "../Eigen/Dense"
#include <cmath>
#include "Boid.h"


//BOID
Boid::Boid() {

	p[0] = 5*(float)(rand())/RAND_MAX;
	p[1] = 5*(float)(rand())/RAND_MAX;
	p[2] = 5*(float)(rand())/RAND_MAX;

	v[0] = (float)(rand())/RAND_MAX;
	v[1] = (float)(rand())/RAND_MAX;
	v[2] = (float)(rand())/RAND_MAX;

	color[0] = (float)(rand())/RAND_MAX;
	color[1] = (float)(rand())/RAND_MAX;
	color[2] = (float)(rand())/RAND_MAX;

	ax = origin_ax.cross(v);
	ax.normalized(); 
	t = 180 / 3.1415 * (acos(v.dot(ax) / sqrt(v.dot(v))));

}

Boid::Boid(Eigen::Vector3f pos, Eigen::Vector3f vit){
	p = pos;
	v = vit;

	color = {255, 255, 255};

	ax = origin_ax.cross(v);
	ax.normalized(); 
	t = 180 / 3.1415 * (acos(v.dot(ax) / sqrt(v.dot(v))));
}

Boid::~Boid() {
}

void Boid::draw()
{
	glPushMatrix();
	glTranslatef(p[0],p[1],p[2]);
	glColor3f(color[0], color[1], color[2]);
	glRotatef(t, ax[0] , ax[1], ax[2]);
	glutSolidCone(size * 0.1, size * 0.2, size * 10, size * 10);
	glPopMatrix();
}

void Boid::move(float dt){
	for (int i=0; i<3; i++){
		p[i] = p[i] + v[i] * dt;

		ax = origin_ax.cross(v);
		ax.normalized(); 
		t = 180 / 3.1415 * (acos(v.dot(ax) / sqrt(v.dot(v))));
	}
}

void Boid::update_speed(Eigen::Vector3f a, float dt){
	a = cap_acc(a);
	v = v + a * dt;
	cap_speed();
}

void Boid::cap_speed(){
	if (v.dot(v) > max_speed*max_speed){
		v = max_speed * v / sqrt(v.dot(v));
	}
}

Eigen::Vector3f Boid::cap_acc(Eigen::Vector3f a){
	if (a.dot(a) > 100){
		a = 10 * a / sqrt(a.dot(a));
	}
	return a;
}

Eigen::Vector3f Boid::compute_flock_c(std::vector<Boid> boids, int n){
	Eigen::Vector3f c = {0, 0, 0};
	for (int i=0; i<n; i++){
		c = c + boids[i].p;
	}
	c = c / n;
	return c;
}

Eigen::Vector3f Boid::compute_flock_v(std::vector<Boid> boids, int n){
	Eigen::Vector3f v = {0, 0, 0};
	for (int i=0; i<n; i++){
		v = v + boids[i].p;
	}
	v = v / n;
	return v;
}

Eigen::Vector3f Boid::rule_cohesion(std::vector<Boid> boids, int n) {
	Eigen::Vector3f c = compute_flock_c(boids, n);
	return 0.1 * (c - p);
}

Eigen::Vector3f Boid::rule_alignement(std::vector<Boid> boids, int n) {
	Eigen::Vector3f cv = compute_flock_c(boids, n);
	return 0.2 * (cv - v);
}

Eigen::Vector3f Boid::rule_separation(std::vector<Boid> boids, int n) {
	int dist;
	Eigen::Vector3f r = {0, 0, 0};
	Eigen::Vector3f base = {1, 1, 1};
	for (int i=0; i<n; i++){
		if ((p - boids[i].p).dot(p-boids[i].p) < 0.002){
			r = r + 0.01 * base;
		} else if ((p - boids[i].p).dot(p-boids[i].p) < 1){
			r = r + 0.5 * (p - boids[i].p);
		} 
	}
	return r;
}
