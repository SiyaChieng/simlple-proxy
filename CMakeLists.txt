cmake_minimum_required(VERSION 3.12)
set(CC g++)

project(ProxyClient VERSION 0.1 LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 17)

include_directories()
link_directories()

set(PROJECT_SOURCE 
    client.cpp
)

add_executable(ProxyClient ${PROJECT_SOURCE})
target_link_libraries(ProxyClient pthread dl rt)
