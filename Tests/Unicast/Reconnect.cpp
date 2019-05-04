#include <gtest/gtest.h>
#include <Unicast/Reconnect.hpp>

using namespace communication::messages;

using T = unicast::Reconnect;

TEST(CommunicationMessagesUnicastReconnect, SerializeDeserialize) {
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
    broadcast::MatchStart matchStart{broadcast::MatchConfig{}, teamConfig, teamConfig,"adsds","bsdsds"};
    T orig{matchStart,{}};
    std::string ser;
    nlohmann::json json;
    T comp;
    EXPECT_NO_THROW(json = orig);
    EXPECT_NO_THROW(ser = json.dump());
    EXPECT_NO_THROW(comp = nlohmann::json::parse(ser).get<T>());
    EXPECT_EQ(comp, orig);
}
