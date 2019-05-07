/**
 * @file Reconnect.cpp
 * @author paul
 * @date 19.03.19
 * @brief Definition of the Reconnect class
 */

#include "Reconnect.hpp"

#include <utility>
#include <Message.hpp>

namespace communication::messages::unicast {

    auto Reconnect::getName() -> std::string {
        return "reconnect";
    }

    Reconnect::Reconnect(broadcast::MatchStart matchStart, broadcast::Snapshot snapshot,
            broadcast::Next next) : matchStart(std::move(
            matchStart)), snapshot(std::move(snapshot)), next(next) {}

    broadcast::MatchStart Reconnect::getMatchStart() const {
        return matchStart;
    }

    broadcast::Snapshot Reconnect::getSnapshot() const {
        return snapshot;
    }

    bool Reconnect::operator==(const Reconnect &rhs) const {
        return matchStart == rhs.matchStart &&
               snapshot == rhs.snapshot;
    }

    bool Reconnect::operator!=(const Reconnect &rhs) const {
        return !(rhs == *this);
    }

    broadcast::Next Reconnect::getNext() const {
        return next;
    }

    void to_json(nlohmann::json &j, const Reconnect &reconnect) {
        j["matchStart"] = messages::Message{reconnect.getMatchStart()};
        j["snapshot"] = messages::Message{reconnect.getSnapshot()};
        j["next"] = messages::Message{reconnect.getNext()};
    }

    void from_json(const nlohmann::json &j, Reconnect &reconnect) {
        auto ms = std::get<broadcast::MatchStart>(j.at("matchStart").get<messages::Message>().getPayload());
        auto ss = std::get<broadcast::Snapshot>(j.at("snapshot").get<messages::Message>().getPayload());
        auto n = std::get<broadcast::Next>(j.at("next").get<messages::Message>().getPayload());
        reconnect = Reconnect{ms,ss,n};
    }
}
