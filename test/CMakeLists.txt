cmake_minimum_required (VERSION 3.16)

project (test)

add_executable(test
        test.cpp
 )

target_link_libraries(test
           ${CMAKE_CURRENT_SOURCE_DIR}/../build/Debug/Super_EGE.lib
)


