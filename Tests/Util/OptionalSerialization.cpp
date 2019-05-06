#include <gtest/gtest.h>

#include <Util/OptionalSerialization.hpp>

TEST(UtilOptionalSerialization, SerializeValue) {
    std::optional<int> a = 0;
    nlohmann::json comp;
    nlohmann::json gt = 0;

    ASSERT_NO_THROW(comp = a);
    ASSERT_EQ(comp, gt);
}

TEST(UtilOptionalSerialization, SerializeNoValue) {
    std::optional<int> a = std::nullopt;
    nlohmann::json comp;
    nlohmann::json gt = nullptr;

    ASSERT_NO_THROW(comp = a);
    ASSERT_EQ(comp, gt);
}

TEST(UtilOptionalSerialization, DeSerializeValue) {
    nlohmann::json a = 0;
    std::optional<int> comp;
    std::optional<int> gt = 0;

    ASSERT_NO_THROW(comp = a.get<std::optional<int>>());
    ASSERT_EQ(comp, gt);
}

TEST(UtilOptionalSerialization, DeSerializeNoValue) {
    nlohmann::json a = nullptr;
    std::optional<int> comp;
    std::optional<int> gt = std::nullopt;

    ASSERT_NO_THROW(comp = a.get<std::optional<int>>());
    ASSERT_EQ(comp, gt);
}
