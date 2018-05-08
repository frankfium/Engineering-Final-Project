//Frank Fiumara
//Final Project Code
const int Last = 100;//set a limit for level loop later on
const int final = 4;//sets game length
int level = 1;//level counter
int velocity = 1000;//game speed
int sequence[Last];//generated array by computer
int input[Last];//user entered array

const int buttonPin= 13;  //declaring buttons
const int buttonPin2 = 12;  
const int buttonPin3 = 11;  

int buttonState = 0;             //sets a button state used when reading for button changes     

void setup() {//declares LEDs and Buttons as respective inputs / outputs
  pinMode(3, OUTPUT);
  pinMode(buttonPin, INPUT);
  pinMode(2, OUTPUT);
  pinMode(buttonPin2, INPUT);
   pinMode(1, OUTPUT);
  pinMode(buttonPin3, INPUT);
  
   digitalWrite(1, LOW);//sets all LEDs to low before loop starts
  digitalWrite(2, LOW);
  digitalWrite(3, LOW);
}

void loop() {
  pattern();//runs the pattern method

  display(); //runs display method
  obtaininput(); //runs the method to capture user entry
}

void pattern(){
randomSeed(millis()); //generates a random start for sequence
for(int i = 0; i < final; i++){
sequence[i] = random(1,4);//randomly selects LED from 1,2, or 3

}

}

void display(){
  
  digitalWrite(1, LOW);//sets all leds to off
  digitalWrite(2, LOW);
  digitalWrite(3, LOW);
for (int i = 0; i < level; i++)//loop to run the sequence as long as level does not exceed final
{

digitalWrite(sequence[i], HIGH);//sets selected led in array to high with set tone and length
if(sequence[i]==1){
  tone(8,3000);
  delay(350);
  noTone(8);
  }
  if(sequence[i]==2){//sets selected led in array to high with set tone and length
      tone(8,4000);
  delay(350);
  noTone(8);
    }
    if(sequence[i]==3){//sets selected led in array to high with set tone and length
        tone(8,5000);
  delay(350);
  noTone(8);
      }
delay(velocity);
digitalWrite(sequence[i], LOW);//resets to low
delay(200);
}
}

void obtaininput()//catches user input by reading button presses looking for low state since initial button state is set to high
{
int choice = 0;
for (int i = 0; i < level; i++)
{
choice = 0;
while(choice == 0)
{
if (digitalRead(buttonPin) == LOW)//reads button
{
  
digitalWrite(2, HIGH);//writes corresponding LED to said button to high
tone(8, 4000);
  delay(250);
  noTone(8);
input[i] = 2;//info on which input was pressed
choice = 1;
delay(200);
if (input[i] != sequence[i])//runs incorrect sequence
{
incorrect();
return;
}
digitalWrite(2, LOW);//resets led
}
  if (digitalRead(buttonPin2) == LOW)
{
   
digitalWrite(3, HIGH);//Same as previous, sets corresponding LED to high for certain button pushed
tone(8, 5000);
  delay(250);
  noTone(8);
input[i] = 3;
choice = 1;
delay(200);
if (input[i] != sequence[i])//runs incorrect method if input does not match computer's array
{
incorrect();
return;
}
digitalWrite(3, LOW);//resets leds
}
if (digitalRead(buttonPin3) == LOW)
{
   
digitalWrite(1, HIGH);
tone(8, 3000);
  delay(250);
  noTone(8);
input[i] = 1;
choice = 1;
delay(200);
if (input[i] != sequence[i])
{
incorrect();
return;
}
digitalWrite(1, LOW);
}
}
}
correct();//runs the correct method (all lights flash once and move on etc.)
}


void incorrect(){
  
  for (int i = 0; i < 3; i++){//just a loop to run the incorrect display 3 times
  tone(8, 6000);
  delay(300);
  tone(8, 4000);
  delay(300);
  tone(8, 2000);
  delay(300);
  noTone(8);
digitalWrite(1, HIGH);//cosmetic details for which leds and sounds should flash/play
digitalWrite(1, LOW);
delay(250);
digitalWrite(2, HIGH);
digitalWrite(1, LOW);
delay(250);
digitalWrite(3, HIGH);
delay(250);
digitalWrite(1, LOW);

digitalWrite(1, HIGH);
digitalWrite(2, HIGH);
digitalWrite(3, HIGH);
delay(250);
digitalWrite(1, LOW);
digitalWrite(2, LOW);
digitalWrite(3, LOW);
}
level = 1;//resets level to 1 so game can continue from start
velocity = 1000;
}
void correct()//allows one flash for the correct sequence entered
{
digitalWrite(1, LOW);
digitalWrite(2, LOW);
digitalWrite(3, LOW);
delay(250);
digitalWrite(1, HIGH);
digitalWrite(2, HIGH);
digitalWrite(3, HIGH);
delay(500);
digitalWrite(1, LOW);
digitalWrite(2, LOW);
digitalWrite(3, LOW);
delay(500);
if (level < final){//level counting
level++;
}
else if(level == final){//if level reaches final value(constant), in this case 4, youwin method runs
  youwin();
  }
velocity -= 50;//stops game from resetting
}
void youwin(){//cosmetics for sound and LEDs in a winning sequence
  tone(8,6000);
  delay(600);
  tone(8,7000);
  delay(600);
  tone(8,8000);
  delay(600);
  noTone(8);
  digitalWrite(1, LOW);
digitalWrite(2, LOW);
digitalWrite(3, LOW);
delay(250);
digitalWrite(1, HIGH);
delay(250);
digitalWrite(2, HIGH);
delay(500);
digitalWrite(3, HIGH);
delay(7500);
digitalWrite(1, LOW);
digitalWrite(2, LOW);
digitalWrite(3, LOW);
level=1;
  }



