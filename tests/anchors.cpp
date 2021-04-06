#include <gtest/gtest.h>
#include <string>
#include "Dictionary.hpp"

TEST(YamlAnchors, Anchors) {
    std::string fileName = "../yamlFiles/anchors.yaml";
    yamlEventReader(fileName);
     
}
	
int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();    
}
