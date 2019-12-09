cmake_minimum_required(VERSION 3.7 FATAL_ERROR)

project(jdlog VERSION 0.0.1 LANGUAGES CXX)
get_directory_property(IS_SUBPROJECT PARENT_DIRECTORY)
message(STATUS "Building: \"${PROJECT_NAME}\" module . . .")

find_package(Boost 1.71 REQUIRED)

##include_directories(${CMAKE_SOURCE_DIR}/src/include)

## Set output binary
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

## Set compiler options
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
link_libraries(stdc++fs)

## Includes ...
include(cmake/clang-format.cmake)
include(cmake/cppcheck.cmake)
## Get version
include(cmake/get_git_version.cmake)
get_git_version(PROJECT_VERSION_FULL)

#string(REGEX REPLACE "[.-]" ";" VERSION_LIST ${PROJECT_VERSION_FULL})
#list(GET VERSION_LIST 0 ${PROJECT_NAME}_VERSION_MAJOR)
#list(GET VERSION_LIST 1 ${PROJECT_NAME}_VERSION_MINOR)
#list(GET VERSION_LIST 2 ${PROJECT_NAME}_VERSION_BUILD)
#list(GET VERSION_LIST 3 ${PROJECT_NAME}_VERSION_PATCH)
#list(GET VERSION_LIST 4 ${PROJECT_NAME}_VERSION_CHANGESET)
#string(TIMESTAMP ${PROJECT_NAME}_BUILD_TIME "%Y-%m-%d %H:%M")

## Configure version
#configure_file(config/version.h.in version.h)
include_directories(${CMAKE_CURRENT_BINARY_DIR})
include_directories(${CMAKE_SOURCE_DIR}/src/include)

## Get files
file(GLOB_RECURSE ${PROJECT_NAME}_SRC src/*.cpp src/*.hpp)
file(GLOB ${PROJECT_NAME}_OTHER

  )
##file(GLOB LIBS ${CMAKE_SOURCE_DIR}/src/libs/*.a)

add_executable(${PROJECT_NAME}  ${${PROJECT_NAME}_SRC} ${${PROJECT_NAME}_OTHER})
target_compile_options(${PROJECT_NAME} PRIVATE -O0 -g)
##target_link_libraries(${PROJECT_NAME} ${Boost_LIBRARIES} ${LIBS})


# !!!ATTENTION!!! Set env BOOST_TEST_REPORT_LEVEL = short

