CBRoboLib
=========

An Arduino library to simplify the the control of a robot with a dual H-bridge and several other functions

Update 7/22/14:
	-Created Robot and drive methods
	-Implement in Sketch with the Robot constructor
		example:	Robot myRobot();
	-drive differentiates between forward, left, right, backward, and slowing down (else)
		example:	myRobot.drive(/* Left Velocity -100 to 100 */, /* Right Velocity -100 to 100 */);
	-Pins 3-8 used for H-Bridge
	-Untested as of 7/22/14