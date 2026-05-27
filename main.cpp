#include <DHT.h>

#include <Wire.h>

#include <LiquidCrystal_I2C.h>
 
#define DHTPIN 2

#define DHTTYPE DHT22
 
#define LED_AQUECEDOR 8

#define LED_COOLER 9

#define LED_IRRIGACAO 10

#define LED_ALERTA 13
 
DHT dht(DHTPIN, DHTTYPE);

LiquidCrystal_I2C lcd(0x27, 16, 2);
 
unsigned long ultimoTempo = 0;

const unsigned long intervalo = 3000;
 
// Especificacoes ideais da alface

const float TEMP_MIN = 18.0;
const float TEMP_MAX = 24.0;
const float UMID_MIN = 50.0;
const float UMID_MAX = 70.0;
 
void setup() {

  Serial.begin(9600);
  dht.begin();
  lcd.init();
  lcd.backlight();
  pinMode(LED_AQUECEDOR, OUTPUT);
  pinMode(LED_COOLER, OUTPUT);
  pinMode(LED_IRRIGACAO, OUTPUT);
  pinMode(LED_ALERTA, OUTPUT);
  lcd.setCursor(0, 0);
  lcd.print("Estufa Marte");
  lcd.setCursor(0, 1);
  lcd.print("Alface Edge");
  delay(2000);
  lcd.clear();
}
 
void loop() {

  unsigned long tempoAtual = millis();
 
  if (tempoAtual - ultimoTempo >= intervalo) {
    ultimoTempo = tempoAtual;
    float temperatura = dht.readTemperature();
    float umidade = dht.readHumidity();
 
    if (isnan(temperatura) || isnan(umidade)) {

      Serial.println("Erro ao ler DHT22");
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Erro DHT22");
      lcd.setCursor(0, 1);
      lcd.print("Ver ligacao");
      digitalWrite(LED_AQUECEDOR, LOW);
      digitalWrite(LED_COOLER, LOW);
      digitalWrite(LED_IRRIGACAO, LOW);
      digitalWrite(LED_ALERTA, HIGH);
      return;

    }
 
    bool aquecer = false;
    bool resfriar = false;
    bool irrigar = false;
    bool alerta = false;
 
    if (temperatura < TEMP_MIN) {
      aquecer = true;
      alerta = true;
    } 

    else if (temperatura > TEMP_MAX) {
      resfriar = true;
      alerta = true;
    }
 
    if (umidade < UMID_MIN) {
      irrigar = true;
      alerta = true;
    } 

    else if (umidade > UMID_MAX) {
      alerta = true;
    }
 
    digitalWrite(LED_AQUECEDOR, aquecer ? HIGH : LOW);
    digitalWrite(LED_COOLER, resfriar ? HIGH : LOW);
    digitalWrite(LED_IRRIGACAO, irrigar ? HIGH : LOW);
    digitalWrite(LED_ALERTA, alerta ? HIGH : LOW);
    Serial.print("Temperatura: ");
    Serial.print(temperatura);
    Serial.print(" C | Umidade: ");
    Serial.print(umidade);
    Serial.print(" % | Status: ");
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("T:");
    lcd.print(temperatura, 1);
    lcd.print("C U:");
    lcd.print(umidade, 0);
    lcd.print("%");
    lcd.setCursor(0, 1);
 
    if (aquecer) {
      Serial.println("Aquecendo");
      lcd.print("Aquecendo");
    } 

    else if (resfriar) {
      Serial.println("Resfriando");
      lcd.print("Resfriando");
    }

    else if (irrigar) {
      Serial.println("Irrigando");
      lcd.print("Irrigando solo");
    } 

    else if (umidade > UMID_MAX) {
      Serial.println("Umidade alta");
      lcd.print("Umidade alta");
    } 

    else {
      Serial.println("Ambiente ideal");
      lcd.print("Ambiente ideal");
    }
  }
}
