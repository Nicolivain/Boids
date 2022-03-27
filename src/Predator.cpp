#include "Predator.h"


Predator::Predator(){

    p = {(float)(rand())/RAND_MAX, (float)(rand())/RAND_MAX, (float)(rand())/RAND_MAX};
    p = 15 * p;
    
    v = {(float)(rand())/RAND_MAX, (float)(rand())/RAND_MAX, (float)(rand())/RAND_MAX};
    normalize_speed();

	color = {255, 0, 0};

	ax = origin_ax.cross(v);
	ax.normalized(); 
	t = 180 / 3.1415 * (acos(v.dot(ax) / sqrt(v.dot(v))));
}

void Predator::normalize_speed(){
    v = speed * v / sqrt(v.dot(v));
}

void Predator::update_speed(Eigen::Vector3f a, float dt){
	v = v + a * dt;
    normalize_speed();
}