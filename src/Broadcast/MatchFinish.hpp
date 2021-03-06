/**
 * @file MatchFinish.hpp
 * @author paul
 * @date 19.03.19
 * @brief Declaration of the MatchFinish class
 */

#ifndef SERVER_MATCHFINISH_HPP
#define SERVER_MATCHFINISH_HPP

#include <string>
#include "json.hpp"

#include "types.hpp"

namespace communication::messages::broadcast {
    class MatchFinish {
    public:
        MatchFinish() = default;
        MatchFinish(int endRound, int leftPoints, int rightPoints, std::string winnerUserName,
                    types::VictoryReason victoryReason);

        int getEndRound() const;
        int getLeftPoints() const;
        int getRightPoints() const;
        std::string getWinnerUserName() const;
        types::VictoryReason getVictoryReason() const;

        static auto getName() -> std::string;

        bool operator==(const MatchFinish &rhs) const;

        bool operator!=(const MatchFinish &rhs) const;

    private:
        int endRound{}, leftPoints{}, rightPoints{};
        std::string winnerUserName;
        types::VictoryReason victoryReason{};
    };

    void to_json(nlohmann::json &j, const MatchFinish &matchFinish);
    void from_json(const nlohmann::json &j, MatchFinish &matchFinish);
}

#endif //SERVER_MATCHFINISH_HPP
