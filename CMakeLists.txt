cmake_minimum_required(VERSION 3.10)

# Build options
set(CMAKE_CXX_STANDARD 17)

if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release)
endif(NOT CMAKE_BUILD_TYPE)

set(CMAKE_CXX_FLAGS "-Wall -Wextra -Wpedantic -Werror -Wno-implicit-fallthrough -march=native -mtune=native")
if (CMAKE_BUILD_TYPE STREQUAL "Debug")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=address -fno-omit-frame-pointer")
    message("Building for debug")
else()
    set(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -O3")
    message("Building for release")
endif ()

# Building
project(SopraMessages VERSION 0.0.1 DESCRIPTION "Messages for SoPra")

include_directories(
        ${CMAKE_SOURCE_DIR}/src/Broadcast
        ${CMAKE_SOURCE_DIR}/src/Request
        ${CMAKE_SOURCE_DIR}/src/Unicast
        ${CMAKE_SOURCE_DIR}/src/Common
        ${CMAKE_SOURCE_DIR}/src/Lib
        ${CMAKE_SOURCE_DIR}/src/Util
        ${CMAKE_SOURCE_DIR}/src/Mods/Broadcast
        ${CMAKE_SOURCE_DIR}/src/Mods/Request
        ${CMAKE_SOURCE_DIR}/src/Mods/Unicast
        ${CMAKE_SOURCE_DIR}/src)

set(SOURCES
        ${CMAKE_SOURCE_DIR}/src/Message.cpp
        ${CMAKE_SOURCE_DIR}/src/Broadcast/DeltaBroadcast.cpp
        ${CMAKE_SOURCE_DIR}/src/Broadcast/GlobalDebug.cpp
        ${CMAKE_SOURCE_DIR}/src/Broadcast/LoginGreeting.cpp
        ${CMAKE_SOURCE_DIR}/src/Broadcast/MatchConfig.cpp
        ${CMAKE_SOURCE_DIR}/src/Broadcast/MatchFinish.cpp
        ${CMAKE_SOURCE_DIR}/src/Broadcast/MatchStart.cpp
        ${CMAKE_SOURCE_DIR}/src/Broadcast/Next.cpp
        ${CMAKE_SOURCE_DIR}/src/Broadcast/PauseResponse.cpp
        ${CMAKE_SOURCE_DIR}/src/Broadcast/Replay.cpp
        ${CMAKE_SOURCE_DIR}/src/Broadcast/Snapshot.cpp
        ${CMAKE_SOURCE_DIR}/src/Request/ContinueRequest.cpp
        ${CMAKE_SOURCE_DIR}/src/Request/DeltaRequest.cpp
        ${CMAKE_SOURCE_DIR}/src/Request/GetReplay.cpp
        ${CMAKE_SOURCE_DIR}/src/Request/JoinRequest.cpp
        ${CMAKE_SOURCE_DIR}/src/Request/PauseRequest.cpp
        ${CMAKE_SOURCE_DIR}/src/Request/SendDebug.cpp
        ${CMAKE_SOURCE_DIR}/src/Request/TeamConfig.cpp
        ${CMAKE_SOURCE_DIR}/src/Request/TeamFormation.cpp
        ${CMAKE_SOURCE_DIR}/src/Unicast/JoinResponse.cpp
        ${CMAKE_SOURCE_DIR}/src/Unicast/PrivateDebug.cpp
        ${CMAKE_SOURCE_DIR}/src/Unicast/Reconnect.cpp
        ${CMAKE_SOURCE_DIR}/src/Common/types.cpp
        ${CMAKE_SOURCE_DIR}/src/Common/Delta.cpp
        ${CMAKE_SOURCE_DIR}/src/ReplayMessage.cpp
        ${CMAKE_SOURCE_DIR}/src/Mods/Broadcast/GlobalChat.cpp
        ${CMAKE_SOURCE_DIR}/src/Mods/Request/GetReplayWithSnapshot.cpp
        ${CMAKE_SOURCE_DIR}/src/Mods/Request/SendChat.cpp
        ${CMAKE_SOURCE_DIR}/src/Mods/Unicast/PrivateError.cpp
        ${CMAKE_SOURCE_DIR}/src/Mods/Unicast/PrivateWarning.cpp
        ${CMAKE_SOURCE_DIR}/src/Mods/Unicast/ReplayWithSnapshot.cpp
        ${CMAKE_SOURCE_DIR}/src/Other/LobbyMod.cpp
        ${CMAKE_SOURCE_DIR}/src/Mods/Unicast/ReconnectChat.cpp)

include_directories(${CMAKE_SOURCE_DIR})
add_library(${PROJECT_NAME} SHARED ${SOURCES})

# Installation via make install
include(GNUInstallDirs)
set_target_properties(${PROJECT_NAME} PROPERTIES
        VERSION ${PROJECT_VERSION}
        SOVERSION 1
        PUBLIC_HEADER
        "src/Message.hpp;src/Broadcast/DeltaBroadcast.hpp;src/Broadcast/GlobalDebug.hpp;src/Broadcast/LoginGreeting.hpp;src/Broadcast/MatchConfig.hpp;src/Broadcast/MatchFinish.hpp;src/Broadcast/MatchStart.hpp;src/Broadcast/Next.hpp;src/Broadcast/PauseResponse.hpp;src/Broadcast/Replay.hpp;src/Broadcast/Snapshot.hpp;src/Request/ContinueRequest.hpp;src/Request/DeltaRequest.hpp;src/Request/GetReplay.hpp;src/Request/JoinRequest.hpp;src/Request/PauseRequest.hpp;src/Request/SendDebug.hpp;src/Request/TeamConfig.hpp;src/Request/TeamFormation.hpp;src/Unicast/JoinResponse.hpp;src/Unicast/PrivateDebug.hpp;src/Unicast/Reconnect.hpp;src/Common/types.hpp;src/Common/Delta.hpp;src/Lib/json.hpp;src/Util/OptionalSerialization.hpp;src/ReplayMessage.h;src/Mods/Broadcast/GlobalChat.h;src/Mods/Request/GetReplayWithSnapshot.h;src/Mods/Request/SendChat.h;src/Mods/Unicast/PrivateError.h;src/Mods/Unicast/PrivateWarning.h;src/Mods/Unicast/ReplayWithSnapshot.h;src/Other/LobbyMod.hpp;src/Mods/Unicast/ReconnectChat.h")
install(TARGETS ${PROJECT_NAME}
        LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
        PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/SopraMessages)

add_subdirectory(Tests)
