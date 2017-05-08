cmake_minimum_required(VERSION 3.7)
project(voprosPoViboru)

set(CMAKE_CXX_STANDARD 14)


# Define sources and executable
set(EXECUTABLE_NAME "VPV")
add_executable(${EXECUTABLE_NAME} src/main.cpp src/Physics.cpp include/Atom.h include/Physics.h)

FIND_PACKAGE( Boost 1.62.0 COMPONENTS iostreams filesystem system)
INCLUDE_DIRECTORIES( ${Boost_INCLUDE_DIR} )

TARGET_LINK_LIBRARIES(${EXECUTABLE_NAME}  ${Boost_LIBRARIES} )

# Detect and add SFML
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}" ${CMAKE_MODULE_PATH})
find_package(SFML 2 REQUIRED system window graphics network audio)
if(SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(${EXECUTABLE_NAME} ${SFML_LIBRARIES})
endif()