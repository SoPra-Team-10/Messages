//
// Created by paulnykiel on 04.05.19.
//

#ifndef SOPRAMESSAGES_REPLAYWITHSNAPSHOT_H
#define SOPRAMESSAGES_REPLAYWITHSNAPSHOT_H

#include <string>
#include <TeamConfig.hpp>
#include <Snapshot.hpp>
#include <Message.hpp>
#include "json.hpp"
#include "MatchConfig.hpp"

namespace commmunication::messages::mods::broadcast {
    class ReplayWithSnapshot {
    public:
        static auto getName() -> std::string;

    private:
        std::string lobby, startTimestamp;
        communication::messages::broadcast::MatchConfig matchConfig;
        communication::messages::request::TeamConfig leftTeamConfig, rightTeamConfig;
        std::string leftTeamUserName, rightTeamUserName;
        std::vector<std::string> spectatorUserName;
        communication::messages::broadcast::Snapshot firstSnapshot;
        std::vector<communication::messages::Message> messages;
    };
}

#endif //SOPRAMESSAGES_REPLAYWITHSNAPSHOT_H
