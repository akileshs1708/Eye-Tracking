/* Adjust these two values to reflect the
   position of the X ultrasonic sensor. */
const int A=20; // cm
const int B=15; // cm

/* Hardware connections */

const int trigPinX=2, echoPinX=3;
const int trigPinY=5, echoPinY=6;
const int servoPinL=8;
const int servoPinR=10;

float measureDist(int trigPin, int echoPin)
{
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(20);
  digitalWrite(trigPin, LOW);
  return pulseIn(echoPin, HIGH)/2*.0343;  
}

void servoControl(int servoPin, int angle)
{
  unsigned int duration;

  duration=map(angle, 0, 180, 544, 2400);
  digitalWrite(servoPin, HIGH);
  delayMicroseconds(duration);
  digitalWrite(servoPin, LOW);
}

void setup()
{
  pinMode(trigPinX, OUTPUT);
  pinMode(trigPinY, OUTPUT);
  pinMode(servoPinL, OUTPUT);
  pinMode(servoPinR, OUTPUT);
}

void loop()
{
  float distX, distY;
  int pos, diff;
  int limDistX, limDistY;

  distX=measureDist(trigPinX, echoPinX);
  limDistX=(int)constrain(distX, 4, 2*A);
  pos=map(limDistX, 4, 2*A, 45, 135);

  distY=measureDist(trigPinY, echoPinY);
  limDistY=(int)constrain(distY, 4, B);
  diff=map(limDistY, 4, B, 40, 0);

  if(pos==135)
  {
    pos=90;
    diff=0;
  }

  servoControl(servoPinL, pos-diff);
  servoControl(servoPinR, pos+diff);
  delay(60);
}