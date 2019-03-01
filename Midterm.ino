
#include <LiquidCrystal.h>
#include <RH_ASK.h>
#include <SPI.h>

RH_ASK driver;


const int RS = 12, EN = 8, D4 = 5, D5 = 4, D6 = 3, D7 = 2;
LiquidCrystal lcd(RS, EN, D4, D5, D6, D7);

void setup() {
  Serial.begin(9600);
  lcd.begin(16, 2);
  lcd.print("Temperature: ");

  if (!driver.init())
    Serial.println("init failed");
}

void loop() {
  uint8_t buf[16];
  uint8_t buflen = sizeof(buf);
  if (driver.recv(buf, &buflen)){
    lcd.setCursor(0,1);
    lcd.print((char *)buf);
  }
}
