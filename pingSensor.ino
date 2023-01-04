int duration; 

const int pingPin = 8; //pingPin yang digunakan di arduino

int EN1 = 5; //pin 5 dan 6 untuk kecepatan roda
int EN2 = 6;
int IN1 = 4; // pin 4 dan 7 untuk mengubah rotasi roda atau motor, HIGH untuk maju dan LOW untuk mundur
int IN2 = 7;

void setup() {
  // inisialisasi pin yang akan digunakan
  pinMode(EN1, OUTPUT);
  pinMode(EN2, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
}

void forward() {
  // function untuk roda bergerak maju
  analogWrite(EN1, 250); //EN1 dan EN2 dibuat kecepatan 250
  analogWrite(EN2, 250);
  digitalWrite(IN1, HIGH); //IN1 dan IN2 dibuat HIGH untuk maju
  digitalWrite(IN2, HIGH);
}


void backward() {
  // function untuk roda bergerak mundur
  analogWrite(EN1, 250); //EN1 dan EN2 dibuat kecepatan 250
  analogWrite(EN2, 250);
  digitalWrite(IN1, LOW); //IN1 dan IN2 dibuat HIGH untuk mundur
  digitalWrite(IN2, LOW);
}

void loop() {
  long cm; // inisialisasi variabel cm sebagai jarak

  pinMode(pingPin, OUTPUT); //melempar sinyal sensor
  digitalWrite(pingPin, LOW);
  delayMicroseconds(2);
  digitalWrite(pingPin, HIGH);
  delayMicroseconds(5);
  digitalWrite(pingPin, LOW);

  pinMode(pingPin, INPUT); //menangkap kembali sinyal sensor yang telah dilempar
  duration = pulseIn(pingPin, HIGH);

  cm = microsecondsToCentimeters(duration); //mengubah microsecond menjadi centimeter dengan rumus bawaan.

  if (cm >= 10) { //kondisi dimana jika jarak yang terdeteksi lebih dari 10 cm, maka akan maju
    //forward();
  } else { //jika jarak kurang dari 10 maka akan mundur
    //backward();
  }
}

long microsecondsToCentimeters(long microseconds) { //function untuk mengubah microseconds menjadi centimeters dengan rumus yang telah ditentukan
  return microseconds / 29 / 2;
}
