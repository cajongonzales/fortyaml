#include <gtest/gtest.h>
#include <string>
#include "yamlEventReader.hpp"

TEST(YamlStrings, Strings) {
    std::string fileName = "../../yamlFiles/strings.yaml";
    InputParser* parser = yamlEventReader(fileName.c_str());
    
    const YAML::Node& node = parser->get_node();

    EXPECT_TRUE(node.IsMap());
    EXPECT_EQ(node.size(), 3);
    EXPECT_TRUE(node["unqouted"].IsScalar());
    EXPECT_TRUE(node["literal-block"].IsScalar());
    EXPECT_TRUE(node["folded"].IsScalar());
    EXPECT_EQ(node["unqouted"].as<std::string>(), "string");
    EXPECT_EQ(node["literal-block"].as<std::string>(), "This entire block of text will be the value of the 'literal-block' key,\nwith line breaks being preserved.\n");
    EXPECT_EQ(node["folded"].as<std::string>(), "This entire block of text will be the value of 'folded', but this time, all newlines will be replaced with a single space.\n");
}
	
int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();    
}
