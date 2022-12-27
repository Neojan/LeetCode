cmake_minimum_required(VERSION 3.1)

project(testLeetCode)

set(CMAKE_PATH $ENV{cmake_path})

include(${CMAKE_PATH}/toolchain.cmake)

include_directories( ./include)
link_directories( ${LIB_PATH})

# aux_source_directory( ./src SRC_LIST)
# add_executable( testLeetCode ${SRC_LIST})
add_executable( testLeetCode ./src/main.cpp)

TARGET_LINK_LIBRARIES( testLeetCode stdc++ pthread)

install( TARGETS testLeetCode RUNTIME DESTINATION ${INSTALL_PATH}/ )