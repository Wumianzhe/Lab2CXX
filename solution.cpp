#include "solution.hpp"
#include <math.h>
const double eps = 1e6;

solution::solution(int rootCount, double x1, double x2) : _rootCount(rootCount), _x1(x1), _x2(x2) {}

bool solution::operator==(const solution& r) {
    if (r._rootCount != _rootCount) {
        return false;
    }
    switch (_rootCount) {
    case 0: {
        return true;
    }
    case 1: {
        if (abs(r._x1 - _x1) > eps) {
            return false;
        } else {
            return true;
        }
    }
    case 2: {
        if (abs(r._x1 - _x1) > eps || abs(r._x2 - _x2) > eps) {
            return false;
        } else {
            return true;
        }
    }
    // rootCount should be a enum, but naming is hard.
    default: {
        return false;
    }
    }
}
