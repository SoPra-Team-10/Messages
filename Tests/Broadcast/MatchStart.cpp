#include <gtest/gtest.h>
#include <Broadcast/MatchStart.hpp>

using namespace communication::messages;

using T = broadcast::MatchStart;

TEST(CommunicationMessagesBroadcastMatchStart, SerializeDeserialize) {
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
    T orig{broadcast::MatchConfig{}, teamConfig, teamConfig,"adsds","bsdsds"};
    std::string ser;
    nlohmann::json json;
    T comp;
    EXPECT_NO_THROW(json = orig);
    EXPECT_NO_THROW(ser = json.dump());
    EXPECT_NO_THROW(comp = nlohmann::json::parse(ser).get<T>());
    EXPECT_EQ(comp, orig);
}
