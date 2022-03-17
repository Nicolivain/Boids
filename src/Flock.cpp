#include <iostream>
#include <GL/glut.h>
#include "Flock.h"
#include "Boid.h"


//BOID
Flock::Flock() {
	//boids = new vector();

	boids.push_back(Boid());
}

Flock::~Flock() {
}

void Flock::draw()
{
	boids[0].draw();

}

void Flock::move()
{

}