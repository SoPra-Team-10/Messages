#include <gtest/gtest.h>
#include <Request/TeamConfig.hpp>

using namespace communication::messages;

using T0 = request::TeamConfig;
using T1 = request::Player;

TEST(RequestTeamConfig, TeamConfigSerializeDeserialize) {
    request::Player player{"abcd", {}, {}};
    T0 orig{"asds","bsdsd","0011FF","FF1100","esdsd",1,2,3,4,5,player,player,player,player,player,player,player};
    std::string ser;
    nlohmann::json json;
    T0 comp;
    ASSERT_NO_THROW(json = orig);
    ASSERT_NO_THROW(ser = json.dump());
    ASSERT_NO_THROW(comp = nlohmann::json::parse(ser).get<T0>());
    ASSERT_EQ(comp, orig);
}

TEST(RequestTeamConfig, PlayerSerializeDeserialize) {
    T1 orig{"Test", types::Broom::FIREBOLT, types::Sex::F};
    std::string ser;
    nlohmann::json json;
    T1 comp;
    ASSERT_NO_THROW(json = orig);
    ASSERT_NO_THROW(ser = json.dump());
    ASSERT_NO_THROW(comp = nlohmann::json::parse(ser).get<T1>());
    ASSERT_EQ(comp, orig);
}
