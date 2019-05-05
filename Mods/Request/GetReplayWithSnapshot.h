//
// Created by paulnykiel on 04.05.19.
//

#ifndef SOPRAMESSAGES_GETREPLAYWITHSNAPSHOT_H
#define SOPRAMESSAGES_GETREPLAYWITHSNAPSHOT_H

#include <string>
#include "json.hpp"

namespace communication::messages::mods::request {
    class GetReplayWithSnapshot {
    public:
        GetReplayWithSnapshot() = default;

        bool operator==(const GetReplayWithSnapshot &rhs) const;

        bool operator!=(const GetReplayWithSnapshot &rhs) const;

        static auto getName() -> std::string;
    };

    void to_json(nlohmann::json &j, const GetReplayWithSnapshot &getReplayWithSnapshot);
    void from_json(const nlohmann::json &j, GetReplayWithSnapshot &getReplayWithSnapshot);
}

#endif //SOPRAMESSAGES_GETREPLAYWITHSNAPSHOT_H
