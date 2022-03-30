project(lab2)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(CMAKE_C_STANDARD 99)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_BUILD_TYPE Debug)

add_library(equations equation.cpp solution.cpp)
add_executable(main main.cpp answers.cpp students.cpp teacher.cpp)
target_link_libraries(main equations)
