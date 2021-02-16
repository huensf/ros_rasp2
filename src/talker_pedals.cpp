#include "ros/ros.h"
#include "std_msgs/String.h"
#include "ros_rasp2/Pedals_msg.h"
#include <sstream>
#include <fstream>

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
		std::ifstream f1("/sys/bus/iio/devices/iio:device0/in_voltage1_raw");
		std::ifstream f2("/sys/bus/iio/devices/iio:device0/in_voltage2_raw");
		
		if(f1 && f2) 
		{
			std::string value1, value2;
			getline(f1,value1);
			getline(f2,value2); 
			
			ros_rasp2::Pedals_msg msg;
			msg.pedal1_value = ::atof(value1.c_str());
			msg.pedal2_value = ::atof(value2.c_str());
		
			chatter_pub.publish(msg);
			
			ros::spinOnce();
		
			loop_rate.sleep();
		}
		else
		{
			//cout << "ERREUR: Impossible d'ouvrir le fichier en lecture" << end1;
		}
		
	}
	
	return 0;
}
