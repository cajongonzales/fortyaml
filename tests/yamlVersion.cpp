#include <gtest/gtest.h>
#include <string>
#include "Dictionary.hpp"
#include "yamlEventReader.hpp"

TEST(YamlVersion, YamlVersion) {
    std::string fileName = "../../yamlFiles/yaml-version.yaml";
    yamlEventReader(fileName.c_str());
     
}
	
int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();    
}
