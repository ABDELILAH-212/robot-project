int droite_mt1 = 2;
int droite_mt2 = 4;

int gouche_mt1 = 7;
int gouche_mt2 = 8;

int IR_droite_1 = 9;
int IR_droite_2 = 10;
int IR_gouche_1 = 11;
int IR_gouche_2 = 12;

void config() {
    pinMode(droite_mt1, OUTPUT);
    pinMode(droite_mt2, OUTPUT);
    pinMode(gouche_mt1, OUTPUT);
    pinMode(gouche_mt2, OUTPUT);

    pinMode(IR_droite_1, INPUT);
    pinMode(IR_droite_2, INPUT);
    pinMode(IR_gouche_1, INPUT);
    pinMode(IR_gouche_2, INPUT);
}

void avance() {
    digitalWrite(droite_mt1, HIGH);
    digitalWrite(droite_mt2, LOW);
    digitalWrite(gouche_mt1, HIGH);
    digitalWrite(gouche_mt2, LOW);
}

void tourne_droite() {
    digitalWrite(droite_mt1, LOW);
    digitalWrite(droite_mt2, LOW);
    digitalWrite(gouche_mt1, HIGH);
    digitalWrite(gouche_mt2, LOW);
}
void demi_toure_droite() {
    digitalWrite(droite_mt1, LOW);
    digitalWrite(droite_mt2, HIGH);
    digitalWrite(gouche_mt1, HIGH);
    digitalWrite(gouche_mt2, LOW);
}
void demi_toure_gauche() {
    digitalWrite(droite_mt1, HIGH);
    digitalWrite(droite_mt2, LOW);
    digitalWrite(gouche_mt1, LOW);
    digitalWrite(gouche_mt2, HIGH);
}

void tourne_gauche() {
    digitalWrite(droite_mt1, HIGH);
    digitalWrite(droite_mt2, LOW);
    digitalWrite(gouche_mt1, LOW);
    digitalWrite(gouche_mt2, LOW);
}

void stop_robot() {
    digitalWrite(droite_mt1, LOW);
    digitalWrite(droite_mt2, LOW);
    digitalWrite(gouche_mt1, LOW);
    digitalWrite(gouche_mt2, LOW);
}

void setup() {
    config();
}

void loop() {
    bool d_ir1 = digitalRead(IR_droite_1);
    bool d_ir2 = digitalRead(IR_droite_2);
    bool g_ir1 = digitalRead(IR_gouche_1);
    bool g_ir2 = digitalRead(IR_gouche_2);

    if (!d_ir1 && !d_ir2 && !g_ir1 && !g_ir2) {
        avance();
    }
    else if (!d_ir1 && !d_ir2 && g_ir1 && g_ir2) {
        tourne_droite();
    }
    else if (d_ir1 && d_ir2 && !g_ir1 && !g_ir2) {
        tourne_gauche();
    }
    else if (d_ir1 && d_ir2 && g_ir1 && g_ir2) {
        demi_toure_droite();
        delay(700);
    }
}



commit message
