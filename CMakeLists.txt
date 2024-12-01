cmake_minimum_required (VERSION 3.16)

set(SDL2_INC ${CMAKE_CURRENT_SOURCE_DIR}/3party/SDL2.30.6/include)
set(GLAD_INC ${CMAKE_CURRENT_SOURCE_DIR}/3party/glad/include)

set(GLAD_SRC ${CMAKE_CURRENT_SOURCE_DIR}/3party/glad/src/glad.c)
set(GLM ${CMAKE_CURRENT_SOURCE_DIR}/3party/glm1.01)
set(FREETYPE_INC ${CMAKE_CURRENT_SOURCE_DIR}/3party/freetype2.13.3/include)



project (Super_EGE)

add_library(Super_EGE SHARED
        ${GLAD_SRC}
        include/super_ege.h
        src/Graphics.cpp
        src/Graphics.h
        src/Window.h
        src/Window.cpp
 )

target_include_directories(Super_EGE PUBLIC 
           ${SDL2_INC}
           ${GLAD_INC}
           ${GLM}
           ${FREETYPE_INC}                                             
)

if("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GUN")
     set(SDL2_LIBS  ${CMAKE_CURRENT_SOURCE_DIR}/3party/SDL2.30.6/lib/mingw64/libSDL2.a
     ${CMAKE_CURRENT_SOURCE_DIR}/3party/SDL2.30.6/lib/mingw64/libSDL2_test.a
     ${CMAKE_CURRENT_SOURCE_DIR}/3party/SDL2.30.6/lib/mingw64/libSDL2main.a)

     set(FREETYPE_LIBS ${CMAKE_CURRENT_SOURCE_DIR}/3party/freetype2.13.3/lib/mingw64/libfreetype.a)

target_link_libraries(Super_EGE
           setupapi
           winmm
           imm32
           version 
           opengl32
           ${SDL2_LIBS}
           ${FREETYPE_LIBS}
)

endif()

if ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "MSVC")
     set(SDL2_LIBS  ${CMAKE_CURRENT_SOURCE_DIR}/3party/SDL2.30.6/lib/msvc/SDL2-static.lib
      ${CMAKE_CURRENT_SOURCE_DIR}/3party/SDL2.30.6/lib/msvc/SDL2_test.lib
      ${CMAKE_CURRENT_SOURCE_DIR}/3party/SDL2.30.6/lib/msvc/SDL2main.lib)

     set(FREETYPE_LIBS ${CMAKE_CURRENT_SOURCE_DIR}/3party/freetype2.13.3/lib/msvc/freetype.lib)

target_link_libraries(Super_EGE
           setupapi
           winmm
           imm32
           version 
           opengl32
           ${SDL2_LIBS}
           ${FREETYPE_LIBS}
)
endif()

