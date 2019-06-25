#include <gtest/gtest.h>
#include <src/Broadcast/Next.hpp>

using namespace communication::messages;

using T = broadcast::Next;

TEST(BroadcastNext, SerializeDeserialize) {
    T orig{types::EntityId::RIGHT_GOBLIN, types::TurnType::MOVE, 37};
    std::string ser;
    nlohmann::json json;
    T comp;
    ASSERT_NO_THROW(json = orig);
    ASSERT_NO_THROW(ser = json.dump());
    ASSERT_NO_THROW(comp = nlohmann::json::parse(ser).get<T>());
    ASSERT_EQ(comp, orig);
}
