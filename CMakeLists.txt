cmake_minimum_required(VERSION 2.8)
set(proj_name go-repo)
project(${proj_name})

# add_compile_options(-std=c++11 -g)

set(Boost_USE_STATIC_LIBS ON)

# CMake can't find boost without some help, as there's no standard places for it to look for installed 3rd party libraries
if (WIN32)
    set(BOOST_ROOT "c:\\Boost\\boost_1_73_0")
endif(WIN32)

find_package(Boost 1.5 REQUIRED COMPONENTS filesystem)

include_directories("include")

file(GLOB_RECURSE sources CONFIGURE_DEPENDS "src/*.cpp")
add_executable(${proj_name} ${sources})

target_link_libraries(${proj_name} PUBLIC Boost::filesystem)

