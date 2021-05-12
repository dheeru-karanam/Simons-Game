const int ledpin1=6, ledpin2=7, ledpin3=8, ledpin4=9;
const int button1=2, button2=3, button3=4, button4=5;
const int start = 13;
const int buzzer = 10;
int check[100];
int userIO[100];
int a[100],i=0,count=2,val1=1,val2=1,flag =0 ;
void setup() {
  // put your setup code here, to run once:
  pinMode(start, INPUT);
  pinMode(ledpin1,OUTPUT); //Initialising Pins A0 and A1 of Arduino as OUTPUT ports
  pinMode(ledpin2,OUTPUT);
  pinMode(ledpin3,OUTPUT); //Initialising Pins A0 and A1 of Arduino as OUTPUT ports
  pinMode(ledpin4,OUTPUT);
  pinMode(button1, INPUT); //Initialising Pins 3 and 4 of Arduino as INPUT ports
  pinMode(button2, INPUT);
  pinMode(button3, INPUT); //Initialising Pins 3 and 4 of Arduino as INPUT ports
  pinMode(button4, INPUT);
  Serial.begin(9600); //Setting BaudRate to 9600
}

void loop() {
  if(count==2){
    count = 2;
    SequenceGenerate();
    SequenceDisplay();
    ReadSequence();
  }
  if(count !=1){
    SequenceDisplay();
    ReadSequence();
  }
}


void SequenceGenerate(){
  randomSeed(millis());
  Serial.println("Entered generate_seq loop");
  for(int i=0;i<100;i++){
    check[i] = random(0,4);    //Generate an array "check" with size of 100 filled with random sequence of numbers 0 and 1
    }
}

void SequenceDisplay(){
  digitalWrite(ledpin2,LOW);
  digitalWrite(ledpin1,LOW);
  digitalWrite(ledpin3,LOW);
  digitalWrite(ledpin4,LOW);
  delay(250);
  for(int i=0;i<count;i++){
    if(check[i]==0){
      digitalWrite(ledpin1, HIGH);
        tone(buzzer, 240 ,250);
        delay(500);
        digitalWrite(ledpin1, LOW);
        delay(500);
    }
    if(check[i]==1){
      digitalWrite(ledpin2, HIGH);
        tone(buzzer, 270 ,250);
        delay(500);
      digitalWrite(ledpin2, LOW);
      delay(500);
    }
    if(check[i]==2){
      digitalWrite(ledpin3, HIGH);
        tone(buzzer, 300 ,250);
        delay(500);
      digitalWrite(ledpin3, LOW);
      delay(500);
    }
    if(check[i]==3){
      digitalWrite(ledpin4, HIGH);
        tone(buzzer, 320 ,250);
        delay(500);
      digitalWrite(ledpin4, LOW);
      delay(500);
    }
  }
}

void ReadSequence(){
  digitalWrite(ledpin1,LOW);
  digitalWrite(ledpin2,LOW);
  int flag =0;
  for(int i=0;i<count;i++){
    flag = 0;
    while(flag==0){
      if(digitalRead(button1)==HIGH){ //If button1 is pressed userIO array is filled with 0 else if button2 is pressed array is filled with 1
        tone(buzzer, 240 ,250);
        userIO[i]=0;
        digitalWrite(ledpin1, HIGH);
        delay(1000);
        flag = 1;
        if(userIO[i]!=check[i]){ //checks if sequence given by user matches with the sequence generated. If it doesn't matches WrongSequence function will be called where count will be reset to 1 
          WrongSequence();
          return;
        }
       digitalWrite(ledpin1,LOW);
      }
      if(digitalRead(button2)==HIGH){
        digitalWrite(ledpin2, HIGH);
        tone(buzzer, 270 ,250);
        delay(1000);
        userIO[i] = 1;
        flag = 1;
        delay(200);
        if(userIO[i]!=check[i]){
          WrongSequence();
          return;
        }
        digitalWrite(ledpin2,LOW);
      }
      if(digitalRead(button3)==HIGH){
        digitalWrite(ledpin3, HIGH);
        tone(buzzer, 300 ,250);
        delay(1000);
        userIO[i] = 2;
        flag = 1;
        delay(200);
        if(userIO[i]!=check[i]){
          WrongSequence();
          return;
        }
        digitalWrite(ledpin3,LOW);
      }
      if(digitalRead(button4)==HIGH                                                                                         ){
        digitalWrite(ledpin4, HIGH);
        tone(buzzer, 320 ,250);
        delay(1000);
        userIO[i] = 3;
        flag = 1;
        delay(200);
        if(userIO[i]!=check[i]){
          WrongSequence();
          return;
        }
        digitalWrite(ledpin4,LOW);
      }
    }
  }
  CorrectSequence(); //If sequence given by user matches with sequence generated, correctSequence function is called where count will be increased.
}

