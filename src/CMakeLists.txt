cmake_minimum_required(VERSION 3.1)

project(testLeetCode)

set(CMAKE_PATH $ENV{cmake_path})

include(${CMAKE_PATH}/toolchain.cmake)

include_directories( ./include)

aux_source_directory( ./src SRC_LIST)
link_directories( ${LIB_PATH})

add_executable( testLeetCode ${SRC_LIST})

if (${OS} STREQUAL ANDROID )
    message(WARNING "LINK ANDROID")
    target_link_libraries( testLeetCode dl c++ m)
else()
    message(WARNING "LINK GNU")
    TARGET_LINK_LIBRARIES( testLeetCode stdc++ pthread)
endif()

install( TARGETS testLeetCode RUNTIME DESTINATION ${INSTALL_PATH}/ )