#include <gtest/gtest.h>
#include <src/Message.hpp>
#include <src/ReplayMessage.h>

using namespace communication::messages;

using T1 = Message;

TEST(CommunicationMessagesMessage, SerializeDeserialize) {
    T1 orig{broadcast::DeltaBroadcast{}};
    std::string ser;
    nlohmann::json json;
    T1 comp;
    ASSERT_NO_THROW(json = orig);
    ASSERT_NO_THROW(ser = json.dump());
    ASSERT_NO_THROW(comp = nlohmann::json::parse(ser).get<T1>());
    ASSERT_EQ(comp, orig);
}

using T2 = ReplayMessage;

TEST(CommunicationMessagesReplayMessage, SerializeDeserialize) {
    request::Player player{"def",{},{}};
    request::TeamConfig teamConfig{
            "abc",
            "abc",
            "00FF11",
            "11FF00",
            "abc",
            1,2,3,4,5,
            player,player,player,player,player,player,player
    };
    broadcast::Replay replay{"Test", "abc", {15,7,8,2,3,4,5,6,7,0.71,0.91,0.101,0.111,0.121,0.131,0.141,0.151,0.161,
           0.171,0.181,0.191,0.201,0.211,0.221,0.231,0.241,0.251,0.261, 0.23}, teamConfig, teamConfig, "asdsd", "ssdsdb", {}, {}, {}};
    T2 orig{replay};
    std::string ser;
    nlohmann::json json;
    T2 comp;
    ASSERT_NO_THROW(json = orig);
    ASSERT_NO_THROW(ser = json.dump());
    ASSERT_NO_THROW(comp = nlohmann::json::parse(ser).get<T2>());
    ASSERT_EQ(comp, orig);
}

