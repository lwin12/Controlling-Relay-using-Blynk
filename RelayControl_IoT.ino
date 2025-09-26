/*************************************************************

  This is a simple demo of sending and receiving some data.
  Be sure to check out other examples!
 *************************************************************/

/* Fill-in information from Blynk Device Info here */
#define BLYNK_TEMPLATE_ID "TMPL6dM-1UoZM"
#define BLYNK_TEMPLATE_NAME "Relay Control"
#define BLYNK_AUTH_TOKEN "ldc8FNf1-nucdNFj0GqNzc9_rlGLY7K7"

/* Comment this out to disable prints and save space */
#define BLYNK_PRINT Serial
#define GREEN D8 
#define RELAY_FEEDBACK D6
#define ON HIGH
#define OFF LOW 

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "Singtel-WPA2";
char pass[] = "atmootletayz";
bool connection = false;
BlynkTimer timer;

// This function is called every time the Virtual Pin 0 state changes
BLYNK_WRITE(V0)
{
  // Set incoming value from pin V0 to a variable
  int value = param.asInt();
  // Update state
  Blynk.virtualWrite(V1, relay(value));
}

// This function is called every time the device is connected to the Blynk.Cloud
BLYNK_CONNECTED()
{
  connection = true;
}

// This function sends Arduino's uptime every second to Virtual Pin 2.
void myTimerEvent()
{
  // You can send any value at any time.
  // Please don't send more that 10 values per second.
  Blynk.virtualWrite(V2, millis() / 1000);
}

void setup()
{
  // Debug console
  Serial.begin(115200);

  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
  pinMode(RELAY_FEEDBACK, INPUT);
  pinMode(GREEN, OUTPUT);

  if(connection == true)
  {
    Blynk.virtualWrite(V1, relay(0));
    Blynk.virtualWrite(V0, relay(0));
  }
  // You can also specify server:
  //Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass, "blynk.cloud", 80);
  //Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass, IPAddress(192,168,1,100), 8080);

  // Setup a function to be called every second
  //timer.setInterval(1000L, myTimerEvent);
}

void loop()
{
  Blynk.run();
}

int relay(int getVal)
{
  digitalWrite(GREEN, getVal == 1 ? ON : OFF);
  return digitalRead(RELAY_FEEDBACK);
}

