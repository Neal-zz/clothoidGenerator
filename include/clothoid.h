#pragma once

#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <vector>
#include <cmath>
#include <vector>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>
#include "state.h"
#include "clothoidPathSegment.h"

static const double PI = 3.14159;
static const int HEIGHT = 800, WIDTH = 800;

using namespace std;

class Clothoid {
public:
    Clothoid();
    int kMax;
    int solution;
    vector<ClothoidPathSegment> paths;
    void getPath(State start, State end);
private:
    int fresnel(double x, double &costerm, double &sinterm);
    void getXY(double s, double a, double b, double c, double& x, double& y);
    void getTrajectory();
    int signum(double a);
    double calcD(double alpha);
    double inRange(double theta);
    
    PathSegment path;
    State start,end;
           

};
