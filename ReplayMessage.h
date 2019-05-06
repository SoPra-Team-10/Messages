//
// Created by paulnykiel on 04.05.19.
//

#ifndef SOPRAMESSAGES_REPLAYMESSAGE_H
#define SOPRAMESSAGES_REPLAYMESSAGE_H

#include "ReplayWithSnapshot.h"
#include "Replay.hpp"
#include "Message.hpp"

namespace communication::messages {
    using ReplayPayload = std::variant<broadcast::Replay, mods::unicast::ReplayWithSnapshot>;

    using ReplayMessage = AbstractMessage<ReplayPayload >;
}

#endif //SOPRAMESSAGES_REPLAYMESSAGE_H
