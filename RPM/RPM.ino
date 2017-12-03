int dataIN = 2; //IR sensor INPUT
const int D = 8; // Diameter in cm (include at the to
  // put your setup code here, to run once:
unsigned long prevmillis; // To store time
unsigned int duration; // To store time difference
int rpm; // RPM value

boolean currentstate; // Current state of IR input scan
boolean prevstate; // State of IR sensor in previous scan
void setup() {
  Serial.begin(9600);
  pinMode(dataIN,INPUT);       
  prevmillis = 0;
  prevstate = LOW;  
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:
  
  currentstate = digitalRead(dataIN); // Read IR sensor state
 if( prevstate != currentstate) // If there is change in input
   {
     if( currentstate == HIGH ) // If input only changes from LOW to HIGH
       {
         duration = ( millis() - prevmillis ); // Time difference between revolution in microsecond
         rpm = (60000/duration); // rpm = (1/ time millis)*1000*1000*60;
         prevmillis = millis(); // store time for nect revolution calc 
         delay(400);
       }
      prevstate = currentstate; // store this scan (prev scan) data for next s
   }
  Serial.println(rpm);
}
