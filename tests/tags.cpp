#include <gtest/gtest.h>
#include <string>
#include "yamlEventReader.hpp"

TEST(YamlTags, Tags) {
    std::string fileName = "../../yamlFiles/tags.yaml";
    yamlEventReader(fileName.c_str());
     
    EXPECT_TRUE(false);
}
	
int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();    
}
