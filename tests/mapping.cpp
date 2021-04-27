#include <gtest/gtest.h>
#include <string>
#include "yamlEventReader.hpp"

TEST(YamlMapping, Mapping) {
    std::string fileName = "../../yamlFiles/mapping.yaml";
    InputParser* parser = yamlEventReader(fileName.c_str());
    
    const YAML::Node& node = parser->get_node();

    EXPECT_TRUE(node.IsMap());
    EXPECT_EQ(node.size(), 2);
    EXPECT_TRUE(node["key"].IsScalar());
    EXPECT_TRUE(node["other-key"].IsScalar());
    EXPECT_EQ(node["key"].as<std::string>(), "value");
    EXPECT_EQ(node["other-key"].as<std::string>(), "other-value");
}
	
int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();    
}
