cmake_minimum_required(VERSION 3.10)

project(simulateur)


set(CMAKE_CXX_STANDARD 17)

add_executable(main.exe main.cpp Problem.cpp Equation.cpp UniformMesh.cpp Variable.cpp Timer.cpp)

find_package(Threads REQUIRED)

target_link_libraries(main.exe Threads::Threads)
 
enable_testing()

add_test(mytest main.exe)

find_package(GTest REQUIRED)
enable_testing()

add_executable(unit_tests tests.cpp Problem.cpp Equation.cpp UniformMesh.cpp Variable.cpp Timer.cpp Upwind.cpp LaxWendroff.cpp)

target_link_libraries(unit_tests PRIVATE GTest::GTest GTest::Main)

gtest_discover_tests(unit_tests)






