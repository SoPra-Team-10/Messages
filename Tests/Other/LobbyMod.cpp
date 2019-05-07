#include <gtest/gtest.h>
#include <Other/LobbyMod.hpp>

using namespace communication::messages::mods;

using T1 = other::LobbyEntry;

TEST(ModsOtherLobbyEntry, SerializeDeserialize) {
    T1 orig{"Test", true, 17};
    std::string ser;
    nlohmann::json json;
    T1 comp{};
    ASSERT_NO_THROW(json = orig);
    ASSERT_NO_THROW(ser = json.dump());
    ASSERT_NO_THROW(comp = nlohmann::json::parse(ser).get<T1>());
    ASSERT_EQ(comp, orig);
}

using T2 = other::LobbyMod;

TEST(ModsOtherLobbyMod, SerializeDeserialize) {
    T2 orig{{{"Test", true, 17},{"Test2", false, 18}}};
    std::string ser;
    nlohmann::json json;
    T2 comp{};
    ASSERT_NO_THROW(json = orig);
    ASSERT_NO_THROW(ser = json.dump());
    ASSERT_NO_THROW(comp = nlohmann::json::parse(ser).get<T2>());
    ASSERT_EQ(comp, orig);
}