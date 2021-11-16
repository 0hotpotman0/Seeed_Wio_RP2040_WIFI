#include <seeed_rp2040_wifi.h>
WiFiClient socket_network;

void setup()
{
    Serial.begin(115200);
    delay(2000);
    Serial.println("******start*******");
    while(false == WiFi.begin("WIFI_SSID", "WIFI_PASSWORD"))
    {
       Serial.println("connect wifi fail ,try again");
       delay(5000);
    }
    Serial.println("success connect wifi");

     while(false == socket_network.connect("192.168.3.32",1080))//Set the server address and port of the socket.
    {
       Serial.println("connect socket server fail");
       delay(2000);
    }
    Serial.println("success connect socket server");
    

    socket_network.write("Hello,Wio",9);//Socket release message. (Message,  length)
}
 
void loop()
{

if(socket_network.available()){//Receiving Socket message.
  Serial.println((char)socket_network.read());
  delay(1000);
}
}