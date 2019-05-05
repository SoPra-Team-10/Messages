//
// Created by paulnykiel on 04.05.19.
//

#include "ReplayWithSnapshot.h"

namespace commmunication::messages::mods::broadcast {

    auto ReplayWithSnapshot::getName() -> std::string {
        return "replayWithSnapshot";
    }

    ReplayWithSnapshot::ReplayWithSnapshot(const std::string &lobby, const std::string &startTimestamp,
                                           const communication::messages::broadcast::MatchConfig &matchConfig,
                                           const communication::messages::request::TeamConfig &leftTeamConfig,
                                           const communication::messages::request::TeamConfig &rightTeamConfig,
                                           const std::string &leftTeamUserName, const std::string &rightTeamUserName,
                                           const std::vector<std::string> &spectatorUserName,
                                           const communication::messages::broadcast::Snapshot &firstSnapshot,
                                           const std::vector<communication::messages::Message> &messages) : lobby(
            lobby), startTimestamp(startTimestamp), matchConfig(matchConfig), leftTeamConfig(leftTeamConfig),
                                                                                                            rightTeamConfig(
                                                                                                                    rightTeamConfig),
                                                                                                            leftTeamUserName(
                                                                                                                    leftTeamUserName),
                                                                                                            rightTeamUserName(
                                                                                                                    rightTeamUserName),
                                                                                                            spectatorUserName(
                                                                                                                    spectatorUserName),
                                                                                                            firstSnapshot(
                                                                                                                    firstSnapshot),
                                                                                                            messages(
                                                                                                                    messages) {}

    const std::string &ReplayWithSnapshot::getLobby() const {
        return lobby;
    }

    const std::string &ReplayWithSnapshot::getStartTimestamp() const {
        return startTimestamp;
    }

    const communication::messages::broadcast::MatchConfig &ReplayWithSnapshot::getMatchConfig() const {
        return matchConfig;
    }

    const communication::messages::request::TeamConfig &ReplayWithSnapshot::getLeftTeamConfig() const {
        return leftTeamConfig;
    }

    const communication::messages::request::TeamConfig &ReplayWithSnapshot::getRightTeamConfig() const {
        return rightTeamConfig;
    }

    const std::string &ReplayWithSnapshot::getLeftTeamUserName() const {
        return leftTeamUserName;
    }

    const std::string &ReplayWithSnapshot::getRightTeamUserName() const {
        return rightTeamUserName;
    }

    const std::vector<std::string> &ReplayWithSnapshot::getSpectatorUserName() const {
        return spectatorUserName;
    }

    const communication::messages::broadcast::Snapshot &ReplayWithSnapshot::getFirstSnapshot() const {
        return firstSnapshot;
    }

    const std::vector<communication::messages::Message> &ReplayWithSnapshot::getMessages() const {
        return messages;
    }

    bool ReplayWithSnapshot::operator==(const ReplayWithSnapshot &rhs) const {
        return lobby == rhs.lobby &&
               startTimestamp == rhs.startTimestamp &&
               matchConfig == rhs.matchConfig &&
               leftTeamConfig == rhs.leftTeamConfig &&
               rightTeamConfig == rhs.rightTeamConfig &&
               leftTeamUserName == rhs.leftTeamUserName &&
               rightTeamUserName == rhs.rightTeamUserName &&
               spectatorUserName == rhs.spectatorUserName &&
               firstSnapshot == rhs.firstSnapshot &&
               messages == rhs.messages;
    }

    bool ReplayWithSnapshot::operator!=(const ReplayWithSnapshot &rhs) const {
        return !(rhs == *this);
    }

}
