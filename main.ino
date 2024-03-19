
const int ldr1 = A2;
const int ldr2 = A1;
const int ldr3 = A0;
const int ldr4 = A3;
const int ldr5 = A4;

int ldrList[5] = {ldr1, ldr2, ldr3, ldr4, ldr5};

int resList[5];
void setup() {
  pinMode(ldr1, INPUT);
  pinMode(ldr2, INPUT);
  pinMode(ldr3, INPUT);
  pinMode(ldr4, INPUT);
  pinMode(ldr5, INPUT);
  Serial.begin(9600);
}

int checkOutlier(int total){
    for(int j = 0; j < sizeof(resList)/sizeof(resList[0]); j++){
        if(resList[j] - total > 100){
            Serial.println("passou por ldr: ");
            Serial.println(resList[j]);
            return resList[j];
          }
      }
      return -1;
  }

void loop() {
  int total = 0;
  for(int i = 0; i < sizeof(ldrList)/sizeof(ldrList[0]); i++){
        int temp = analogRead(ldrList[i]);
        resList[i] = temp;
        total += temp;
  }
  total /= 5;
  delay(3);
}
