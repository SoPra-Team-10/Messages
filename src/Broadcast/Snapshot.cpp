/**
 * @file Snapshot.cpp
 * @author paul
 * @date 19.03.19
 * @brief Declaration of the Snapshot class
 */

#include "Snapshot.hpp"

#include <utility>

#include "OptionalSerialization.hpp"

namespace communication::messages::broadcast {

    auto Snapshot::getName() -> std::string {
        return "snapshot";
    }

    Snapshot::Snapshot(broadcast::DeltaBroadcast lastDeltaBroadcast, types::PhaseType phase, std::vector<std::string> spectatorUserName, int round,
                       TeamSnapshot leftTeam, TeamSnapshot rightTeam, std::optional<int> snitchX, std::optional<int> snitchY,
                       int quaffleX, int quaffleY, int bludger1X, int bludger1Y, int bludger2X, int bludger2Y,
                       std::vector<std::pair<int, int>> wombatCubes, bool goalWasThrownThisRound) :
                       lastDeltaBroadcast{lastDeltaBroadcast}, phase(
            phase), spectatorUserName(std::move(spectatorUserName)), round(round), leftTeam(std::move(leftTeam)), rightTeam(std::move(rightTeam)),
                                                                                                                 snitchX(snitchX),
                                                                                                                 snitchY(snitchY),
                                                                                                                 quaffleX(
                                                                                                                         quaffleX),
                                                                                                                 quaffleY(
                                                                                                                         quaffleY),
                                                                                                                 bludger1X(
                                                                                                                         bludger1X),
                                                                                                                 bludger1Y(
                                                                                                                         bludger1Y),
                                                                                                                 bludger2X(
                                                                                                                         bludger2X),
                                                                                                                 bludger2Y(
                                                                                                                         bludger2Y),
                                                                                                                 wombatCubes(std::move(wombatCubes)),
                                                                                                                 goalWasThrownThisRound(goalWasThrownThisRound) {}

    types::PhaseType Snapshot::getPhase() const {
        return phase;
    }

    std::vector<std::string> Snapshot::getSpectatorUserName() const {
        return spectatorUserName;
    }

    int Snapshot::getRound() const {
        return round;
    }

    TeamSnapshot Snapshot::getLeftTeam() const {
        return leftTeam;
    }

    TeamSnapshot Snapshot::getRightTeam() const {
        return rightTeam;
    }

    std::optional<int >Snapshot::getSnitchX() const {
        return snitchX;
    }

    std::optional<int> Snapshot::getSnitchY() const {
        return snitchY;
    }

    int Snapshot::getQuaffleX() const {
        return quaffleX;
    }

    int Snapshot::getQuaffleY() const {
        return quaffleY;
    }

    int Snapshot::getBludger1X() const {
        return bludger1X;
    }

    int Snapshot::getBludger1Y() const {
        return bludger1Y;
    }

    int Snapshot::getBludger2X() const {
        return bludger2X;
    }

    int Snapshot::getBludger2Y() const {
        return bludger2Y;
    }

    bool Snapshot::operator==(const Snapshot &rhs) const {
        return phase == rhs.phase &&
               spectatorUserName == rhs.spectatorUserName &&
               round == rhs.round &&
               leftTeam == rhs.leftTeam &&
               rightTeam == rhs.rightTeam &&
               snitchX == rhs.snitchX &&
               snitchY == rhs.snitchY &&
               quaffleX == rhs.quaffleX &&
               quaffleY == rhs.quaffleY &&
               bludger1X == rhs.bludger1X &&
               bludger1Y == rhs.bludger1Y &&
               bludger2X == rhs.bludger2X &&
               bludger2Y == rhs.bludger2Y &&
               wombatCubes == rhs.wombatCubes &&
               goalWasThrownThisRound == rhs.goalWasThrownThisRound;
    }

    bool Snapshot::operator!=(const Snapshot &rhs) const {
        return !(rhs == *this);
    }

    DeltaBroadcast Snapshot::getLastDeltaBroadcast() const {
        return lastDeltaBroadcast;
    }

    void Snapshot::setSpectators(const std::vector<std::string> &spectators) {
        this->spectatorUserName = spectators;
    }

    auto Snapshot::getWombatCubes() const -> std::vector<std::pair<int, int>> {
        return wombatCubes;
    }

    bool Snapshot::isGoalWasThrownThisRound() const {
        return goalWasThrownThisRound;
    }

    int TeamSnapshot::getPoints() const {
        return points;
    }

