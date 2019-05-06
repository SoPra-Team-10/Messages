/**
 * @file Delta.hpp
 * @author paul
 * @date 25.04.19
 * @brief Declaration of the Delta class
 */

#ifndef SERVER_DELTA_HPP
#define SERVER_DELTA_HPP

#include <optional>
#include "json.hpp"
#include "types.hpp"

namespace communication::messages {
    class Delta {
    public:
        Delta() = default;

        Delta(types::DeltaType deltaType, const std::optional<bool> &success, const std::optional<int> &xPosOld,
              const std::optional<int> &yPosOld, const std::optional<int> &xPosNew,
              const std::optional<int> &yPosNew, const std::optional<types::EntityId> &activeEntity,
              const std::optional<types::EntityId> &passiveEntity, types::PhaseType phase, int leftPoints,
              int rightPoints, int round, std::optional<types::BanReason> banReason);

        types::DeltaType getDeltaType() const;

        std::optional<bool> isSuccess() const;

        std::optional<int> getXPosOld() const;

        std::optional<int> getYPosOld() const;

        std::optional<int> getXPosNew() const;

        std::optional<int> getYPosNew() const;

        std::optional<types::EntityId> getActiveEntity() const;

        std::optional<types::EntityId> getPassiveEntity() const;

        types::PhaseType getPhase() const;

        int getLeftPoints() const;

        int getRightPoints() const;

        int getRound() const;

        const std::optional<types::BanReason> &getBanReason() const;

        bool operator==(const Delta &rhs) const;

        bool operator!=(const Delta &rhs) const;

    private:
        types::DeltaType deltaType{};
        std::optional<bool> success;
        std::optional<int> xPosOld, yPosOld, xPosNew, yPosNew;
        std::optional<types::EntityId> activeEntity, passiveEntity;
        types::PhaseType phase{};
        int leftPoints{}, rightPoints{}, round{};
        std::optional<types::BanReason> banReason;
    };

    void to_json(nlohmann::json &j, const Delta &delta);
    void from_json(const nlohmann::json &j, Delta &delta);
}

#endif //SERVER_DELTA_HPP
