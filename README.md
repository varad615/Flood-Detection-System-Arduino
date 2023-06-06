# Flood Detection System (NodeMCU ESP8266)
## Overview
The Flood Detection System is a project that utilizes NodeMCU ESP8266, an Android app developed using Java in Android Studio, and Firebase to create a system for detecting and monitoring floods. The NodeMCU ESP8266 is connected to the internet and sends real-time data to Firebase, which is then fetched by the Android app. The system aims to provide timely flood detection and alerting, allowing users to take necessary actions in case of potential flooding.

## Features
Real-time flood detection: The NodeMCU ESP8266 continuously monitors water levels and detects flooding events in real time.
Data transmission to Firebase: The NodeMCU ESP8266 is connected to the internet and sends flood data to Firebase for storage and retrieval.
Android app integration: The Android app developed in Java using Android Studio fetches flood data from Firebase and provides a user-friendly interface for monitoring flood conditions.
Firebase integration: Firebase serves as the backend for storing flood data, allowing seamless communication between the NodeMCU ESP8266 and the Android app.
Alerting system: The Android app can send notifications or alerts to users in case of detected floods, ensuring prompt action and response.

## Installation and Setup
To set up the Flood Detection System, follow these steps:

### NodeMCU ESP8266
Connect the NodeMCU ESP8266 to your computer or power source.
Install the necessary libraries and dependencies for the NodeMCU ESP8266.
Update the code with your Wi-Fi credentials and Firebase API keys.
Upload the code to the NodeMCU ESP8266 using the Arduino IDE or a suitable programming tool.

### Firebase
Create a new project in Firebase.
Enable the Firebase Realtime Database and Firebase Cloud Messaging services.
Set up the database rules to allow read and write access for the Flood Detection System.
Obtain the Firebase API keys and configuration details.
Update the NodeMCU ESP8266 code and Android app code with the Firebase API keys and configuration.

## Usage
Once the Flood Detection System is set up and running, you can perform the following tasks:

### NodeMCU ESP8266
The NodeMCU ESP8266 will automatically start monitoring water levels and send data to Firebase.
Ensure the NodeMCU ESP8266 is properly connected to the power source and has an internet connection.

### Android App
Open the Flood Detection System Android app on your Android device.
The app will fetch flood data from Firebase and display the current flood status.
If a flood event is detected, the app will send notifications or alerts to your device.
Use the app to monitor flood conditions and take necessary actions in case of emergencies.
Support and Contributions
For any issues, questions, or suggestions regarding the Flood Detection System, please open an issue on the project's GitHub repository. Contributions are welcome and encouraged. Feel free to submit a pull request to improve the system.

## License
The Flood Detection System project is licensed under the MIT License. Please see the LICENSE file for more details.
