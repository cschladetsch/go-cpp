cmake_minimum_required(VERSION 2.8)
project(go)

add_compile_options(-std=c++11)

set(Boost_USE_STATIC_LIBS ON)

find_package(Boost 1.5 REQUIRED COMPONENTS filesystem)

add_executable(go main.cpp)

target_link_libraries(go PUBLIC Boost::filesystem)


