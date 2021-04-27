#include <gtest/gtest.h>
#include <string>
#include "InputParser.hpp"

TEST(YamlComponentExample, missingData) {
    std::string fileName = "../../yamlFiles/componentExample.yaml";
    InputParser* parser = input_parser_ctor(fileName.c_str());

    // Number doesn't exist, variable doesn't exist, group doesn't exist
    EXPECT_DOUBLE_EQ(get_var_for_comp(parser, 100, "slurmp", "spuunt"), 1.0);

    // Number doesn't exist, variable doesn't exist, group does exist
    EXPECT_DOUBLE_EQ(get_var_for_comp(parser, 100, "slurmp", "Secondary"), 1.0);

    // Number doesn't exist, variable does exist, group doesn't exist
    EXPECT_DOUBLE_EQ(get_var_for_comp(parser, 100, "design_factor3", "spuunt"), 1.0);

    // Number doesn't exist, variable does exist, group does exist
    EXPECT_DOUBLE_EQ(get_var_for_comp(parser, 100, "design_factor3", "Secondary"), 1.0);

    // Number does exist, variable doesn't exist, group doesn't exist
    EXPECT_DOUBLE_EQ(get_var_for_comp(parser, 200, "slurmp", "spuunt"), 1.0);

    // Number does exist, variable doesn't exist, group does exist
    EXPECT_DOUBLE_EQ(get_var_for_comp(parser, 200, "slurmp", "Secondary"), 1.0);

    // Number does exist, variable does exist, group doesn't exist
    EXPECT_DOUBLE_EQ(get_var_for_comp(parser, 200, "design_factor3", "spuunt"), 1.0);

    // Number does exist, variable does exist, group does exist
    EXPECT_DOUBLE_EQ(get_var_for_comp(parser, 200, "design_factor3", "Secondary"), 1.0);
}

TEST(YamlComponentExample, localData) {
    std::string fileName = "../../yamlFiles/componentExample.yaml";
    InputParser* parser = input_parser_ctor(fileName.c_str());

    // For the purposes of these tests, the group name is completely irrelevant,
    // and yet here I am, checking it anyway.

    // Group does not exist
    EXPECT_DOUBLE_EQ(get_var_for_comp(parser, 200, "friction_design_factor", "spuunt"), 1.23);
    EXPECT_DOUBLE_EQ(get_var_for_comp(parser, 122, "friction_design_factor", "spuunt"), 2.23);
    EXPECT_DOUBLE_EQ(get_var_for_comp(parser, 300, "friction_design_factor", "spuunt"), 2.2354343);
    EXPECT_DOUBLE_EQ(get_var_for_comp(parser, 500, "friction_design_factor", "spuunt"), 2.2354343);

    EXPECT_DOUBLE_EQ(get_var_for_comp(parser, 200, "design_factor2", "spuunt"), 27.5);
    EXPECT_DOUBLE_EQ(get_var_for_comp(parser, 300, "design_factor5", "spuunt"), 5000.0);
    EXPECT_DOUBLE_EQ(get_var_for_comp(parser, 500, "design_factor5", "spuunt"), 5000.0);

    // Group exists
    EXPECT_DOUBLE_EQ(get_var_for_comp(parser, 200, "friction_design_factor", "Secondary"), 1.23);
    EXPECT_DOUBLE_EQ(get_var_for_comp(parser, 122, "friction_design_factor", "Secondary"), 2.23);
    EXPECT_DOUBLE_EQ(get_var_for_comp(parser, 300, "friction_design_factor", "Secondary"), 2.2354343);
    EXPECT_DOUBLE_EQ(get_var_for_comp(parser, 500, "friction_design_factor", "Secondary"), 2.2354343);

    EXPECT_DOUBLE_EQ(get_var_for_comp(parser, 200, "design_factor2", "Secondary"), 27.5);
    EXPECT_DOUBLE_EQ(get_var_for_comp(parser, 300, "design_factor5", "Secondary"), 5000.0);
    EXPECT_DOUBLE_EQ(get_var_for_comp(parser, 500, "design_factor5", "Secondary"), 5000.0);
}

