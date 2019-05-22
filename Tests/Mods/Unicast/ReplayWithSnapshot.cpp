#include <gtest/gtest.h>
#include <Mods/Unicast/ReplayWithSnapshot.h>

using namespace communication::messages::mods;

using T = unicast::ReplayWithSnapshot;

TEST(ModsUnicastReplayWithSnapshot, SerializeDeserialize) {
    communication::messages::request::Player player{"def",{},{}};
    communication::messages::request::TeamConfig teamConfig{
            "abc",
            "abc",
            "00FF11",
            "11FF00",
            "abc",
            1,2,3,4,5,
            player,player,player,player,player,player,player
    };
    T orig{"Test", "abc", {15,7,8,2,3,4,5,6,7,0.71,0.91,0.101,0.111,0.121,0.131,0.141,0.151,0.161,
           0.171,0.181,0.191,0.201,0.211,0.221,0.231,0.241,0.251,0.261, 0.23}, teamConfig, teamConfig, "asdsd", "ssdsdb", {}, {}, {}};
    std::string ser;
    nlohmann::json json;
    T comp;
    ASSERT_NO_THROW(json = orig);
    ASSERT_NO_THROW(ser = json.dump());
    ASSERT_NO_THROW(comp = nlohmann::json::parse(ser).get<T>());
    ASSERT_EQ(comp, orig);
}
