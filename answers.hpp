#ifndef ANSWERS_H_
#define ANSWERS_H_

#include "equation.hpp"
#include "solution.hpp"
#include <queue>
#include <string>
#include <tuple>

typedef std::tuple<equation, solution, std::string> answer;

// C-like class with hidden structure seems like the best way to do access control without friends.
// Another way I thought about is privately inheriting queue by reader and writer, but that way requires
// initializing queue pointer in constructor

namespace answers {

class queue;
queue* createQueue();
// inline did what static/extern can not
inline queue* Default = nullptr;

class reader {
  protected:
    void pop(answers::queue* q = Default);
    answer front(answers::queue* q = Default);
    bool isEmpty(answers::queue* q = Default);
};
class writer {
  protected:
    void push(answer ans, queue* q = Default);
};

} // namespace answers

#endif // ANSWERS_H_
