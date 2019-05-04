#include <utility>

//
// Created by paulnykiel on 26.04.19.
//

#include "Message.hpp"
#include "Replay.hpp"
#include <sstream>
#include <iomanip>
#include <iostream>

namespace communication::messages {
    template <>
    void from_json(const nlohmann::json &j, AbstractMessage<Payload> &message) {
        std::string payloadType = j.at("payloadType");
        auto payloadJ = j.at("payload");

        Payload payload;
        if (payloadType == broadcast::DeltaBroadcast::getName()) {
            payload = payloadJ.get<broadcast::DeltaBroadcast>();
        } else if (payloadType == broadcast::GlobalDebug::getName()) {
            payload = payloadJ.get<broadcast::GlobalDebug>();
        } else if (payloadType == broadcast::LoginGreeting::getName()) {
            payload = payloadJ.get<broadcast::LoginGreeting>();
        } else if (payloadType == broadcast::MatchConfig::getName()) {
            payload = payloadJ.get<broadcast::MatchConfig>();
        } else if (payloadType == broadcast::MatchFinish::getName()) {
            payload = payloadJ.get<broadcast::MatchFinish>();
        } else if (payloadType == broadcast::MatchStart::getName()) {
            payload = payloadJ.get<broadcast::MatchStart>();
        } else if (payloadType == broadcast::Next::getName()) {
            payload = payloadJ.get<broadcast::Next>();
        } else if (payloadType == broadcast::PauseResponse::getName()) {
            payload = payloadJ.get<broadcast::PauseResponse>();
        } else if (payloadType == broadcast::Snapshot::getName()) {
            payload = payloadJ.get<broadcast::Snapshot>();
        } else if (payloadType == request::ContinueRequest::getName()) {
            payload = payloadJ.get<request::ContinueRequest>();
        } else if (payloadType == request::DeltaRequest::getName()) {
            payload = payloadJ.get<request::DeltaRequest>();
        } else if (payloadType == request::GetReplay::getName()) {
            payload = payloadJ.get<request::GetReplay>();
        } else if (payloadType == request::JoinRequest::getName()) {
            payload = payloadJ.get<request::JoinRequest>();
        } else if (payloadType == request::PauseRequest::getName()) {
            payload = payloadJ.get<request::PauseRequest>();
        } else if (payloadType == request::SendDebug::getName()) {
            payload = payloadJ.get<request::SendDebug>();
        } else if (payloadType == request::TeamConfig::getName()) {
            payload = payloadJ.get<request::TeamConfig>();
        } else if (payloadType == request::TeamFormation::getName()) {
            payload = payloadJ.get<request::TeamFormation>();
        } else if (payloadType == unicast::JoinResponse::getName()) {
            payload = payloadJ.get<unicast::JoinResponse>();
        } else if (payloadType == unicast::PrivateDebug::getName()) {
            payload = payloadJ.get<unicast::PrivateDebug>();
        } else if (payloadType == unicast::Reconnect::getName()) {
            payload = payloadJ.get<unicast::Reconnect>();
        } else {
            throw std::runtime_error{"Not a valid payloadType"};
        }
        message = Message{payload};
    }

    template <>
    void from_json(const nlohmann::json &j, AbstractMessage<broadcast::Replay> &message) {
        message = ReplayMessage{j.at("payload").get<broadcast::Replay>()};
    }
}
