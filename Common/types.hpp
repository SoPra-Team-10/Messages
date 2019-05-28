/**
 * @file types.hpp
 * @author paul
 * @date 25.04.19
 * @brief declaration of types used in the standard
 */

#ifndef SERVER_TYPES_HPP
#define SERVER_TYPES_HPP

#include <string>

namespace communication::messages::types {
    enum class EntityId {
        LEFT_SEEKER, LEFT_KEEPER, LEFT_CHASER1, LEFT_CHASER2, LEFT_CHASER3, LEFT_BEATER1, LEFT_BEATER2,
        RIGHT_SEEKER, RIGHT_KEEPER, RIGHT_CHASER1, RIGHT_CHASER2, RIGHT_CHASER3, RIGHT_BEATER1, RIGHT_BEATER2,
        SNITCH, BLUDGER1, BLUDGER2, QUAFFLE,
        LEFT_GOBLIN, LEFT_TROLL, LEFT_ELF, LEFT_NIFFLER, LEFT_WOMBAT,
        RIGHT_GOBLIN, RIGHT_TROLL, RIGHT_ELF, RIGHT_NIFFLER, RIGHT_WOMBAT
    };

    auto toString(EntityId entityId) -> std::string;
    auto fromStringEntityId(const std::string &s) -> EntityId;

    enum class TurnType {
        MOVE, ACTION, FAN, REMOVE_BAN
    };

    auto toString(TurnType turnType) -> std::string;
    auto fromStringTurnType(const std::string &s) -> TurnType;

    enum class VictoryReason {
        DISQUALIFICATION, BOTH_DISQUALIFICATION_MOST_POINTS,
        BOTH_DISQUALIFICATION_POINTS_EQUAL_SNITCH_CATCH,
        BOTH_DISQUALIFICATION_POINTS_EQUAL_LAST_DISQUALIFICATION,
        MOST_POINTS,
        POINTS_EQUAL_SNITCH_CATCH,
        VIOLATION_OF_PROTOCOL
    };

    auto toString(VictoryReason victoryReason) -> std::string;
    auto fromStringVictoryReason(const std::string &s) -> VictoryReason;

    enum class FanType {
        GOBLIN, TROLL, ELF, NIFFLER, WOMBAT
    };

    auto toString(FanType fanType) -> std::string;
    auto fromStringFanType(const std::string &s) -> FanType ;

    enum class Broom {
        TINDERBLAST, CLEANSWEEP11, COMET260, NIMBUS2001, FIREBOLT
    };

    auto toString(Broom broom) -> std::string;
    auto fromStringBroom(const std::string &s) -> Broom;

    enum class Sex {
        M, F
    };

    auto toString(Sex s) -> std::string;
    auto fromStringSex(const std::string &s) -> Sex;

    enum class DeltaType {
        SNITCH_CATCH, BLUDGER_BEATING, QUAFFLE_THROW,
        SNITCH_SNATCH, TROLL_ROAR, ELF_TELEPORTATION,
        GOBLIN_SHOCK, BAN, BLUDGER_KNOCKOUT, MOVE,
        PHASE_CHANGE, GOAL_POINTS_CHANGE, ROUND_CHANGE,
        SKIP, UNBAN, WREST_QUAFFLE, FOOL_AWAY, TURN_USED
    };

    auto toString(DeltaType deltaType) -> std::string;
    auto fromStringDeltaType(const std::string &s) -> DeltaType;

    enum class PhaseType {
        BALL_PHASE, PLAYER_PHASE, FAN_PHASE, GAME_FINISH, UNBAN_PHASE
    };

    auto toString(PhaseType phaseType) -> std::string;
    auto fromStringPhaseType(const std::string &s) -> PhaseType;

    enum class Mods {
        CHAT, DISABLE_GENDER_BALANCE, REPLAY_WITH_SNAPSHOT, ERROR, WARNING, LOBBIES
    };

    auto toString(Mods mods) -> std::string;
    auto fromStringMod(const std::string &s) -> Mods;

    enum class BanReason {
        STOOGING, BLATCHING, FLACKING, HAVERSACKING, SNITCHNIP, SNITCH_SNATCH,
        ELF_TELEPORTATION, GOBLIN_SHOCK, TROLL_ROAR
    };

    auto toString(BanReason banReason) -> std::string;
    auto fromStringBanReason(const std::string &s) -> BanReason;
}

#endif //SERVER_TYPES_HPP
