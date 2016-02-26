// -----------------------------------
// demo lock-firmware for OpenInAClick (works with leds :))
// for user with our drupal module.
// Peter Willemsen <peter@codebuffet.co>
// -----------------------------------

int led1 = D0;

// Last time, we only needed to declare pins in the setup function.
// This time, we are also going to register our Spark function

void setup()
{
   // Here's the pin configuration, same as last time
   pinMode(led1, OUTPUT);

   // We are also going to declare a Spark.function so that we can turn the LED on and off from the cloud.
   Particle.function("toggleLock",toggleLock);
   
   // For good measure, let's also make sure both LEDs are off when we start:
   digitalWrite(led1, LOW);

}

String getValue(String data, char separator, int index)
{
 int found = 0;
  int strIndex[] = {
0, -1  };
  int maxIndex = data.length()-1;
  for(int i=0; i<=maxIndex && found<=index; i++){
  if(data.charAt(i)==separator || i==maxIndex){
  found++;
  strIndex[0] = strIndex[1]+1;
  strIndex[1] = (i == maxIndex) ? i+1 : i;
  }
 }
  return found>index ? data.substring(strIndex[0], strIndex[1]) : "";
}

void loop()
{
   // Nothing to do here
}

int pinStringToNumber(String portStr) {
    portStr = portStr.toUpperCase();
    if(portStr == "D0") {
        return D0;
    }
    if(portStr == "D1") {
        return D1;
    }
    if(portStr == "D2") {
        return D2;
    }
    if(portStr == "D3") {
        return D3;
    }
    if(portStr == "D4") {
        return D4;
    }
    if(portStr == "D5") {
        return D5;
    }
    if(portStr == "D6") {
        return D6;
    }
    if(portStr == "D7") {
        return D7;
    }
    
    // analog
    if(portStr == "A0") {
    	return A0;
    }
    if(portStr == "A1") {
    	return A1;
    }
    if(portStr == "A2") {
    	return A2;
    }
    if(portStr == "A3") {
    	return A3;
    }
    if(portStr == "A4") {
    	return A4;
    }
    if(portStr == "A5") {
    	return A5;
    }
    if(portStr == "A6") {
    	return A6;
    }
    if(portStr == "A7") {
    	return A7;
    }
    
    return D1;
}

// This will toggle the led (which will be the lock)
int toggleLock(String data) {
    String delayStr = getValue(data, '_', 0);
    String portStr = getValue(data, '_', 1);
    
    Particle.publish("toggleLock: " + delayStr + " " + portStr);
    
    int delay_ = delayStr.toInt();
    int lockPin = pinStringToNumber(portStr);
    
    pinMode(lockPin, OUTPUT);
    digitalWrite(led1,HIGH);
    digitalWrite(lockPin,HIGH);
    
    delay(delay_ * 1000);
    
    digitalWrite(led1,LOW);
    digitalWrite(lockPin,LOW);
}
