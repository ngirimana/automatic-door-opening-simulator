/*
Simulating a system that opens the door by using a
password.
Written by 
NGIRIMANA Schadrack =================218008824
MUKUNDIYUKURI Didace ================218005617
*/

#include <LiquidCrystal.h>
#include <Servo.h>
#include <Keypad.h>
Servo servo;
/* 
Position of servo motor
*/
int pos=0; 
LiquidCrystal lcd(A4, A5, A3, A2, A1, A0);
const byte rows=4;
const byte cols=3;
 
char key[rows][cols]={
{'1','2','3'},
{'4','5','6'},
{'7','8','9'},
{'*','0','#'}
};
byte rowPins[rows]={0,1,2,3};
byte colPins[cols]={4,5,6};
Keypad keypad= Keypad(makeKeymap(key),rowPins,colPins,rows,cols);
/*
    Password for Opening door
*/
char* password="8824";
int currentposition=0;
 
 
 
void setup()
{
 
displayscreen();
/* 
Connectiing servo motor 
*/
servo.attach(9); 
 
lcd.begin(16,2);
 
}
 
void loop()
{
if( currentposition==0)
{
displayscreen();
 
}
int l ;
char code=keypad.getKey();
if(code!=NO_KEY)
{
lcd.clear();
lcd.setCursor(0,0);
lcd.print("PASSWORD:");
lcd.setCursor(7,1);
lcd.print(" ");
lcd.setCursor(7,1);
for(l=0;l<=currentposition;++l)
{
 /* 
    Hashing password
 */
lcd.print("*");

}
 
if (code==password[currentposition])
{
++currentposition;
if(currentposition==4)
{
 
unlockdoor();
currentposition=0;
 
}
 
}

 
else
{
incorrect();
currentposition=0;
 
}
}
}
 
/*
    Method for opening door 
*/
 
void unlockdoor()
{
delay(900);
 
lcd.setCursor(0,0);
lcd.println(" ");
lcd.setCursor(1,0);
lcd.print("Access Granted");
lcd.setCursor(4,1);
lcd.println("Wecome!!");
lcd.setCursor(15,1);
lcd.println(" ");
lcd.setCursor(16,1);
lcd.println(" ");
lcd.setCursor(14,1);
lcd.println(" ");
lcd.setCursor(13,1);
lcd.println(" ");
/*
    Open the door
*/
for(pos = 180; pos>=0; pos-=5)
{
servo.write(pos); 
delay(50); 
}
delay(2000);
 
 
 
delay(1000);
counterbeep();
 
delay(1000);
 /*
    Close the door
*/
for(pos = 0; pos <= 180; pos +=5) // 
{ // in steps of 1 degree
servo.write(pos); 
delay(50);
 
 
currentposition=0;
 
lcd.clear();
displayscreen();
 
}
}
 
 /*
    Method for detecting incorrect password
*/
 
void incorrect()
{
delay(500);
lcd.clear();
lcd.setCursor(1,0);
lcd.print("Code");
lcd.setCursor(6,0);
lcd.print("Incorrect");
lcd.setCursor(15,1);
lcd.println(" ");
lcd.setCursor(4,1);
lcd.println("Get Away!!!");
 
lcd.setCursor(13,1);
lcd.println(" ");
Serial.println("Code Incorrect You Are Unauthorized");
delay(3000);
lcd.clear();
displayscreen();
}
/*
    Method Function for Clearing screen
*/

void clearscreen()
{
lcd.setCursor(0,0);
lcd.println(" ");
lcd.setCursor(0,1);
lcd.println(" ");
lcd.setCursor(0,2);
lcd.println(" ");
lcd.setCursor(0,3);
lcd.println(" ");
}

/*
    Method for display
*/

void displayscreen()
{
 
lcd.setCursor(0,0);
lcd.println("*Enter The Code*");
lcd.setCursor(1 ,1);
 
lcd.println("To Open Door!!");
}


/*
    Count down
*/
void counterbeep()
{
delay(1200);
 
 
lcd.clear();
 
lcd.setCursor(2,15);
lcd.println(" ");
lcd.setCursor(2,14);
lcd.println(" ");
lcd.setCursor(2,0);
delay(200);
lcd.println("Get In Within:::");
 
lcd.setCursor(4,1);
lcd.print("5");
delay(200);
lcd.clear();
lcd.setCursor(2,0);
lcd.println("Get In Within:");
delay(1000);
lcd.setCursor(2,0);
lcd.println("Get In Within:");
lcd.setCursor(4,1); //2
lcd.print("4");
delay(100);
lcd.clear();
lcd.setCursor(2,0);
lcd.println("Get In Within:");
delay(1000);

lcd.setCursor(2,0);
lcd.println("Get In Within:");
lcd.setCursor(4,1); 
lcd.print("3");
delay(100);
lcd.clear();
lcd.setCursor(2,0);
lcd.println("Get In Within:");
delay(1000);

lcd.setCursor(2,0);
lcd.println("Get In Within:");
lcd.setCursor(4,1); 
lcd.print("2");
delay(100);
lcd.clear();
lcd.setCursor(2,0);
lcd.println("Get In Within:");
delay(1000);

lcd.setCursor(4,1);
lcd.print("1");
delay(100);
lcd.clear();
lcd.setCursor(2,0);
lcd.println("Get In Within::");

delay(1000);
delay(40);
lcd.clear();
lcd.setCursor(2,0);
lcd.print("Re-Locking");
delay(1000);
lcd.setCursor(12,0);
lcd.print(".");
delay(500);
lcd.setCursor(13,0);
lcd.print(".");
delay(500);
lcd.setCursor(14,0);
lcd.print(".");
delay(400);
lcd.clear();
lcd.setCursor(4,0);
lcd.print("Locked!");
delay(440);
}
