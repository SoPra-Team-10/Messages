#include <gtest/gtest.h>
#include <src/Broadcast/PauseResponse.hpp>

using namespace communication::messages;

using T = broadcast::PauseResponse;

TEST(BroadcastPauseResponse, SerializeDeserialize) {
    T orig{"Test", "Test2", true};
    std::string ser;
    nlohmann::json json;
    T comp;
    ASSERT_NO_THROW(json = orig);
    ASSERT_NO_THROW(ser = json.dump());
    ASSERT_NO_THROW(comp = nlohmann::json::parse(ser).get<T>());
    ASSERT_EQ(comp, orig);
}
