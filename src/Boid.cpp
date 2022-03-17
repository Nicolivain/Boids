#include <iostream>
#include <GL/glut.h>
#include "Boid.h"


//BOID
Boid::Boid() {
	//srand(0);
	p[0] = 5*(float)(rand())/RAND_MAX;
	p[1] = 5*(float)(rand())/RAND_MAX;
	p[2] = 5*(float)(rand())/RAND_MAX;

	v[0] = (float)(rand())/RAND_MAX;
	v[1] = (float)(rand())/RAND_MAX;
	v[2] = (float)(rand())/RAND_MAX;


}

Boid::~Boid() {
}

void Boid::draw()
{
	std::cout << p <<std::endl;	
	glPushMatrix();
	glTranslatef(p[0],p[1],p[2]);
	glutSolidCone(0.1, 0.2, 10, 10);
	glPopMatrix();
}

void Boid::move(){
	int i;

	for (i=0; i<3; i++){
		p[i] = p[i] + v[i]*0.00001;
	}
}

