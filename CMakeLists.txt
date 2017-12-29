cmake_minimum_required(VERSION 3.6)
project(RAC_RenifleurDuXul)
set (CMAKE_CXX_STANDARD 14)
add_definitions( "-Wall -pedantic -W" )

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
set(INCLUDE_FORMATBOOST_DIR, third_party/format/include/)

################################
# END Json Boost
################################

set(INCLUDE_LOG_DIRECTORY "include/log/")
set(INCLUDE_TIME_DIRECTORY "include/time/")
set(INCLUDE_SOCKET_DIRECTORY "include/socket/")
set(INCLUDE_CONF_DIRECTORY "include/conf/")
set(INCLUDE_ERROR_DIRECTORY "include/error/")
set(INCLUDE_DATA_DIRECTORY "include/data/")
set(INCLUDE_PROTOCOLS_DIRECTORY "include/protocols/")
set(INCLUDE_DECODER_DIRECTORY "include/decoder/")
set(EXECUTABLE_OUTPUT_PATH bin)

    add_executable(

	    RAC_RenifleurDuXul

	    main.cpp

	    src/log/LogHandler.cpp
	    include/log/LogHandler.h
	    include/log/LogInstanceInitializer.h

	    include/time/TimeHandler.h

	    src/socket/RawSocketTCP.cpp
	    src/socket/ISocket.cpp
	    include/socket/ISocket.h
	    include/socket/RawSocketTCP.h

	    src/conf/JsonConfHandler.cpp
	    include/conf/JsonConfHandler.h
	    include/conf/JsonConfInstanceInitializer.h

	    src/socket/RawSocketProducer.cpp
	    src/socket/RawSocketListener.cpp
	    include/socket/RawSocketProducer.h
	    include/socket/RawSocketListener.h

	    src/error/ErrorSocket.cpp
	    include/error/ErrorSocket.h

	    include/data/PacketData.h
	    include/data/RawDataInstanceInitializer.h

	    src/socket/RawSocketConsumer.cpp
	    include/socket/RawSocketConsumer.h

	    src/protocols/ProtocolIP.cpp
	    src/protocols/ProtocolEthernet.cpp
	    include/protocols/IProtocol.h
	    include/protocols/ProtocolIP.h
	    include/protocols/ProtocolsDefinition.h
	    include/protocols/ProtocolEthernet.h
	    include/protocols/ProtocolsHeader.h

	    src/decoder/DecoderLayer.cpp
	    include/decoder/DecoderLayer.h
	    )

TARGET_LINK_LIBRARIES( RAC_RenifleurDuXul
pthread
)
include_directories(${INCLUDE_LOG_DIRECTORY} ${gtest_SOURCE_DIR} ${INCLUDE_TIME_DIRECTORY} 
		    ${INCLUDE_SOCKET_DIRECTORY} ${INCLUDE_CONF_DIRECTORY} ${INCLUDE_JSONBOOST_DIR} 
		    ${INCLUDE_ERROR_DIRECTORY} ${INCLUDE_DATA_DIRECTORY}  ${INCLUDE_PROTOCOLS_DIRECTORY}
		    ${INCLUDE_FORMATBOOST_DIR} ${INCLUDE_DECODER_DIRECTORY} )




