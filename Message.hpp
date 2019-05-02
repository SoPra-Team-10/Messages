//
// Created by paulnykiel on 26.04.19.
//

#ifndef SERVER_MESSAGE_H
#define SERVER_MESSAGE_H


#include "Broadcast/DeltaBroadcast.hpp"

#include <variant>
#include <Broadcast/GlobalDebug.hpp>
#include <Broadcast/LoginGreeting.hpp>
#include <Broadcast/MatchConfig.hpp>
#include <Broadcast/MatchFinish.hpp>
#include <Broadcast/MatchStart.hpp>
#include <Broadcast/Next.hpp>
#include <Broadcast/PauseResponse.hpp>
#include <Broadcast/Snapshot.hpp>
#include <Request/ContinueRequest.hpp>
#include <Request/DeltaRequest.hpp>
#include <Request/GetReplay.hpp>
#include <Request/JoinRequest.hpp>
#include <Request/PauseRequest.hpp>
#include <Request/SendDebug.hpp>
#include <Request/TeamFormation.hpp>
#include <Unicast/JoinResponse.hpp>
#include <Unicast/PrivateDebug.hpp>
#include <Unicast/Reconnect.hpp>
#include <chrono>

namespace communication::messages {
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

    class Message {
    public:
        Message();
        explicit Message(Payload payload);
        auto getPayload() const -> Payload;
        auto getPayloadType() const -> std::string;
        auto getTimeStamp() const -> std::string;

        bool operator==(const Message &rhs) const;

        bool operator!=(const Message &rhs) const;

    private:
        std::chrono::milliseconds timestamp;
        std::tm time{};
        Payload payload;
    };

    void to_json(nlohmann::json &j, const Message &message);
    void from_json(const nlohmann::json &j, Message &message);
}

#endif //SERVER_MESSAGE_H
