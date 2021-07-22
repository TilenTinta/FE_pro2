//IO
#define cip1_1 7 
#define cip1_2 6
#define cip1_3 5
#define cip1_4 4

#define cip2_1 3
#define cip2_2 2
#define cip2_3 1
#define cip2_4 0

int stevilo1 = -1;
int stevilo2 = -1;

void setup()
{
  pinMode(cip1_1, OUTPUT);
  pinMode(cip1_2, OUTPUT);
  pinMode(cip1_3, OUTPUT);
  pinMode(cip1_4, OUTPUT);
  
  pinMode(cip2_1, OUTPUT);
  pinMode(cip2_2, OUTPUT);
  pinMode(cip2_3, OUTPUT);
  pinMode(cip2_4, OUTPUT);
}

void loop()
{
  for(int i = 0; i <= 9; i++){
    stevilo1 = stevilo1+1;
    if (stevilo1 == 10){
          stevilo1 = 0;
          //Display2(stevilo2);
    	}
    for(int j = 0; j <= 9; j++){
      stevilo2 = stevilo2+1;  
      if (stevilo2 == 10){
      		stevilo2 = 0;
      		//Display2(stevilo2);
    	}
        Display1(stevilo1);
        Display2(stevilo2);
        delay(1000);
    }
  }
}


void Display1(int num1){
  digitalWrite(cip1_4,(num1 >> 3) & 0x1);
  digitalWrite(cip1_3,(num1 >> 2) & 0x1);
  digitalWrite(cip1_2,(num1 >> 1) & 0x1);
  digitalWrite(cip1_1,(num1 >> 0) & 0x1);
}

void Display2(int num2){
  digitalWrite(cip2_4,(num2 >> 3) & 0x1);
  digitalWrite(cip2_3,(num2 >> 2) & 0x1);
  digitalWrite(cip2_2,(num2 >> 1) & 0x1);
  digitalWrite(cip2_1,(num2 >> 0) & 0x1);
}