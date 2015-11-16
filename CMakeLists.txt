cmake_minimum_required(VERSION 3.0)

include("cmake/HunterGate.cmake")
HunterGate(
    URL "https://github.com/ruslo/hunter/archive/v0.12.26.tar.gz"
    SHA1 "fb52c562bc5d8b48278cc2a84b0de682014adae5"
)

set(PROJECT_NAME linlib)
project(${PROJECT_NAME})

hunter_add_package(GTest)
find_package(GTest CONFIG REQUIRED NO_CMAKE_BUILDS_PATH)

file(GLOB_RECURSE HEADERS "src/*.h")
file(GLOB_RECURSE SOURCES "src/*.cpp")

file(GLOB_RECURSE UNIT_TEST_HEADERS "test/unit/*.h")
file(GLOB_RECURSE UNIT_TEST_SOURCES "test/unit/*.cpp")

file(GLOB_RECURSE FUNC_TEST_HEADERS "test/functional/*.h")
file(GLOB_RECURSE FUNC_TEST_SOURCES "test/functional/*.cpp")

if(CMAKE_COMPILER_IS_GNUCXX)
    set(CMAKE_CXX_FLAGS "-std=gnu++0x -Wall")
endif(CMAKE_COMPILER_IS_GNUCXX)

include_directories(${CMAKE_SOURCE_DIR})
#add_library(${PROJECT_NAME} ${HEADERS} ${SOURCES})

add_executable(${PROJECT_NAME}_unit ${UNIT_TEST_HEADERS} ${UNIT_TEST_SOURCES} )
target_link_libraries(${PROJECT_NAME}_unit GTest::main)

add_executable(${PROJECT_NAME}_functional ${FUNC_TEST_HEADERS} ${FUNC_TEST_SOURCES} )
target_link_libraries(${PROJECT_NAME}_functional GTest::main)

enable_testing()
add_test(UnitTests ${PROJECT_NAME}_unit)
add_test(FunctionalTests ${PROJECT_NAME}_functional)
