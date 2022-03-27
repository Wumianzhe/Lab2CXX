#ifndef SOLVER_H_
#define SOLVER_H_

#include "solution.hpp"
#include <iostream>

class equation {
  public:
    equation(std::istream& in);
    solution solve() const;

    friend std::istream& operator>>(std::istream& is, equation& eqn);

  private:
    double _a;
    double _b;
    double _c;
};

#endif // SOLVER_H_
