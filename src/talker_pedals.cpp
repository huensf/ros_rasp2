#include "ros/ros.h"
#include "std_msgs/String.h"
#include "ros_rasp2/Pedals_msg.h"
#include <sstream>

//#define SENSOR1_DIR "/sys/bus/iio/devices/iio:device0/in_voltage1_raw"
//#define SENSOR2_DIR "/sys/bus/iio/devices/iio:device0/in_voltage2_raw"

int main(int argc, char **argv) 
{
	ros::init(argc, argv, "talker_pedals");
	
	ros::NodeHandle n;
	
	ros::Publisher chatter_pub = n.advertise<ros_rasp2::Pedals_msg>("chatter_pedals",1000);
	
	ros::Rate loop_rate(1000);
	
	while(ros::ok())
	{
		ros_rasp2::Pedals_msg msg;
		//msg.pedal1_value = 0.0;
		//msg.pedal2_value = 0.0;
		//msg.pedal1_value = (double)SENSOR1_DIR;
		//msg.pedal2_value = (double)SENSOR2_DIR;
		
		chatter_pub.publish(msg);
		
		ros::spinOnce();
		
		loop_rate.sleep();
	}
	
	return 0;
}
