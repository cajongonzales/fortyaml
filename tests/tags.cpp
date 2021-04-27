#include <gtest/gtest.h>
#include <string>
#include "InputParser.hpp"

TEST(YamlTags, Tags) {
    std::string fileName = "../../yamlFiles/tags.yaml";
    input_parser_ctor(fileName.c_str());
     
    EXPECT_TRUE(false);
}
	
int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();    
}
