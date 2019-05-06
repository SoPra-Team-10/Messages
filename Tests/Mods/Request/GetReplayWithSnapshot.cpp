#include <gtest/gtest.h>
#include <Mods/Request/GetReplayWithSnapshot.h>

using namespace communication::messages::mods;

using T = request::GetReplayWithSnapshot;

TEST(ModsRequestGetReplayWithSnapshot, SerializeDeserialize) {
    T orig{};
    std::string ser;
    nlohmann::json json;
    T comp;
    ASSERT_NO_THROW(json = orig);
    ASSERT_NO_THROW(ser = json.dump());
    ASSERT_NO_THROW(comp = nlohmann::json::parse(ser).get<T>());
    ASSERT_EQ(comp, orig);
}
