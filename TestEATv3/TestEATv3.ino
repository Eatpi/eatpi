#include "ESP2866ATcmd.h"

SoftwareSerial esp2866(2,3);
 String jap;
 boolean doneit = false;
 String current_ip;
 
void setup() {
  // put your setup code here, to run once:

  Serial.begin(4800);
  esp2866.begin(4800);
  
  esp2866.println("ATE");

  
  delay(1000);
 
}

 
void loop() {
  
  if (doneit == false)
  {
     Serial.println("Reset the module");
     ESP_Reset(); 
     Displayresponse();
     
     doneit = true;
     Serial.println("");
      delay(2000);
      Echo("AT+CWMODE=3");
      Displayresponse();
      
      //delay(2000);
      //Echo("AT+CWLAP");
      //delay(8000); 
      //Displayresponse();
//
      delay(2000);
      String jap;
      jap="AT+CWJAP_CUR=";      
      jap.concat("\"");      jap.concat("EAT_PI");      jap.concat("\"");      jap.concat(",");   jap.concat("\""); jap.concat("withcustard");
      jap.concat("\"");
     
      Echo(jap);
      Displayresponse();
      
      Echo("AT+CIFSR");
      Displayresponse();
     
      //Echo("AT+CIFSR");
      //Displayresponse();
    
      current_ip = GetLocalIP();
      ////////////////////////////
      //Echo("AT+PING=\"192.168.1.1\"");
      //Displayresponse();
     
      ////////////////////////////
      ESP_SEND();
      Displayresponse();
    }
  // put your main code here, to run repeatedly:
            if(esp2866.available()>0)
              {
                Serial.println("ESP available");
                Serial.println(".............");
                delay(50);
                while(esp2866.available())
                  {
                    delay(10);
                    char c =esp2866.read();
                   // Serial.print(c);
                   Serial.write(c); 
                  }
              }
            if(Serial.available())
            {
              delay(1000);
              String command="";
              while(Serial.available())
              {
                
                  command+= (char)Serial.read();
                 
              }
              esp2866.flush();
              esp2866.println(command);
             
            }


//SetupAP
//AT+CWMODE=3

//Diagnostic
//Firmware version AT+GMR 
//List Access Points AT+CWLAP
//Get IP Address AT+CIFSR
//WiFi Mode AT+CWMODE?
//TCP/UDP Connections AT+ CIPMUX?
//Check IP address AT+CIFSR 
//Baud Rate* AT+CIOBAUD? Supported: 9600, 19200, ....not yet supported
//Join Access Point AT+CWJAP_CUR="EAT_PI", "withcustard"
//Leave Access Point  AT+CWQAP





}





