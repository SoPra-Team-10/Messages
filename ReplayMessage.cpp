#include "ReplayMessage.h"
#include "json.hpp"

namespace communication::messages {
    template<>
    void from_json(const nlohmann::json &j, AbstractMessage <broadcast::Replay> &message) {
        message = ReplayMessage{j.at("payload").get<broadcast::Replay>()};
    }

    template<>
    auto AbstractMessage<broadcast::Replay>::getPayloadType() const -> std::string {
        return broadcast::Replay::getName();
    }

    template<>
    AbstractMessage<broadcast::Replay>::AbstractMessage() :
            timestamp{std::chrono::duration_cast<std::chrono::milliseconds>(
                    std::chrono::system_clock::now().time_since_epoch())},
            payload{}{
        auto globTime = std::time(nullptr);
        this->time = *std::localtime(&globTime);
    }

    template <>
    void to_json(nlohmann::json &j, const AbstractMessage<broadcast::Replay> &message) {
        j["timestamp"] = message.getTimeStamp();
        j["payloadType"] = message.getPayloadType();
        j["payload"] = message.getPayload();
    }

}