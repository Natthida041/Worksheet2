#include <Adafruit_Sensor.h>
#include <DHT.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// กำหนดค่าตัวแปรสำหรับเซ็นเซอร์ DHT
float temperature;
float humidity;
DHT dht(D4, DHT11);

// กำหนดค่าตัวแปรสำหรับหน้าจอ LCD
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  // เริ่มต้นการทำงานของ Serial
  Serial.begin(9600);
  
  // เริ่มต้นการทำงานของเซ็นเซอร์ DHT
  dht.begin();
  
  // เริ่มต้นการทำงานของหน้าจอ LCD
  lcd.begin();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Tempe:       C");
  lcd.setCursor(0, 1);
  lcd.print("Humi:        %");
}

void loop() {
  // อ่านค่าอุณหภูมิและความชื้นจากเซ็นเซอร์ DHT
  humidity = dht.readHumidity();
  temperature = dht.readTemperature();

  // แสดงผลลัพธ์บน Serial Monitor
  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.print(" C  Humidity: ");
  Serial.print(humidity);
  Serial.println(" %");

  // แสดงผลลัพธ์บนหน้าจอ LCD
  lcd.setCursor(6, 0);
  lcd.print(temperature);
  lcd.setCursor(6, 1);
  lcd.print(humidity);

  // หน่วงเวลา 1 วินาที
  delay(1000); 
}
