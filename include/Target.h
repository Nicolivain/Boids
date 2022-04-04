#include <vector>
#include <Eigen/Dense>
#include "Boid.h"


class Target {
private:
    int MAX_X = 10;
    int MIN_X = -10;
    int MAX_Y = 10;
    int MIN_Y = -10;
    int MAX_Z = 10;
    int MIN_Z = -10;

    float range_x = MAX_X - MIN_X;
    float range_y = MAX_Y - MIN_Y;
    float range_z = MAX_Z - MIN_Z;

    float alpha = 1;
    Eigen::Vector3f pos;

public:
    Target();
    void draw();
    void update(Eigen::Vector3f);
    void reorient_speed(Boid);
    Eigen::Vector3f get_aim_acceleration(Boid);
};
