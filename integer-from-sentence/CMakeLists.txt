# create me a cmakelist.txt file 
cmake_minimum_required(VERSION 3.5)

# set the project name
project(integer_from_sentence)

# set the cxx standard
set(CMAKE_CXX_STANDARD 17)

# generate the compile_commands.json file
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# add the executable
add_executable(integer_from_sentence ${CMAKE_SOURCE_DIR}/integer_from_sentense.cc)
