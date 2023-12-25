cmake_minimum_required(VERSION 3.26)
project(DungeonMaster)

set(CMAKE_CXX_STANDARD 23)
set(INCLUDE_DIR include)
set(SRC_DIR src)

file(GLOB_RECURSE PROJECT_HEADERS  ${INCLUDE_DIR}/*.h ${INCLUDE_DIR}/*.hpp)
file(GLOB_RECURSE PROJECT_SOURCES ${SRC_DIR}/*.cpp)
file(COPY resources DESTINATION ${CMAKE_BINARY_DIR})

find_package(SFML COMPONENTS graphics REQUIRED)

add_executable(${PROJECT_NAME})

target_include_directories(${PROJECT_NAME} PUBLIC ${INCLUDE_DIR} ${SFML_INCLUDE_DIR})

target_link_libraries(${PROJECT_NAME} PUBLIC sfml-graphics)

target_sources(${PROJECT_NAME} PRIVATE ${PROJECT_SOURCES} PRIVATE ${PROJECT_HEADERS})
