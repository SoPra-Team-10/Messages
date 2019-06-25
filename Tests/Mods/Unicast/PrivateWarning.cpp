#include <gtest/gtest.h>
#include <src/Mods/Unicast/PrivateWarning.h>

using namespace communication::messages::mods;

using T = unicast::PrivateWarning;

TEST(ModsUnicastPrivateWarning, SerializeDeserialize) {
    T orig{"abc", "def"};
    std::string ser;
    nlohmann::json json;
    T comp;
    ASSERT_NO_THROW(json = orig);
    ASSERT_NO_THROW(ser = json.dump());
    ASSERT_NO_THROW(comp = nlohmann::json::parse(ser).get<T>());
    ASSERT_EQ(comp, orig);
}
