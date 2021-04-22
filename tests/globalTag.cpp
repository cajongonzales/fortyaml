#include <gtest/gtest.h>
#include <string>
#include "yamlEventReader.hpp"

TEST(YamlGlobalTag, GlobalTag) {
    std::string fileName = "../../yamlFiles/global-tag.yaml";
    yamlEventReader(fileName.c_str());
    
    EXPECT_TRUE(false);
}
	
int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();    
}
