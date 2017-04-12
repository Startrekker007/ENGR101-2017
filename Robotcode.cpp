#include "E101.h"
#include <stdio.h>
int main(){
	initialise();
	

}

void turnLeft(int turnTimes, int turnTimeMS, int change)
{
	setMotor(1, 127-change);
	setMotor(2, 127+change);
	sleep1(turnTimes, turnTimeMS);
	stop(1); stop(2);
}
void turnRight(int turnTimes, int turnTimeMS, int change)
{
	setMotor(1, 127+change);
	setMotor(2, 127-change);
	sleep1(turnTimes, turnTimeMS);
	stop(1); stop(2);
}
void driveStraight(int timeS, int timeMS, int speed)
{
	setMotor(1, speed);
	setMotor(2, speed);
	sleep1(timeS, timeMS);
	stop(1); stop(2);
}
void driveStraight(int speed)
{
	setMotor(1, speed);
	setMotor(2, speed);
}
void reverseSlow(int timeS, int timeMS, int speed)
{
	setMotor(1, (int)(-0.5*speed));
	setMotor(2, (int)(-0.5*speed));
	sleep1(timeS, timeMS);
	stop(1);stop(2);
}
void reverseSlow(int speed)
{
	setMotor(1, (int)(-0.5*speed));
	setMotor(2, (int)(-0.5*speed));
}
int measureIR(int num)
{
	int total = 0;
	for(int i = 0; i<num;i++)
	{
		total = total+readAnalog(0);
		sleep(0,10000);
	}
	return (int)(total/num);
}

void reverseIfIR()
{
	int IROut = measureIR(5);
	if(IROut>500)
	{
		reverseSlow(127);
	}
	
}
