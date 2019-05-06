#include <gtest/gtest.h>
#include <Mods/Request/SendChat.h>

using namespace communication::messages::mods;

using T = request::SendChat;

TEST(ModsRequestSendChat, SerializeDeserialize) {
    T orig{"abc"};
    std::string ser;
    nlohmann::json json;
    T comp;
    ASSERT_NO_THROW(json = orig);
    ASSERT_NO_THROW(ser = json.dump());
    ASSERT_NO_THROW(comp = nlohmann::json::parse(ser).get<T>());
    ASSERT_EQ(comp, orig);
}
