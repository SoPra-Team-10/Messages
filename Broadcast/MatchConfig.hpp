/**
 * @file MatchConfig.hpp
 * @author paul
 * @date 19.03.19
 * @brief Declaration of the MatchConfig class
 */

#ifndef SERVER_MATCHCONFIG_HPP
#define SERVER_MATCHCONFIG_HPP

#include <string>
#include "json.hpp"

namespace communication::messages::broadcast {
    class MatchConfig {
    public:
        MatchConfig() = default;
        MatchConfig(int maxRounds, int teamFormationTimeout, int playerTurnTimeout, int fanTurnTimeout, int unbanTurnTimout,
                    int playerPhaseTime, int fanPhaseTime, int minUnbanPhaseAnimationDuration,
                    int ballPhaseTime, float probThrowSuccess, float probKnockOut,
                    float probCatchSnitch, float probCatchQuaffle, float probWrestQuaffle, float probExtraTinderblast,
                    float probExtraCleansweep, float probExtraComet, float probExtraNimbus, float probExtraFirebolt,
                    float probFoulFlacking, float probFoulHaversacking, float probFoulStooging, float probFoulBlatching,
                    float probFoulSnitchnip, float probFoulElf, float probFoulGoblin, float probFoulTroll,
                    float probFoulSnitch);

        int getMaxRounds() const;
        int getTeamFormationTimeout() const;
        int getPlayerTurnTimeout() const;
        int getFanTurnTimeout() const;
        int getPlayerPhaseTime() const;
        int getFanPhaseTime() const;
        int getBallPhaseTime() const;
        float getProbThrowSuccess() const;
        float getProbKnockOut() const;
        float getProbCatchSnitch() const;
        float getProbCatchQuaffle() const;
        float getProbWrestQuaffle() const;
        float getProbExtraTinderblast() const;
        float getProbExtraCleansweep() const;
        float getProbExtraComet() const;
        float getProbExtraNimbus() const;
        float getProbExtraFirebolt() const;
        float getProbFoulFlacking() const;
        float getProbFoulHaversacking() const;
        float getProbFoulStooging() const;
        float getProbFoulBlatching() const;
        float getProbFoulSnitchnip() const;
        float getProbFoulElf() const;
        float getProbFoulGoblin() const;
        float getProbFoulTroll() const;
        float getProbFoulSnitch() const;
        int getUnbanTurnTimeout() const;
        int getUnbanPhaseTime() const;

        static auto getName() -> std::string;

        bool operator==(const MatchConfig &rhs) const;

        bool operator!=(const MatchConfig &rhs) const;

    private:
        int maxRounds, teamFormationTimeout;
        int playerTurnTimeout, fanTurnTimeout, unbanTurnTimeout, playerPhaseTime, fanPhaseTime, ballPhaseTime,
            unbanPhaseTime;
        float probThrowSuccess, probKnockOut, probCatchSnitch, probCatchQuaffle,
                probWrestQuaffle, probExtraTinderblast, probExtraCleansweep, probExtraComet, probExtraNimbus,
                probExtraFirebolt, probFoulFlacking, probFoulHaversacking, probFoulStooging, probFoulBlatching,
                probFoulSnitchnip, probFoulElf, probFoulGoblin, probFoulTroll, probFoulSnitch;
    };

    void to_json(nlohmann::json &j, const MatchConfig &matchConfig);
    void from_json(const nlohmann::json &j, MatchConfig &matchConfig);
}

#endif //SERVER_MATCHCONFIG_HPP