TEST(YamlComponentExample, groupData) {
    std::string fileName = "../../yamlFiles/componentExample.yaml";
    InputParser* parser = input_parser_ctor(fileName.c_str());

    // Defined by all known numbers, so we pick a number unassociated with any component
    EXPECT_DOUBLE_EQ(get_var_for_comp(parser, 100, "friction_design_factor", "Primary"), 2.8); 

    // Not defined by any known numbers
    EXPECT_DOUBLE_EQ(get_var_for_comp(parser, 100, "design_factor1", "Primary"), 8.7);    
    EXPECT_DOUBLE_EQ(get_var_for_comp(parser, 122, "design_factor1", "Primary"), 8.7); 
    EXPECT_DOUBLE_EQ(get_var_for_comp(parser, 200, "design_factor1", "Primary"), 8.7); 
    EXPECT_DOUBLE_EQ(get_var_for_comp(parser, 300, "design_factor1", "Primary"), 8.7); 
    EXPECT_DOUBLE_EQ(get_var_for_comp(parser, 500, "design_factor1", "Primary"), 8.7);  

    EXPECT_DOUBLE_EQ(get_var_for_comp(parser, 100, "interfacial_design_factor", "Secondary"), 200.54);    
    EXPECT_DOUBLE_EQ(get_var_for_comp(parser, 122, "interfacial_design_factor", "Secondary"), 200.54); 
    EXPECT_DOUBLE_EQ(get_var_for_comp(parser, 200, "interfacial_design_factor", "Secondary"), 200.54); 
    EXPECT_DOUBLE_EQ(get_var_for_comp(parser, 300, "interfacial_design_factor", "Secondary"), 200.54); 
    EXPECT_DOUBLE_EQ(get_var_for_comp(parser, 500, "interfacial_design_factor", "Secondary"), 200.54);  

    EXPECT_DOUBLE_EQ(get_var_for_comp(parser, 100, "design_factor4", "Secondary"), 5.01);    
    EXPECT_DOUBLE_EQ(get_var_for_comp(parser, 122, "design_factor4", "Secondary"), 5.01); 
    EXPECT_DOUBLE_EQ(get_var_for_comp(parser, 200, "design_factor4", "Secondary"), 5.01); 
    EXPECT_DOUBLE_EQ(get_var_for_comp(parser, 300, "design_factor4", "Secondary"), 5.01); 
    EXPECT_DOUBLE_EQ(get_var_for_comp(parser, 500, "design_factor4", "Secondary"), 5.01); 

    EXPECT_DOUBLE_EQ(get_var_for_comp(parser, 100, "design_factor3", "LOCCA_Injection"), 0.5); 
    EXPECT_DOUBLE_EQ(get_var_for_comp(parser, 122, "design_factor3", "LOCCA_Injection"), 0.5); 
    EXPECT_DOUBLE_EQ(get_var_for_comp(parser, 200, "design_factor3", "LOCCA_Injection"), 0.5); 
    EXPECT_DOUBLE_EQ(get_var_for_comp(parser, 300, "design_factor3", "LOCCA_Injection"), 0.5); 
    EXPECT_DOUBLE_EQ(get_var_for_comp(parser, 500, "design_factor3", "LOCCA_Injection"), 0.5); 
}

TEST(YamlComponentExample, globalData) {
    std::string fileName = "../../yamlFiles/componentExample.yaml";
    InputParser* parser = input_parser_ctor(fileName.c_str());

    // Defined only by group Secondary
    EXPECT_DOUBLE_EQ(get_var_for_comp(parser, 100, "interfacial_design_factor", "spuunt"), 100.59);
    EXPECT_DOUBLE_EQ(get_var_for_comp(parser, 122, "interfacial_design_factor", "spuunt"), 100.59);
    EXPECT_DOUBLE_EQ(get_var_for_comp(parser, 200, "interfacial_design_factor", "spuunt"), 100.59);
    EXPECT_DOUBLE_EQ(get_var_for_comp(parser, 300, "interfacial_design_factor", "spuunt"), 100.59);
    EXPECT_DOUBLE_EQ(get_var_for_comp(parser, 500, "interfacial_design_factor", "spuunt"), 100.59);

    EXPECT_DOUBLE_EQ(get_var_for_comp(parser, 100, "interfacial_design_factor", "Primary"), 100.59);
    EXPECT_DOUBLE_EQ(get_var_for_comp(parser, 122, "interfacial_design_factor", "Primary"), 100.59);
    EXPECT_DOUBLE_EQ(get_var_for_comp(parser, 200, "interfacial_design_factor", "Primary"), 100.59);
    EXPECT_DOUBLE_EQ(get_var_for_comp(parser, 300, "interfacial_design_factor", "Primary"), 100.59);
    EXPECT_DOUBLE_EQ(get_var_for_comp(parser, 500, "interfacial_design_factor", "Primary"), 100.59);

    EXPECT_DOUBLE_EQ(get_var_for_comp(parser, 100, "interfacial_design_factor", "LOCCA_Injection"), 100.59);
    EXPECT_DOUBLE_EQ(get_var_for_comp(parser, 122, "interfacial_design_factor", "LOCCA_Injection"), 100.59);
    EXPECT_DOUBLE_EQ(get_var_for_comp(parser, 200, "interfacial_design_factor", "LOCCA_Injection"), 100.59);
    EXPECT_DOUBLE_EQ(get_var_for_comp(parser, 300, "interfacial_design_factor", "LOCCA_Injection"), 100.59);
    EXPECT_DOUBLE_EQ(get_var_for_comp(parser, 500, "interfacial_design_factor", "LOCCA_Injection"), 100.59);

    // Defined by all known numbers and Primary group
    EXPECT_DOUBLE_EQ(get_var_for_comp(parser, 100, "friction_design_factor", "spuunt"), 1.13);
    EXPECT_DOUBLE_EQ(get_var_for_comp(parser, 100, "friction_design_factor", "Secondary"), 1.13);
    EXPECT_DOUBLE_EQ(get_var_for_comp(parser, 100, "friction_design_factor", "LOCCA_Injection"), 1.13);
}

int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();    
}
