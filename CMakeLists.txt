cmake_minimum_required(VERSION 3.5)
project(OpenCV_Camera_Calibration)

# specify the C++ standard
#set(CMAKE_CXX_STANDARD 26) not sure why this doesn't work. msvc doesn't support 26 yet?
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# specify where the boost library is
set(Boost_DEBUG ON)
set(Boost_USE_STATIC_LIBS ON)
set(BOOST_ROOT "C:/Program Files/boost/boost_1_85_0")

# have to compile boost for this next line to work
find_package(Boost 1.85 REQUIRED COMPONENTS filesystem)

#Find OpenCV package
find_package(OpenCV REQUIRED)

# Include directories from OpenCV and Boost
include_directories(${OpenCV_INCLUDE_DIRS})
include_directories(${BOOST_ROOT})

# if you're having trouble building opencv_video_calib or opencv_video_undistort,
# uncomment these two lines to see if it's a general build issue or an issue with linking the boost library
# add_executable(test_main test_main.cpp)
# target_link_libraries(test_main ${OpenCV_LIBS})

# Create executables
add_executable(opencv_video_calib opencv_video_calib.cpp)
add_executable(opencv_video_undistort opencv_video_undistort.cpp)

# Link OpenCV libraries
target_link_libraries(opencv_video_calib ${OpenCV_LIBS})
target_link_libraries(opencv_video_undistort ${OpenCV_LIBS})

# Link Boost libraries
target_link_libraries(opencv_video_calib ${Boost_LIBRARIES})
target_link_libraries(opencv_video_undistort ${Boost_LIBRARIES})