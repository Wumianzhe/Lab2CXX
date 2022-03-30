#include "answers.hpp"

using namespace answers;

// explicit namespace mention required
class answers::queue {
  public:
    queue() = default;
    ~queue() = default;
    std::queue<answer> _q;
};

queue* answers::createQueue() {
    queue* q = new queue();
    Default = q;
    return q;
}
void writer::push(answer ans, queue* q) { q->_q.push(ans); }
void reader::pop(queue* q) { q->_q.pop(); }
answer reader::front(queue* q) { return q->_q.front(); }
bool reader::isEmpty(queue* q) { return q->_q.empty(); }
