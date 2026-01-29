int droite_mt1 = 2;
int droite_mt2 = 3;

int gouche_mt1 = 4;
int gouche_mt2 = 5;

int IR_gouche_1 = 6;
int IR_aventeA_2 = 7;
int IR_aventeB_3 = 8;
int IR_gouche_4 = 9;
#define trig 10
#define echo 11
float distance=0;
long duree;
void config() {
    pinMode(droite_mt1, OUTPUT);
    pinMode(droite_mt2, OUTPUT);
    pinMode(gouche_mt1, OUTPUT);
    pinMode(gouche_mt2, OUTPUT);

    pinMode(IR_gouche_1, INPUT);
    pinMode(IR_aventeA_2, INPUT);
    pinMode(IR_aventeB_3, INPUT);
    pinMode(IR_gouche_4, INPUT);

    pinMode(trig,OUTPUT);
    pinMode(echo,INPUT);
}
void config_ultrason(){
    digitalWrite(trig,LOW);
    delayMicroseconds(3);
    digitalWrite(trig,HIGH);
    delayMicroseconds(10);
    digitalWrite(trig,LOW);
    duree=pulseIn(echo,HIGH);
    distance=duree*0.034/2;
    Serial.println(distance);
    delay(500);
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
    Serial.begin(9600);
    config();
}
void loop(){


    bool g_ir1 = digitalRead(IR_gouche_1 );
    bool A_ir2 = digitalRead(IR_aventeA_2);
    bool A_ir3 = digitalRead(IR_aventeB_3);
    bool d_ir4 = digitalRead(IR_gouche_4);
 if( g_ir1 && !A_ir2 && !A_ir3 && d_ir4){
        avance();
    }
 else if (g_ir1 && !A_ir2 && !A_ir3 && !d_ir4){
    tourne_droite();
    }
 else if (g_ir1 && A_ir2 && !A_ir3 && d_ir4){
    tourne_droite();
    }
    else if (g_ir1 && A_ir2 && A_ir3 && !d_ir4){
    tourne_droite();
    }

 else if (!g_ir1 && !A_ir2 && !A_ir3 && d_ir4){
    tourne_gauche();
    }
    else if (g_ir1 && !A_ir2 && A_ir3 && d_ir4){
    tourne_gauche();
 else if (!g_ir1 && A_ir2 && A_ir3 && d_ir4){
    tourne_gauche();
    }
 else if (g_ir1 && A_ir2 && A_ir3 && d_ir4){
    demi_toure_droite();
    }
}
