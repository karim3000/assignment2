///Task 1 variables
int pulse1 = 0.05 * 1000;  //Represents the duration of the Signal 1 pulse
int led1 = 21;
///Task 2 variables
int button1 = 22; //Pin of Button 1
unsigned int buttonState;
///Task 3 variables
int task3pin = 14;
unsigned int frequency;
///task 4 variables
int task4pin = 13;
int ANLGinput = 0;
///Task 5 variables
unsigned int task5avg;
int readcounter = 0;
int oldANLG = 0;
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

void loop() {
  // put your main code here, to run repeatedly:
   task1();
   
}

void task1(){
  digitalWrite(led1, HIGH); //This line coupled with the 2 below will run a signal 
  delayMicroseconds(pulse1);            //with duration of 50uS to LED 2 representing signal B
  digitalWrite(led1, LOW);}
void task2(){
  buttonState = digitalRead(button1);}
void task3(){
  
}
void task4(){
  readcounter++;
  oldANLG = ANLGinput;
  ANLGinput = digitalRead(task4pin);}

void task5(){
  if (readcounter <= 4){
    task5avg = task5avg + ANLGinput;}
  else {
    task5avg = task5avg + ANLGinput - oldANLG;}
    compAvg = task5avg / 4;
}
void task6(){
  while (task6counter <= 1000){
    __asm__ __volatile__ ("nop");
    task6counter++;}
}
void task7(){
  if (compAvg > (0.5 * 256)){
    error = 1;}
else{
    error = 0;}
}
void task8(){
  digitalWrite(led2, error);
}
void task9(){
  Serial.println(buttonState && ", " && frequency && ", " && compAvg);}
