#include <gtest/gtest.h>
#include <string>
#include "yamlEventReader.hpp"

TEST(YamlAnchors, Anchors) {
    std::string fileName = "../../yamlFiles/anchors.yaml";
    InputParser* parser = yamlEventReader(fileName.c_str());
    
    const YAML::Node& node = parser->get_node();

    std::cout << node << std::endl;
    
    EXPECT_TRUE(false);
}
	
int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();    
}
