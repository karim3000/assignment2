///Task 1 variables
int led1 = 21;
///Task 2 variables
int button1 = 22; //Pin of Button 1

int task3pin = 13;

int pulse1 = 0.05 * 1000;  //Represents the duration of the Signal 1 pulse

void setup() {
  // put your setup code here, to run once:
  pinMode(led1, OUTPUT); //Defines the directionality of the led 1 pin to output
  pinMode(led2, OUTPUT); //Defines the directionality of the led 2 pin to output
  pinMode(button1, INPUT); //Defines the directionality of the button 1 pin to input
  pinMode(button2, INPUT); //Defines the directionality of the button 2 pin to input
 
}

void loop() {
  // put your main code here, to run repeatedly:
   task1();
   
}

void task1(){
  digitalWrite(led2, HIGH); //This line coupled with the 2 below will run a signal 
  delayMicroseconds(pulse1);            //with duration of 50uS to LED 2 representing signal B
  digitalWrite(led2, LOW);}
void task2(){
  Serial.write(button1);}
void task3(){
  
}
void task4(){
  
