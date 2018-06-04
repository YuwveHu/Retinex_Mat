cmake_minimum_required(VERSION 3.9)
project(retinex)

set(CMAKE_CXX_STANDARD 11)

find_package(OpenCV REQUIRED)


include_directories(./)

set(LIB_MSRCR_SOURCE ./Msrcr.cpp ./Msrcr.h)
add_library(msrcr SHARED ${LIB_MSRCR_SOURCE})
target_link_libraries(msrcr ${OpenCV_LIBS})


add_executable(Retinex_mat main.cpp)
target_link_libraries(Retinex_mat ${OpenCV_LIBS} ${MYNTEYE_SDK_ROOT}/lib/libmynteye_core.so msrcr)

