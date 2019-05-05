#include <gtest/gtest.h>
#include <Broadcast/Snapshot.hpp>

using namespace communication::messages;

using T1 = broadcast::Snapshot;

TEST(BroadcastSnapshot, SerializeDeserialize) {
    T1 orig{{}, types::PhaseType::FAN_PHASE, {}, 17, {}, {},
           1,2,3,4,5,6,7,8};
    std::string ser;
    nlohmann::json json;
    T1 comp;
    EXPECT_NO_THROW(json = orig);
    EXPECT_NO_THROW(ser = json.dump());
    EXPECT_NO_THROW(comp = nlohmann::json::parse(ser).get<T1>());
    EXPECT_EQ(comp, orig);
}

using T2 = broadcast::TeamSnapshot;

TEST(BroadcastTeamSnapshot, SerializeDeserialize) {
    T2 orig{17, {}, 18, 19, true, false, true, 20, 21, true, false, true, false,
            22, 23, false, true, false, true,
            24, 25, true, false, true, false,
            26, 27, false, true, false, true,
            28, 29, true, false, true, false,
            30, 31, false, true, false, true};
    std::string ser;
    nlohmann::json json;
    T2 comp;
    EXPECT_NO_THROW(json = orig);
    EXPECT_NO_THROW(ser = json.dump());
    EXPECT_NO_THROW(comp = nlohmann::json::parse(ser).get<T2>());
    EXPECT_EQ(comp, orig);
}
