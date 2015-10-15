#include <SPI.h>
#include <Ethernet.h>
#include <PubSubClient.h>


// Update these with values suitable for your network.
byte mac[]    = {  0xDE, 0xED, 0xBA, 0xFE, 0xFE, 0xED };
byte server[] = { 192, 168, 0, 16 }; // IP Address of your MQTT Server
byte ip[]     = { 192, 168, 0, 120 }; // IP for this device


EthernetClient ethClient;
PubSubClient client(server, 1883, callback, ethClient);

void callback(char* topic, byte* payload, unsigned int length) {
Serial.println("Callback");
Serial.print("TopicSerial.println(topic)");
Serial.print("LengthSerial.println(length)");
Serial.print("PayloadSerial.write(payload,length)");
Serial.println();

  if (strcmp(topic,"/home/ard/p1/com")==0) { 
   if (payload[0] == '0') 
    {
    digitalWrite(22, LOW);
    client.publish("/home/ard/p1/state","0");
    } 
    else if (payload[0] == '1') 
    {
    digitalWrite(22, HIGH);
    client.publish("/home/ard/p1/state","1");
    }
   } 

  if (strcmp(topic,"/home/ard/p2/com")==0) { 
   if (payload[0] == '0') 
    {
    digitalWrite(24, LOW);
    client.publish("/home/ard/p2/state","0");
    } 
    else if (payload[0] == '1') 
    {
    digitalWrite(24, HIGH);
    client.publish("/home/ard/p2/state","1");
    }
   }
  if (strcmp(topic,"/home/ard/p3/com")==0) { 
   if (payload[0] == '0') 
    {
    digitalWrite(26, LOW);
    client.publish("/home/ard/p3/state","0");
    } 
    else if (payload[0] == '1') 
    {
    digitalWrite(26, HIGH);
    client.publish("/home/ard/p3/state","1");
    }
   }
  if (strcmp(topic,"/home/ard/p4/com")==0) { 
   if (payload[0] == '0') 
    {
    digitalWrite(28, LOW);
    client.publish("/home/ard/p4/state","0");
    } 
    else if (payload[0] == '1') 
    {
    digitalWrite(28, HIGH);
    client.publish("/home/ard/p4/state","1");
    }
   } 
  if (strcmp(topic,"/home/ard/p5/com")==0) { 
   if (payload[0] == '0') 
    {
    digitalWrite(30, LOW);
    client.publish("/home/ard/p5/state","0");
    } 
    else if (payload[0] == '1') 
    {
    digitalWrite(30, HIGH);
    client.publish("/home/ard/p5/state","1");
    }
   } 
  if (strcmp(topic,"/home/ard/p6/com")==0) { 
   if (payload[0] == '0') 
    {
    digitalWrite(32, LOW);
    client.publish("/home/ard/p6/state","0");
    } 
    else if (payload[0] == '1') 
    {
    digitalWrite(32, HIGH);
    client.publish("/home/ard/p6/state","1");
    }
   }
  if (strcmp(topic,"/home/ard/p7/com")==0) { 
   if (payload[0] == '0') 
    {
    digitalWrite(34, LOW);
    client.publish("/home/ard/p7/state","0");
    } 
    else if (payload[0] == '1') 
    {
    digitalWrite(34, HIGH);
    client.publish("/home/ard/p7/state","1");
    }
   }
  if (strcmp(topic,"/home/ard/p8/com")==0) { 
   if (payload[0] == '0') 
    {
    digitalWrite(36, LOW);
    client.publish("/home/ard/p8/state","0");
    } 
    else if (payload[0] == '1') 
    {
    digitalWrite(36, HIGH);
    client.publish("/home/ard/p8/state","1");
    }
   }
  if (strcmp(topic,"/home/ard/p9/com")==0) { 
   if (payload[0] == '0') 
    {
    digitalWrite(38, LOW);
    client.publish("/home/ard/p9/state","0");
    } 
    else if (payload[0] == '1') 
    {
    digitalWrite(38, HIGH);
    client.publish("/home/ard/p9/state","1");
    }
   }
    int pins = 0;
   switch (pins == HIGH) {
    case 23:
    digitalWrite(22, HIGH);
    client.publish("/home/ard/p1/state","1");
    break;
    case 25:
    digitalWrite(24, HIGH);
    client.publish("/home/ard/p2/state","1");
    break;
    case 27:
    digitalWrite(26, HIGH);
    client.publish("/home/ard/p3/state","1");
    break;
    case 29:
    digitalWrite(28, HIGH);
    client.publish("/home/ard/p4/state","1");
    break;
    case 31:
    digitalWrite(30, HIGH);
    client.publish("/home/ard/p5/state","1");
    break;
    case 33:
    digitalWrite(32, HIGH);
    client.publish("/home/ard/p6/state","1");
    break;
    case 35:
    digitalWrite(34, HIGH);
    client.publish("/home/ard/p7/state","1");
    break;
    case 37:
    digitalWrite(36, HIGH);
    client.publish("/home/ard/p8/state","1");
    break;
    case 39:
    digitalWrite(38, HIGH);
    client.publish("/home/ard/p9/state","1");
    break;
  }
}


void setup()
{
  Serial.begin(9600);
  Ethernet.begin(mac, ip);
    
  if (client.connect("arduinoClient", login, pass)) {
    client.publish("outTopic","hello world");
    client.subscribe("/home/ard/#");  // Subscribe to all messages for this device
  }
  pinMode(22, OUTPUT);
  pinMode(23, INPUT);
  digitalWrite(22, LOW);
  pinMode(24, OUTPUT);
  pinMode(25, INPUT);
  digitalWrite(24, LOW);
  pinMode(26, OUTPUT);
  pinMode(27, INPUT);
  digitalWrite(26, LOW);
  pinMode(28, OUTPUT);
  pinMode(29, INPUT);
  digitalWrite(28, LOW);
  pinMode(30, OUTPUT);
  pinMode(31, INPUT);
  digitalWrite(30, LOW);
  pinMode(32, OUTPUT);
  pinMode(33, INPUT);
  digitalWrite(32, LOW);
  pinMode(34, OUTPUT);
  pinMode(35, INPUT);
  digitalWrite(34, LOW);
  pinMode(36, OUTPUT);
  pinMode(37, INPUT);
  digitalWrite(36, LOW);
  pinMode(38, OUTPUT);
  pinMode(29, INPUT);
  digitalWrite(38, LOW);
}

void loop()
{
  client.loop();
}