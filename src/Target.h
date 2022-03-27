#include <vector>
#include "Boid.h"


class Target {
private:
    int MAX_X = 100;
    int MIN_X = -100;
    int MAX_Y = 100;
    int MIN_Y = -100;
    int MAX_Z = 100;
    int MIN_Z = -100;

    float range_x = MAX_X - MIN_X;
    float range_y = MAX_Y - MIN_Y;
    float range_z = MAX_Z - MIN_Z;

    float alpha = 0.5;
    Eigen::Vector3f pos;

public:
    Target();
    void draw();
    void update(Eigen::Vector3f);
    Eigen::Vector3f get_aim_accelaration(Boid);
};
