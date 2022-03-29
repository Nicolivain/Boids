#include <iostream>
#include <GL/glut.h>
#include "Target.h"
#include "Boid.h"


Target::Target(){
    pos = {range_x * (float)(rand())/RAND_MAX - MAX_X, range_y * (float)(rand())/RAND_MAX - MAX_Y, range_z * (float)(rand())/RAND_MAX - MAX_Z};
}

void Target::draw() {
    glPushMatrix();
	glTranslatef(pos[0],pos[1],pos[2]);
	glColor3f(0, 255, 0);
	glutSolidCube(0.3);
	glPopMatrix();
}

Eigen::Vector3f Target::get_aim_acceleration(Boid b) {
    return alpha * (pos - b.p);
}

void Target::reorient_speed(Boid b){
    b.v = b.v + 0.1 * (pos - b.p)/sqrt((pos-b.p).dot(pos-b.p));
}

void Target::update(Eigen::Vector3f c) { 
    std::cout << (pos-c).dot(pos-c) << std::endl;
    if ((pos-c).dot(pos-c) < 10){
        pos = {range_x * (float)(rand())/RAND_MAX - MAX_X, range_y * (float)(rand())/RAND_MAX - MAX_Y, range_z * (float)(rand())/RAND_MAX - MAX_Z};
    }
}