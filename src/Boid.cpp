#include <iostream>
#include <GL/glut.h>
#include <Eigen/Dense>
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
	glutSolidCone(0.1, 0.2, 10, 10);
	glPopMatrix();
}

void Boid::move(float dt){
	int i;

	for (i=0; i<3; i++){
		p[i] = p[i] + v[i] * dt;

		ax = origin_ax.cross(v);
		ax.normalized(); 
		t = 180 / 3.1415 * (acos(v.dot(ax) / sqrt(v.dot(v))));
	}
	
}

void Boid::update_speed(Eigen::Vector3f a, float dt){
	v = v + a * dt;
}

