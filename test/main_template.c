// COMMENT

//CHECKING IF THE BRANCHING IS WORKING>

// MATT!!  read the turn_left and turn_right functions to figure out what you need to tune
// MATT!!  also read the loop to find values that need tuning

const int L90sensor = 3;   //  James's pin declarations
const int R90sensor = 8;
const int L45sensor = 4;
const int R45sensor = 9;
const int LeftMotor = 11;
const int RightMotor = 10;


const int sense_1 = 3, sense_2 = 4, sense_3 = 5, sense_4 = 9, sense_5 = 8;  // IR sensor pins

const int L_encoder1 = 1, L_encoder2 = 14;   // left encoder pins

const int R_encoder1 = 0, R_encoder2 = 31;  // right encoder pins

const int right_enable = 10, left_enable = 11;        // motor enable pins

const int led1 = 15, led2 = 16, led3 = 17, led4 = 18, led5 = 19;  // test led pins

const int switch1 = 20, switch2 = 21, switch3 = 22, switch4 = 23, switch5 = 24;   // switch pins

const int R_fwd = 13, R_bkw = 12, L_fwd = 7, L_bkw = 6;  // (verify)  motor direction pins

int R_enable_val = 60000;  // initialize enable values high
int L_enable_val = 60000;

volatile int R_encoder_val = 0;  // declare encoder interrupt values
volatile int L_encoder_val = 0;

typedef struct node
  {
  short int distance;
  char section;
  
  short int row;
  short int column;

  bool traveled_to;
  bool traced;
  
  struct node* up;
  struct node* down;
  struct node* left;
  struct node* right;
  };

  //struct node maze[16][16];


void setup()
{
  
  pinMode(sense_1, INPUT_ANALOG);
  pinMode(sense_2, INPUT_ANALOG);
  pinMode(sense_3, INPUT_ANALOG);
  pinMode(sense_4, INPUT_ANALOG);
  pinMode(sense_5, INPUT_ANALOG);
  
  attachInterrupt(L_encoder1, left_interrupt, RISING);  // may need to adjust encoder operation
  attachInterrupt(L_encoder2, left_interrupt, RISING);
  attachInterrupt(R_encoder1, right_interrupt, RISING);
  attachInterrupt(R_encoder2, right_interrupt, RISING);  // comment out interrupts not used

  pinMode(right_enable, PWM);
  pinMode(left_enable, PWM);
  
  pinMode(led1, PWM);         // configure first two test LEDs as PWM outs
  pinMode(led2, PWM);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  pinMode(led5, OUTPUT);
  
  pinMode(switch1, INPUT);
  pinMode(switch2, INPUT);
  pinMode(switch3, INPUT);
  pinMode(switch4, INPUT);
  pinMode(switch5, INPUT);
  
  pinMode(R_fwd, OUTPUT);
  pinMode(R_bkw, OUTPUT);
  pinMode(L_fwd, OUTPUT);
  pinMode(L_bkw, OUTPUT);
  
 
  pwmWrite(right_enable, 60000);
  pwmWrite(left_enable, 60000);
  //SerialUSB.println("hello world");
  
}


void loop()
{
  

	motor_test();
	/*
	
	int left, right, straight;  // make sure the left90 sensor is pin 4, left45 is pin 5, right45 is 9
				    // and right90 is pin 3
				    // if this isn't true, change the pin declarations up top
				    // (BOTH mine and James's)
				    // my senors from 1 through 5 correspond to from left to right (90,45,0,45,90)
	
	left = analogRead(sense_1);
	right = analogRead(sense_5);
	straight = analogRead(sense_3);
	
	if(straight < 4000)     // if the mouse gets too close to the wall before turning, decrease the value
	{			// if the mouse starts to turn before getting close enough, increase delay
				// delay can be found in the next three if statements, all delay functions
				// must have the same delqy value;
		
		digitalWrite(R_bkw, LOW);
  		digitalWrite(L_bkw, LOW);
		digitalWrite(R_fwd, HIGH);
  		digitalWrite(L_fwd, HIGH);
		
		GoStraight();
		
		
	}
	
	else if(right < 3000)  // if the mouse doesnt see the opening, increase the value (including below)
	{			// if the mouse turns where it shouldnt, decrease the value (including below)
		
		delay(0);  // increase by 100's, if the mouse goes too far, increase by 10's or 20's
		
		turn_right;
	}
	
	else if(left < 3000)  //  if the mouse doesnt see the opening, increase the value
	{			// if the mouse turns where it shouldnt, decrease the value
		
		delay(0);  // increase by 100's, if the mouse goes too far, increase by 10's or 20's
		
		turn_left();
	}
	
	else
	{
		delay(0);  // increase by 100's, if the mouse goes too far, increase by 10's or 20's
		
		turn_left();
		turn_left();
	}
*/
  
	 /*
	 // figure out how fast mouse can slow down 
	 // need decision(algorithm) function 
	 // need mapping function 
	 // need function to determine current grid location
	 // need turning functions 
	 // need exploration(algorithm) function 
	 // need straight line function
	 // need race function (premapped maze) <- shortest path
	 // ^ race function may need to be called at dead end (to find closest door)
   
  
  
  */
  
  
  
}

