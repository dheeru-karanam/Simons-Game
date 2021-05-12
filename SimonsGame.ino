const int ledpin1=A0, ledpin2=A1;
const int button1=3, button2=4;
int check[100];
int userIO[100];
int a[100],i=0,count=1,val1=1,val2=1,flag =0 ;
void setup() {
  // put your setup code here, to run once:
  pinMode(ledpin1,OUTPUT);
  pinMode(ledpin2,OUTPUT);
  pinMode(3, INPUT);
  pinMode(4, INPUT);
  digitalWrite(ledpin1,0);
  delay(1000);
  digitalWrite(ledpin2,0);
  delay(1000);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(count == 1){
    Serial.println("Entered count==1 loop");
    SequenceGenerate();
    Serial.println("Exited generate_seq loop");
  
    for(int i=0;i<2;i++){
      Serial.println(i);
      digitalWrite(A0,LOW);
      digitalWrite(A1,LOW);
      delay(500);
      digitalWrite(A0,HIGH);
      digitalWrite(A1,HIGH);
      delay(500);
      Serial.println("Entered for loop");
      if(digitalRead(3)==LOW || count != 1){
    digitalWrite(ledpin1,LOW);
    digitalWrite(ledpin2,LOW);
    delay(1000);
    Serial.println("Entered start");
    SequenceDisplay();
    digitalWrite(ledpin1,LOW);
    digitalWrite(ledpin2,LOW);
    ReadSequence();

   }
    }
  }
  if(digitalRead(3)==LOW || count != 1){
    digitalWrite(ledpin1,LOW);
    digitalWrite(ledpin2,LOW);
    delay(1000);
    Serial.println("Entered start");
    SequenceDisplay();
    digitalWrite(ledpin1,LOW);
    digitalWrite(ledpin2,LOW);
    ReadSequence();

   }
}


void SequenceGenerate(){
  randomSeed(millis());
  Serial.println("Entered generate_seq loop");
  for(int i=0;i<100;i++){
    check[i] = random(0,2);
    }
}

void SequenceDisplay(){
  digitalWrite(ledpin2,LOW);
  digitalWrite(ledpin1,LOW);
  //delay(1000);
  for(int i=0;i<count;i++){
    Serial.println(check[i]);
    if(check[i]==0){
      digitalWrite(A0, HIGH);
      delay(500);
      digitalWrite(A0,LOW);
      delay(500);
      }
      else{
        digitalWrite(A1,HIGH);
        delay(500);
       digitalWrite(A1,LOW);
       delay(500);
        }
    }
  }

void ReadSequence(){
  digitalWrite(ledpin1,LOW);
    digitalWrite(ledpin2,LOW);
  Serial.println("Entered get_seq");
  int flag =0;
  Serial.println("\n\n\n");
  Serial.println(count);
  Serial.println("\n\n\n");
  for(int i=0;i<count;i++){
    flag = 0;
    while(flag==0){
      if(digitalRead(3)==LOW){
        Serial.println("Digitalread3");
        userIO[i]=0;
        digitalWrite(ledpin1, HIGH);
        delay(1000);
        flag = 1;
        if(userIO[i]!=check[i]){
          Serial.println("Wrong");
          WrongSequence();
          return;
          }
     
        digitalWrite(ledpin1,LOW);
       }
      if(digitalRead(4)==LOW){
        Serial.println("Digitalread4");
        digitalWrite(ledpin2, HIGH);
        delay(1000);
        userIO[i] = 1;
        flag = 1;
        delay(200);
        if(userIO[i]!=check[i]){
          Serial.println("Wrong");
          WrongSequence();
          return;
          }
        digitalWrite(ledpin2,LOW);

      } 
    }
  }
  CorrectSequence();
}

void WrongSequence(){
  digitalWrite(ledpin1, LOW);
  digitalWrite(ledpin2, LOW);
  delay(350);
  digitalWrite(ledpin1, HIGH);
  digitalWrite(ledpin2, HIGH);
  delay(350);
  digitalWrite(ledpin1, LOW);
  digitalWrite(ledpin2, LOW);
  delay(350);
  digitalWrite(ledpin1, HIGH);
  digitalWrite(ledpin2, HIGH);
  delay(350);
  digitalWrite(ledpin1, LOW);
  digitalWrite(ledpin2, LOW);
  delay(350);
  digitalWrite(ledpin1, HIGH);
  digitalWrite(ledpin2, HIGH);
  delay(350);
  digitalWrite(ledpin1, LOW);
  digitalWrite(ledpin2, LOW);
  count = 1;
  return ;
  }


void CorrectSequence(){
  digitalWrite(ledpin1, LOW);
  digitalWrite(ledpin2, LOW);
  delay(250);
  digitalWrite(ledpin1, HIGH);
  digitalWrite(ledpin2, HIGH);
  delay(250);
  digitalWrite(ledpin1, LOW);
  digitalWrite(ledpin2, LOW);
  delay(250);
  count++; 
  return;
  }
