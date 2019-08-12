#include <LiquidCrystal.h>
#define COLS 16 // Columnas del LCD
#define ROWS 2 
LiquidCrystal lcd(7, 8, 9, 10, 11, 12); 


int sensorHumedad = A0;
const int Rele = 2;


void setup() {

  pinMode(sensorHumedad, INPUT);
  pinMode(Rele, OUTPUT);
  lcd.begin(COLS, ROWS); // Activamos LCD
 
  Serial.begin(9600);
  
  
}

void loop() {
 
  int valorSensor = analogRead(sensorHumedad);
  int lecturaEnPorcentaje = map(valorSensor, 1023 , 0, 0, 100);
  
  
  
  Serial.print("PORCENTAJE DE HUMEDAD: ");
  Serial.print(lecturaEnPorcentaje);
  Serial.println("%");
  
  lcd.setCursor(0,0);
  lcd.print("Hum. Suelo: "+ String(lecturaEnPorcentaje)+"%");
  
  
  if(lecturaEnPorcentaje < 30 ){
     
     
      digitalWrite(2,LOW);
      Serial.print("El suelo está seco");
      

       lcd.setCursor(0,1);
       lcd.print("Est. suelo: Seco");
      
      }else if(lecturaEnPorcentaje >30 and lecturaEnPorcentaje<70 ){
            
        
        digitalWrite(2, HIGH);  
        Serial.print("El suelo se encuentra humeda");
        
        lcd.setCursor(0,1);
        
        lcd.print("Est. suelo: Hum");
          
                       
        }else if(lecturaEnPorcentaje > 70 ){
          
          digitalWrite(2, HIGH);
          Serial.print("El suelo se encunetra mojado");
          

          lcd.setCursor(0,1);
          
          lcd.print("Est. suelo: Moj");
              
      }
  
    delay(2000);
   
}