void left_interrupt()
{
  ++ L_encoder_val;
}

void right_interrupt()
{
  ++ R_encoder_val;
}

void motor_test()  // motor testing function
{
  pwmWrite(right_enable, R_enable_val);
  pwmWrite(left_enable, L_enable_val);
  
  digitalWrite(R_bkw, LOW);
  digitalWrite(L_bkw, LOW);
  
  digitalWrite(R_fwd, HIGH);
  digitalWrite(L_fwd, HIGH);
  /*
  delay(1000);
  
  digitalWrite(R_fwd, LOW);
  digitalWrite(L_fwd, LOW);
  
  delay(100);
  
  digitalWrite(R_fwd, HIGH);
  digitalWrite(L_bkw, HIGH);
  
  delay(1000);
  
  digitalWrite(R_fwd, LOW);
  digitalWrite(L_bkw, LOW);
  
  delay(100);
  
  digitalWrite(R_bkw, HIGH);
  digitalWrite(L_fwd, HIGH);
  
  delay(1000);
  
  digitalWrite(R_bkw, LOW);
  digitalWrite(L_fwd, LOW);
  
  delay(100);
  
  digitalWrite(R_bkw, HIGH);
  digitalWrite(L_bkw, LOW);
  
  delay(1000);
  
  digitalWrite(R_bkw, LOW);
  digitalWrite(L_bkw, LOW);
  */
}

void turn_left() // point turn
{
  digitalWrite(R_fwd, LOW);
  digitalWrite(L_fwd, LOW);
  digitalWrite(R_bkw, LOW);
  digitalWrite(L_bkw, LOW);
  
  pwmWrite(right_enable, 50000);  // decrese the value for a slower turn, increase it to go faster
  pwmWrite(left_enable, 50000);	  // decrese the value for a slower turn, increase it to go faster
  
  delay(100);  // decrease delay if mouse pauses too much, increase it if the mouse tries to turn
  	       // before slowing down enough (same thing in turn_right)
  
  digitalWrite(R_fwd, HIGH);
  
  digitalWrite(L_bkw, HIGH);
  
  delay(1500);  // tune this value for complete turn ************* ///////////////////

  digitalWrite(R_fwd, LOW);
  digitalWrite(L_bkw, LOW);
}

void turn_right()  // point turn
{
  digitalWrite(R_fwd, LOW);
  digitalWrite(L_fwd, LOW);
  digitalWrite(R_bkw, LOW);
  digitalWrite(L_bkw, LOW);
  
  pwmWrite(right_enable, 50000);  // decrese the value for a slower turn, increase it to go faster
  pwmWrite(left_enable, 50000);   // decrese the value for a slower turn, increase it to go faster
  
  delay(100);
  
  digitalWrite(L_fwd, HIGH);
  
  digitalWrite(R_bkw, HIGH);
  
  delay(1500);  // tune this value for complete turn ******* ///////////////////

  digitalWrite(L_fwd, LOW);
  digitalWrite(R_bkw, LOW);
}


void spin()  // because, why not?
{
  	while(1)
  	{
  		turn_left();
  	}
}

void GoStraight()
{
//int currentVoltage;
int voltageChange = 5;
int D1 = analogRead(L45sensor) - analogRead(R45sensor);
delay(20);						//  delay MIGHT need to be longer
int D2 = analogRead(L45sensor) - analogRead(R45sensor);

if(D1 == D2)
;
else if(D1 < D2)
{
if(voltageChange < 0)
{
  ChangeLeft(&voltageChange);
}
else
{
  ChangeRight(&voltageChange);
}
}
else if(D1 > D2)
{
if(voltageChange < 0)
ChangeRight(&voltageChange);
else
{
  ChangeLeft(&voltageChange);
}
}
}

void ChangeRight(int* change)
{
int currentVoltage = analogRead(RightMotor);
if(currentVoltage == 0 || currentVoltage > 3125)  //change 1020 value to max 
*change = -(*change);                                             //voltage wanted
pwmWrite(RightMotor, currentVoltage*16 + *change);
}

void ChangeLeft(int* change)
{
int currentVoltage = analogRead(LeftMotor);
if(currentVoltage == 0 || currentVoltage > 3125)  //change 1020 value to max 
*change = -(*change);                                             //voltage wanted
pwmWrite(LeftMotor, currentVoltage*16 + *change);
}
