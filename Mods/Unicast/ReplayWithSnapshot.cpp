#include <utility>

#include <utility>

//
// Created by paulnykiel on 04.05.19.
//

#include "ReplayWithSnapshot.h"

#include <utility>

namespace communication::messages::mods::unicast {

    auto ReplayWithSnapshot::getName() -> std::string {
        return "replayWithSnapshot";
    }

    ReplayWithSnapshot::ReplayWithSnapshot(std::string lobby, std::string startTimestamp,
                                           const communication::messages::broadcast::MatchConfig &matchConfig,
                                           communication::messages::request::TeamConfig leftTeamConfig,
                                           communication::messages::request::TeamConfig rightTeamConfig,
                                           std::string leftTeamUserName, std::string rightTeamUserName,
                                           std::vector<std::string> spectatorUserName,
                                           communication::messages::broadcast::Snapshot firstSnapshot,
                                           std::vector<communication::messages::Message> messages) : lobby(std::move(
            lobby)), startTimestamp(std::move(startTimestamp)), matchConfig(matchConfig), leftTeamConfig(std::move(leftTeamConfig)),
                                                                                                            rightTeamConfig(std::move(
                                                                                                                    rightTeamConfig)),
                                                                                                            leftTeamUserName(std::move(
                                                                                                                    leftTeamUserName)),
                                                                                                            rightTeamUserName(std::move(
                                                                                                                    rightTeamUserName)),
                                                                                                            spectatorUserName(std::move(
                                                                                                                    spectatorUserName)),
                                                                                                            firstSnapshot(std::move(
                                                                                                                    firstSnapshot)),
                                                                                                            messages(std::move(
                                                                                                                    messages)) {}

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

    ReplayWithSnapshot::ReplayWithSnapshot(std::string lobby, std::string startTime,
                                           const communication::messages::broadcast::MatchConfig &matchConfig)
                                           : lobby{std::move(lobby)},
                                           startTimestamp{std::move(startTime)}, matchConfig{matchConfig} {}

    void ReplayWithSnapshot::setLeftTeamConfig(const communication::messages::request::TeamConfig &leftTeamConfig) {
        this->leftTeamConfig = leftTeamConfig;
    }

    void ReplayWithSnapshot::setRightTeamConfig(const communication::messages::request::TeamConfig &rightTeamConfig) {
        this->rightTeamConfig = rightTeamConfig;
    }

    void ReplayWithSnapshot::setLeftTeamUserName(const std::string &leftTeamUserName) {
        this->leftTeamUserName = leftTeamUserName;
    }

    void ReplayWithSnapshot::setRightTeamUserName(const std::string &rightTeamUserName) {
        this->rightTeamUserName = rightTeamUserName;
    }

    void ReplayWithSnapshot::addSpectator(const std::string &name) {
        this->spectatorUserName.emplace_back(name);
    }

    void ReplayWithSnapshot::setFirstSnapshot(const communication::messages::broadcast::Snapshot &firstSnapshot) {
        this->firstSnapshot = firstSnapshot;
    }

    void ReplayWithSnapshot::addLog(const messages::Message &message) {
        this->messages.emplace_back(message);
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
            j.at("spectatorUserName").get<std::vector<std::string>>(),
            j.at("firstSnapshot").get<communication::messages::broadcast::Snapshot>(),
            j.at("log").get<std::vector<communication::messages::Message>>()
        };
    }
}
