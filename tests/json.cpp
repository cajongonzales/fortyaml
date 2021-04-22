#include <gtest/gtest.h>
#include <string>
#include "yamlEventReader.hpp"

TEST(YamlJson, Json) {
    std::string fileName = "../../yamlFiles/json.yaml";
    yamlEventReader(fileName.c_str());
    
    EXPECT_TRUE(false);
}
	
int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();    
}
