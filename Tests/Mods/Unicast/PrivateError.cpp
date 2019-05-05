#include <gtest/gtest.h>
#include <Mods/Unicast/PrivateError.h>

using namespace communication::messages::mods;

using T = unicast::PrivateError;

TEST(ModsUnicastPrivateError, SerializeDeserialize) {
    T orig{"abc", "def"};
    std::string ser;
    nlohmann::json json;
    T comp;
    EXPECT_NO_THROW(json = orig);
    EXPECT_NO_THROW(ser = json.dump());
    EXPECT_NO_THROW(comp = nlohmann::json::parse(ser).get<T>());
    EXPECT_EQ(comp, orig);
}