    std::vector<Fan> TeamSnapshot::getFans() const {
        return fans;
    }

    int TeamSnapshot::getSeekerX() const {
        return seekerX;
    }

    int TeamSnapshot::getSeekerY() const {
        return seekerY;
    }

    bool TeamSnapshot::isSeekerBanned() const {
        return seekerBanned;
    }

    bool TeamSnapshot::isSeekerTurnUsed() const {
        return seekerTurnUsed;
    }

    int TeamSnapshot::getKeeperX() const {
        return keeperX;
    }

    int TeamSnapshot::getKeeperY() const {
        return keeperY;
    }

    bool TeamSnapshot::isKeeperBanned() const {
        return keeperBanned;
    }

    bool TeamSnapshot::isKeeperHoldsQuaffle() const {
        return keeperHoldsQuaffle;
    }

    bool TeamSnapshot::isKeeperTurnUsed() const {
        return keeperTurnUsed;
    }

    int TeamSnapshot::getChaser1X() const {
        return chaser1X;
    }

    int TeamSnapshot::getChaser1Y() const {
        return chaser1Y;
    }

    bool TeamSnapshot::isChaser1Banned() const {
        return chaser1Banned;
    }

    bool TeamSnapshot::isChaser1HoldsQuaffle() const {
        return chaser1HoldsQuaffle;
    }

    bool TeamSnapshot::isChaser1TurnUsed() const {
        return chaser1TurnUsed;
    }

    int TeamSnapshot::getChaser2X() const {
        return chaser2X;
    }

    int TeamSnapshot::getChaser2Y() const {
        return chaser2Y;
    }

    bool TeamSnapshot::isChaser2Banned() const {
        return chaser2Banned;
    }

    bool TeamSnapshot::isChaser2HoldsQuaffle() const {
        return chaser2HoldsQuaffle;
    }

    bool TeamSnapshot::isChaser2TurnUsed() const {
        return chaser2TurnUsed;
    }

    int TeamSnapshot::getChaser3X() const {
        return chaser3X;
    }

    int TeamSnapshot::getChaser3Y() const {
        return chaser3Y;
    }

    bool TeamSnapshot::isChaser3Banned() const {
        return chaser3Banned;
    }

    bool TeamSnapshot::isChaser3HoldsQuaffle() const {
        return chaser3HoldsQuaffle;
    }

    bool TeamSnapshot::isChaser3TurnUsed() const {
        return chaser3TurnUsed;
    }

    int TeamSnapshot::getBeater1X() const {
        return beater1X;
    }

    int TeamSnapshot::getBeater1Y() const {
        return beater1Y;
    }

    bool TeamSnapshot::isBeater1Banned() const {
        return beater1Banned;
    }

    bool TeamSnapshot::isBeater1HoldsBludger() const {
        return beater1HoldsBludger;
    }

    bool TeamSnapshot::isBeater1TurnUsed() const {
        return beater1TurnUsed;
    }

    int TeamSnapshot::getBeater2X() const {
        return beater2X;
    }

    int TeamSnapshot::getBeater2Y() const {
        return beater2Y;
    }

    bool TeamSnapshot::isBeater2Banned() const {
        return beater2Banned;
    }

    bool TeamSnapshot::isBeater2HoldsBludger() const {
        return beater2HoldsBludger;
    }

    bool TeamSnapshot::isBeater2TurnUsed() const {
        return beater2TurnUsed;
    }


