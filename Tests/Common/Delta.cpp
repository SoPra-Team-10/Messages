#include <gtest/gtest.h>
#include <Common/Delta.hpp>

using namespace communication::messages;

TEST(CommonDelta, SerializeDeserialize) {
    Delta orig{types::DeltaType::SNITCH_SNATCH, true, 17,38,-12,35,
                types::EntityId::LEFT_NIFFLER, types::EntityId::RIGHT_BEATER1, types::PhaseType::FAN_PHASE,
                34,33,32};
    std::string ser;
    nlohmann::json json;
    Delta comp;
    ASSERT_NO_THROW(json = orig);
    ASSERT_NO_THROW(ser = json.dump());
    ASSERT_NO_THROW(comp = nlohmann::json::parse(ser).get<Delta>());
    ASSERT_EQ(comp, orig);
}