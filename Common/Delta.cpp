/**
 * @file Delta.cpp
 * @author paul
 * @date 25.04.19
 * @brief Definition of the Delta class
 */

#include "Delta.hpp"
#include "OptionalSerialization.hpp"

#include <utility>

namespace communication::messages {

    types::DeltaType Delta::getDeltaType() const {
        return deltaType;
    }

    std::optional<bool> Delta::isSuccess() const {
        return success;
    }

    std::optional<int> Delta::getXPosOld() const {
        return xPosOld;
    }

    std::optional<int> Delta::getYPosOld() const {
        return yPosOld;
    }

    std::optional<int> Delta::getXPosNew() const {
        return xPosNew;
    }

    std::optional<int> Delta::getYPosNew() const {
        return yPosNew;
    }

    std::optional<types::EntityId> Delta::getActiveEntity() const {
        return activeEntity;
    }

    std::optional<types::EntityId> Delta::getPassiveEntity() const {
        return passiveEntity;
    }

    Delta::Delta(types::DeltaType deltaType, const std::optional<bool> &success, const std::optional<int> &xPosOld,
                 const std::optional<int> &yPosOld, const std::optional<int> &xPosNew,
                 const std::optional<int> &yPosNew, const std::optional<types::EntityId> &activeEntity,
                 const std::optional<types::EntityId> &passiveEntity, std::optional<types::PhaseType> phase, std::optional<int> leftPoints,
                 std::optional<int> rightPoints, std::optional<int> round, std::optional<types::BanReason> banReason)
            : deltaType(deltaType), success(success), xPosOld(xPosOld),
              yPosOld(yPosOld), xPosNew(xPosNew), yPosNew(yPosNew),
              activeEntity(activeEntity), passiveEntity(passiveEntity), phase(phase),
              leftPoints(leftPoints), rightPoints(rightPoints), round(round), banReason(banReason) {}

    std::optional<types::PhaseType> Delta::getPhase() const {
        return phase;
    }

    std::optional<int> Delta::getLeftPoints() const {
        return leftPoints;
    }

    std::optional<int> Delta::getRightPoints() const {
        return rightPoints;
    }

    std::optional<int> Delta::getRound() const {
        return round;
    }

    bool Delta::operator==(const Delta &rhs) const {
        return deltaType == rhs.deltaType &&
               success == rhs.success &&
               xPosOld == rhs.xPosOld &&
               yPosOld == rhs.yPosOld &&
               xPosNew == rhs.xPosNew &&
               yPosNew == rhs.yPosNew &&
               activeEntity == rhs.activeEntity &&
               passiveEntity == rhs.passiveEntity &&
               phase == rhs.phase &&
               leftPoints == rhs.leftPoints &&
               rightPoints == rhs.rightPoints &&
               round == rhs.round;
    }

    bool Delta::operator!=(const Delta &rhs) const {
        return !(rhs == *this);
    }

    const std::optional<types::BanReason> &Delta::getBanReason() const {
        return banReason;
    }

    void to_json(nlohmann::json &j, const Delta &delta) {
        j["deltaType"] = types::toString(delta.getDeltaType());
        j["success"] = delta.isSuccess();
        j["xPosOld"] = delta.getXPosOld();
        j["yPosOld"] = delta.getYPosOld();
        j["xPosNew"] = delta.getXPosNew();
        j["yPosNew"] = delta.getYPosNew();

        if (delta.getActiveEntity().has_value()) {
            j["activeEntity"] = types::toString(delta.getActiveEntity().value());
        } else {
            j["activeEntity"] = nullptr;
        }
        if (delta.getPassiveEntity().has_value()) {
            j["passiveEntity"] = types::toString(delta.getPassiveEntity().value());
        } else {
            j["passiveEntity"] = nullptr;
        }

        if (delta.getPhase().has_value()) {
            j["phase"] = types::toString(delta.getPhase().value());
        } else {
            j["phase"] = nullptr;
        }
        j["leftPoints"] = delta.getLeftPoints();
        j["rightPoints"] = delta.getRightPoints();
        j["round"] = delta.getRound();

        if (delta.getBanReason().has_value()) {
            j["banReason"] = types::toString(delta.getBanReason().value());
        } else {
            j["banReason"] = nullptr;
        }
    }

    void from_json(const nlohmann::json &j, Delta &delta) {
        std::optional<types::EntityId> active = std::nullopt, passive = std::nullopt;
        std::optional<types::BanReason> banReason = std::nullopt;
        std::optional<types::PhaseType> phaseType = std::nullopt;
        try {
            if (!j.at("activeEntity").is_null()) {
                active = types::fromStringEntityId(j.at("activeEntity").get<std::string>());
            }
        } catch (nlohmann::json::exception&) {}
        try {
            if (!j.at("passiveEntity").is_null()) {
                passive = types::fromStringEntityId(j.at("passiveEntity").get<std::string>());
            }
        } catch (nlohmann::json::exception&) {}
        try {
            if (!j.at("banReason").is_null()) {
                banReason = types::fromStringBanReason(j.at("banReason").get<std::string>());
            }
        } catch (nlohmann::json::exception&) {}
        try {
            if (!j.at("phase").is_null()) {
                phaseType = types::fromStringPhaseType(j.at("phase").get<std::string>());
            }
        } catch (nlohmann::json::exception&) {}

        delta = Delta{
            types::fromStringDeltaType(j.at("deltaType").get<std::string>()),
                j.at("success").get<std::optional<bool>>(),
                j.at("xPosOld").get<std::optional<int>>(),
                j.at("yPosOld").get<std::optional<int>>(),
                j.at("xPosNew").get<std::optional<int>>(),
                j.at("yPosNew").get<std::optional<int>>(),
                active, passive,
                phaseType,
                j.at("leftPoints").get<std::optional<int>>(),
                j.at("rightPoints").get<std::optional<int>>(),
                j.at("round").get<std::optional<int>>(),
                banReason
        };
    }
}