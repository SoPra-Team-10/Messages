#include <gtest/gtest.h>
#include <Request/JoinRequest.hpp>

using namespace communication::messages;

using T = request::JoinRequest;

TEST(RequestJoinRequest, SerializeDeserialize) {
    T orig{"abc", "bcdf", "csdsd", true, {types::Mods::WARNING, types::Mods::DISABLE_GENDER_BALANCE}};
    std::string ser;
    nlohmann::json json;
    T comp;
    ASSERT_NO_THROW(json = orig);
    ASSERT_NO_THROW(ser = json.dump());
    ASSERT_NO_THROW(comp = nlohmann::json::parse(ser).get<T>());
    ASSERT_EQ(comp, orig);
}
