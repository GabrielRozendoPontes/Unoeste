//#include <ESP8266WiFi.h> //Caso utilizar o ESP8266
#include <WiFi.h> //ESP32
#include <WiFiClientSecure.h> 
//#include <ESP8266HTTPClient.h> //Caso utilizar o ESP8266
#include <HTTPClient.h> //ESP32
//#include <ArduinoJson.h> //Caso retornar JSON
#include <Wire.h>


const char* ssid = "WIFI_AAPM_CFP914"; //nome da rede wifi
const char* password =""; //senha da red e wifi
const char* url_api = "https://niloweb.com.br/transit-room/api/point_consulta.php"; //url endpoint Nilo irá disponibilizar

//url da API e qual o nome do enpoint que foi criado na API
//qual o tipo de retorno do endpoint? 
//Nos precsamos que retorne esses caracteres: VD, VM, AM

//http://url-da-api/endpoint

//declar os tres pinos
const int VD = 22;
const int VM = 19;
const int AM = 18;
const int BZ = 5;

void setup() {
  WiFi.begin(ssid, password);
  Serial.begin(9600);
  Serial.println("Serial OK");
  delay(10);

  pinMode(VD, OUTPUT);
  pinMode(VM, OUTPUT);
  pinMode(AM, OUTPUT);
  pinMode(BZ, OUTPUT);
  Serial.println("PINOS INICIALIZADOS");
  digitalWrite(VD, HIGH);
  delay(2000);
  digitalWrite(VD, LOW);
  delay(2000);

  //inicializar como saida os tres pinos

  while (WiFi.status() != WL_CONNECTED) {  
   digitalWrite(VM, HIGH);
   delay(500);
   digitalWrite(VM, LOW);
   delay(500);
   digitalWrite(AM, HIGH);
   delay(500);
   digitalWrite(AM, LOW);
   delay(500);
   digitalWrite(VD, HIGH);
   delay(500);
   digitalWrite(VD, LOW);
   delay(500);
    Serial.println("Tentando Conexao!");
    delay(2000);
    Serial.println(WiFi.status());
  }
  Serial.println("Dispositivo Conectado!");
}

void loop() {
  if (WiFi.status() == WL_CONNECTED) {
    Serial.println("CONECTADO");
    HTTPClient http;
    http.begin(url_api);   
    Serial.println("HTTPCLIENT = OK"); 
    int httpCode = http.GET();   
    Serial.println(httpCode);
    if (httpCode > 0) { 
      Serial.println("ENTROU HTTPCODE");

      
      String semaforo = http.getString();
      Serial.println(semaforo);
      semaforo.remove(0, 9);
      semaforo.remove(1, 3);
      Serial.println(semaforo);

      if (semaforo == "L"){
        digitalWrite(AM, LOW);
        digitalWrite(VD, HIGH);
        digitalWrite(VM, LOW);
        
      } else if (semaforo == "A"){
        digitalWrite(AM, HIGH);
        digitalWrite(VD, LOW);
        digitalWrite(VM, LOW);
        //ligar o pino amarelo
        //apagar outros
      } else if (semaforo == "B"){
        digitalWrite(AM, LOW);
        digitalWrite(VD, LOW);
        digitalWrite(VM, HIGH);
        //ligar o pino vermelho
        //apagar outros
      }
      else if (semaforo == "N"){
        digitalWrite(AM, LOW);
        digitalWrite(VD, HIGH);
        digitalWrite(VM, LOW);
        //ligar o pino verde
        //apagar outros
      }
    }   
  }
  delay(20000); // esta espera é pra não ficar a todo momento requisitando no servidor/endpoint
}

