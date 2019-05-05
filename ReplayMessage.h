//
// Created by paulnykiel on 04.05.19.
//

#ifndef SOPRAMESSAGES_REPLAYMESSAGE_H
#define SOPRAMESSAGES_REPLAYMESSAGE_H

#include "ReplayWithSnapshot.h"
#include "Replay.hpp"
#include "Message.hpp"

namespace communication::messages {
    using ReplayMessage = AbstractMessage<broadcast::Replay>;
    using ReplayWithSnapshotMessage = AbstractMessage<mods::unicast::ReplayWithSnapshot>;
}

#endif //SOPRAMESSAGES_REPLAYMESSAGE_H
