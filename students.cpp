#include "students.hpp"

using namespace student;

void base::submit(const equation& eqn, answers::queue* q) {
    answer ans = {eqn, solve(eqn), _name};
    push(ans, q);
}

solution good::solve(const equation& eqn) { return eqn.solve(); }

solution bad::solve(const equation& eqn) { return solution{1, 0, 0}; }

solution average::solve(const equation& eqn) { return (rand() % 2) ? (eqn.solve()) : (solution{1, 0, 0}); }
