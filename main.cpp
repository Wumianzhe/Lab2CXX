#include "students.hpp"
#include "teacher.hpp"
#include <fstream>
#include <iostream>

using namespace std;

// generate unique name for student from list of 15 names
string nameGen();
// generate =size= quadratic or linear equations, write to is
void testSuiteGen(int size, std::ostream& os);
// random double from a to b
double random(double a, double b);

int main(int argc, char* argv[]) {
    // seeding
    if (argc == 1) {
        srand(time(0));
        int seed = rand() % 1024;
        cout << "seed: " << seed << endl;
        srand(seed);
    } else {
        int seed = std::stoi(argv[1]);
        srand(seed);
    }

    // don't know a way to disable this part in runtime other than more complicated flag system or environment variables
    // both of which are not used often on Windows (as far as i know), so commenting out it is.
    ofstream os("input.txt");
    testSuiteGen(1000, os);
    os.close();

    const int groupSize = 10;
    teacher prof;
    answers::queue* pending = answers::createQueue();

    vector<student::base*> group(groupSize);
    // unsure, but I think i need reference there to write to group
    for (auto& pStud : group) {
        string name = nameGen();
        switch (rand() % 3) {
        case 0: {
            pStud = new student::bad(name);
            break;
        }
        case 1: {
            pStud = new student::average(name);
            break;
        }
        case 2: {
            pStud = new student::good(name);
            break;
        }
        }
    }

    ifstream in("input.txt");
    equation eqn(in);
    do {
        for (auto pStud : group) {
            pStud->submit(eqn, pending);
        }
    } while (in >> eqn);
    in.close();

    while (prof.hasWork(pending)) {
        prof.review(pending);
    }
    prof.printResults();

    return 0;
}

string nameGen() {
    string name = "";
    static string nameList[15] = {"Анищенко Михаил",       "Бойцов Антон",       "Дикарева Мария",   "Ерошкин Иван",
                                  "Зинякова Екатерина",    "Копнов Александр",   "Красников Роман",  "Петрошенко Артём",
                                  "Попов Павел",           "Пустынная Юлия",     "Рубанова Валерия", "Салихов Магомет",
                                  "Тройнягина Александра", "Чайковский Николай", "Чибышев Тимофей"};
    static int remaining = 15;
    if (!remaining) {
        throw std::runtime_error("Generating more than 15 names is not supported");
    }
    const int num = rand() % remaining;
    // reduce amount of remaining names
    remaining--;
    name = nameList[num];
    // move used name to end
    swap(nameList[num], nameList[remaining]);
    return name;
}

void testSuiteGen(int size, std::ostream& os) {
    for (int i = 0; i < size; i++) {
        int rc = rand() % 3;
        double x1 = random(-10, 10);
        double x2 = random(-10, 10);
        double a = random(-10, 10);
        double b, c;
        switch (rc) {
        case 0: {
            b = a * (x1 + x2);
            c = a * x1 * x2;
            break;
        }
        case 1: {
            int quadratic = rand() % 5;
            int rootNotZero = rand() % 10;
            if (quadratic) {
                if (rootNotZero) {
                    b = -2 * a * x1;
                    c = a * x1 * x1;
                } else {
                    b = c = 0;
                }
            } else {
                a = 0;
                b = x2;
                if (rootNotZero) {
                    c = -b * x1;
                } else {
                    c = 0;
                }
            }
            break;
        }
        case 2: {
            b = -a * (x1 + x2);
            c = a * x1 * x2;
            break;
        }
        }
        os << a << ' ' << b << ' ' << c << '\n';
    }
    os << endl;
}

double random(double a, double b) { return a + (double)rand() * (b - a) / RAND_MAX; }
