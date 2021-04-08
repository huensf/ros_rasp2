# ros_rasp2
This package is an "extension" to [ros_rasp](https://git.immc.ucl.ac.be/huensf/ros_rasp).

Here, we use a second Raspberry Pi4B to send information about two pedals so that the speed of the vehicle can be varied in the Robotran simulation. This is the main difference with the other package: the exchange of information is not bi-directional anymore but only from the Raspberry Pi to the PC.

[[_TOC_]]

## Configuration of ROS & network setup

For the configuration of ROS and the network setup between the devices, I suggest you to read this [tutorial](https://git.immc.ucl.ac.be/huensf/ros_rasp). The only difference is the IP address: ss is **192.168.100.6** and the name of the package is now **ros_rasp2**.

*Note:* You may have to use a router to allow multiple ethernet connexion with the PC


## Global architecture

<img src="https://git.immc.ucl.ac.be/huensf/ros_rasp2/-/raw/master/img/globalarchi2.JPG" width="700">


## Compilation and run instructions
Again, it works the same way as for *ros_rasp* except that the node is called *talker_pedals*.


## I²C interface & ADC Converter

In order to retrieve the pedals position, we use two [linear potentiometers](https://www.dimed.eu/brands/penny-giles/sensors/hlp190.html) connected to an [ADC](https://wiki.seeedstudio.com/4-Channel_16-Bit_ADC_for_Raspberry_Pi-ADS1115/) fixed on the Raspberry Pi's GPIO pins.

If you want to use the same device, you have to follow [this tutorial](https://wiki.seeedstudio.com/4-Channel_16-Bit_ADC_for_Raspberry_Pi-ADS1115/) to get the desired data.

An example of use is given in [talker_pedals.cpp](https://git.immc.ucl.ac.be/huensf/ros_rasp2/-/blob/master/src/talker_pedals.cpp).


