#include "ReplayMessage.h"
#include "json.hpp"

namespace communication::messages {
    template<>
    void from_json(const nlohmann::json &j, ReplayMessage &message) {
        std::string payloadType = j.at("payloadType");
        auto payloadJ = j.at("payload");

        ReplayPayload payload;
        if (payloadType == broadcast::Replay::getName()) {
            payload = j.at("payload").get<broadcast::Replay>();
        } else if (payloadType == mods::unicast::ReplayWithSnapshot::getName()) {
            payload = j.at("payload").get<mods::unicast::ReplayWithSnapshot>();
        }

        message = ReplayMessage{payload};
    }

    template<>
    AbstractMessage<ReplayPayload>::AbstractMessage() :
            timestamp{std::chrono::duration_cast<std::chrono::milliseconds>(
                    std::chrono::system_clock::now().time_since_epoch())},
            payload{broadcast::Replay{}}{
        auto globTime = std::time(nullptr);
        this->time = *std::localtime(&globTime);
    }

}