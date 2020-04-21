cmake_minimum_required(VERSION 3.14)
project(design_pattern)
set(CMAKE_CXX_STANDARD 17)

#配置include
include_directories(./)

aux_source_directory(. DIR_SRCS)
add_executable(design_pattern ${DIR_SRCS})

