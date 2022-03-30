#include "teacher.hpp"
#include <iomanip>

solution teacher::solve(const equation& eqn) { return eqn.solve(); }

void teacher::review(answers::queue* pending) {
    answer ans = front(pending);
    pop(pending);
    // if results do not contain name of student
    std::string studentName = std::get<std::string>(ans);
    if (results.find(studentName) == results.end()) {
        results.insert({studentName, {0, 0}});
    }
    // whether student's and teacher's solutions match
    bool right = std::get<solution>(ans) == solve(std::get<equation>(ans));

    // increment solved and total counters if answer is correct, don't increment solved otherwise
    if (right) {
        results[studentName].first++;
        results[studentName].second++;
    } else {
        results[studentName].second++;
    }
}

void teacher::printResults(std::ostream& os) {
    // table header
    int c1Width = 30;
    os << "+" << std::string(c1Width, '-') << "+" << std::string(17, '-') << "+\n";
    os << "|" << std::string(c1Width - 5, ' ') << "Имя  |  решено/сдано   |\n";
    os << "+" << std::string(c1Width, '-') << "+" << std::string(17, '-') << "+\n";
    // table body
    for (auto& res : results) {
        // unicode...
        int nameLength = (res.first.size() - 1) / 2;
        os << "|" << std::setw(c1Width + nameLength) << res.first << "|" << std::setw(8) << res.second.first << "/"
           << std::setw(8) << res.second.second << "|\n";
    }
    // table footer
    os << "+" << std::string(c1Width, '-') << "+" << std::string(17, '-') << "+" << std::endl;
}
