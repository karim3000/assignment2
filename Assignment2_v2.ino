///Task 1 variables
int pulse1 = 0.05 * 1000;  //Represents the duration of the Signal 1 pulse
int led1 = 21;
///Task 2 variables
int button1 = 22; //Pin of Button 1
///Task 3 variables
int task3pin = 14;
///task 4 variables
int task4pin = 13;
unsigned int ANLGinput;
///Task 5 variables
unsigned int task5avg;
int readcounter = 0;
void setup() {
  // put your setup code here, to run once:
  pinMode(led1, OUTPUT); //Defines the directionality of the led 1 pin to output
  //pinMode(led2, OUTPUT); //Defines the directionality of the led 2 pin to output
  pinMode(button1, INPUT); //Defines the directionality of the button 1 pin to input
  //pinMode(button2, INPUT); //Defines the directionality of the button 2 pin to input
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
  Serial.write(button1);}
void task3(){
  
}
void task4(){
  ANLGinput = digitalRead(task4pin);
  Serial.println(ANLGinput);
  if (counter >= 4){
    
  }
  task5avg = task5avg +}
void task5(){
  
}
