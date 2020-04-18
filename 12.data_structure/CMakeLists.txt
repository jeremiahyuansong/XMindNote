cmake_minimum_required(VERSION 3.14)
project(data_struct)
set(CMAKE_CXX_STANDARD 17)

#配置include
include_directories(./)

aux_source_directory(. DIR_SRCS)
add_executable(data_struct ${DIR_SRCS})

