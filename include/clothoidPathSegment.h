#pragma once

#include "pathSegment.h"

class ClothoidPathSegment : public PathSegment {
    
public:
    double sigma;

    ClothoidPathSegment(std::vector<State>& path_, double larc_, double sigma_)
        : PathSegment(path_, larc_), sigma(sigma_) {}


};