#include <gtest/gtest.h>
#include <string>
#include "Dictionary.hpp"
#include "yamlEventReader.hpp"

TEST(YamlMapping, Mapping) {
    std::string fileName = "../../yamlFiles/mapping.yaml";
    yamlEventReader(fileName.c_str());
     
}
	
int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();    
}
