#include <gtest/gtest.h>
#include <gtest/gtest-spi.h>
#include <string>
#include "InputParser.hpp"

TEST(YamlAnchors, Anchors) {
    std::string fileName = "../../yamlFiles/anchors.yaml";
    InputParser* parser = input_parser_ctor(fileName.c_str());
    
    const YAML::Node& node = parser->get_node();
    EXPECT_EQ(node.size(), 3);
    EXPECT_EQ(node["base"]["name"].as<std::string>(), "Everyone has same name");
    EXPECT_TRUE(node["foo"].IsMap());
    EXPECT_EQ(node["foo"]["age"].as<int>(), 10);
    EXPECT_EQ(node["bar"]["age"].as<int>(), 20);
}
	
int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();    
}
