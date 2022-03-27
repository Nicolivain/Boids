#include "Boid.h"


class Predator: public Boid{
    public:
    float speed = 2;
    Predator();

    void normalize_speed();
    void update_speed(Eigen::Vector3f, float);
};
