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

    void to_json(nlohmann::json &j, const ReplayWithSnapshot &replayWithSnapshot) {
        j["lobby"] = replayWithSnapshot.getLobby();
        j["startTimestamp"] = replayWithSnapshot.getStartTimestamp();
        j["matchConfig"] = replayWithSnapshot.getMatchConfig();
        j["leftTeamConfig"] = replayWithSnapshot.getLeftTeamConfig();
        j["rightTeamConfig"] = replayWithSnapshot.getRightTeamConfig();
        j["leftTeamUserName"] = replayWithSnapshot.getLeftTeamUserName();
        j["rightTeamUserName"] = replayWithSnapshot.getRightTeamUserName();
        j["spectatorUserName"] = replayWithSnapshot.getSpectatorUserName();
        j["firstSnapshot"] = replayWithSnapshot.getFirstSnapshot();
        j["log"] = replayWithSnapshot.getMessages();
    }

    void from_json(const nlohmann::json &j, ReplayWithSnapshot &replayWithSnapshot) {
        replayWithSnapshot = ReplayWithSnapshot{
            j.at("lobby").get<std::string>(),
            j.at("startTimestamp").get<std::string>(),
            j.at("matchConfig").get<communication::messages::broadcast::MatchConfig>(),
            j.at("leftTeamConfig").get<communication::messages::request::TeamConfig>(),
            j.at("rightTeamConfig").get<communication::messages::request::TeamConfig>(),
            j.at("leftTeamUserName").get<std::string>(),
            j.at("rightTeamUserName").get<std::string>(),
            j.at("spectatorUserNames").get<std::vector<std::string>>(),
            j.at("firstSnapshot").get<communication::messages::broadcast::Snapshot>(),
            j.at("log").get<std::vector<communication::messages::Message>>()
        };
    }
}