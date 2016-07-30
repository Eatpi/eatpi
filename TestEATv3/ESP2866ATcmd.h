#include <Arduino.h>
#include <SoftwareSerial.h>
extern SoftwareSerial esp2866;
//extern String ip_data;

// EAT functions
extern void Displayresponse();
extern void Echo(String cmd);

//ESP functions
extern void  ESP_Reset();
extern void Echo(String cmd);
extern String GetLocalIP();
extern boolean ESP_MultiConStart();
extern boolean ESP_TcpUdpConnect(byte type, String addr, int port);
extern boolean ESP_SEND();
//extern boolean ESP_SendData(String data);
extern boolean ESP_SendData(int modeUDPTCP,String ip,int port, String data);

extern void ESP_TcpUdpClose(void);








