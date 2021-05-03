#include <gtest/gtest.h>
#include <string>
#include "InputParser.hpp"

TEST(YamlJson, Json) {
    std::string fileName = "../../yamlFiles/json.yaml";
    InputParser* parser = input_parser_ctor(fileName.c_str());
    const YAML::Node& node = parser->get_node();    
    EXPECT_TRUE(true);
}
	
int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();    
}
