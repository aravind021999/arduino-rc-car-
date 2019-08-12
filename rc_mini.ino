int X = 5;
int Y = 6;

int x, y, z, a;

int tol = 20;
int xmax = 1778;
int xcent = 1400;  
int xmin = 1028;
int ymin = 1100;
int ycent = 1410;
int ymax = 1750;
int dir1 = 12;
int dir2  =9;
int pwm1 = 11;
int pwm2 = 10;
void setup() {
  // put your setup code here, to run once:
  pinMode(X, INPUT);
  pinMode(Y, INPUT);
  pinMode(dir1, OUTPUT);
  pinMode(dir2, OUTPUT);
  pinMode(pwm1, OUTPUT);
  pinMode(pwm2, OUTPUT);

  Serial.begin(9600);

}

void loop() {

  // put your main code here, to run repeatedly:
  x = pulseIn(X, HIGH);
  Serial.print(x);
  delay(10);
  Serial.print("        ");
  y = pulseIn(Y, HIGH);
  Serial.print(y);
  delay(10);


  if ( (x > (xcent - tol) && x < (xcent + tol)) && (y > (ycent - tol) && y < (ycent + tol)) ) //rest
  {
    analogWrite(pwm1, 0);
    analogWrite(pwm2, 0);
    Serial.println("Rest");
  }
  else if (x < xmin && y < ymin) //rest
  {
    analogWrite(pwm1, 0);
    analogWrite(pwm2, 0);
    Serial.println("Rest");

  }

  if ((x > (xcent + tol) && (x < xmax)) && (y > (ycent - tol) && y < (ycent + tol))) //forward
  {
    z = map(x, (xcent + tol), xmax, 0, 255);
    analogWrite(pwm1, z);
    analogWrite(pwm2, z);
    digitalWrite(dir1,HIGH);
    digitalWrite(dir2,HIGH);
    Serial.println("Forward");

  }
  else if ((x < (xcent - tol) && (x > xmin)) && (y > (ycent - tol) && y < (ycent + tol))) //back
  {
    z = map(x, (xcent - tol), xmin, 0, 255);
    analogWrite(pwm1, z);
    analogWrite(pwm2, z);
    
    digitalWrite(dir1,LOW);
    digitalWrite(dir2,LOW);
    Serial.println("Backward");
  }

  else if ((x > (xcent - tol) && (x < (xcent + tol))) && (y > (ycent + tol) && y < ymax)) //diffrential right
  {
    z = map(y, (ycent + tol), ymin, 0, 255);
    
    
    analogWrite(pwm1, z);
    analogWrite(pwm2, z);
    
    digitalWrite(dir1,LOW);
    digitalWrite(dir2,HIGH);
    
    Serial.println("Differential Right");

  }
  else if ((x > (xcent - tol) && (x < (xcent + tol))) && (y < (ycent - tol) && y > ymin)) // differential left
  {

    z = map(y, (ycent - tol), ymin, 0, 255);
    
    analogWrite(pwm1, z);
    analogWrite(pwm2, z);
    
    digitalWrite(dir1,HIGH);
    digitalWrite(dir2,LOW);
    
    Serial.println("Differential Left");

  }
/*
else if ((x > (xcent + tol) && (x < xmax)) && (y > (ycent + tol) && y < ymax)) // forward right
  {

    z = map(x, (xcent - tol), xmin, 0, 255);
    w = map(y, (ycent - tol), ymin, 0, 255);
    analogWrite(pwm1, z-w);
    analogWrite(pwm2, z+w);
    
    digitalWrite(dir1,LOW);
    digitalWrite(dir2,HIGH);
    
    Serial.println("Forward Right");

  }

 
else if ((x > (xcent + tol) && (x < xmax)) && (y < (ycent - tol) && y > ymin)) // forward left
  {

    z = map(x, (xcent - tol), xmin, 0, 255);
    w = map(y, (ycent - tol), ymin, 0, 255);
    analogWrite(pwm1, z+w);
    analogWrite(pwm2, z-w);
    
    digitalWrite(dir1,HIGH);
    digitalWrite(dir2,LOW);
    
    Serial.println("Forward Left");

  } */
  }
 
