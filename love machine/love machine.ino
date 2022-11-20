//inspiration: https://forum.arduino.cc/t/previous-value-vs-current-value-of-an-analog-read/64157; https://www.arduino.cc/en/Tutorial/BuiltInExamples/StateChangeDetection; https://forum.arduino.cc/t/how-to-monitor-a-switchs-state-and-do-x-if-switch-has-remained-in-state-b/99873
int sensor1=A0;
int sensor2=A1;
//const int LEDCOUNT =1;
int LEDPins1=2;
int LEDPins2=3;
int randomNum;
int current1;
int current2;
int previous1;
int previous2;

void setup() {
  Serial.begin(9600);
  pinMode(LEDPins1,OUTPUT);
  pinMode(LEDPins2,OUTPUT);
  pinMode(sensor1,INPUT);
  pinMode(sensor2,INPUT);
  
  //randomNum = random(2,4);
  

}
void loop() {
  compare();
  //int val1 = analogRead(sensor1);
  //int val2 = analogRead(sensor2);
  // Serial.println(val1);
  // Serial.println(val2);

  // if(val2<=600){
  //   digitalWrite(LEDPins[0], HIGH);
  //   digitalWrite(LEDPins[1], LOW);
  // } else {
  //   digitalWrite(LEDPins[1], HIGH);
  //   digitalWrite(LEDPins[0], LOW);
  // }

    //if(val1<=600&&val2<=600){
      //digitalWrite(randomNum,HIGH);
     // Serial.println(randomNum);
   // } else if (val1>500&&val2>500){
      //digitalWrite(randomNum, LOW);
     // digitalWrite(randomNum, LOW);
      
    }

     

void compare(){
  //store the last time value
previous1=current1; 
previous2=current2;
// get the new value while working
current1= analogRead (sensor1);
Serial.println(current1);
current2= analogRead (sensor2);
//while working, light up a random light
if ( current1-previous1 >200 && current2-previous2 >200) {  
     current1=1;
     current2=1;
     digitalWrite(randomNum,HIGH);
    //shut down the light when off 
  } else {
current1=0;
current2=0;
digitalWrite(LEDPins1, LOW);
digitalWrite(LEDPins2, LOW);
}
//compare the states: when press, states become different, choose a random number for light
if (current1 !=previous1 && current2!=previous2 ) {
      randomNum = random(2,4);
      digitalWrite(5-randomNum, LOW);
           Serial.println(randomNum);
}
}
