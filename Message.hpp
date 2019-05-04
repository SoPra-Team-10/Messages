//
// Created by paulnykiel on 26.04.19.
//

#ifndef SERVER_MESSAGE_H
#define SERVER_MESSAGE_H

#include <chrono>
#include <variant>
#include <iomanip>

#include "DeltaBroadcast.hpp"
#include "GlobalDebug.hpp"
#include "LoginGreeting.hpp"
#include "MatchConfig.hpp"
#include "MatchFinish.hpp"
#include "MatchStart.hpp"
#include "Next.hpp"
#include "PauseResponse.hpp"
#include "Snapshot.hpp"
#include "ContinueRequest.hpp"
#include "DeltaRequest.hpp"
#include "GetReplay.hpp"
#include "JoinRequest.hpp"
#include "PauseRequest.hpp"
#include "SendDebug.hpp"
#include "TeamFormation.hpp"
#include "JoinResponse.hpp"
#include "PrivateDebug.hpp"
#include "Reconnect.hpp"

namespace communication::messages {
    namespace broadcast {
        class Replay;
    }

    using Payload = std::variant<
            broadcast::DeltaBroadcast,
            broadcast::GlobalDebug,
            broadcast::LoginGreeting,
            broadcast::MatchConfig,
            broadcast::MatchFinish,
            broadcast::MatchStart,
            broadcast::Next,
            broadcast::PauseResponse,
            broadcast::Snapshot,
            request::ContinueRequest,
            request::DeltaRequest,
            request::GetReplay,
            request::JoinRequest,
            request::PauseRequest,
            request::SendDebug,
            request::TeamConfig,
            request::TeamFormation,
            unicast::JoinResponse,
            unicast::PrivateDebug,
            unicast::Reconnect>;

    template <typename Payload>
    class AbstractMessage {
    public:
        AbstractMessage();
        explicit AbstractMessage(Payload payload);
        auto getPayload() const -> Payload;
        auto getPayloadType() const -> std::string;
        auto getTimeStamp() const -> std::string;

        bool operator==(const AbstractMessage<Payload> &rhs) const;

        bool operator!=(const AbstractMessage<Payload> &rhs) const;

    private:
        std::chrono::milliseconds timestamp;
        std::tm time{};
        Payload payload;
    };

    template<typename Payload>
    AbstractMessage<Payload>::AbstractMessage() :
        timestamp{std::chrono::duration_cast<std::chrono::milliseconds>(
                std::chrono::system_clock::now().time_since_epoch())},
                payload{broadcast::DeltaBroadcast{}}{
            auto globTime = std::time(nullptr);
            this->time = *std::localtime(&globTime);
    }

    template<typename Payload>
    AbstractMessage<Payload>::AbstractMessage(Payload payload) :
        timestamp{std::chrono::duration_cast<std::chrono::milliseconds>(
                std::chrono::system_clock::now().time_since_epoch())},
                time{},
                payload{std::move(payload)} {
            auto globTime = std::time(nullptr);
            this->time = *std::localtime(&globTime);
    }

    template<typename Payload>
    auto AbstractMessage<Payload>::getPayload() const -> Payload {
        return this->payload;
    }

    template<typename Payload>
    auto AbstractMessage<Payload>::getPayloadType() const -> std::string {
        std::string type;
        std::visit([&type](auto &&arg){
            type = arg.getName();
        }, this->payload);
        return type;
    }

    template<typename Payload>
    auto AbstractMessage<Payload>::getTimeStamp() const -> std::string {
        // Formats the timestamp according to the standard
        // (time has only second accuracy, that's why there is this
        // stream magic)
        std::stringstream sstream;
        sstream << std::put_time(&this->time,"%F %T:")
                << std::setfill('0') <<std::setw(3) << (this->timestamp.count() % 1000);

        return sstream.str();
    }

    template<typename Payload>
    bool AbstractMessage<Payload>::operator==(const AbstractMessage<Payload> &rhs) const {
        return payload == rhs.payload;
    }

    template<typename Payload>
    bool AbstractMessage<Payload>::operator!=(const AbstractMessage<Payload> &rhs) const {
        return !(rhs == *this);
    }

    using Message = AbstractMessage<Payload>;
    using ReplayMessage = AbstractMessage<broadcast::Replay>;

    template<typename T>
    void to_json(nlohmann::json &j, const AbstractMessage<T> &message);

    template<typename T>
    void from_json(const nlohmann::json &j, AbstractMessage<T> &message);

    template <typename T>
    void to_json(nlohmann::json &j, const AbstractMessage<T> &message) {
        j["timestamp"] = message.getTimeStamp();
        j["payloadType"] = message.getPayloadType();
        std::visit([&j](auto &&arg){
            j["payload"] = arg;
        }, message.getPayload());
    }
}

#endif //SERVER_MESSAGE_H
