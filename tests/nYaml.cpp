#include <gtest/gtest.h>
#include <string>
#include "InputParser.hpp"

TEST(YamlnYaml, nYaml) {
    std::string fileName = "../../yamlFiles/nYaml.yaml";
    InputParser* parser = input_parser_ctor(fileName.c_str());
    
    const YAML::Node& node = parser->get_node();

    EXPECT_TRUE(node.IsMap());
    EXPECT_EQ(node.size(), 5);

    EXPECT_TRUE(node["Global"].IsMap());
    EXPECT_TRUE(node["Primary"].IsMap());
    EXPECT_TRUE(node["Secondary"].IsMap());
    EXPECT_TRUE(node["LOCCA_Injection"].IsMap());
    EXPECT_TRUE(node["Local"].IsMap());

    const YAML::Node& global = node["Global"];
    EXPECT_TRUE(global.IsMap());
    EXPECT_EQ(global.size(), 2);
    EXPECT_TRUE(global["friction_design_factor"].IsScalar());
    EXPECT_TRUE(global["interfacial_condesation_design_factor"].IsScalar());
    EXPECT_DOUBLE_EQ(global["friction_design_factor"].as<double>(), 1.13);
    EXPECT_DOUBLE_EQ(global["interfacial_condesation_design_factor"].as<double>(), 100.59);

    const YAML::Node& primary = node["Primary"];
    EXPECT_TRUE(primary.IsMap());
    EXPECT_EQ(primary.size(), 2);
    EXPECT_TRUE(primary["friction_design_factor"].IsScalar());
    EXPECT_TRUE(primary["design_factor"].IsScalar());
    EXPECT_DOUBLE_EQ(primary["friction_design_factor"].as<double>(), 2.8);
    EXPECT_DOUBLE_EQ(primary["design_factor"].as<double>(), 8.7);
    
    const YAML::Node& secondary = node["Secondary"];
    EXPECT_TRUE(secondary.IsMap());
    EXPECT_EQ(secondary.size(), 1);
    EXPECT_TRUE(secondary["interfacial_condesation_design_factor"].IsScalar());
    EXPECT_DOUBLE_EQ(secondary["interfacial_condesation_design_factor"].as<double>(), 200.54);
    
    const YAML::Node& locca = node["LOCCA_Injection"];
    EXPECT_TRUE(locca.IsMap());
    EXPECT_EQ(locca.size(), 1);
    EXPECT_TRUE(locca["arbitrary_special_design_factor"].IsScalar());
    EXPECT_DOUBLE_EQ(locca["arbitrary_special_design_factor"].as<double>(), 0.5);
    
    const YAML::Node& local = node["Local"];
    EXPECT_TRUE(local.IsMap());
    EXPECT_EQ(local.size(), 3);

    const YAML::Node& component1 = local["component1"];
    EXPECT_TRUE(component1.IsMap());
    EXPECT_EQ(component1.size(), 3);
    EXPECT_TRUE(component1["number"].IsScalar());
    EXPECT_EQ(component1["number"].as<int>(), 104);
    EXPECT_TRUE(component1["friction_design_factor"].IsScalar());
    EXPECT_DOUBLE_EQ(component1["friction_design_factor"].as<double>(), 1.23);
    EXPECT_TRUE(component1["design_factor2"].IsScalar());
    EXPECT_DOUBLE_EQ(component1["design_factor2"].as<double>(), 27.5);

    const YAML::Node& component2 = local["component2"];
    EXPECT_TRUE(component2.IsMap());
    EXPECT_EQ(component2.size(), 2);
    EXPECT_TRUE(component2["number"].IsScalar());
    EXPECT_EQ(component2["number"].as<int>(), 105);
    EXPECT_TRUE(component2["friction_design_factor"].IsScalar());
    EXPECT_DOUBLE_EQ(component2["friction_design_factor"].as<double>(), 2.23);

    const YAML::Node& component3 = local["component3"];
    EXPECT_TRUE(component3.IsMap());
    EXPECT_EQ(component3.size(), 2);
    EXPECT_TRUE(component3["number"].IsSequence());
    EXPECT_EQ(component3["number"].size(), 3);
    EXPECT_EQ(component3["number"][0].as<int>(), 106);
    EXPECT_EQ(component3["number"][1].as<int>(), 107);
    EXPECT_EQ(component3["number"][2].as<int>(), 108);
    EXPECT_TRUE(component3["friction_design_factor"].IsScalar());
    EXPECT_DOUBLE_EQ(component3["friction_design_factor"].as<double>(), 2.2354343);
}
	
int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();    
}
