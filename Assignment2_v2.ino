//////////////////////////////////////////////////////////////
///This code is comprised of 3 sections: Initialization   ////
///(variables and setup), Task subroutines, and the main  ////
///loop. Variables are split among their relevant         ////
///subroutines with names indicative of their purpose.    ////
///The main loop will execute tasks based on their frequency//
///by dividing the current time by the task period then   ///
///checking for a remainder.                             ////
/////////////////////////////////////////////////////////////

///Task 1 variables
int pulse1 = 0.05 * 1000;  //Represents the duration of the Signal 1 pulse
int led1 = 21; //LED pin
///Task 2 variables
int button1 = 22; //Pin of Button 1
unsigned int buttonState; 
unsigned long timeRN; //Tracks current time
int counter = 0; //Used to reset the current time every 5000 ms
///Task 3 variables
int task3pin = 16;   ///orange wire (analog input)
int frequency = 0;  
unsigned int measure1; //Holds the first measurement
unsigned int time1; 
unsigned int time2;
///task 4 variables
int task4pin = 13;
int ANLGinput = 0;
///Task 5 variables
unsigned int task5avg;
int readcounter = 0;
int oldANLG[] = {};
int compAvg = 0;
///Task 6 variables
int task6counter = 0;
///Task 7 variables
unsigned int error;
///Task 8 variables 
int led2 = 15;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(led1, OUTPUT); //Defines the directionality of the led 1 pin to output
  pinMode(led2, OUTPUT); //Defines the directionality of the led 2 pin to output
  pinMode(button1, INPUT); //Defines the directionality of the button 1 pin to input
  pinMode(task3pin, INPUT);
  pinMode(task4pin, INPUT);
}

void task1(){ //Turn LED on and off for duration of "pulse1"
  digitalWrite(led1, HIGH); //This line coupled with the 2 below will run a signal 
  delayMicroseconds(pulse1);
  digitalWrite(led1, LOW);}
  
void task2(){ //Store button state
  buttonState = digitalRead(button1);}
  
void task3(){ //Check task 3 pin then calculate the time it takes to change state
  measure1 = digitalRead(task3pin);
  time1 = millis();
  while (digitalRead(task3pin) == frequency){
  }
  time2 = millis();
  frequency = 1 / (time2 - time1);}
  
void task4(){ //Read and store an analog input from task4pin
  readcounter++;
  if (readcounter>=5){
    readcounter = 1;
  }
  ANLGinput = analogRead(task4pin);
  oldANLG[readcounter] = ANLGinput;}
  
  
void task5(){ //Calculate average of the last 4 analog inputs
  task5avg = oldANLG[1] + oldANLG[2] + oldANLG[3] + oldANLG[4];
  compAvg = task5avg / 4;}
    
void task6(){ 
  while (task6counter <= 100){
    __asm__ __volatile__ ("nop");
    task6counter++;}}
void task7(){ //Check error state 
  if (compAvg > (0.5 * 1023)){
    error = 1;}
  else{
    error = 0;}}
    
void task8(){ //LED 2 reflects error state (on = error)
  digitalWrite(led2, error);}
  
void task9(){
  ///Prints data in the format of: "buttonState, frequency, average"
  Serial.print(buttonState);
  Serial.print(", " );
  Serial.print(frequency);
  Serial.print(", " );
  Serial.println(compAvg);
  }


void loop() {
// put your main code here, to run repeatedly:
 timeRN = millis();
 if (timeRN > 5000){  //This creates a counter that resets every 5000 ticks
  counter++; //Increment counter
  timeRN = timeRN - (counter*5000);} //Cycles between 0-5000
 
 if ((timeRN % 9)== 0){ //Task 1 every 9ms
  task1();}
 if (timeRN % 200){  //Task 2 every 200ms
  task2();}
 if ((timeRN % 1000) == 0){ //Task 3 every 1000ms
  task3();}
 if ((timeRN % 42) == 0){ //Task 4 then 5 every 42 ms
  task4();
  task5();}
 if ((timeRN % 100) == 0){  //Task 6 every 100ms
  task6();}  
 if ((timeRN % 333) == 0){  //Task  then 8 every 333ms
  task7();
  task8();} 
 if (timeRN / 5000 == 1.00){  //Task 9 every 5000ms
  task9();}
}
