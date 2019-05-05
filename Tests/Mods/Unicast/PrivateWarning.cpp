#include <gtest/gtest.h>
#include <Mods/Unicast/PrivateWarning.h>

using namespace communication::messages::mods;

using T = unicast::PrivateWarning;

TEST(ModsUnicastPrivateWarning, SerializeDeserialize) {
    T orig{"abc", "def"};
    std::string ser;
    nlohmann::json json;
    T comp;
    EXPECT_NO_THROW(json = orig);
    EXPECT_NO_THROW(ser = json.dump());
    EXPECT_NO_THROW(comp = nlohmann::json::parse(ser).get<T>());
    EXPECT_EQ(comp, orig);
}
