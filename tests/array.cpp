#include <gtest/gtest.h>
#include <string>
#include "yamlEventReader.hpp"

TEST(YamlArray, Array) {
    std::string fileName = "../../yamlFiles/array.yaml";
    InputParser* parser = yamlEventReader(fileName.c_str());
    
    const YAML::Node& node = parser->get_node();

    EXPECT_TRUE(node.IsSequence());
    EXPECT_EQ(node.size(), 2);
    EXPECT_TRUE(node[0].IsScalar());
    EXPECT_TRUE(node[1].IsScalar());
    EXPECT_EQ(node[0].as<std::string>(), "member");
    EXPECT_EQ(node[1].as<std::string>(), "member2");
}
	
int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();    
}
