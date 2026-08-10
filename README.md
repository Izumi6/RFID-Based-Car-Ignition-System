<div align="center">

# 🔐 RFID-Based Car Ignition System

[![C++](https://img.shields.io/badge/C++-Arduino-00599C?style=flat-square&logo=cplusplus&logoColor=white)](https://www.arduino.cc/)
[![Arduino](https://img.shields.io/badge/Arduino-Embedded-00979D?style=flat-square&logo=arduino&logoColor=white)](https://www.arduino.cc/)
[![License](https://img.shields.io/badge/License-MIT-green?style=flat-square)](LICENSE)

*NFC/RFID-based smart vehicle ignition system with encrypted UID authentication — preventing unauthorized vehicle starts.*

</div>

---

## 📋 Overview

A hardware+software security system that replaces traditional car keys with **RFID/NFC card authentication**. Built with Arduino and the MFRC522 RFID reader, the system reads the unique identifier (UID) from an RFID card/tag and only activates the ignition relay when an authorized card is presented.

## 🏗️ System Architecture

```
RFID Card/Tag (NFC)
    ↓  [tap]
MFRC522 Reader Module
    ↓  [SPI bus]
Arduino Microcontroller
    ↓  [UID comparison]
Is Authorized? ──→ YES → Relay ON → Ignition Activated ✅
                └→ NO  → Relay OFF → Access Denied ❌
```

## 🔧 Hardware Components

| Component | Purpose |
|-----------|---------|
| **Arduino Uno/Nano** | Main controller |
| **MFRC522 RFID Module** | Reads RFID/NFC card UIDs |
| **5V Relay Module** | Controls ignition circuit |
| **RFID Card/Tag** | Authentication token |
| **LED + Buzzer** (optional) | Visual/audio feedback |

## ⚡ Pin Configuration

| MFRC522 Pin | Arduino Pin |
|-------------|-------------|
| RST | Pin 9 |
| SDA (SS) | Pin 10 |
| MOSI | Pin 11 |
| MISO | Pin 12 |
| SCK | Pin 13 |
| Relay | Pin 4 |

## ✨ Features

- 🔒 **UID-Based Authentication** — Only authorized cards activate the ignition
- 🔄 **Toggle Mechanism** — Tap to start, tap again to stop
- 📟 **Serial Monitoring** — Real-time status logs via Serial Monitor
- 🛡️ **Anti-Theft Protection** — Prevents unauthorized vehicle start
- ⚡ **Low Latency** — Sub-second card read and verification

## 🚀 Setup

```bash
git clone https://github.com/Izumi6/RFID-Based-Car-Ignition-System.git
```

1. Open `rfid_car_ignition.ino` in Arduino IDE
2. Install **MFRC522** library (`Sketch → Include Library → Manage Libraries`)
3. Replace `authorizedUID` with your card's UID
4. Upload to Arduino and test

## 📁 Files

| File | Description |
|------|-------------|
| `rfid_car_ignition.ino` | Main ignition control system |
| `read_rfid_uid.ino` | Utility to read and display card UIDs |

## 👤 Author

**Suyash Vakhariya** — [suyashvakhariya.com](https://suyashvakhariya.com) · [LinkedIn](https://www.linkedin.com/in/suyashvakhariya) · [GitHub](https://github.com/Izumi6)
