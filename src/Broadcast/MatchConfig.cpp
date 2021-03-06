/**
 * @file MatchConfig.cpp
 * @author paul
 * @date 19.03.19
 * @brief Definition of the MatchConfig class
 */

#include "MatchConfig.hpp"

namespace communication::messages::broadcast {

    auto MatchConfig::getName() -> std::string {
        return "matchConfig";
    }

    MatchConfig::MatchConfig(int maxRounds, int teamFormationTimeout, int playerTurnTimeout, int fanTurnTimeout, int unbanTurnTimeout,
                            int playerPhaseTime, int fanPhaseTime, int ballPhaseTime, int minUnbanPhaseAnimationDuration,
                            float probThrowSuccess,
                             float probKnockOut, float probCatchSnitch, float probCatchQuaffle,
                             float probWrestQuaffle, float probExtraTinderblast, float probExtraCleansweep,
                             float probExtraComet, float probExtraNimbus, float probExtraFirebolt,
                             float probFoulFlacking, float probFoulHaversacking, float probFoulStooging,
                             float probFoulBlatching, float probFoulSnitchnip, float probFoulElf, float probFoulGoblin,
                             float probFoulTroll, float probFoulSnitch, float probWombatPoo) : maxRounds{maxRounds},
                                                                             teamFormationTimeout{teamFormationTimeout},
                                                                          playerTurnTimeout{playerTurnTimeout},
                                                                          fanTurnTimeout{fanTurnTimeout},
                                                                          unbanTurnTimeout{unbanTurnTimeout},
                                                                          playerPhaseTime{playerPhaseTime},
                                                                          fanPhaseTime{fanPhaseTime},
                                                                          ballPhaseTime{ballPhaseTime},
                                                                          unbanPhaseTime{minUnbanPhaseAnimationDuration},
                                                                          probThrowSuccess{probThrowSuccess},
                                                                          probKnockOut{probKnockOut},
                                                                          probCatchSnitch{probCatchSnitch},
                                                                          probCatchQuaffle{probCatchQuaffle},
                                                                          probWrestQuaffle{probWrestQuaffle},
                                                                          probExtraTinderblast{probExtraTinderblast},
                                                                          probExtraCleansweep{probExtraCleansweep},
                                                                          probExtraComet{probExtraComet},
                                                                          probExtraNimbus{probExtraNimbus},
                                                                          probExtraFirebolt{probExtraFirebolt},
                                                                          probFoulFlacking{probFoulFlacking},
                                                                          probFoulHaversacking{probFoulHaversacking},
                                                                          probFoulStooging{probFoulStooging},
                                                                          probFoulBlatching{probFoulBlatching},
                                                                          probFoulSnitchnip{probFoulSnitchnip},
                                                                          probFoulElf{probFoulElf},
                                                                          probFoulGoblin{probFoulGoblin},
                                                                          probFoulTroll{probFoulTroll},
                                                                          probFoulSnitch{probFoulSnitch},
                                                                          probWombatPoo{probWombatPoo} {}

    int MatchConfig::getMaxRounds() const {
        return maxRounds;
    }

    int MatchConfig::getTeamFormationTimeout() const {
        return teamFormationTimeout;
    }


    int MatchConfig::getPlayerTurnTimeout() const {
        return playerTurnTimeout;
    }

    int MatchConfig::getFanTurnTimeout() const {
        return fanTurnTimeout;
    }

    int MatchConfig::getPlayerPhaseTime() const {
        return playerPhaseTime;
    }

    int MatchConfig::getFanPhaseTime() const {
        return fanPhaseTime;
    }

    int MatchConfig::getBallPhaseTime() const {
        return ballPhaseTime;
    }

    float MatchConfig::getProbThrowSuccess() const {
        return probThrowSuccess;
    }

    float MatchConfig::getProbKnockOut() const {
        return probKnockOut;
    }

    float MatchConfig::getProbCatchSnitch() const {
        return probCatchSnitch;
    }

    float MatchConfig::getProbCatchQuaffle() const {
        return probCatchQuaffle;
    }

    float MatchConfig::getProbWrestQuaffle() const {
        return probWrestQuaffle;
    }

    float MatchConfig::getProbExtraTinderblast() const {
        return probExtraTinderblast;
    }

    float MatchConfig::getProbExtraCleansweep() const {
        return probExtraCleansweep;
    }

    float MatchConfig::getProbExtraComet() const {
        return probExtraComet;
    }

    float MatchConfig::getProbExtraNimbus() const {
        return probExtraNimbus;
    }

    float MatchConfig::getProbExtraFirebolt() const {
        return probExtraFirebolt;
    }

    float MatchConfig::getProbFoulFlacking() const {
        return probFoulFlacking;
    }

    float MatchConfig::getProbFoulHaversacking() const {
        return probFoulHaversacking;
    }

    float MatchConfig::getProbFoulStooging() const {
        return probFoulStooging;
    }

    float MatchConfig::getProbFoulBlatching() const {
        return probFoulBlatching;
    }

    float MatchConfig::getProbFoulSnitchnip() const {
        return probFoulSnitchnip;
    }

