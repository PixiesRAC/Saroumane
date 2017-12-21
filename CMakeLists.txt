cmake_minimum_required(VERSION 3.6)
project(RAC_RenifleurDuXul)
set (CMAKE_CXX_STANDARD 14)

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
add_executable( runUnitTests test/log_unit_test/log_unit_test.cpp test/conf_unit_test/conf_unit_test.cpp src/conf/JsonConfHandler.cpp)

# Link test executable against gtest & gtest_main
target_link_libraries(runUnitTests gtest gtest_main)
add_test( runUnitTests runUnitTests )


################################
# END GTest
################################


################################
# Json Boost
################################

set(INCLUDE_JSONBOOST_DIR, third_party/property_tree/include/)

################################
# END Json Boost
################################

set(INCLUDE_LOG_DIRECTORY "include/log/")
set(INCLUDE_TIME_DIRECTORY "include/time/")
set(INCLUDE_SOCKET_DIRECTORY "include/socket/")
set(INCLUDE_CONF_DIRECTORY "include/conf/")
set(EXECUTABLE_OUTPUT_PATH bin)

    add_executable(

	    RAC_RenifleurDuXul

	    main.cpp

	    src/log/LogHandler.cpp
	    include/log/LogHandler.h
	    include/log/LogInstanceInitializer.h

	    include/time/TimeHandler.h

	    src/socket/RawSocketTCP.cpp
	    include/socket/IRawSocket.h
	    include/socket/RawSocketTCP.h

	    src/conf/JsonConfHandler.cpp
	    include/conf/JsonConfHandler.h
	    include/conf/JsonConfInstanceInitializer.h
	    )

include_directories(${INCLUDE_LOG_DIRECTORY} ${gtest_SOURCE_DIR} ${INCLUDE_TIME_DIRECTORY} 
		    ${INCLUDE_SOCKET_DIRECTORY} ${INCLUDE_CONF_DIRECTORY} ${INCLUDE_JSONBOOST_DIR} )
