cmake_minimum_required(VERSION 3.5) # for Boost::* imported targets

project(example_python)

find_package(Python REQUIRED COMPONENTS Development)
set(boost_python "python${Python_VERSION_MAJOR}${Python_VERSION_MINOR}")
find_package(Boost REQUIRED COMPONENTS "${boost_python}")

add_library(hello SHARED hello.cpp)
target_link_libraries(hello PRIVATE Python::Module)
target_link_libraries(hello PRIVATE Boost::disable_autolinking "Boost::${boost_python}")
