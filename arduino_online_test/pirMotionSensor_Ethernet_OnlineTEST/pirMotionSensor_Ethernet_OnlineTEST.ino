// Ethernet Interface Module TEST
#include <UIPEthernet.h>
#include <SPI.h>

// Send predetermined data to an online MySQL database

// Duinotech Ethernet Module
// HanRun HR911105A 16/02
// S1: Master Out Slave in (D11)
// CS: Chip Select (D10)
// VCC: Power (3.3v)
// SO: Master In Slave Out (D12)
// SCK: Serial Clock (D13)
// GND: Ground Connection (GND)

// Grab data from motion sensor and push it into an SQL server

// Declare variables
const int pirPin = 8;       // Pin for pir motion sensor
int pirState = LOW, value = 0;

// Randomly generated MAC Address (As long as it does not conflict with another device on network)
byte mac[] = {0xDE, 0x10, 0x15, 0x82, 0xA1, 0x17};
IPAddress ip(192, 168, 1, 188);

char server[] = "110.232.141.214";  //IP Address of server to dump data to
EthernetClient client;
// Set up variable for connection
boolean connected = false;

void setup() {
  pinMode(pirPin, INPUT);   // Declare pir motion sensor as input

  Serial.begin(9600);
  if (Ethernet.begin(mac) == 0) {
    Serial.println("Failed to configure Ethernet using DHCP");
    Serial.println("Failed to configure Ethernet using DHCP, using Static Mode");
    Ethernet.begin(mac, ip);
  }



  // Print network details
  Serial.println("ARDUINO SQL DATABASE");
  Serial.println("------------------------------------------------");
  Serial.print("IP Address  :");
  Serial.println(Ethernet.localIP());
  Serial.print("Subnet Mask :");
  Serial.println(Ethernet.subnetMask());
  Serial.print("Default Gateway IP: ");
  Serial.println(Ethernet.gatewayIP());
  Serial.print("DNS Server IP :");
  Serial.println(Ethernet.dnsServerIP());
}

void loop() {
  // If not already connected to server
  if (!connected) {
    // Connect to the server
    if (client.connect(server, 3306)) {
      Serial.println("-- CONNECTED --");
      connected = true;
    } else {
      // If it cannot connect to server display message
      Serial.println("-- CONNECTION FAIL --");
    }
  } else {
    // If connected to server run this code
    value = digitalRead(pirPin);  // Read pir motion sensor value
    if (value == HIGH && pirState == LOW) {
      Serial.println("Motion Detected");
      pirState = HIGH;

      // Make HTTP Request
      client.print("GET /arduino_test/add_data.php?");
      client.print("machine=");
      client.print("TRUMPF");
      client.print("&");
      client.print("start=");
      client.print("2017-04-10%2014:00:00.000");
      client.print("&");
      client.print("end=");
      client.print("2017-04-10%2014:00:30.000");
      client.print("&");
      client.print("length=");
      client.print("30");
      client.println(" HTTP/1.1");
      client.print("Host: ");
      client.println(server);
      client.println("Connection: close\r\n");
      client.stop();
      
    } else if (value == LOW && pirState == HIGH) {
      Serial.println("Motion Ended");
      pirState = LOW;
    }
    client.connect(server, 3306);
  }
  Ethernet.maintain();
  

}

