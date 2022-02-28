#include <ros/ros.h>
#include <kst_servoing.hpp>
#include <boost/asio.hpp>

int main(int argc, char** argv){
	ros::init(argc, argv, "KSTRosNode");

	KSTServoing s;
	boost::asio::io_context io_context;
	std::string robot_ip = "172.31.1.147";
	s(robot_ip, io_context);

}