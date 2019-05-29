/**
 * @file Replay.hpp
 * @author paul
 * @date 19.03.19
 * @brief Declaration of the Replay class
 */

#ifndef SERVER_REPLAY_HPP
#define SERVER_REPLAY_HPP

#include <string>
#include "json.hpp"
#include "TeamConfig.hpp"
#include "MatchConfig.hpp"
#include "Snapshot.hpp"
#include "Message.hpp"

namespace communication::messages::broadcast {
    class Replay {
    public:
        Replay() = default;
        Replay(std::string lobby, std::string startTime, const MatchConfig &matchConfig, request::TeamConfig leftTeamConfig,
               request::TeamConfig rightTeamConfig, std::string leftTeamUserName,
               std::string rightTeamUserName, std::vector<std::string> spectatrUserNames,
               Snapshot firstSnapshot, std::vector<Message> log);

        Replay(std::string lobby, std::string startTime, const MatchConfig &matchConfig);

        std::string getLobby() const;

        std::string getStartTime() const;

        MatchConfig getMatchConfig() const;

        request::TeamConfig getLeftTeamConfig() const;

        request::TeamConfig getRightTeamConfig() const;

        std::string getLeftTeamUserName() const;

        std::string getRightTeamUserName() const;

        std::vector<std::string> getSpectatorUserNames() const;

        Snapshot getFirstSnapshot() const;

        std::vector<Message> getLog() const;

        static auto getName() -> std::string;

        bool operator==(const Replay &rhs) const;

        bool operator!=(const Replay &rhs) const;

        void setLeftTeamConfig(const request::TeamConfig &leftTeamConfig);

        void setRightTeamConfig(const request::TeamConfig &rightTeamConfig);

        void setLeftTeamUserName(const std::string &leftTeamUserName);

        void setRightTeamUserName(const std::string &rightTeamUserName);

        void addSpectator(const std::string &name);

        void setFirstSnapshot(const Snapshot &firstSnapshot);

        void addLog(const messages::Message &message);
    private:
        std::string lobby;
        std::string startTime;
        MatchConfig matchConfig{};
        request::TeamConfig leftTeamConfig, rightTeamConfig;
        std::string leftTeamUserName, rightTeamUserName;
        std::vector<std::string> spectatorUserNames;
        Snapshot firstSnapshot;
        std::vector<Message> log;
    };

    void to_json(nlohmann::json &j, const Replay &replay);
    void from_json(const nlohmann::json &j, Replay &replay);
}

#endif //SERVER_REPLAY_HPP
