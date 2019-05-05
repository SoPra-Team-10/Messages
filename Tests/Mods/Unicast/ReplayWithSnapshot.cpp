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
            1,2,3,4,
            player,player,player,player,player,player,player
    };
    T orig{"Test", "abc", {}, teamConfig, teamConfig, "asdsd", "ssdsdb", {}, {}, {}};
    std::string ser;
    nlohmann::json json;
    T comp;
    EXPECT_NO_THROW(json = orig);
    EXPECT_NO_THROW(ser = json.dump());
    /*EXPECT_NO_THROW*/(comp = nlohmann::json::parse(ser).get<T>());
    EXPECT_EQ(comp, orig);
}
