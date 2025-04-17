cmake_minimum_required(VERSION 3.30)
project(algorithm)

set(CMAKE_CXX_STANDARD 20)

add_executable(algorithm main.cpp
        util.h
        algorithm/leetcode2278.h
        algorithm/leetcode695.h
        algorithm/leetcode39.h
        algorithm/leetcode40.h
        algorithm/leetcode45.h
        algorithm/leetcode55.h
        algorithm/leetcode46.h
        algorithm/leetcode47.h
        algorithm/leetcode141.h
        algorithm/leetcode142.h
        algorithm/leetcode19.h
        algorithm/leetcode26.h
        algorithm/leetcode27.h
        algorithm/leetcode83.h
        algorithm/leetcode283.h)
