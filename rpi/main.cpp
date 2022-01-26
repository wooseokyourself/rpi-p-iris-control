#include <iostream>
#include <wiringPi.h>

using namespace std;

int posA = 5, negA = 6, posB = 13, negB = 19;
int curr = 0;

int seq[4][4] = {
  {HIGH, LOW, LOW, HIGH},
  {LOW, HIGH, LOW, HIGH},
  {LOW, HIGH, HIGH, LOW},
  {HIGH, LOW, HIGH, LOW}
};

void step(const int idx) {
  digitalWrite(posA, seq[idx][0]);
  digitalWrite(negA, seq[idx][1]);
  digitalWrite(posB, seq[idx][2]);
  digitalWrite(negB, seq[idx][3]);
}

void open(const int cnt) {
  for (int j = 0; j < cnt; ++j) {
    step(curr++);
    delay(15);
    if (curr > 3)
      curr = 0;
  }
}

void close(const int cnt) {
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

int c;
bool loop() {
  cout << "1: open" << endl;
  cout << "2: close" << endl;
  cout << ":"; cin >> c;
  if (c == 1)
    open(1);
  else if (c == 2)
    close(1);
  else
    return false;
  return true;
}

int main (void) {
  if (wiringPiSetupGpio() == -1)
    cerr << "unable to start wiringPi" << endl
  setup();
  bool lp = true;
  while (lp)
    lp = loop();
  return 0;
}