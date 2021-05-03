#include <gtest/gtest.h>
#include <string>
#include "InputParser.hpp"

TEST(YamlJson, Json) {
    std::string fileName = "../../yamlFiles/json.yaml";
    InputParser* parser = input_parser_ctor(fileName.c_str());
    const YAML::Node& node = parser->get_node();    
    
    EXPECT_EQ(node.size(), 6);
    EXPECT_EQ(node["A null"].as<std::string>(), "null");
    EXPECT_EQ(node["Also a null"].as<std::string>(), "");
    EXPECT_EQ(node["Not a null"].as<std::string>(), "");
    
    EXPECT_TRUE(node["Booleans"].IsSequence());
    EXPECT_EQ(node["Booleans"][0].as<bool>(), true);
    EXPECT_EQ(node["Booleans"][1].as<bool>(), true);
    EXPECT_EQ(node["Booleans"][2].as<bool>(), false);
    EXPECT_EQ(node["Booleans"][3].as<bool>(), false);

    EXPECT_TRUE(node["Integers"].IsSequence());
    EXPECT_EQ(node["Integers"][0].as<int>(), 0); 
//    EXPECT_EQ(node["Integers"][1].as<int>(), 0); // I dont know what 0o7 is... 
    EXPECT_EQ(node["Integers"][2].as<int>(), 58); 
    EXPECT_EQ(node["Integers"][3].as<int>(), -19); 
    
    EXPECT_TRUE(node["Floats"].IsSequence());
    EXPECT_EQ(node["Floats"][0].as<float>(), 0.0);
    EXPECT_EQ(node["Floats"][1].as<float>(), -0.0); 
    EXPECT_EQ(node["Floats"][2].as<float>(), 0.5);
    EXPECT_EQ(node["Floats"][3].as<float>(), 12000);

}
	
int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();    
}
