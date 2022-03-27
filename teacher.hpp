#ifndef TEACHER_H_
#define TEACHER_H_

#include "answers.hpp"
#include <iostream>
#include <map>
#include <utility>

class teacher : public answers::reader {
  public:
    void review(answers::queue* pending = answers::latest);
    void printResults(std::ostream& os = std::cout);

  private:
    solution solve(const equation& eqn);
    std::map<std::string, std::pair<int, int>> results;
};

#endif // TEACHER_H_
