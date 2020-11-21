#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include <ESP8266mDNS.h>
#ifndef STASSID

#define STASSID "SSID"
#define STAPSK "PASSWORD"

#endif
const char *ssid = STASSID;
const char *password = STAPSK;
ESP8266WebServer server(80);

#define pannello D1
#define V1 D2
#define V2 D5
#define G1 D6
#define G2 D7
#define R1 D8
#define linea D0

bool inSovraccarico = false, inVerde = false, statoLinea = false;
bool prima_volta = true; 
double voltaggio, corrente, potenza, soglia_potenza = 120;
long int ultima_lettura = 0;
float valori_grafico[100] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 2, 3, 4, 5, 6, 7, 8, 9, 0, 9, 8, 7, 6, 56, 4, 43, 2, 2, 4, 5, 7, 7};
int n_valori = 0;

void setup(void) {
  pinMode(pannello,INPUT);
    pinMode(D0, OUTPUT);
  pinMode(V1, OUTPUT);
  pinMode(V2, OUTPUT);
  pinMode(G1, OUTPUT);
  pinMode(G2, OUTPUT);
  pinMode(R1, OUTPUT);
  int p = 0;
  Serial.begin(115200);
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  Serial.println("");
statoTraliccio(6);
  // Wait for connection
  while (WiFi.status() != WL_CONNECTED || p > 10) {
    delay(500);
    Serial.print(".");
    p++;
  }
statoTraliccio(8);

  Serial.println("");

  Serial.print("indirizzo IP: ");
  Serial.println(WiFi.localIP());

  if (MDNS.begin("esp8266")) {
    Serial.println("MDNS responder started");
  }

  server.on("/", codice);
  server.on("/dati", paginaDati);
  server.on("/linea", paginaLinea);
  server.on("/paginaModal",paginaDatiConModal);

  server.begin();
  Serial.println("HTTP server started");
  aggiornaValori();

statoTraliccio(5);
}

void loop(void) {
  Serial.println(WiFi.localIP());
  digitalWrite(D0, statoLinea);
  Serial.println((float)corrente);

  if ( millis() - ultima_lettura > 20) {
    ultima_lettura = millis();
    aggiornaValori();
    if (n_valori >= 100) {
      for (int i = 0; i < 100; i++) {
        valori_grafico[i] = valori_grafico[i + 1];
      }
    }
    else {
      n_valori++;
    }
    valori_grafico[n_valori] = 80-(potenza/2);


  }
  statoTraliccio(potenza/25);
  server.handleClient();
  MDNS.update();

}
