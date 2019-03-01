
#include <LiquidCrystal.h>
#include <RH_ASK.h>
#include <SPI.h>

RH_ASK driver;


const int rs = 12, en = 8, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.print("Temperature: ");

  if (!driver.init())
    Serial.println("init failed");
}

void loop() {
  uint8_t buf[16];
  uint8_t buflen = sizeof(buf);
  if (driver.recv(buf, &buflen)){
    int i;
    lcd.setCursor(0,1);
    lcd.print((char *)buf);
    //lcd.setCursor(8, 1);
    //lcd.print("    ");
  }
}
