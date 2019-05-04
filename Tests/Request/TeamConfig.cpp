#include <gtest/gtest.h>
#include <Request/TeamConfig.hpp>

using namespace communication::messages;

using T0 = request::TeamConfig;
using T1 = request::Player;

TEST(CommunicationMessagesRequestTeamConfig, TeamConfigSerializeDeserialize) {
    request::Player player{"abcd", {}, {}};
    T0 orig{"asds","bsdsd","0011FF","FF1100","esdsd",1,2,3,4,player,player,player,player,player,player,player};
    std::string ser;
    nlohmann::json json;
    T0 comp;
    EXPECT_NO_THROW(json = orig);
    EXPECT_NO_THROW(ser = json.dump());
    EXPECT_NO_THROW(comp = nlohmann::json::parse(ser).get<T0>());
    EXPECT_EQ(comp, orig);
}

TEST(CommunicationMessagesRequestTeamConfig, PlayerSerializeDeserialize) {
    T1 orig{"Test", types::Broom::FIREBOLT, types::Sex::F};
    std::string ser;
    nlohmann::json json;
    T1 comp;
    EXPECT_NO_THROW(json = orig);
    EXPECT_NO_THROW(ser = json.dump());
    EXPECT_NO_THROW(comp = nlohmann::json::parse(ser).get<T1>());
    EXPECT_EQ(comp, orig);
}
