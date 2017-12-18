cmake_minimum_required(VERSION 3.6)
project(RAC_Renifleur)
set (CMAKE_CXX_STANDARD 11)

set(gtest_SOURCE_DIR, third_party/googletest/googletest/include/)
set(SRC_LOG_TEST_DIRECTORY "test/log_unit_test")

################################
# GTest
################################

enable_testing()
add_subdirectory(third_party/googletest)
include_directories(${gtest_SOURCE_DIR})

################################
# Unit Tests
################################

# Add test cpp file
add_executable( runUnitTests test/log_unit_test/log_unit_test.cpp )

# Link test executable against gtest & gtest_main
target_link_libraries(runUnitTests gtest gtest_main)
add_test( runUnitTests runUnitTests )


################################
# END GTest
################################


set(INCLUDE_LOG_DIRECTORY "include/log/")
set(INCLUDE_TIME_DIRECTORY "include/time/")
set(EXECUTABLE_OUTPUT_PATH bin)


    add_executable(

	    RAC_Renifleur

	    main.cpp

	    src/log/LogHandler.cpp
	    include/log/LogHandler.h
	    include/log/LogInstanceInitializer.h

	    include/time/TimeHandler.h
	    )

include_directories(${INCLUDE_LOG_DIRECTORY} ${gtest_SOURCE_DIR} ${INCLUDE_TIME_DIRECTORY})
