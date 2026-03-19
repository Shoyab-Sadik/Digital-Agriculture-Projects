#include<LiquidCrystal_I2C.h>
LiquidCrystal_I2C  lcd (0x27, 20, 4);
#include<DHT.h>
#define DHTPIN 2
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);
#define pump 3
#define buzz 4
#define soil A2
#define rain A3

void setup()
{
  pinMode(soil, INPUT);
  pinMode(rain, INPUT);
  pinMode(pump, OUTPUT);
  pinMode(buzz, OUTPUT);
  digitalWrite(buzz, LOW);
  dht.begin();
  Serial.begin(9600);
  delay(1000);
  Serial.println("Starting the programme-\nby- Shoyab Sadik\nCell:01575317604\nPico Robotics & MSS ElectroTech");
  lcd.begin();
  welcome();
  delay(3000);
  start();
  delay(3000);
}

void loop()
{
  lcd.begin();
  datas();
}

void welcome()
{
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Welcome to -");
  delay(600);
  lcd.setCursor(0,1);
  lcd.print("Digital Agriculture");
  delay(600);
  lcd.setCursor(0,2);
  lcd.print("by- Shoyab Sadik");
  delay(500);
  lcd.setCursor(0,3);
  lcd.print("(Pico Robotics)");
}

void start()
{
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Exploring");
  lcd.setCursor(1,1);
  lcd.print("Digital Agriculture");
  lcd.setCursor(3,3);
  lcd.print("with > Jihad");
}

void datas()
{
  int soil_read = analogRead(soil);
  int rain_read = analogRead(rain);
  Serial.println("Soil -");
  Serial.print(soil_read);
  Serial.println("Rain -");
  Serial.print(rain_read);
  int soil_value = map(soil_read, 1023, 0, 0, 100);
  int rain_value = map(rain_read, 1023, 0, 0, 100);

  float humi = dht.readHumidity();
  float temp = dht.readTemperature();

  if(soil_value > 5 && soil_value < 50)
  {
    digitalWrite(pump, HIGH); //pump on
    soil_buzzer();
  }
  else
  {
    digitalWrite(pump, LOW); //pump off
  }

  lcd.clear();
  lcd.setCursor(0,0); lcd.print("Rain Approx- "); lcd.print(rain_value); lcd.print("%");
  lcd.setCursor(0,1); lcd.print("Temperature- "); lcd.print(temp); lcd.print(char(223)); lcd.print("C");
  lcd.setCursor(0,2); lcd.print("Humidity - "); lcd.print(humi); lcd.print("%");
  lcd.setCursor(0,3); lcd.print("Soil Moisture- "); lcd.print(soil_value); lcd.print("%");

  if(rain_value > 60)
  {
    buzzer_sound();
  }
  else
  {
    digitalWrite(buzz, LOW);
  }
}

void buzzer_sound()
{
      digitalWrite(buzz, HIGH);
      delay(500);
      digitalWrite(buzz, LOW);
      delay(500);
      digitalWrite(buzz, HIGH);
      delay(500);
      digitalWrite(buzz, LOW);
      delay(500);
      digitalWrite(buzz, HIGH);
      delay(500);
      digitalWrite(buzz, LOW);
      delay(500);
      digitalWrite(buzz, HIGH);
      delay(500);
      digitalWrite(buzz, LOW);
}

void soil_buzzer()
{
      digitalWrite(buzz, HIGH);
      delay(100);
      digitalWrite(buzz, LOW);
      delay(100);
      digitalWrite(buzz, HIGH);
      delay(100);
      digitalWrite(buzz, LOW);
      delay(100);
      digitalWrite(buzz, HIGH);
      delay(100);
      digitalWrite(buzz, LOW);
}

/*void soil_wet()
{
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("The Soil is Wet!");
  lcd.setCursor(0,1);
  lcd.print("No need to Watering");
  lcd.setCursor(0,2);
  lcd.print("Pump is Off");
}

void soil_pump()
{
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("There is some-");
  lcd.setCursor(0,1);
  lcd.print("Moisture in Soil!");
  lcd.setCursor(0,2);
  lcd.print("You Can Water!");
  lcd.setCursor(0,3);
  lcd.print("Pump is Off");
}

void soil_dry()
{
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("The Soil is Dry!");
  lcd.setCursor(0,1);
  lcd.print("Watering by Pump");
  lcd.setCursor(0,2);
  lcd.print("Automatically!");
  lcd.setCursor(0,3);
  lcd.print("Pump is On!");
}*/