
const int IR = 3;    
const int relay =  5;
const int buzzer=  7; 

int readState = 0;
int trigMusState=0;
void setup() {
  pinMode(relay, OUTPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(IR, INPUT);
  bootMusic();
  delay(2000);
  bufferReadyMusic();

}

void loop() {
  readState = digitalRead(IR);
  if (readState == LOW) {
    trigMusState=0;
    int _checkLessThan=0;
    while(digitalRead(IR)==LOW && _checkLessThan<500){
      digitalWrite(relay, HIGH);  
      if(trigMusState==0){
        triggerMusic();  
        trigMusState++;
        }
      delay(10);
      _checkLessThan++;
      }
      
      
    
    
    } 
  else{
    digitalWrite(relay, LOW);  
//    Serial.println("low");
      }
      
delay(500);
}


void bootMusic(){
//   musicFreq(2500,100);
//  digitalWrite(buzzer, HIGH);   
//  delay(500);              
//  digitalWrite(buzzer, LOW); 
  digitalWrite(buzzer, HIGH);   
  delay(1000);              
  digitalWrite(buzzer, LOW); 
  }


void bufferReadyMusic(){
  musicFreq(2200,100);
  musicFreq(2500,100);
  musicFreq(2300,100);
  
//  musicFreq(2400,100);
  digitalWrite(buzzer, HIGH);   
  delay(300);              
  digitalWrite(buzzer, LOW); 
  
  }

void musicFreq(int freq,int duration){
  tone(buzzer,freq);
  delay(duration);
  noTone(buzzer);
  delay(duration);
  }


void triggerMusic(){
   digitalWrite(buzzer, HIGH);   
  delay(50);              
  digitalWrite(buzzer, LOW);    
  delay(100);             
  digitalWrite(buzzer, HIGH);   
  delay(200);              
  digitalWrite(buzzer, LOW); 
  
  }
