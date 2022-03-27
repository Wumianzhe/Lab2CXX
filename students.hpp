#ifndef STUDENTS_H_
#define STUDENTS_H_
#include "answers.hpp"
#include <string>

namespace student {

// inheriting classes are small, so i put them all in one header.
class base : public answers::writer {
  public:
    base(std::string name) : _name(name){};
    void submit(const equation& eqn);
    virtual ~base() = default;

  private:
    virtual solution solve(const equation& eqn);
    std::string _name;
};

class bad : public base {
  public:
    bad(std::string name) : base(name){};

  private:
    solution solve(const equation& eqn) override;
};

class good : public base {
  public:
    good(std::string name) : base(name){};

  private:
    solution solve(const equation& eqn) override;
};

class average : public base {
  public:
    average(std::string name) : base(name){};

  private:
    solution solve(const equation& eqn) override;
};

} // namespace student

#endif // STUDENTS_H_