    float MatchConfig::getProbFoulElf() const {
        return probFoulElf;
    }

    float MatchConfig::getProbFoulGoblin() const {
        return probFoulGoblin;
    }

    float MatchConfig::getProbFoulTroll() const {
        return probFoulTroll;
    }

    float MatchConfig::getProbFoulSnitch() const {
        return probFoulSnitch;
    }

    bool MatchConfig::operator==(const MatchConfig &rhs) const {
        return maxRounds == rhs.maxRounds &&
               playerTurnTimeout == rhs.playerTurnTimeout &&
               fanTurnTimeout == rhs.fanTurnTimeout &&
               playerPhaseTime == rhs.playerPhaseTime &&
               fanPhaseTime == rhs.fanPhaseTime &&
               ballPhaseTime == rhs.ballPhaseTime &&
               probThrowSuccess == rhs.probThrowSuccess &&
               probKnockOut == rhs.probKnockOut &&
               probCatchSnitch == rhs.probCatchSnitch &&
               probCatchQuaffle == rhs.probCatchQuaffle &&
               probWrestQuaffle == rhs.probWrestQuaffle &&
               probExtraTinderblast == rhs.probExtraTinderblast &&
               probExtraCleansweep == rhs.probExtraCleansweep &&
               probExtraComet == rhs.probExtraComet &&
               probExtraNimbus == rhs.probExtraNimbus &&
               probExtraFirebolt == rhs.probExtraFirebolt &&
               probFoulFlacking == rhs.probFoulFlacking &&
               probFoulHaversacking == rhs.probFoulHaversacking &&
               probFoulStooging == rhs.probFoulStooging &&
               probFoulBlatching == rhs.probFoulBlatching &&
               probFoulSnitchnip == rhs.probFoulSnitchnip &&
               probFoulElf == rhs.probFoulElf &&
               probFoulGoblin == rhs.probFoulGoblin &&
               probFoulTroll == rhs.probFoulTroll &&
               probFoulSnitch == rhs.probFoulSnitch &&
               unbanTurnTimeout == rhs.unbanTurnTimeout &&
               unbanPhaseTime == rhs.getUnbanPhaseTime() &&
               probWombatPoo == rhs.probWombatPoo;
    }

    bool MatchConfig::operator!=(const MatchConfig &rhs) const {
        return !(rhs == *this);
    }

    int MatchConfig::getUnbanTurnTimeout() const {
        return unbanTurnTimeout;
    }

    int MatchConfig::getUnbanPhaseTime() const {
        return unbanPhaseTime;
    }

    float MatchConfig::getProbWombatPoo() const {
        return probWombatPoo;
    }

    void to_json(nlohmann::json &j, const MatchConfig &matchConfig) {
        j["maxRounds"] = matchConfig.getMaxRounds();
        j["timings"]["teamFormationTimeout"] = matchConfig.getTeamFormationTimeout();
        j["timings"]["playerTurnTimeout"] = matchConfig.getPlayerTurnTimeout();
        j["timings"]["fanTurnTimeout"] = matchConfig.getFanTurnTimeout();
        j["timings"]["unbanTurnTimeout"] = matchConfig.getUnbanTurnTimeout();
        j["timings"]["minPlayerPhaseAnimationDuration"] = matchConfig.getPlayerPhaseTime();
        j["timings"]["minFanPhaseAnimationDuration"] = matchConfig.getFanPhaseTime();
        j["timings"]["minBallPhaseAnimationDuration"] = matchConfig.getBallPhaseTime();
        j["timings"]["minUnbanPhaseAnimationDuration"] = matchConfig.getUnbanPhaseTime();
        j["probabilities"]["throwSuccess"] = matchConfig.getProbThrowSuccess();
        j["probabilities"]["knockOut"] = matchConfig.getProbKnockOut();
        j["probabilities"]["catchSnitch"] = matchConfig.getProbCatchSnitch();
        j["probabilities"]["catchQuaffle"] = matchConfig.getProbCatchQuaffle();
        j["probabilities"]["wrestQuaffle"] = matchConfig.getProbWrestQuaffle();
        j["probabilities"]["extraMove"]["tinderblast"] = matchConfig.getProbExtraTinderblast();
        j["probabilities"]["extraMove"]["cleansweep11"] = matchConfig.getProbExtraCleansweep();
        j["probabilities"]["extraMove"]["comet260"] = matchConfig.getProbExtraComet();
        j["probabilities"]["extraMove"]["nimbus2001"] = matchConfig.getProbExtraNimbus();
        j["probabilities"]["extraMove"]["firebolt"] = matchConfig.getProbExtraFirebolt();
        j["probabilities"]["foulDetection"]["flacking"] = matchConfig.getProbFoulFlacking();
        j["probabilities"]["foulDetection"]["haversacking"] = matchConfig.getProbFoulHaversacking();
        j["probabilities"]["foulDetection"]["stooging"] = matchConfig.getProbFoulStooging();
        j["probabilities"]["foulDetection"]["blatching"] = matchConfig.getProbFoulBlatching();
        j["probabilities"]["foulDetection"]["snitchnip"] = matchConfig.getProbFoulSnitchnip();
        j["probabilities"]["fanFoulDetection"]["elfTeleportation"] = matchConfig.getProbFoulElf();
        j["probabilities"]["fanFoulDetection"]["goblinShock"] = matchConfig.getProbFoulGoblin();
        j["probabilities"]["fanFoulDetection"]["trollRoar"] = matchConfig.getProbFoulTroll();
        j["probabilities"]["fanFoulDetection"]["snitchSnatch"] = matchConfig.getProbFoulSnitch();
        j["probabilities"]["fanFoulDetection"]["wombatPoo"] = matchConfig.getProbWombatPoo();
    }

