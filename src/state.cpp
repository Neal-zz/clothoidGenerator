#include "state.h"
#include <cmath>

State::State(const double x_, const double y_, const double theta_,const double curvature_)
	: x(x_), y(y_), theta(theta_), curvature(curvature_) {}

State::State(const double x_, const double y_, const double theta_)
    : x(x_), y(y_), theta(theta_) {}

State::State()
    : x(0), y(0), theta(0), curvature(0) {}

// 两个 state 之间的直线距离
double State::getDistance(State b) {
    return sqrt((x - b.x) * (x - b.x) + (y - b.y) * (y - b.y));
}