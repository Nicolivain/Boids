#include "Predator.h"


Predator::Predator(){

    p = {(float)(rand())/RAND_MAX, (float)(rand())/RAND_MAX, (float)(rand())/RAND_MAX};
    p = 15 * p;
    
    v = {(float)(rand())/RAND_MAX, (float)(rand())/RAND_MAX, (float)(rand())/RAND_MAX};

	color = {255, 0, 0};

	ax = origin_ax.cross(v);
	ax.normalized(); 
	t = 180 / 3.1415 * (acos(v.dot(ax) / sqrt(v.dot(v))));

    size = 8;
    max_speed = 2;
}

void Predator::update_speed(Eigen::Vector3f c, float dt){
	v = v + (c-p) * dt;
    cap_speed();
}
