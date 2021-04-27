#include <gtest/gtest.h>
#include <string>
#include "yamlEventReader.hpp"

TEST(YamlNumbers, Numbers) {
    std::string fileName = "../../yamlFiles/numbers.yaml";
    InputParser* parser = yamlEventReader(fileName.c_str());
    
    const YAML::Node& node = parser->get_node();

    EXPECT_TRUE(node.IsSequence());
    EXPECT_EQ(node.size(), 4);
    EXPECT_DOUBLE_EQ(node[0].as<double>(), 100);
    EXPECT_DOUBLE_EQ(node[1].as<double>(), 12.5);
    EXPECT_DOUBLE_EQ(node[2].as<double>(), -130);
    EXPECT_DOUBLE_EQ(node[3].as<double>(), 1.3e+9);
}
	
int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();    
}
