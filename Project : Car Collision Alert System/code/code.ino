#include <Wire.h>
#include <SoftwareSerial.h>

#define TRIG_PIN 9
#define ECHO_PIN 10
#define GREEN_GOOD 13
#define RED_FAIL 2
#define RED_LED 3
#define ORANGE_LED 4
#define WHITE_LED 5
#define BUZZER 6
#define SWITCH_PIN 7

const int MPU_ADDR = 0x68;
int16_t ax, ay, az;
float prevAcceleration = 0;
const float impactThreshold = 2.5;

SoftwareSerial BT(11,12);

void setup() {
    Serial.begin(9600);
    BT.begin(9600);
    
    pinMode(TRIG_PIN, OUTPUT);
    pinMode(ECHO_PIN, INPUT);
    pinMode(GREEN_GOOD, OUTPUT);
    pinMode(RED_FAIL, OUTPUT);
    pinMode(RED_LED, OUTPUT);
    pinMode(ORANGE_LED, OUTPUT);
    pinMode(WHITE_LED, OUTPUT);
    pinMode(BUZZER, OUTPUT);
    pinMode(SWITCH_PIN, INPUT);

    Wire.begin();
    Wire.setClock(400000);
    Wire.beginTransmission(MPU_ADDR);
    Wire.write(0x6B);
    Wire.write(0);
    Wire.endTransmission(true);

    Serial.println("MPU6050 initialized!");
    digitalWrite(GREEN_GOOD, HIGH);
}

long getDistance() {
    digitalWrite(TRIG_PIN, LOW);
    delayMicroseconds(2);
    digitalWrite(TRIG_PIN, HIGH);
    delayMicroseconds(10);
    digitalWrite(TRIG_PIN, LOW);
    long duration = pulseIn(ECHO_PIN, HIGH);
    return duration * 0.034 / 2;
}

void controlLEDs(long distance) {
    if(distance < 15) {
        digitalWrite(RED_LED, HIGH);
        digitalWrite(ORANGE_LED, LOW);
        digitalWrite(WHITE_LED, LOW);
    }
    else if(distance >= 15 && distance < 25) {
        digitalWrite(RED_LED, LOW);
        digitalWrite(ORANGE_LED, HIGH);
        digitalWrite(WHITE_LED, LOW);
    }
    else if(distance <= 35) {
        digitalWrite(RED_LED, LOW);
        digitalWrite(ORANGE_LED, LOW);
        digitalWrite(WHITE_LED, HIGH);
    }
    else{
        digitalWrite(RED_LED, LOW);
        digitalWrite(ORANGE_LED, LOW);
        digitalWrite(WHITE_LED, LOW);
    }
}

void controlBuzzer(long distance) {
    if (distance < 25) {
        int delayTime = map(distance, 0, 30, 50, 1000); // Faster beeps as object gets closer
        tone(BUZZER, 1000);
        delay(delayTime);
        noTone(BUZZER);
        delay(delayTime);
    } else {
        noTone(BUZZER);
    }
}

void checkCrash() {
    Wire.beginTransmission(MPU_ADDR);
    Wire.write(0x3B);
    Wire.endTransmission(false);
    Wire.requestFrom(MPU_ADDR, 6, true);

    ax = Wire.read() << 8 | Wire.read();
    ay = Wire.read() << 8 | Wire.read();
    az = Wire.read() << 8 | Wire.read();

    float ax_g = ax / 16384.0;
    float ay_g = ay / 16384.0;
    float az_g = az / 16384.0;
    float acceleration = sqrt(ax_g * ax_g + ay_g * ay_g + az_g * az_g);
    float impactForce = abs(acceleration - prevAcceleration);

    Serial.print("Impact Force: ");
    Serial.println(impactForce);

    if (impactForce > impactThreshold) {
        digitalWrite(GREEN_GOOD, LOW);
        digitalWrite(RED_FAIL, HIGH);
        digitalWrite(RED_LED, LOW);
        digitalWrite(ORANGE_LED, LOW);
        digitalWrite(WHITE_LED, LOW);
        BT.println("Code00X: Release Air Bag");
        Serial.println("🚗💥 Crash Detected! System Disabled.");
        
        while (true) {
            digitalWrite(RED_FAIL, HIGH);
            digitalWrite(GREEN_GOOD, LOW);
            tone(BUZZER, 1000);
        }
    }
    prevAcceleration = acceleration;
}

void loop() {
    checkCrash();

    long distance = getDistance();
    int mode = digitalRead(SWITCH_PIN);
    controlLEDs(distance);
    
    if (mode == 1) {
        controlBuzzer(distance);
    } else {
        noTone(BUZZER);
    }
    
    delay(100);
}
