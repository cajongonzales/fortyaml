#include <gtest/gtest.h>
#include <string>
#include "InputParser.hpp"

TEST(YamlVersion, YamlVersion) {
    std::string fileName = "../../yamlFiles/yaml-version.yaml";
    InputParser* parser = input_parser_ctor(fileName.c_str());
    
    const YAML::Node& node = parser->get_node();

    EXPECT_TRUE(node.IsSequence());
    EXPECT_EQ(node.size(), 3);
    EXPECT_EQ(node[0].as<int>(), 1);
    EXPECT_EQ(node[1].as<int>(), 2);
    EXPECT_EQ(node[2].as<int>(), 3);
}
	
int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();    
}
