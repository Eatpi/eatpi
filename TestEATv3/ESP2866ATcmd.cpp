
#include "ESP2866ATcmd.h"

boolean ESP_SEND()
{
    //ESP_IpConfig();
    //ESP_SendData(1, "192.168.1.223", 5000,"Hello Mum");
    ESP_SendData(1, "192.168.1.1", 5000,"Hello Mummy");
    ESP_TcpUdpClose();
}

boolean ESP_SendData(int modeUDPTCP,String ip,int port, String data)
{
    boolean result = false;
    result = ESP_MultiConStart();
   
    result = ESP_TcpUdpConnect(modeUDPTCP, ip, port);
    String cmd;
    cmd.concat("AT+CIPSEND=");
    cmd.concat(data.length());

    //try
    Echo("AT+CIPMODE=0");
    Displayresponse();
    //Echo(cmd);
     esp2866.flush();
     esp2866.println(cmd);
     delay(3000);
    //esp2866.println(cmd);
    Displayresponse();
  
    bool found;
    unsigned long start;
//    while (millis()-start<5000) 
//    {                            
//        if(esp2866.find(">")==true )
//        {
//      found = true;
//            break;
//        }
//    }
//    if(found)
       //esp2866.print(">");
        //esp2866.print(data);
        esp2866.println(data);
//    else
//    {
//      ESP_TcpUdpClose();
//      return false;
//    }
    String responsedata;
   responsedata="";
    start = millis();
    //while (millis()-start<5000) 
     while (millis()-start<15000) 
    {
       //Serial.println("==== Debug 1 ====");
       
       if(esp2866.available()>0)
        {
         
          //if(esp2866.find("+IPD")==true)
          //{
             Serial.println("==== Found received data ====");
             delay(1000);
             while(esp2866.available())
              {
              //Serial.println("==== Debug 2 ====");
              char a =esp2866.read();
              responsedata=responsedata+a;
              //Serial.println(responsedata);
              }
              Serial.println(responsedata);
          //}
        }
       // if (responsedata.indexOf("SEND OK")!=-1)
       // {
       //   Serial.println("==== Debug 3 ====");
      //      return true;
       // }
    }
    ESP_TcpUdpClose();
    return false;
  
  }


boolean ESP_MultiConStart(void)
{
    Echo("AT+CIPMUX=0");
   
    Displayresponse();     

}
//
//  
boolean ESP_TcpUdpConnect(byte type, String addr, int port)
{
  //esp2866.flush();

   //esp2866.print("AT+CIPSTART=");
    String cmd;
    cmd="AT+CIPSTART=";
  
    if(type>0)
    {
       // esp2866.print("\"TCP\"");
        cmd.concat("\"");
        cmd.concat("TCP");
        cmd.concat("\"");
        cmd.concat(","); 
     
        cmd.concat("\"");
        cmd.concat(addr);
        cmd.concat("\"");

        cmd.concat(",");   
        cmd.concat(port);
    
     
       
    }else
    {
        //esp2866.print("\"UDP\"");
        cmd.concat("\"");
        cmd.concat("UDP");
        cmd.concat("\"");
        cmd.concat(","); 
     
        cmd.concat("\"");
        cmd.concat(addr);
        cmd.concat("\"");
    
        cmd.concat(","); 
        cmd.concat(port);
        cmd.concat(","); 
        cmd.concat(11);
         cmd.concat(","); 
        cmd.concat(0);//transparent transmission
    }
    

    Echo(cmd);
    Displayresponse();
    delay(1000);

    Echo("AT+CIPSTATUS");
       Displayresponse();
    return true;
  }
void ESP_Reset()
  {
//    int loopi;
//    loopi=0;
//    do{
      
          //Serial.print(".");
//          if(esp2866.available())
//          {
            esp2866.println("AT+RST");
            unsigned long start;
            start = millis();
            while(millis() - start < 5000)
            {
                if(esp2866.find("OK") == true)
                {
                  Serial.println("Reset OK");
                    break;
                }
            }
//          }

              delay(100);
            
  Serial.println("======= Reset Complete =========");
  }

String GetLocalIP()
{
      Echo("AT+CIFSR");
      String ip_data;         
      do
      {
        unsigned long start;    
        start = millis();
        while (millis()-start<3000) 
          {
             Serial.println("Reading IP");
              while(esp2866.available()>0)
              {
                  char a =esp2866.read();
                  ip_data=ip_data+a;
                 // Serial.println(ip_data);
              }   
              if (ip_data.indexOf("AT+CIFSR")!=-1)
                  break;
          }
        if(ip_data.indexOf(".") != -1)
        {
          break; 
        }
        ip_data = "";
      }while(1);
    char head[4] = {0x0D,0x0A};   
    char tail[7] = {0x0D,0x0D,0x0A};        
    ip_data.replace("AT+CIFSR","");
    ip_data.replace(tail,"");
    ip_data.replace(head,"");  
    Serial.println("== == == == == ==");
    Serial.println(ip_data);
    ip_data.replace("+CIFSR:STAIP,","");
    ip_data.remove(ip_data.indexOf("+CIFSR:STAMAC"));
    Serial.println("== == == == == ==");
    Serial.print(ip_data);
    
    Serial.println();
 
    return ip_data;
  
  }
void Displayresponse()
  {
    Serial.println("==== Response ====");
    Serial.println("");
    while(esp2866.available()>0)
                  {
                    //delay(80);
                    //delay(40);
                    char c =esp2866.read();
                    delay(20);
                
                   Serial.write(c); 
                  }

    Serial.println("");
    Serial.println("==================");
  }
  void Echo(String cmd)
  {
                             
         Serial.println("Send Command");
        // Serial.println(cmd);
          
         esp2866.flush();
         esp2866.println(cmd);
         //delay(4000);
         delay(1000);
//         unsigned long start;
//         while(millis() - start < 5000)
//              {
//                  if(esp2866.find("OK") == true)
//                  {
//                    Serial.print("command executed");
//                      break;
//                  }
//              }
  }
  boolean Register()
  {
    //ESP_IpConfig();
    //ESP_SendData(1, "192.168.1.223", 5000,"Hello Mum");
    ESP_SendData(1, "192.168.1.1", 5000,"TV Adapter");
    ESP_TcpUdpClose();
  }
  //turn off TCP or UDP
void ESP_TcpUdpClose(void)
{
    esp2866.flush();
    esp2866.println("AT+CIPCLOSE");

    String data;
    unsigned long start;
    start = millis();
    while (millis()-start<3000) 
    {
        if(esp2866.available()>0)
        {
            char a =esp2866.read();
            data=data+a;
        }
        if (data.indexOf("Linked")!=-1 || data.indexOf("ERROR")!=-1 || data.indexOf("we must restart")!=-1)
            break;
    }
}
