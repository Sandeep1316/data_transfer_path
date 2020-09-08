const int numledpins=10;
const int sourcenode=2;
const int destinationnode=3;
const int ledPins[numledpins]={2,3,4,5,6,7,8,9,10,11};
void setup(){
  Serial.begin(9600);
}
void loop(){
  int x=sourcenode;
  int y=destinationnode;
  if((1<=x && x<=4)&&(1<=y && y<=4)){
     datanodes1(x,y,0);
  }
  if((5<=x &&x <=8)&&(5<=y && y<=8)){
    datanodes2(x,y,5);
  }
  if((1<=x &&x <=4)&&(5<=y && y<=8)){
    datanodes3(x,y,0);
  }
  if((5<=x &&x <=8)&&(1<=y && y<=4)){
    datanodes4(x,y,5);
  }
}
void datanodes1(int x,int y,int z){
  int p,anode,cathode;
  anode=y-1;
  while(true){
    if(anode==y-1){
      p=x-1;
      ledglowr(z,p);
    }
    else{
      p=y-1;
      ledglow(z,p);
    }
    anode=p;
  }
}
void datanodes2(int x,int y,int z){
  int p,anode,cathode;
  anode=y;
  while(true){
    if(anode==y){
      p=x;
      ledglowr(z,p);
    }
    else{
      p=y;
      ledglow(z,p);
    }
    anode=p;
  }
}
void datanodes3(int x,int y,int z){
  int p,a,anode,cathode;
  a=z;
  anode=y;
  while(true){
    if(anode==y){
      p=x-1;
      ledglowr(z,p);
    }
    else{
      p=y;
      ledglow(z+5,p);
    }
    anode=p;
    if(anode==x-1){
      p=4;
      ledglow(a,p);
      p=9;
      ledglowr(a+5,p);
    }
  }
}
void datanodes4(int x,int y,int z){
  int p,a,anode,cathode;
  a=z;
  anode=y-1;
  while(true){
    if(anode==y-1){
      p=x;
      ledglowr(z,p);
    }
    else{
      p=y-1;
      ledglow(z-5,p);
    }
    anode=p;
    if(anode==x){
      p=9;
      ledglow(a,p);
      p=4;
      ledglowr(a-5,p);
    }
  }
}
void ledglow(int a,int anode){
  int cathode;
  for(int i=a;i<a+5;i++){
      if(i!=anode){
        cathode=i;
        pinMode(ledPins[anode], OUTPUT);
        digitalWrite(ledPins[anode], HIGH);
        pinMode(ledPins[cathode], OUTPUT);
        delay(400);
        Serial.print(" anode pin: ");
        Serial.print(ledPins[anode]);
        Serial.print(" cathode pin: ");
        Serial.println(ledPins[cathode]);
        digitalWrite(ledPins[anode], LOW);
        pinMode(ledPins[anode], INPUT);
        pinMode(ledPins[cathode], INPUT);
      }
    }
}
void ledglowr(int a,int anode){
  int cathode;
  for(int i=a+4;i>=a;i--){
      if(i!=anode){
        cathode=i;
        pinMode(ledPins[anode], OUTPUT);
        digitalWrite(ledPins[anode], HIGH);
        pinMode(ledPins[cathode], OUTPUT);
        delay(400);
        Serial.print(" anode pin: ");
        Serial.print(ledPins[anode]);
        Serial.print(" cathode pin: ");
        Serial.println(ledPins[cathode]);
        digitalWrite(ledPins[anode], LOW);
        pinMode(ledPins[anode], INPUT);
        pinMode(ledPins[cathode], INPUT);
      }
    }
}

