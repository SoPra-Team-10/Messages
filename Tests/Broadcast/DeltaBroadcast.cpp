#include <gtest/gtest.h>
#include <Broadcast/DeltaBroadcast.hpp>

using namespace communication::messages;

TEST(BroadcastDeltaBroadcast, SerializeDeserialize) {
    broadcast::DeltaBroadcast orig{types::DeltaType::SNITCH_SNATCH, true, 17,38,-12,35,
               types::EntityId::LEFT_NIFFLER, types::EntityId::RIGHT_BEATER1, types::PhaseType::PLAYER_PHASE,
               17, 18, 34};
    std::string ser;
    nlohmann::json json;
    broadcast::DeltaBroadcast comp;
    ASSERT_NO_THROW(json = orig);
    ASSERT_NO_THROW(ser = json.dump());
    ASSERT_NO_THROW(comp = nlohmann::json::parse(ser).get<broadcast::DeltaBroadcast>());
    ASSERT_EQ(comp, orig);
}
