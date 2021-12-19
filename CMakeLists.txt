cmake_minimum_required(VERSION 3.16)
project(LHTTPServer C)

set(CMAKE_C_STANDARD 99)

add_executable(LHTTPServer server.c)
add_executable(LHTTPClient client.c)