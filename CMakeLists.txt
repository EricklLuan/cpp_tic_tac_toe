cmake_minimum_required(VERSION 3.0.0)
project(jogo_da_velha VERSION 0.1.0)

find_package(SDL2 CONFIG REQUIRED)
find_package(SDL2_image CONFIG REQUIRED)

file(GLOB_RECURSE HEADERS "include/*.hpp")
file(GLOB SOURCES "src/*.cpp")

include_directories("./include")

add_executable(jogo_da_velha main.cpp ${SOURCES} ${HEADERS})

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

target_link_libraries(jogo_da_velha PRIVATE SDL2::SDL2)
target_link_libraries(jogo_da_velha PRIVATE $<IF:$<TARGET_EXISTS:SDL2_image::SDL2_image>,SDL2_image::SDL2_image,SDL2_image::SDL2_image-static>)
