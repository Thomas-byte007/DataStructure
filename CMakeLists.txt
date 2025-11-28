cmake_minimum_required(VERSION 3.15)
project(DataStructure)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(Tree Tree/BinaryTree/Main.cpp Tree/BinaryTree/LinkBinaryTree.cpp)