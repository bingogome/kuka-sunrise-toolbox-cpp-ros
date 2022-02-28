cmake_minimum_required(VERSION 3.5)
project(kst_cpp_ros)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  cmake_modules
  roslib
  )

find_package(Boost REQUIRED COMPONENTS system)

catkin_package(
  INCLUDE_DIRS include 
  LIBRARIES ${PROJECT_NAME}
  CATKIN_DEPENDS roscpp
  )

add_library(${PROJECT_NAME} 
  ../kst_cpp/src/kst_servoing.cpp
  )

target_include_directories(${PROJECT_NAME} PUBLIC 
  include/kst_cpp_ros
  ../kst_cpp/include/kst_cpp
  ${catkin_INCLUDE_DIRS} 
  ${Boost_INCLUDE_DIRS}
  )

target_link_libraries(${PROJECT_NAME} ${catkin_LIBRARIES})

add_executable(test_node src/test.cpp)
target_link_libraries(test_node ${PROJECT_NAME})
