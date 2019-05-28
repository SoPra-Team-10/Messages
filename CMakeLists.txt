cmake_minimum_required(VERSION 3.10)

# Build options
set(CMAKE_CXX_STANDARD 17)

if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release)
endif(NOT CMAKE_BUILD_TYPE)

set(CMAKE_CXX_FLAGS "-Wall -Wextra -Wpedantic")
if (CMAKE_BUILD_TYPE STREQUAL "Debug")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=address -fno-omit-frame-pointer")
endif ()

# Building
project(SopraMessages VERSION 0.0.1 DESCRIPTION "Messages for SoPra")

include_directories(src/Broadcast src/Request src/Unicast src/Common src/Lib src/Util src/Mods/Broadcast src/Mods/Request src/Mods/Unicast ${CMAKE_SOURCE_DIR})

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
        "Message.hpp;Broadcast/DeltaBroadcast.hpp;Broadcast/GlobalDebug.hpp;Broadcast/LoginGreeting.hpp;Broadcast/MatchConfig.hpp;Broadcast/MatchFinish.hpp;Broadcast/MatchStart.hpp;Broadcast/Next.hpp;Broadcast/PauseResponse.hpp;Broadcast/Replay.hpp;Broadcast/Snapshot.hpp;Request/ContinueRequest.hpp;Request/DeltaRequest.hpp;Request/GetReplay.hpp;Request/JoinRequest.hpp;Request/PauseRequest.hpp;Request/SendDebug.hpp;Request/TeamConfig.hpp;Request/TeamFormation.hpp;Unicast/JoinResponse.hpp;Unicast/PrivateDebug.hpp;Unicast/Reconnect.hpp;Common/types.hpp;Common/Delta.hpp;Lib/json.hpp;Util/OptionalSerialization.hpp;ReplayMessage.h;Mods/Broadcast/GlobalChat.h;Mods/Request/GetReplayWithSnapshot.h;Mods/Request/SendChat.h;Mods/Unicast/PrivateError.h;Mods/Unicast/PrivateWarning.h;Mods/Unicast/ReplayWithSnapshot.h;Other/LobbyMod.hpp;Mods/Unicast/ReconnectChat.h")
install(TARGETS ${PROJECT_NAME}
        LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
        PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/SopraMessages)

add_subdirectory(Tests)
