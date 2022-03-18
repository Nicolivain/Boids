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