    TeamSnapshot::TeamSnapshot(int points, std::vector<Fan> fans, int seekerX,
                               int seekerY, bool seekerBanned, bool seekerTurnUsed, bool seekerKnockout, int keeperX,
                               int keeperY, bool keeperBanned, bool keeperHoldsQuaffle, bool keeperTurnUsed,
                               bool keeperKnockout, int chaser1X, int chaser1Y, bool chaser1Banned,
                               bool chaser1HoldsQuaffle, bool chaser1TurnUsed, bool chaser1Knockout, int chaser2X,
                               int chaser2Y, bool chaser2Banned, bool chaser2HoldsQuaffle, bool chaser2TurnUsed,
                               bool chaser2Knockout, int chaser3X, int chaser3Y, bool chaser3Banned,
                               bool chaser3HoldsQuaffle, bool chaser3TurnUsed, bool chaser3Knockout, int beater1X,
                               int beater1Y, bool beater1Banned, bool beater1HoldsBludger, bool beater1TurnUsed,
                               bool beater1Knockout, int beater2X, int beater2Y, bool beater2Banned,
                               bool beater2HoldsBludger, bool beater2TurnUsed, bool beater2Knockout) : points(points),
                                                                                                       fans(std::move(fans)),
                                                                                                       seekerX(seekerX),
                                                                                                       seekerY(seekerY),
                                                                                                       seekerBanned(
                                                                                                               seekerBanned),
                                                                                                       seekerTurnUsed(
                                                                                                               seekerTurnUsed),
                                                                                                       seekerKnockout(
                                                                                                               seekerKnockout),
                                                                                                       keeperX(keeperX),
                                                                                                       keeperY(keeperY),
                                                                                                       keeperBanned(
                                                                                                               keeperBanned),
                                                                                                       keeperHoldsQuaffle(
                                                                                                               keeperHoldsQuaffle),
                                                                                                       keeperTurnUsed(
                                                                                                               keeperTurnUsed),
                                                                                                       keeperKnockout(
                                                                                                               keeperKnockout),
                                                                                                       chaser1X(
                                                                                                               chaser1X),
                                                                                                       chaser1Y(
                                                                                                               chaser1Y),
                                                                                                       chaser1Banned(
                                                                                                               chaser1Banned),
                                                                                                       chaser1HoldsQuaffle(
                                                                                                               chaser1HoldsQuaffle),
                                                                                                       chaser1TurnUsed(
                                                                                                               chaser1TurnUsed),
                                                                                                       chaser1Knockout(
                                                                                                               chaser1Knockout),
                                                                                                       chaser2X(
                                                                                                               chaser2X),
                                                                                                       chaser2Y(
                                                                                                               chaser2Y),
                                                                                                       chaser2Banned(
                                                                                                               chaser2Banned),
                                                                                                       chaser2HoldsQuaffle(
                                                                                                               chaser2HoldsQuaffle),
                                                                                                       chaser2TurnUsed(
                                                                                                               chaser2TurnUsed),
                                                                                                       chaser2Knockout(
                                                                                                               chaser2Knockout),
                                                                                                       chaser3X(
                                                                                                               chaser3X),
                                                                                                       chaser3Y(
                                                                                                               chaser3Y),
                                                                                                       chaser3Banned(
                                                                                                               chaser3Banned),
                                                                                                       chaser3HoldsQuaffle(
                                                                                                               chaser3HoldsQuaffle),
                                                                                                       chaser3TurnUsed(
                                                                                                               chaser3TurnUsed),
                                                                                                       chaser3Knockout(
                                                                                                               chaser3Knockout),
                                                                                                       beater1X(
                                                                                                               beater1X),
                                                                                                       beater1Y(
                                                                                                               beater1Y),
                                                                                                       beater1Banned(
                                                                                                               beater1Banned),
                                                                                                       beater1HoldsBludger(
                                                                                                               beater1HoldsBludger),
                                                                                                       beater1TurnUsed(
                                                                                                               beater1TurnUsed),
                                                                                                       beater1Knockout(
                                                                                                               beater1Knockout),
                                                                                                       beater2X(
                                                                                                               beater2X),
                                                                                                       beater2Y(
                                                                                                               beater2Y),
                                                                                                       beater2Banned(
                                                                                                               beater2Banned),
                                                                                                       beater2HoldsBludger(
                                                                                                               beater2HoldsBludger),
                                                                                                       beater2TurnUsed(
                                                                                                               beater2TurnUsed),
                                                                                                       beater2Knockout(
                                                                                                               beater2Knockout) {}

    bool TeamSnapshot::isSeekerKnockout() const {
        return seekerKnockout;
    }

    bool TeamSnapshot::isKeeperKnockout() const {
        return keeperKnockout;
    }

    bool TeamSnapshot::isChaser1Knockout() const {
        return chaser1Knockout;
    }

    bool TeamSnapshot::isChaser2Knockout() const {
        return chaser2Knockout;
    }

    bool TeamSnapshot::isChaser3Knockout() const {
        return chaser3Knockout;
    }

    bool TeamSnapshot::isBeater1Knockout() const {
        return beater1Knockout;
    }

    bool TeamSnapshot::isBeater2Knockout() const {
        return beater2Knockout;
    }

