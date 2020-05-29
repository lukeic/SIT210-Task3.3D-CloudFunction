const int LED = D7;

void flashLed(int delayFor) {
    digitalWrite(LED, HIGH);
    delay(delayFor);
    digitalWrite(LED, LOW);
    delay(delayFor);
}

void handleWave(const char *event, const char *data) {
    if (strcmp(data, "wave") == 0) {
        flashLed(250);
        flashLed(250);
        flashLed(250); 
    } else if(strcmp(data, "pat") == 0) {
        flashLed(50);
        flashLed(50);
        flashLed(50);
        flashLed(50);
    }
}

void setup() {
    Particle.subscribe("Deakin_RIOT_SIT210_Photon_Buddy", handleWave);
    pinMode(LED, OUTPUT);
    digitalWrite(LED, LOW);
}

void loop() {
}
