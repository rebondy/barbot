# barbot
BarBot is a cocktail making robot. I imagine most people will interact with the machine through the webpage that is hosted locally on the ESP8266. The software is comprised of 3 parts. 

The first part of is the iOS app. The app automatically connects to the ESP 8266's default wifi network. The app prompts the user for how the home wifi credentials, and then attaches the ESP8266 to the wifi network. Then the app asks the user what they put into the machine, and then tells them what drinks they can make. 

The second par is the webpage. The app uses the user input information to assemble an HTML file, and uploads it to the ESP8266. The iOS app contains a HTML template, and makes a new HTML file with all the buttons that match with the drinks that can be made with what is in the machine. 

Lastly is the ESP8266, which is quite simple. It just parses what the webpage sends to the ESP8266.


The machine has 4 servos, each servo controls the flow of 3 liquids. The algorithm figures out what the optimal location is for each servo.
