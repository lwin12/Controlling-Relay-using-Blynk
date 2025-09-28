# Controlling-Relay-using-Blynk
This project demonstrates how we can control a relay using Blynk to in cooperate the use of IoT. 

This project uses a simple NodeMCU, esp8266.

The aim of this program is to be able to control GPIOs using the blynk application.  
The relay is attached to PIN D8 & the feedback PIN is D6. Do remember to short D8 and D6.

Do remember to change these 

#define BLYNK_TEMPLATE_ID "<insert_your_template_ID>"  
#define BLYNK_TEMPLATE_NAME "<insert_your_template_name>"  
#define BLYNK_AUTH_TOKEN "<insert_your_token>"  

char ssid[] = "<your_network_ID>";  
char pass[] = "<your_network_password>"; 
  
<img width="1705" height="719" alt="image" src="https://github.com/user-attachments/assets/a2893a00-2846-4ab3-935b-fef257a1c08c" />

