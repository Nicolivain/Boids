#include <iostream>
#include <GL/glut.h>
#include "Boid.h"


//BOID
Boid::Boid() {
	//srand(0);
	p[0] = 5*(float)(rand())/RAND_MAX;
	p[1] = 5*(float)(rand())/RAND_MAX;
	p[2] = 5*(float)(rand())/RAND_MAX;
	std::cout << p <<std::endl;

}

Boid::~Boid() {
}

void Boid::draw()
{
	glPushMatrix();
	glTranslatef(p[0],p[1],p[2]);
	glutSolidCone(0.1, 0.2, 10, 10);
	glPopMatrix();
}
