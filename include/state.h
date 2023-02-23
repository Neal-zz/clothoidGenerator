#pragma once

class State {
    
public:
    double x, y, theta, curvature;
    State(const double x_, const double y_, const double theta_, const double curvature_);
    State(const double x_, const double y_, const double theta_);
    State();
    double getDistance(State b);
    // State& operator=(const State a);
};