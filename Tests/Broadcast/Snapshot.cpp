#include <gtest/gtest.h>
#include <Broadcast/Snapshot.hpp>

using namespace communication::messages;

using T1 = broadcast::Snapshot;

TEST(BroadcastSnapshot, SerializeDeserialize) {
    T1 orig{{}, types::PhaseType::FAN_PHASE, {}, 17, {}, {},
           1,2,3,4,5,6,7,8, {{1,2},{3,4}}, true};
    std::string ser;
    nlohmann::json json;
    T1 comp;
    ASSERT_NO_THROW(json = orig);
    ASSERT_NO_THROW(ser = json.dump());
    ASSERT_NO_THROW(comp = nlohmann::json::parse(ser).get<T1>());
    ASSERT_EQ(comp, orig);
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
    ASSERT_NO_THROW(json = orig);
    ASSERT_NO_THROW(ser = json.dump());
    ASSERT_NO_THROW(comp = nlohmann::json::parse(ser).get<T2>());
    ASSERT_EQ(comp, orig);
}

using T3 = broadcast::Fan;

TEST(BroadcastFan, SerializeDeserialize) {
    T3 orig{types::FanType::TROLL, true, false};
    std::string ser;
    nlohmann::json json;
    T3 comp;
    ASSERT_NO_THROW(json = orig);
    ASSERT_NO_THROW(ser = json.dump());
    ASSERT_NO_THROW(comp = nlohmann::json::parse(ser).get<T3>());
    ASSERT_EQ(comp, orig);
}