    bool TeamSnapshot::operator==(const TeamSnapshot &rhs) const {
        return points == rhs.points &&
               fans == rhs.fans &&
               seekerX == rhs.seekerX &&
               seekerY == rhs.seekerY &&
               seekerBanned == rhs.seekerBanned &&
               seekerTurnUsed == rhs.seekerTurnUsed &&
               seekerKnockout == rhs.seekerKnockout &&
               keeperX == rhs.keeperX &&
               keeperY == rhs.keeperY &&
               keeperBanned == rhs.keeperBanned &&
               keeperHoldsQuaffle == rhs.keeperHoldsQuaffle &&
               keeperTurnUsed == rhs.keeperTurnUsed &&
               keeperKnockout == rhs.keeperKnockout &&
               chaser1X == rhs.chaser1X &&
               chaser1Y == rhs.chaser1Y &&
               chaser1Banned == rhs.chaser1Banned &&
               chaser1HoldsQuaffle == rhs.chaser1HoldsQuaffle &&
               chaser1TurnUsed == rhs.chaser1TurnUsed &&
               chaser1Knockout == rhs.chaser1Knockout &&
               chaser2X == rhs.chaser2X &&
               chaser2Y == rhs.chaser2Y &&
               chaser2Banned == rhs.chaser2Banned &&
               chaser2HoldsQuaffle == rhs.chaser2HoldsQuaffle &&
               chaser2TurnUsed == rhs.chaser2TurnUsed &&
               chaser2Knockout == rhs.chaser2Knockout &&
               chaser3X == rhs.chaser3X &&
               chaser3Y == rhs.chaser3Y &&
               chaser3Banned == rhs.chaser3Banned &&
               chaser3HoldsQuaffle == rhs.chaser3HoldsQuaffle &&
               chaser3TurnUsed == rhs.chaser3TurnUsed &&
               chaser3Knockout == rhs.chaser3Knockout &&
               beater1X == rhs.beater1X &&
               beater1Y == rhs.beater1Y &&
               beater1Banned == rhs.beater1Banned &&
               beater1HoldsBludger == rhs.beater1HoldsBludger &&
               beater1TurnUsed == rhs.beater1TurnUsed &&
               beater1Knockout == rhs.beater1Knockout &&
               beater2X == rhs.beater2X &&
               beater2Y == rhs.beater2Y &&
               beater2Banned == rhs.beater2Banned &&
               beater2HoldsBludger == rhs.beater2HoldsBludger &&
               beater2TurnUsed == rhs.beater2TurnUsed &&
               beater2Knockout == rhs.beater2Knockout;
    }

    bool TeamSnapshot::operator!=(const TeamSnapshot &rhs) const {
        return !(rhs == *this);
    }

