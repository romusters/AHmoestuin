int relayPin = 5;

void setup()
{
  Serial.begin(9600);
  //The sensor pin
  pinMode(A0, INPUT);
  pinMode(relayPin, OUTPUT);
  digitalWrite(relayPin, HIGH);
  
}

bool flag = false;

void loop()
{
  int SensorValue = analogRead(A0); //take a sample
  Serial.print(SensorValue); Serial.print(" - ");
  
  if(SensorValue >= 1000) {
   Serial.println("Sensor is not in the Soil or DISCONNECTED");
  }
  if(SensorValue < 1000 && SensorValue >= 600 && !flag) { 
   Serial.println("Soil is DRY");
   //Give water ...
   digitalWrite(relayPin, LOW); 
   delay(5000);
   digitalWrite(relayPin, HIGH); 
   //and only give new water if the soil has become humid again
   flag = true;
  }
  
  if(SensorValue < 600 && SensorValue >= 370) {
   Serial.println("Soil is HUMID"); 
   flag = false;
  }
  
  if(SensorValue < 370) {
   Serial.println("Sensor in WATER");
  }
  delay(5000);
}

