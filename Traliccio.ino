#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include <ESP8266mDNS.h>
#ifndef STASSID
//#define STASSID "federico-Inspiron-5567-nuovo"
//#define STAPSK  "password"
#define STASSID "FBI-van"
#define STAPSK "ajejejeje"
#endif
const char *ssid = STASSID;
const char *password = STAPSK;
ESP8266WebServer server(80);

#define pala 1
bool inSovraccarico = false, prima_volta = true, inVerde = false;
double voltaggio, corrente, potenza, soglia_potenza=60;
long int ultima_lettura = 0;
float valori_grafico[100]={1,2,3,4,5,6,7,8,9,10,9,8,7,6,5,4,3,2,1,2,3,4,5,6,7,8,9,0,9,8,7,6,56,4,43,2,2,4,5,7,7};
int n_valori =0;

void setup(void) {

  Serial.begin(115200);
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  Serial.println("");

  // Wait for connection
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");

  Serial.print("indirizzo IP: ");
  Serial.println(WiFi.localIP());

  if (MDNS.begin("esp8266")) {
    Serial.println("MDNS responder started");
  }

  server.on("/", codice);
  server.on("/dati", paginaDati);

  server.begin();
  Serial.println("HTTP server started");
  aggiornaValori();
}

void loop(void) {

  
  if ( millis() - ultima_lettura > 10) {
    ultima_lettura=millis();
    if (n_valori >= 100){
      for(int i=0;i<100;i++){
        valori_grafico[i]=valori_grafico[i+1];
      }
    }
    else{
      n_valori++;
    }
        valori_grafico[n_valori] = potenza;


  }

  server.handleClient();
  MDNS.update();
}