    void from_json(const nlohmann::json &j, MatchConfig &matchConfig) {
        matchConfig = MatchConfig{
            j.at("maxRounds").get<int>(),
            j.at("timings").at("teamFormationTimeout").get<int>(),
            j.at("timings").at("playerTurnTimeout").get<int>(),
            j.at("timings").at("fanTurnTimeout").get<int>(),
            j.at("timings").at("unbanTurnTimeout").get<int>(),
            j.at("timings").at("minPlayerPhaseAnimationDuration").get<int>(),
            j.at("timings").at("minFanPhaseAnimationDuration").get<int>(),
            j.at("timings").at("minBallPhaseAnimationDuration").get<int>(),
            j.at("timings").at("minUnbanPhaseAnimationDuration").get<int>(),
            j.at("probabilities").at("throwSuccess").get<float>(),
            j.at("probabilities").at("knockOut").get<float>(),
            j.at("probabilities").at("catchSnitch").get<float>(),
            j.at("probabilities").at("catchQuaffle").get<float>(),
            j.at("probabilities").at("wrestQuaffle").get<float>(),
            j.at("probabilities").at("extraMove").at("tinderblast").get<float>(),
            j.at("probabilities").at("extraMove").at("cleansweep11").get<float>(),
            j.at("probabilities").at("extraMove").at("comet260").get<float>(),
            j.at("probabilities").at("extraMove").at("nimbus2001").get<float>(),
            j.at("probabilities").at("extraMove").at("firebolt").get<float>(),
            j.at("probabilities").at("foulDetection").at("flacking").get<float>(),
            j.at("probabilities").at("foulDetection").at("haversacking").get<float>(),
            j.at("probabilities").at("foulDetection").at("stooging").get<float>(),
            j.at("probabilities").at("foulDetection").at("blatching").get<float>(),
            j.at("probabilities").at("foulDetection").at("snitchnip").get<float>(),
            j.at("probabilities").at("fanFoulDetection").at("elfTeleportation").get<float>(),
            j.at("probabilities").at("fanFoulDetection").at("goblinShock").get<float>(),
            j.at("probabilities").at("fanFoulDetection").at("trollRoar").get<float>(),
            j.at("probabilities").at("fanFoulDetection").at("snitchSnatch").get<float>(),
            j.at("probabilities").at("fanFoulDetection").at("wombatPoo").get<float>()
        };

        if (matchConfig.getMaxRounds() < 0 || matchConfig.getTeamFormationTimeout() < 0 ||
            matchConfig.getFanTurnTimeout() < 0 ||
            matchConfig.getPlayerPhaseTime() < 0 || matchConfig.getFanPhaseTime() < 0 ||
            matchConfig.getBallPhaseTime() < 0 ||
            matchConfig.getUnbanPhaseTime() < 0 ||
            matchConfig.getUnbanTurnTimeout() < 0) {
            throw std::runtime_error{"Timeout not valid"};
        }

        auto isProb = [](double p) {
            return 0<=p && p<=1;
        };

        if (!isProb(matchConfig.getProbThrowSuccess()) ||
                !isProb(matchConfig.getProbKnockOut()) ||
                !isProb(matchConfig.getProbCatchSnitch()) ||
                !isProb(matchConfig.getProbCatchQuaffle()) ||
                !isProb(matchConfig.getProbWrestQuaffle()) ||
                !isProb(matchConfig.getProbExtraTinderblast()) ||
                !isProb(matchConfig.getProbExtraCleansweep()) ||
                !isProb(matchConfig.getProbExtraComet()) ||
                !isProb(matchConfig.getProbExtraFirebolt()) ||
                !isProb(matchConfig.getProbFoulFlacking()) ||
                !isProb(matchConfig.getProbFoulHaversacking()) ||
                !isProb(matchConfig.getProbFoulStooging()) ||
                !isProb(matchConfig.getProbFoulBlatching()) ||
                !isProb(matchConfig.getProbFoulSnitchnip()) ||
                !isProb(matchConfig.getProbFoulElf()) ||
                !isProb(matchConfig.getProbFoulGoblin()) ||
                !isProb(matchConfig.getProbFoulTroll()) ||
                !isProb(matchConfig.getProbFoulSnitch()) ||
                !isProb(matchConfig.getProbWombatPoo())) {
            throw std::runtime_error{"Probabilites not valid"};
        }

        if (matchConfig.getMaxRounds() < 13 || matchConfig.getMaxRounds() > 100) {
            throw std::runtime_error{"Invalid MaxRounds"};
        }
    }
}
