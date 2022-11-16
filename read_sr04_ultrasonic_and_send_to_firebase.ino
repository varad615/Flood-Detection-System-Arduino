#include <ESP8266WiFi.h>
#include <FirebaseESP8266.h> 
#include "ThingSpeak.h"
/* Buzzer */
const int buzzer =  2;
/*  */

int RED = 5;
int GREEN = 4;
int BLUE = 0;
                          
#define FIREBASE_HOST "nodemcu-esp8266-ioe-default-rtdb.firebaseio.com"                     //Your Firebase Project URL goes here without "http:" , "\" and "/"
#define FIREBASE_AUTH "Dr0NHkSBrodsPaoNbSM4UvGV5pBEFOhrHylJ7Cb8" //Your Firebase Database Secret goes here

#define WIFI_SSID "gundap"                                               //WiFi SSID to which you want NodeMCU to connect
#define WIFI_PASSWORD "29july2001"                                      //Password of your wifi network 

// thinkspeak
WiFiClient  client;
unsigned long myChannelNumber = 000000; // Channel ID here
const int FieldNumber = 1;
const char * myWriteAPIKey = "NX3IUCP59IY9Y3Z8"; // Your Write API Key here

// Declare the Firebase Data object in the global scope
FirebaseData firebaseData;

// Declare global variable to store value
int val=0;

float temp = 0;

//ultrasonice sensor
const int trigPin = 12;
const int echoPin = 14;

//define sound velocity in cm/uS
#define SOUND_VELOCITY 0.034
#define CM_TO_INCH 0.393701

long duration;
float distanceCm;
float distanceInch;
float format_temp;

void setup() {

  pinMode(RED, OUTPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(BLUE, OUTPUT);
  Serial.begin(115200);
  // define temp sensor LM35 pins ( A0 -tfMiddle pin | Left pin - 3v | Right pin - Gnd)
  pinMode(A0, INPUT); 

  //ultrasoncie sensor
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output ( Trig pin in D6 )
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input ( Echo in D5 )

  Serial.println("Serial communication started\n\n");  
           
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);//try to connect with wifi
  Serial.print("Connecting to ");
  Serial.print(WIFI_SSID);

  ThingSpeak.begin(client);

  /* Buzzer */
  pinMode(buzzer, OUTPUT);
  /* 3*/
  
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }

  
  Serial.println();
  Serial.print("Connected to ");
  Serial.println(WIFI_SSID);
  Serial.print("IP Address is : ");
  Serial.println(WiFi.localIP());                                            //print local IP address
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);   // connect to firebase

  Firebase.reconnectWiFi(true);
  delay(1000);
}

void loop() { 

  //water sensor | Ultrasonice sensor
  // Clears the trigPin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  
  // Calculate the distance
  distanceCm = duration * SOUND_VELOCITY/2;
  
  // Convert to inches
  distanceInch = distanceCm * CM_TO_INCH;
  

  // ultrasonice sensor ends

  //temp try

  int analogValue = analogRead(A0);
  float millivolts = (analogValue/1024.0) * 3300;
  float celsius = millivolts/10;
//  Serial.print("Degree C= ");
//  Serial.println(celsius);

  //try
  
  temp = (analogRead(A0) * 330.0) / 1023.0;
  Serial.print("Temperature: ");  
  Serial.print(temp);  
  Serial.println("°C ");
  String fireTemp = String(temp) + String("°C");              

  Firebase.setInt(firebaseData, "/sensor/temp", celsius);
  Firebase.setInt(firebaseData, "/sensor/water", distanceCm);
// send humidity to firebase database
// thinkspeak led
 ThingSpeak.writeField(myChannelNumber, FieldNumber, distanceCm, myWriteAPIKey);

  /* buzzer */
  if (distanceCm >=9){

    digitalWrite(buzzer, LOW);
      }
  else if (distanceCm < 9 && distanceCm >=6){
    digitalWrite(buzzer, LOW);}
  else {
    digitalWrite(buzzer, HIGH);
    delay(1000);
    digitalWrite(buzzer, LOW);
    
  }



  
  /* buzzer */


    if (distanceCm >=9){
    digitalWrite(RED,LOW);
    digitalWrite(GREEN,HIGH);
    digitalWrite(BLUE,LOW);
      }
  else if (distanceCm < 9 && distanceCm >=6){
    digitalWrite(RED,LOW);
    digitalWrite(GREEN,LOW);
    digitalWrite(BLUE,HIGH);
    }
  else {
    digitalWrite(RED,HIGH);
    digitalWrite(GREEN,LOW);
    digitalWrite(BLUE,LOW);    
  }

//Print all at serial monitor
  Serial.print("Distance (cm): ");
  Serial.println(distanceCm);





}
