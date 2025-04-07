cmake_minimum_required(VERSION 3.30)
project(algorithm)

set(CMAKE_CXX_STANDARD 20)

add_executable(algorithm main.cpp
        algorithm/leetcode2278.h
        algorithm/leetcode695.h
        algorithm/leetcode39.h
        util.h
        algorithm/leetcode40.h
        algorithm/leetcode45.h
        algorithm/leetcode55.h
        algorithm/leetcode46.h
        algorithm/leetcode47.h)
