byte posA = 10, negA = 11, posB = 12, negB = 13;

int curr = 0;

byte seq[4][4] = {
  {HIGH, LOW, LOW, HIGH},
  {LOW, HIGH, LOW, HIGH},
  {LOW, HIGH, HIGH, LOW},
  {HIGH, LOW, HIGH, LOW}
};

void step(const byte idx) {
  digitalWrite(posA, seq[idx][0]);
  digitalWrite(negA, seq[idx][1]);
  digitalWrite(posB, seq[idx][2]);
  digitalWrite(negB, seq[idx][3]);
}

void open(byte cnt) {
  for (int j = 0; j < cnt; ++j) {
    step(curr++);
    delay(15);
    if (curr > 3)
      curr = 0;
  }
}

void close(byte cnt) {
  for (int j = 0; j < cnt; ++j) {
    step(curr--);
    delay(15);
    if (curr < 0)
      curr = 3; 
  }
}

void setup() {
  pinMode(posA, OUTPUT);
  pinMode(negA, OUTPUT);
  pinMode(posB, OUTPUT);
  pinMode(negB, OUTPUT);
}

int k = 0;
void loop() {
  if(k == 0) {
    // Write what you wanna do
    ++k;
  }
}