    void to_json(nlohmann::json &j, const TeamSnapshot &teamSnaphot) {
        j["points"] = teamSnaphot.getPoints();
        j["fans"] = teamSnaphot.getFans();
        j["players"]["seeker"]["xPos"] = teamSnaphot.getSeekerX();
        j["players"]["seeker"]["yPos"] = teamSnaphot.getSeekerY();
        j["players"]["seeker"]["banned"] = teamSnaphot.isSeekerBanned();
        j["players"]["seeker"]["turnUsed"] = teamSnaphot.isSeekerTurnUsed();
        j["players"]["seeker"]["knockout"] = teamSnaphot.isSeekerKnockout();
        j["players"]["keeper"]["xPos"] = teamSnaphot.getKeeperX();
        j["players"]["keeper"]["yPos"] = teamSnaphot.getKeeperY();
        j["players"]["keeper"]["banned"] = teamSnaphot.isKeeperBanned();
        j["players"]["keeper"]["holdsQuaffle"] = teamSnaphot.isKeeperHoldsQuaffle();
        j["players"]["keeper"]["turnUsed"] = teamSnaphot.isKeeperTurnUsed();
        j["players"]["keeper"]["knockout"] = teamSnaphot.isKeeperKnockout();
        j["players"]["chaser1"]["xPos"] = teamSnaphot.getChaser1X();
        j["players"]["chaser1"]["yPos"] = teamSnaphot.getChaser1Y();
        j["players"]["chaser1"]["banned"] = teamSnaphot.isChaser1Banned();
        j["players"]["chaser1"]["holdsQuaffle"] = teamSnaphot.isChaser1HoldsQuaffle();
        j["players"]["chaser1"]["turnUsed"] = teamSnaphot.isChaser1TurnUsed();
        j["players"]["chaser1"]["knockout"] = teamSnaphot.isChaser1Knockout();
        j["players"]["chaser2"]["xPos"] = teamSnaphot.getChaser2X();
        j["players"]["chaser2"]["yPos"] = teamSnaphot.getChaser2Y();
        j["players"]["chaser2"]["banned"] = teamSnaphot.isChaser2Banned();
        j["players"]["chaser2"]["holdsQuaffle"] = teamSnaphot.isChaser2HoldsQuaffle();
        j["players"]["chaser2"]["turnUsed"] = teamSnaphot.isChaser2TurnUsed();
        j["players"]["chaser2"]["knockout"] = teamSnaphot.isChaser2Knockout();
        j["players"]["chaser3"]["xPos"] = teamSnaphot.getChaser3X();
        j["players"]["chaser3"]["yPos"] = teamSnaphot.getChaser3Y();
        j["players"]["chaser3"]["banned"] = teamSnaphot.isChaser3Banned();
        j["players"]["chaser3"]["holdsQuaffle"] = teamSnaphot.isChaser3HoldsQuaffle();
        j["players"]["chaser3"]["turnUsed"] = teamSnaphot.isChaser3TurnUsed();
        j["players"]["chaser3"]["knockout"] = teamSnaphot.isChaser3Knockout();
        j["players"]["beater1"]["xPos"] = teamSnaphot.getBeater1X();
        j["players"]["beater1"]["yPos"] = teamSnaphot.getBeater1Y();
        j["players"]["beater1"]["banned"] = teamSnaphot.isBeater1Banned();
        j["players"]["beater1"]["holdsBludger"] = teamSnaphot.isBeater1HoldsBludger();
        j["players"]["beater1"]["knockout"] = teamSnaphot.isBeater1Knockout();
        j["players"]["beater1"]["turnUsed"] = teamSnaphot.isBeater1TurnUsed();
        j["players"]["beater2"]["xPos"] = teamSnaphot.getBeater2X();
        j["players"]["beater2"]["yPos"] = teamSnaphot.getBeater2Y();
        j["players"]["beater2"]["banned"] = teamSnaphot.isBeater2Banned();
        j["players"]["beater2"]["holdsBludger"] = teamSnaphot.isBeater2HoldsBludger();
        j["players"]["beater2"]["turnUsed"] = teamSnaphot.isBeater2TurnUsed();
        j["players"]["beater2"]["knockout"] = teamSnaphot.isBeater2Knockout();
    }

    void from_json(const nlohmann::json &j, TeamSnapshot &teamSnaphot) {
        teamSnaphot = TeamSnapshot{
            j.at("points").get<int>(),
            j.at("fans").get<std::vector<Fan>>(),
            j.at("players").at("seeker").at("xPos").get<int>(),
            j.at("players").at("seeker").at("yPos").get<int>(),
            j.at("players").at("seeker").at("banned").get<bool>(),
            j.at("players").at("seeker").at("turnUsed").get<bool>(),
            j.at("players").at("seeker").at("knockout").get<bool>(),
            j.at("players").at("keeper").at("xPos").get<int>(),
            j.at("players").at("keeper").at("yPos").get<int>(),
            j.at("players").at("keeper").at("banned").get<bool>(),
            j.at("players").at("keeper").at("holdsQuaffle").get<bool>(),
            j.at("players").at("keeper").at("turnUsed").get<bool>(),
            j.at("players").at("keeper").at("knockout").get<bool>(),
            j.at("players").at("chaser1").at("xPos").get<int>(),
            j.at("players").at("chaser1").at("yPos").get<int>(),
            j.at("players").at("chaser1").at("banned").get<bool>(),
            j.at("players").at("chaser1").at("holdsQuaffle").get<bool>(),
            j.at("players").at("chaser1").at("turnUsed").get<bool>(),
            j.at("players").at("chaser1").at("knockout").get<bool>(),
            j.at("players").at("chaser2").at("xPos").get<int>(),
            j.at("players").at("chaser2").at("yPos").get<int>(),
            j.at("players").at("chaser2").at("banned").get<bool>(),
            j.at("players").at("chaser2").at("holdsQuaffle").get<bool>(),
            j.at("players").at("chaser2").at("turnUsed").get<bool>(),
            j.at("players").at("chaser2").at("knockout").get<bool>(),
            j.at("players").at("chaser3").at("xPos").get<int>(),
            j.at("players").at("chaser3").at("yPos").get<int>(),
            j.at("players").at("chaser3").at("banned").get<bool>(),
            j.at("players").at("chaser3").at("holdsQuaffle").get<bool>(),
            j.at("players").at("chaser3").at("turnUsed").get<bool>(),
            j.at("players").at("chaser3").at("knockout").get<bool>(),
            j.at("players").at("beater1").at("xPos").get<int>(),
            j.at("players").at("beater1").at("yPos").get<int>(),
            j.at("players").at("beater1").at("banned").get<bool>(),
            j.at("players").at("beater1").at("holdsBludger").get<bool>(),
            j.at("players").at("beater1").at("turnUsed").get<bool>(),
            j.at("players").at("beater1").at("knockout").get<bool>(),
            j.at("players").at("beater2").at("xPos").get<int>(),
            j.at("players").at("beater2").at("yPos").get<int>(),
            j.at("players").at("beater2").at("banned").get<bool>(),
            j.at("players").at("beater2").at("holdsBludger").get<bool>(),
            j.at("players").at("beater2").at("turnUsed").get<bool>(),
            j.at("players").at("beater2").at("knockout").get<bool>()
        };
    }

