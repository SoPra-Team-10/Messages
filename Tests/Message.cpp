#include <gtest/gtest.h>
#include <Message.hpp>
#include <ReplayMessage.h>

using namespace communication::messages;

using T1 = Message;

TEST(CommunicationMessagesMessage, SerializeDeserialize) {
    T1 orig{broadcast::DeltaBroadcast{}};
    std::string ser;
    nlohmann::json json;
    T1 comp;
    EXPECT_NO_THROW(json = orig);
    EXPECT_NO_THROW(ser = json.dump());
    EXPECT_NO_THROW(comp = nlohmann::json::parse(ser).get<T1>());
    EXPECT_EQ(comp, orig);
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
            1,2,3,4,
            player,player,player,player,player,player,player
    };
    broadcast::Replay replay{"Test", "abc", {}, teamConfig, teamConfig, "asdsd", "ssdsdb", {}, {}, {}};
    T2 orig{replay};
    std::string ser;
    nlohmann::json json;
    T2 comp;
    EXPECT_NO_THROW(json = orig);
    EXPECT_NO_THROW(ser = json.dump());
    EXPECT_NO_THROW(comp = nlohmann::json::parse(ser).get<T2>());
    EXPECT_EQ(comp, orig);
}

using T3 = ReplayWithSnapshotMessage;

TEST(CommunicationMessagesReplayWithSnapshotMessage, SerializeDeserialize) {
    request::Player player{"def",{},{}};
    request::TeamConfig teamConfig{
            "abc",
            "abc",
            "00FF11",
            "11FF00",
            "abc",
            1,2,3,4,
            player,player,player,player,player,player,player
    };
    mods::unicast::ReplayWithSnapshot replay{"Test", "abc", {}, teamConfig, teamConfig, "asdsd", "ssdsdb", {}, {}, {}};
    T3 orig{replay};
    std::string ser;
    nlohmann::json json;
    T3 comp;
    EXPECT_NO_THROW(json = orig);
    EXPECT_NO_THROW(ser = json.dump());
    EXPECT_NO_THROW(comp = nlohmann::json::parse(ser).get<T3>());
    EXPECT_EQ(comp, orig);
}
