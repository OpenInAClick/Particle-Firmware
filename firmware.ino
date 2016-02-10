// -----------------------------------
// demo lock-firmware for OpenInAClick (works with leds :))
// for user with our drupal module.
// Peter Willemsen <peter@codebuffet.co>
// -----------------------------------

// First, let's create our "shorthand" for the pins
// Same as in the Blink an LED example:
// led1 is D0, led2 is D7

int led1 = D0;
int lockPin = D1;

// Last time, we only needed to declare pins in the setup function.
// This time, we are also going to register our Spark function

void setup()
{

   // Here's the pin configuration, same as last time
   pinMode(led1, OUTPUT);
   pinMode(lockPin, OUTPUT);

   // We are also going to declare a Spark.function so that we can turn the LED on and off from the cloud.
   Particle.function("toggleLock",toggleLock);
   // This is saying that when we ask the cloud for the function "led", it will employ the function ledToggle() from this app.

   // For good measure, let's also make sure both LEDs are off when we start:
   digitalWrite(led1, LOW);
   digitalWrite(lockPin, LOW);

}

void loop()
{
   // Nothing to do here
}

// This will toggle the led (which will be the lock)
int toggleLock(String delayStr) {
    int delay_ = delayStr.toInt();
    digitalWrite(led1,HIGH);
    digitalWrite(lockPin,HIGH);
    
    delay(delay_ * 1000);
    
    digitalWrite(led1,LOW);
    digitalWrite(lockPin,LOW);
}
