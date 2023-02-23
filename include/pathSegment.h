#pragma once

#include "state.h"
#include <vector>

class PathSegment {

public:
    PathSegment() {}
    PathSegment(std::vector<State>& path_, double lengthOfPath_)
        : path(path_), lengthOfPath(lengthOfPath_) {}

    std::vector<State> path;
    double lengthOfPath;
    double sigma;
};