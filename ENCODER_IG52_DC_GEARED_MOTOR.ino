
#define ENCA 2 
#define ENCB 3 

#define PWMA 5
#define PWMB 6
#define ENA_A 8
#define ENA_B 9

#define CPR 9360  //Counts Per Revolution
#define FACTOR 6.5    //Factor which is used to convert position from degree to PPR 


long pos;



void setup() {
  Serial.begin(9600);

  pinMode(PWMA,OUTPUT);
  pinMode(PWMB,OUTPUT);
  pinMode(ENA_A,OUTPUT);
  pinMode(ENA_B,OUTPUT);
  digitalWrite(ENA_A,HIGH);
  digitalWrite(ENA_B,HIGH);



  pinMode(ENCA,INPUT);
  pinMode(ENCB,INPUT);
  attachInterrupt(digitalPinToInterrupt(ENCA),readEncoder,RISING);
}

void loop() {

  setMotor(1, 255); 
  Serial.println(pos);

}

void setMotor(int dir, int pwmVal){
  if(dir == 1){
    analogWrite(PWMA,pwmVal);
    digitalWrite(PWMB,LOW);
  }
  else if(dir == -1){
    digitalWrite(PWMA,LOW);
    analogWrite(PWMB,pwmVal);
  }
  else{
    digitalWrite(PWMA,LOW);
    digitalWrite(PWMB,LOW);
  }  
}

void readEncoder(){
  int b = digitalRead(ENCB);
  if(b > 0){
    pos++;
  }
  else{
    pos--;
  }

}

