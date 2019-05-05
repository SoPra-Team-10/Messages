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

namespace communication::messages::mods::unicast {
    class ReplayWithSnapshot {
    public:
        ReplayWithSnapshot() = default;
        ReplayWithSnapshot(std::string lobby, std::string startTimestamp,
                           const communication::messages::broadcast::MatchConfig &matchConfig,
                           communication::messages::request::TeamConfig leftTeamConfig,
                           communication::messages::request::TeamConfig rightTeamConfig,
                           std::string leftTeamUserName, std::string rightTeamUserName,
                           std::vector<std::string> spectatorUserName,
                           communication::messages::broadcast::Snapshot firstSnapshot,
                           std::vector<communication::messages::Message> messages);

        const std::string &getLobby() const;

        const std::string &getStartTimestamp() const;

        const communication::messages::broadcast::MatchConfig &getMatchConfig() const;

        const communication::messages::request::TeamConfig &getLeftTeamConfig() const;

        const communication::messages::request::TeamConfig &getRightTeamConfig() const;

        const std::string &getLeftTeamUserName() const;

        const std::string &getRightTeamUserName() const;

        const std::vector<std::string> &getSpectatorUserName() const;

        const communication::messages::broadcast::Snapshot &getFirstSnapshot() const;

        const std::vector<communication::messages::Message> &getMessages() const;

        bool operator==(const ReplayWithSnapshot &rhs) const;

        bool operator!=(const ReplayWithSnapshot &rhs) const;

        static auto getName() -> std::string;
    private:
        std::string lobby, startTimestamp;
        communication::messages::broadcast::MatchConfig matchConfig{};
        communication::messages::request::TeamConfig leftTeamConfig, rightTeamConfig;
        std::string leftTeamUserName, rightTeamUserName;
        std::vector<std::string> spectatorUserName;
        communication::messages::broadcast::Snapshot firstSnapshot;
        std::vector<communication::messages::Message> messages;
    };

    void to_json(nlohmann::json &j, const ReplayWithSnapshot &replayWithSnapshot);
    void from_json(const nlohmann::json &j, ReplayWithSnapshot &replayWithSnapshot);
}

#endif //SOPRAMESSAGES_REPLAYWITHSNAPSHOT_H
