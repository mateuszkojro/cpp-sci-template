cmake_minimum_required(VERSION 3.17)
project(test)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(DCMAKE_CXX_COMPILER_LAUNCHER ccache)

# heello
#set(HELLO true)
set(XTENSOR_USE_XSIMD true)



add_subdirectory(xsimd)

add_subdirectory(xtl)
include_directories(./xtl/include)

add_subdirectory(xtensor/)
include_directories("./xtensor/include")

#add_subdirectory(sciplot)
include_directories(sciplot/)

add_executable(test main.cc)

target_link_libraries(
        test
        xtensor
)
