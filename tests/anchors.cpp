#include <gtest/gtest.h>
#include <string>
#include "Dictionary.hpp"
#include "yamlEventReader.hpp"

TEST(YamlAnchors, Anchors) {
    std::string fileName = "../../yamlFiles/anchors.yaml";
    yamlEventReader(fileName.c_str());
     
}
	
int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();    
}
