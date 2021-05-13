/*------------------------------------------------------------------------------
  01/10/2020
  Author: Makerbro
  Platforms: ESP8266
  Language: C++/Arduino
  File: webserver_rc_robot.ino
  ------------------------------------------------------------------------------
  Description: 
  Code for YouTube video showing how to build a wheeled robot, and control its
  movement over Wi-Fi:
  https://youtu.be/4gl7IZLo7yA
  Do you like my videos? You can support the channel:
  https://patreon.com/acrobotic
  https://paypal.me/acrobotic
  ------------------------------------------------------------------------------
  Please consider buying products from ACROBOTIC to help fund future
  Open-Source projects like this! We'll always put our best effort in every
  project, and release all our design files and code for you to use. 
  https://acrobotic.com/
  https://amazon.com/acrobotic
  ------------------------------------------------------------------------------
  License:
  Please see attached LICENSE.txt file for details.
------------------------------------------------------------------------------*/
// curl -F "file=@$PWD/index.html" 192.168.1.XX/upload

#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include <LittleFS.h>
#include <WebSocketsServer.h>
#include <Adafruit_MotorShield.h>
#include <ArduinoJson.h>
#define SPIFFS LittleFS

ESP8266WebServer server;
char const* ssid = "159cadence";
char const * password = "welcomehome";

// hold uploaded file
File fsUploadFile;

// websockets server for handling messages sent by the client
WebSocketsServer webSocket = WebSocketsServer(81);

// objects for moving the dc motors
Adafruit_MotorShield AFMS = Adafruit_MotorShield();
Adafruit_DCMotor *motor_left = AFMS.getMotor(3);
Adafruit_DCMotor *motor_right = AFMS.getMotor(4);

void setup()
{
  SPIFFS.begin();
  WiFi.begin(ssid,password);
  Serial.begin(115200);
  while(WiFi.status()!=WL_CONNECTED)
  {
    Serial.print(".");
    delay(500);
  }
  Serial.println("");
  Serial.print("IP Address: ");
  Serial.println(WiFi.localIP());

  server.on("/",handleIndexFile);
  // list available files
  server.on("/list", HTTP_GET, handleFileList);
  // handle file upload
  server.on("/upload", HTTP_POST, [](){
    server.send(200, "text/plain", "{\"success\":1}");
  }, handleFileUpload);
  server.begin();
  webSocket.begin();
  // function to be called whenever there's a websocket event
  webSocket.onEvent(webSocketEvent);

  AFMS.begin();
  // set the initial Strength of the motors
  //motor_left->setStrength(0);
  //motor_right->setStrength(0);
}

void loop()
{
  webSocket.loop();
  server.handleClient();
}

void webSocketEvent(uint8_t num, WStype_t type, uint8_t *payload, size_t length)
{
  if(type == WStype_TEXT)
  {
    // handle the websocket messages with direction and Strength
    // by parsing the parameters from a JSON string
    String payload_str = String((char*) payload);
    
    // using the ArduinoJson library
    StaticJsonDocument<200> doc;
    
    // deserialize the data
    DeserializationError error = deserializeJson(doc, payload_str);
    
    // parse the parameters we expect to receive (TO-DO: error handling)
    String dir = doc["direction"];

//    Serial.print("direction: ");
//    Serial.println(dir);
    if(dir == "Margarita") {
      //motor_left->run(RELEASE);
      //motor_right->run(RELEASE);
      Serial.println("Making Margarita");
    } else {
      int Strength = doc["strength"];
      Serial.println("Strength is: ");
      Serial.println(Strength);
      if(dir == "Margarita") {
        //motor_left->run(FORWARD);
        //motor_right->run(FORWARD);
        Serial.println("Margarita2");
      } else if(dir == "Mojito") {
        //motor_left->run(BACKWARD);
        //motor_right->run(BACKWARD);
        Serial.println("Mojito");
      } else if(dir == "Manhattan") {
        //motor_left->run(FORWARD);
        //motor_right->run(BACKWARD);
        Serial.println("Manhattan");
      } else if(dir == "OldFashioned") {
        //motor_left->run(BACKWARD);
        //motor_right->run(FORWARD);
        Serial.println("Old Fashioned");
      }
    }
  }
}

void handleFileUpload()
{
  HTTPUpload& upload = server.upload();
  if(upload.status == UPLOAD_FILE_START)
  {
    String filename = upload.filename;
    if(!filename.startsWith("/"))
      filename = "/"+filename;
    Serial.print("handleFileUpload Name: "); Serial.println(filename);
    fsUploadFile = SPIFFS.open(filename, "w");
  } else if(upload.status == UPLOAD_FILE_WRITE)
  {
    if(fsUploadFile)
      fsUploadFile.write(upload.buf, upload.currentSize);
  } else if(upload.status == UPLOAD_FILE_END)
  {
    if(fsUploadFile)
      fsUploadFile.close();
    Serial.print("handleFileUpload Size: "); Serial.println(upload.totalSize);
  }
}

void handleFileList()
{
  String path = "/";
  // Assuming there are no subdirectories
  Dir dir = SPIFFS.openDir(path);
  String output = "[";
  while(dir.next())
  {
    File entry = dir.openFile("r");
    // Separate by comma if there are multiple files
    if(output != "[")
      output += ",";
    output += String(entry.name()).substring(1);
    entry.close();
  }
  output += "]";
  server.send(200, "text/plain", output);
}

void handleIndexFile()
{
  File file = SPIFFS.open("/index.html","r");
  server.streamFile(file, "text/html");
  file.close();
}

/*------------------------------------------------------------------------------
  Basic movement of data:
  1. User opens iOS App.
  2. iOS App prompts the user for home network credentials.
  3. iOS App confirms these credentials work.
  4. iOS App automatically/immediately connects to the AP created by the ESP 8266, which will be the same coming from the factory (maybe BARBOT for the SSID, and BOOZE for the password).
  5. iOS App sends GET request to the ESP, with home network SSID and password in the URL (maybe not a great idea).
  6. User fills the bottles up and tells the iOS App what liquid is where.
  7. iOS app compiles the info into an index.html, and uploads it to the ESP8266.
------------------------------------------------------------------------------*/
