#include <LiquidCrystal.h>

// Ultrasonic Sensor Pins
int trig = 3;
int echo = 2;
long duration;
float dist_cm, dist_in;

// Initialize LCD with interface pins
LiquidCrystal lcd(7, 8, 9, 10, 11, 12);

void setup() {
  // Initialize LCD
  lcd.begin(16, 2);
  
  // Initialize Ultrasonic Sensor
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  
  // Initialize Serial Monitor
  Serial.begin(9600);

  // Display a welcome message
  lcd.print("Hello, World!");
  delay(2000); // Show message for 2 seconds
  lcd.clear();
}

void loop() {
  // Trigger the Ultrasonic Sensor
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
  
  // Read the Echo pin
  duration = pulseIn(echo, HIGH);

  // Calculate distance in cm and inches
  dist_cm = duration * 0.0343 / 2.0;
  dist_in = duration * 0.0135 / 2.0;
  
  // Display on Serial Monitor
  Serial.print("Distance: ");
  Serial.print(dist_cm);
  Serial.print(" cm / ");
  Serial.print(dist_in);
  Serial.println(" in");

  // Display on LCD
  lcd.clear();  // Clear the display before updating
  lcd.setCursor(0, 0);
  lcd.print("Distance:");
  lcd.setCursor(0, 1);
  lcd.print(dist_cm);
  lcd.print(" cm / ");
  lcd.print(dist_in);
  lcd.print(" in");

  delay(500);  // Wait before next measurement
}
