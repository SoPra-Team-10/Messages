//
// Created by paulnykiel on 26.04.19.
//

#ifndef SERVER_MESSAGE_H
#define SERVER_MESSAGE_H

#include <chrono>
#include <variant>

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
