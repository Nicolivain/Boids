#include "Boid.h"


class Predator: Boid{
    public:
    float speed = 1;
    Predator();
    void normalize_speed();
    void update_speed(Eigen::Vector3f);
};
