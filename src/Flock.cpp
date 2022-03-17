#include <iostream>
#include <GL/glut.h>
#include "Flock.h"
#include "Boid.h"


//BOID
Flock::Flock() {
	//boids = new vector();

	int i;
	for (i=0; i<10; i++){
		boids.push_back(Boid());
	}
	
}

Flock::~Flock() {
}

void Flock::draw()
{
	int i; 
	for (i=0; i<10; i++){
		boids[i].draw();
	}

}

void Flock::move()
{

}