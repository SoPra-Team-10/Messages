/**
 * @file Snapshot.hpp
 * @author paul
 * @date 19.03.19
 * @brief Declaration of the Snapshot class
 */

#ifndef SERVER_SNAPSHOT_HPP
#define SERVER_SNAPSHOT_HPP

#include <string>
#include "json.hpp"

#include "types.hpp"
#include "DeltaBroadcast.hpp"

namespace communication::messages::broadcast {
    class TeamSnapshot {
    public:
        TeamSnapshot() = default;
        TeamSnapshot(int points, std::vector<std::pair<types::FanType, bool>> fans, int seekerX, int seekerY,
                     bool seekerBanned, bool seekerTurnUsed, bool seekerKnockout, int keeperX, int keeperY,
                     bool keeperBanned, bool keeperHoldsQuaffle, bool keeperTurnUsed, bool keeperKnockout, int chaser1X,
                     int chaser1Y, bool chaser1Banned, bool chaser1HoldsQuaffle, bool chaser1TurnUsed,
                     bool chaser1Knockout, int chaser2X, int chaser2Y, bool chaser2Banned, bool chaser2HoldsQuaffle,
                     bool chaser2TurnUsed, bool chaser2Knockout, int chaser3X, int chaser3Y, bool chaser3Banned,
                     bool chaser3HoldsQuaffle, bool chaser3TurnUsed, bool chaser3Knockout, int beater1X, int beater1Y,
                     bool beater1Banned, bool beater1HoldsBludger, bool beater1TurnUsed, bool beater1Knockout,
                     int beater2X, int beater2Y, bool beater2Banned, bool beater2HoldsBludger, bool beater2TurnUsed,
                     bool beater2Knockout);

        int getPoints() const;
        std::vector<std::pair<types::FanType, bool>> getFans() const;
        int getSeekerX() const;
        int getSeekerY() const;
        bool isSeekerBanned() const;
        bool isSeekerTurnUsed() const;
        int getKeeperX() const;
        int getKeeperY() const;
        bool isKeeperBanned() const;
        bool isKeeperHoldsQuaffle() const;
        bool isKeeperTurnUsed() const;
        int getChaser1X() const;
        int getChaser1Y() const;
        bool isChaser1Banned() const;
        bool isChaser1HoldsQuaffle() const;
        bool isChaser1TurnUsed() const;
        int getChaser2X() const;
        int getChaser2Y() const;
        bool isChaser2Banned() const;
        bool isChaser2HoldsQuaffle() const;
        bool isChaser2TurnUsed() const;
        int getChaser3X() const;
        int getChaser3Y() const;
        bool isChaser3Banned() const;
        bool isChaser3HoldsQuaffle() const;
        bool isChaser3TurnUsed() const;
        int getBeater1X() const;
        int getBeater1Y() const;
        bool isBeater1Banned() const;
        bool isBeater1HoldsBludger() const;
        bool isBeater1TurnUsed() const;
        int getBeater2X() const;
        int getBeater2Y() const;
        bool isBeater2Banned() const;
        bool isBeater2HoldsBludger() const;
        bool isBeater2TurnUsed() const;

        bool isSeekerKnockout() const;

        bool isKeeperKnockout() const;

        bool isChaser1Knockout() const;

        bool isChaser2Knockout() const;

        bool isChaser3Knockout() const;

        bool isBeater1Knockout() const;

        bool isBeater2Knockout() const;

        bool operator==(const TeamSnapshot &rhs) const;

        bool operator!=(const TeamSnapshot &rhs) const;

    private:
        int points{};
        std::vector<std::pair<types::FanType, bool>> fans;
        int seekerX{}, seekerY{};
        bool seekerBanned{}, seekerTurnUsed{}, seekerKnockout{};
        int keeperX{}, keeperY{};
        bool keeperBanned{}, keeperHoldsQuaffle{}, keeperTurnUsed{}, keeperKnockout{};
        int chaser1X{}, chaser1Y{};
        bool chaser1Banned{}, chaser1HoldsQuaffle{}, chaser1TurnUsed{}, chaser1Knockout{};
        int chaser2X{}, chaser2Y{};
        bool chaser2Banned{}, chaser2HoldsQuaffle{}, chaser2TurnUsed{}, chaser2Knockout{};
        int chaser3X{}, chaser3Y{};
        bool chaser3Banned{}, chaser3HoldsQuaffle{}, chaser3TurnUsed{}, chaser3Knockout{};
        int beater1X{}, beater1Y{};
        bool beater1Banned{}, beater1HoldsBludger{}, beater1TurnUsed{}, beater1Knockout{};
        int beater2X{}, beater2Y{};
        bool beater2Banned{}, beater2HoldsBludger{}, beater2TurnUsed{}, beater2Knockout{};
    };

    void to_json(nlohmann::json &j, const TeamSnapshot &teamSnaphot);
    void from_json(const nlohmann::json &j, TeamSnapshot &teamSnaphot);

    class Snapshot {
    public:
        Snapshot() = default;
        Snapshot(broadcast::DeltaBroadcast lastDeltaBroadcast, types::PhaseType phase, std::vector<std::string> spectatorUserName, int round,
                 TeamSnapshot leftTeam, TeamSnapshot rightTeam, std::optional<int> snitchX, std::optional<int> snitchY, int quaffleX,
                 int quaffleY, int bludger1X, int bludger1Y, int bludger2X, int bludger2Y);

        DeltaBroadcast getLastDeltaBroadcast() const;

        types::PhaseType getPhase() const;
        std::vector<std::string> getSpectatorUserName() const;
        int getRound() const;
        TeamSnapshot getLeftTeam() const;
        TeamSnapshot getRightTeam() const;
        std::optional<int> getSnitchX() const;
        std::optional<int> getSnitchY() const;
        int getQuaffleX() const;
        int getQuaffleY() const;
        int getBludger1X() const;
        int getBludger1Y() const;
        int getBludger2X() const;
        int getBludger2Y() const;

        static auto getName() -> std::string;

        bool operator==(const Snapshot &rhs) const;

        bool operator!=(const Snapshot &rhs) const;

    private:
        broadcast::DeltaBroadcast lastDeltaBroadcast;
        types::PhaseType phase{};
        std::vector<std::string> spectatorUserName;
        int round{};
        TeamSnapshot leftTeam, rightTeam;
        std::optional<int> snitchX{}, snitchY{};
        int quaffleX{}, quaffleY{};
        int bludger1X{}, bludger1Y{};
        int bludger2X{}, bludger2Y{};
    };

    void to_json(nlohmann::json &j, const Snapshot &snaphot);
    void from_json(const nlohmann::json &j, Snapshot &snaphot);
}

#endif //SERVER_SNAPSHOT_HPP
