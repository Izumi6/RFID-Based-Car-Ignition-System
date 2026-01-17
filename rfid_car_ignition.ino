#include <SPI.h>
#include <MFRC522.h>

// Pin definitions for RC522
#define RST_PIN 9
#define SS_PIN  10

// Relay pin (ignition control)
#define RELAY_PIN 4

// Create MFRC522 instance
MFRC522 mfrc522(SS_PIN, RST_PIN);

// Store authorized UID as hex string (without spaces)
String authorizedUID = "25bcefb0";   // <-- REPLACE with your card/tag UID

bool ignitionOn = false; // ignition state

String getUIDString(MFRC522::Uid *uid) {
  String uidString = "";
  for (byte i = 0; i < uid->size; i++) {
    if (uid->uidByte[i] < 0x10) uidString += "0";
    uidString += String(uid->uidByte[i], HEX);
  }
  uidString.toLowerCase();
  return uidString;
}

void setup() {
  Serial.begin(9600);
  while (!Serial);

  SPI.begin();
  mfrc522.PCD_Init();
  Serial.println("RFID-Based Car Ignition System");
  Serial.println("Scan your RFID tag...");

  pinMode(RELAY_PIN, OUTPUT);
  digitalWrite(RELAY_PIN, LOW);  // Ignition OFF
}

void loop() {
  if (!mfrc522.PICC_IsNewCardPresent()) return;
  if (!mfrc522.PICC_ReadCardSerial()) return;

  String readUID = getUIDString(&mfrc522.uid);
  Serial.print("Scanned UID: ");
  Serial.println(readUID);

  if (readUID == authorizedUID) {
    Serial.println("Authorized card.");

    ignitionOn = !ignitionOn;

    if (ignitionOn) {
      digitalWrite(RELAY_PIN, HIGH);   // turn ignition ON
      Serial.println("Ignition: ON");
    } else {
      digitalWrite(RELAY_PIN, LOW);    // turn ignition OFF
      Serial.println("Ignition: OFF");
    }
  } else {
    Serial.println("Unauthorized card. Ignition unchanged.");
  }

  mfrc522.PICC_HaltA();
  mfrc522.PCD_StopCrypto1();
}