void WrongSequence(){
  int i;
  for(i=1000;i>=0;i--){
    tone(buzzer, i, 250);
  }
  digitalWrite(ledpin1, LOW);  //LEDs blink in following fashion if the sequence is wrong
  digitalWrite(ledpin2, LOW);
  digitalWrite(ledpin3, LOW);
  digitalWrite(ledpin4, LOW);
  delay(350);
  digitalWrite(ledpin1, HIGH);
  digitalWrite(ledpin2, HIGH);
  digitalWrite(ledpin3, HIGH);
  digitalWrite(ledpin4, HIGH);
  delay(350);
  digitalWrite(ledpin1, LOW);
  digitalWrite(ledpin2, LOW);
  digitalWrite(ledpin3, LOW);
  digitalWrite(ledpin4, LOW);
  delay(350);
  digitalWrite(ledpin1, HIGH);
  digitalWrite(ledpin2, HIGH);
  digitalWrite(ledpin3, HIGH);
  digitalWrite(ledpin4, HIGH);
  delay(350);
  digitalWrite(ledpin1, LOW);
  digitalWrite(ledpin2, LOW);
  digitalWrite(ledpin3, LOW);
  digitalWrite(ledpin4, LOW);
  delay(350);
  digitalWrite(ledpin1, HIGH);
  digitalWrite(ledpin2, HIGH);
  digitalWrite(ledpin3, HIGH);
  digitalWrite(ledpin4, HIGH);
  delay(350);
  digitalWrite(ledpin1, LOW);
  digitalWrite(ledpin2, LOW);
  digitalWrite(ledpin3, LOW);
  digitalWrite(ledpin4, LOW);
  count = 2; //Count is reset to 1
  return ;
}


void CorrectSequence(){
  int i;
  for(i=500;i<1000;i++){
    //tone(buzzer, i , 250);
    tone(buzzer, i, 250);
  }
  
 // tone(buzzer, 250, 250);
  digitalWrite(ledpin1, LOW); //LEDs blink in following fashion if the sequence is correct
  digitalWrite(ledpin2, LOW);
  digitalWrite(ledpin3, LOW);
  digitalWrite(ledpin4, LOW);
  delay(250);
  digitalWrite(ledpin1, HIGH);
  digitalWrite(ledpin2, HIGH);
  digitalWrite(ledpin3, HIGH);
  digitalWrite(ledpin4, HIGH);
  delay(250);
  digitalWrite(ledpin1, LOW);
  digitalWrite(ledpin2, LOW);
  digitalWrite(ledpin3, LOW);
  digitalWrite(ledpin4, LOW);
  delay(250);
  digitalWrite(ledpin1, HIGH);
  digitalWrite(ledpin2, HIGH);
  digitalWrite(ledpin3, HIGH);
  digitalWrite(ledpin4, HIGH);
  delay(250);
  digitalWrite(ledpin1, LOW);
  digitalWrite(ledpin2, LOW);
  digitalWrite(ledpin3, LOW);
  digitalWrite(ledpin4, LOW);
  delay(250);
  digitalWrite(ledpin1, HIGH);
  digitalWrite(ledpin2, HIGH);
  digitalWrite(ledpin3, HIGH);
  digitalWrite(ledpin4, HIGH);
  delay(250);
  digitalWrite(ledpin1, LOW);
  digitalWrite(ledpin2, LOW);
  digitalWrite(ledpin3, LOW);
  digitalWrite(ledpin4, LOW);
  delay(250);
  count++; //count is increased.
  return;
}
