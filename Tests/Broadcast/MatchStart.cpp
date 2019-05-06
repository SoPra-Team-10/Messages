#include <gtest/gtest.h>
#include <Broadcast/MatchStart.hpp>

using namespace communication::messages;

using T = broadcast::MatchStart;

TEST(BroadcastMatchStart, SerializeDeserialize) {
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
    ASSERT_NO_THROW(json = orig);
    ASSERT_NO_THROW(ser = json.dump());
    ASSERT_NO_THROW(comp = nlohmann::json::parse(ser).get<T>());
    ASSERT_EQ(comp, orig);
}
