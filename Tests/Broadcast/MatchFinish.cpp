#include <gtest/gtest.h>
#include <Broadcast/MatchFinish.hpp>

using namespace communication::messages;

using T = broadcast::MatchFinish;

TEST(BroadcastMatchFinish, SerializeDeserialize) {
    T orig{1,2,3,"Test",types::VictoryReason::MOST_POINTS};
    std::string ser;
    nlohmann::json json;
    T comp;
    ASSERT_NO_THROW(json = orig);
    ASSERT_NO_THROW(ser = json.dump());
    ASSERT_NO_THROW(comp = nlohmann::json::parse(ser).get<T>());
    ASSERT_EQ(comp, orig);
}
