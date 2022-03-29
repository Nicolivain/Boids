#include "Boid.h"


class Predator: public Boid{
    public:
    Predator();

    void update_speed(Eigen::Vector3f, float);
};
