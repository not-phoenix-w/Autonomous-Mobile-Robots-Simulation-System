cmake_minimum_required(VERSION 3.10)

project(ROBOT_APP)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(raylib CONFIG REQUIRED)
if (NOT raylib_FOUND)
    message(FATAL_ERROR "Raylib not found. Please install it or set the path correctly.")
endif()

find_package(yaml-cpp REQUIRED)
if (NOT yaml-cpp_FOUND)
    message(FATAL_ERROR "yaml-cpp not found. Please install it or set the path correctly.")
endif()

file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS
    "${CMAKE_CURRENT_SOURCE_DIR}/GUI/src/*.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/configs/src/*.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/engine/src/*.cpp"
)

add_executable(${PROJECT_NAME} main.cpp)

target_sources(${PROJECT_NAME} PRIVATE ${SOURCES} ${SRC_FILES})

target_link_libraries(${PROJECT_NAME} PRIVATE raylib)
target_link_libraries(${PROJECT_NAME} PRIVATE yaml-cpp)

include_directories(${raygui_SOURCE_DIR}/src)

target_include_directories(${PROJECT_NAME} PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/
    ${CMAKE_CURRENT_SOURCE_DIR}/GUI/include
    ${CMAKE_CURRENT_SOURCE_DIR}/thirdparty
    ${CMAKE_CURRENT_SOURCE_DIR}/engine/include
    ${CMAKE_CURRENT_SOURCE_DIR}/configs/include
)