    void to_json(nlohmann::json &j, const Snapshot &snaphot) {
        j["lastDeltaBroadcast"] = snaphot.getLastDeltaBroadcast();
        j["phase"] = types::toString(snaphot.getPhase());
        j["spectatorUserName"] = snaphot.getSpectatorUserName();
        j["round"] = snaphot.getRound();
        j["leftTeam"] = snaphot.getLeftTeam();
        j["rightTeam"] = snaphot.getRightTeam();
        j["balls"]["snitch"]["xPos"] = snaphot.getSnitchX();
        j["balls"]["snitch"]["yPos"] = snaphot.getSnitchY();
        j["balls"]["quaffle"]["xPos"] = snaphot.getQuaffleX();
        j["balls"]["quaffle"]["yPos"] = snaphot.getQuaffleY();
        j["balls"]["bludger1"]["xPos"] = snaphot.getBludger1X();
        j["balls"]["bludger1"]["yPos"] = snaphot.getBludger1Y();
        j["balls"]["bludger2"]["xPos"] = snaphot.getBludger2X();
        j["balls"]["bludger2"]["yPos"] = snaphot.getBludger2Y();
        j["wombatCubes"] = nlohmann::json::array();
        for (const auto &cube : snaphot.getWombatCubes()) {
            nlohmann::json pos{{"xPos", cube.first}, {"yPos", cube.second}};
            j["wombatCubes"].push_back(pos);
        }
        j["goalWasThrownThisRound"] = snaphot.isGoalWasThrownThisRound();
    }

    void from_json(const nlohmann::json &j, Snapshot &snaphot) {
        std::vector<std::pair<int, int>> wombatCubes;
        for (const auto &cube : j.at("wombatCubes")) {
            wombatCubes.emplace_back(cube.at("xPos").get<int>(), cube.at("yPos").get<int>());
        }

        snaphot = Snapshot{
            j.at("lastDeltaBroadcast"),
            types::fromStringPhaseType(
                    j.at("phase").get<std::string>()),
            j.at("spectatorUserName").get<std::vector<std::string>>(),
            j.at("round").get<int>(),
            j.at("leftTeam").get<TeamSnapshot>(),
            j.at("rightTeam").get<TeamSnapshot>(),
            j.at("balls").at("snitch").at("xPos").get<std::optional<int>>(),
            j.at("balls").at("snitch").at("yPos").get<std::optional<int>>(),
            j.at("balls").at("quaffle").at("xPos").get<int>(),
            j.at("balls").at("quaffle").at("yPos").get<int>(),
            j.at("balls").at("bludger1").at("xPos").get<int>(),
            j.at("balls").at("bludger1").at("yPos").get<int>(),
            j.at("balls").at("bludger2").at("xPos").get<int>(),
            j.at("balls").at("bludger2").at("yPos").get<int>(),
            wombatCubes,
            j.at("goalWasThrownThisRound").get<bool>()
        };
    }

    void to_json(nlohmann::json &j, const Fan &fan) {
        j["fanType"] = types::toString(fan.fanType);
        j["banned"] = fan.banned;
        j["turnUsed"] = fan.turnUsed;
    }

    void from_json(const nlohmann::json &j, Fan &fan) {
        fan.fanType = types::fromStringFanType(j.at("fanType").get<std::string>());
        fan.banned = j.at("banned").get<bool>();
        fan.turnUsed = j.at("turnUsed").get<bool>();
    }

    bool Fan::operator==(const Fan &rhs) const {
        return fanType == rhs.fanType &&
               banned == rhs.banned &&
               turnUsed == rhs.turnUsed;
    }

    bool Fan::operator!=(const Fan &rhs) const {
        return !(rhs == *this);
    }
}
