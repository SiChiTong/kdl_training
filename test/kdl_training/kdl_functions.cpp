#include <gtest/gtest.h>
#include <kdl_training/kdl_functions.hpp>
#include <kdl_parser/kdl_parser.hpp>
#include <ros/ros.h>
#include <kdl/frames_io.hpp>

namespace kdl_training;
class TransformTest : public ::testing::Test
{
	protected:
	    virtual void SetUp()
	    {
	    	dof = 8;
		joint_names.resize(dof);
     		joint_names.push_back("torso_lift_joint");
      		joint_names.push_back("r_shoulder_pan_joint");
      		joint_names.push_back("r_shoulder_lift_join");
		joint_names.push_back("r_upper_arm_roll_joint");
		joint_names.push_back("r_elbow_flex_joint");
		joint_names.push_back("r_forearm_flex_joint");
		joint_names.push_back("r_wrist_flex_joint");
		joint_names.push_back("r_wrist_roll_joint");

		 if (!kdl_parser::treeFromFile("pr2.urdf", my_tree)){
       		 	throw std::logic_error( "Could not construct the tree" );


		if (!my_tree.getChain("base_link", "r_gripper_tool_frame", chain_))
		        throw std::logic_error( "Could not construct the chain" );
	    }

	    virtual void TearDown()
	    {
	      
	    }

	     std::size_t dof;
	     std::vector<std::string> joint_names;
	     KDL::Tree my_tree;
	     KDL::Chain chain_;
};

TEST_F(TransformTest, RunTest)
{	
	
//	joint_names_function = kdl_functions::getJointNames(?);
//	for (int i = 0; i < joint_names.size(); i++)
//		ASSERT_STREQ(joint_names_hardcoded[i], joint_names_function[i]);
}

