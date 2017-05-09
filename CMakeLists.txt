cmake_minimum_required(VERSION 3.7)
project(voprosPoViboru)

set(CMAKE_CXX_STANDARD 14)

# Define sources and executable
set(EXECUTABLE_NAME "VPV")
add_executable(${EXECUTABLE_NAME} src/main.cpp src/Physics.cpp include/Atom.h
        include/Physics.h include/PlotDrawer.h src/PlotDrawer.cpp
        include/Utility.h src/Utility.cpp src/Atom.cpp)

SET(GCC_COVERAGE_LINK_FLAGS "-lboost_iostreams")
SET( CMAKE_EXE_LINKER_FLAGS  "${CMAKE_EXE_LINKER_FLAGS} ${GCC_COVERAGE_LINK_FLAGS}" )

#FIND_PACKAGE( Boost 1.62.0 COMPONENTS iostreams filesystem system)
find_package(Boost COMPONENTS program_options signals thread system)
find_package(Threads)
INCLUDE_DIRECTORIES( ${Boost_INCLUDE_DIR} )

target_link_libraries(${EXECUTABLE_NAME} ${Boost_LIBRARIES} ${CMAKE_THREAD_LIBS_INIT})
target_include_directories(${EXECUTABLE_NAME} PUBLIC SYSTEM ${Boost_INCLUDE_DIRS})
#TARGET_LINK_LIBRARIES(${EXECUTABLE_NAME}  ${Boost_LIBRARIES} )

# Detect and add SFML
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}" ${CMAKE_MODULE_PATH})
find_package(SFML 2 REQUIRED system window graphics network audio)
if(SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(${EXECUTABLE_NAME} ${SFML_LIBRARIES})
endif()