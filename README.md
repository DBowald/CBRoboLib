CBRoboLib
=========

An Arduino library to simplify the the control of a robot with a dual H-bridge and several other functions

Update 7/27/14b:
	-Changed left motor to pins 9 and 10 from 3 and 4
	-Diagram of H-Bridge connections: ![alt text](http://paulugolini.com/H-Bridge%20Diagram.png "H-Bridge Diagram")

Update 7/27/14:
	-Fixed various syntax issues
	-Fixed bug where reverse left and reverse right were not possible with (-100, 0) and (0, -100)
	-Tested various velocity values
	-Included diagram for H-Bridge connections to Arduino Uno
		
Update 7/22/14:
	-Created Robot and drive methods
	-Implement in Sketch with the Robot constructor
		example:	Robot myRobot();
	-Drive differentiates between forward, left, right, backward, and slowing down (else)
		example:	myRobot.drive(/* Left Velocity -100 to 100 */, /* Right Velocity -100 to 100 */);
	-Pins 3-8 used for H-Bridge
	-Untested as of 7/22/14