#include "WiFiS3.h"
#include "RTC.h"

char ssid[] = "iainhendry";        // your network SSID (name)
char pass[] = "iain061271";    // your network password (use for WPA, or use as key for WEP)
int keyIndex = 0;                 // your network key index number (needed only for WEP)

int status = WL_IDLE_STATUS;

WiFiServer server(80);

void setup() {
  //Initialize serial and wait for port to open:
  Serial.begin(9600);

  // attempt to connect to WiFi network:
  while (status != WL_CONNECTED) {
    Serial.print("Attempting to connect to SSID: ");
    Serial.println(ssid);
    // Connect to WPA/WPA2 network. Change this line if using open or WEP network:
    status = WiFi.begin(ssid, pass);

    // wait 10 seconds for connection:
    delay(10000);
  }
  server.begin();
  printWifiStatus();
  RTC.begin(); 
  RTCTime startTime(02, Month::JULY, 2023, 15, 00, 00, DayOfWeek::SUNDAY, SaveLight::SAVING_TIME_ACTIVE);
  RTC.setTime(startTime);
}


void loop() 
{
  RTCTime currentTime;
  // Get current time from RTC
  RTC.getTime(currentTime);
  // listen for incoming clients
  WiFiClient client = server.available();
  if (client) 
  {
   // Serial.println("new client");
    // an HTTP request ends with a blank line
    boolean currentLineIsBlank = true;
    while (client.connected()) 
    {
      if (client.available()) 
      {
        char c = client.read();
        //Serial.write(c);
        // if you've gotten to the end of the line (received a newline
        // character) and the line is blank, the HTTP request has ended,
        // so you can send a reply
        if (c == '\n' && currentLineIsBlank) 
        {
          // send a standard HTTP response header
          client.println("HTTP/1.1 200 OK");
          client.println("Content-Type: text/html");
          client.println("Connection: close");  // the connection will be closed after completion of the response
          client.println("Refresh: 1");  // refresh the page automatically every 1 sec
          client.println();
          client.println("<!DOCTYPE HTML>");
          client.println("<html>");
          client.print("<h1>");
          client.print("Current Time ");
          client.print(currentTime.getHour());
          client.print(":");
          client.print(currentTime.getMinutes());
          client.print(":");
          client.print(currentTime.getSeconds());
          client.print("</h1>");
          client.println("</html>");
          break;
        }
        if (c == '\n') 
        {
          // you're starting a new line
          currentLineIsBlank = true;
        } else if (c != '\r') 
        {
          // you've gotten a character on the current line
          currentLineIsBlank = false;
        }
      }
    }
    // give the web browser time to receive the data
    //delay(0.1);

    // close the connection:
    client.stop();
   // Serial.println("client disconnected");
  }
}


void printWifiStatus() {
  // print the SSID of the network you're attached to:
  Serial.print("SSID: ");
  Serial.println(WiFi.SSID());

  // print your board's IP address:
  IPAddress ip = WiFi.localIP();
  Serial.print("IP Address: ");
  Serial.println(ip);
}
