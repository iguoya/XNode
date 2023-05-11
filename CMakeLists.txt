cmake_minimum_required(VERSION 3.5)

project(XNode LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


#find_package(Poco REQUIRED)
find_package(nlohmann_json REQUIRED)

set(PROJECT_SOURCES
    main.cpp
    xnode.h xnode.cpp
    server.h server.cpp
    client.h client.cpp
    message.h message.cpp
#    command/connect.h command/connect.cpp
    command.h command.cpp
#    config.json
#    conanfile.txt
)

add_executable(XNode
    ${PROJECT_SOURCES}
)

#include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
#conan_basic_setup()



#add_executable(XNode main.cpp xnode.h xnode.cpp)


add_subdirectory(Application)
#add_subdirectory(ConanExample)
#add_subdirectory(compressor)
#add_subdirectory(NodeServer)
#add_subdirectory(StandAloneNode)
#add_subdirectory(Server)

#add_subdirectory(Client)
