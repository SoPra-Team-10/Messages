//
// Created by paulnykiel on 04.05.19.
//

#ifndef SOPRAMESSAGES_REPLAYMESSAGE_H
#define SOPRAMESSAGES_REPLAYMESSAGE_H

#include "Replay.hpp"
#include "Message.hpp"

namespace communication::messages {
    using ReplayMessage = AbstractMessage<broadcast::Replay>;
}

#endif //SOPRAMESSAGES_REPLAYMESSAGE_H
