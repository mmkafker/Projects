/*Servo library to operate motors.*/
#include <Servo.h>

/*Pins used by the ultrasonic sensor*/
#define trigPin 8
#define echoPin 9

/*Variables to be used in the code*/
long duration;
float distanceInch;
int dir;

/*Instantiate servo objects(?)*/
Servo lServo;
Servo rServo;

void setup() {

  /*Trigger pin will output to the sensor.*/
  pinMode(trigPin, OUTPUT); 
  /*Echo pin will get data from the sensor.*/
  pinMode(echoPin, INPUT); 

  /*Attach servos to pins 10, 11.*/
  lServo.attach(10);
  rServo.attach(11);

  /*90 degrees corresponds to not moving. Stay still for 5 seconds.*/
  lServo.write(90);
  rServo.write(90);

  delay(5000);

}

void loop() {

  /*Next 5 lines send out ultrasonic pulse for 10 microseconds.*/
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  /*Record returning pulse.*/
  duration = pulseIn(echoPin, HIGH);
  
  /*2*d=vt*/
  distanceInch = duration * 0.0133 /2;

  /*Move forward*/
  lServo.write(60);
  rServo.write(60);

  /*If within 5 inches*/
  if (distanceInch < 5) {
    /*Pick a direction, either 1 or 2, at random.*/
    dir = random(1,3);

    /*Rotate in one direction by a random angle between 0 and Pi. 
    875 = (period of rotation at this speed)/2 */
    if (dir == 1) {
      lServo.write(50);
      rServo.write(130);
      delay(random(875));
    }
    /*Otherwise, rotate in the other direction.*/
    else {
      lServo.write(130);
      rServo.write(50);
      delay(random(875));
    }
  }
  delay(10);
    
}
