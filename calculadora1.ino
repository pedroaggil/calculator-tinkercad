/*
 * Script of calculator system
 * Project remixed; idealized by external user [samuelreis714]
 * Version developed by [Pedro Gil]
 * Also available on GitHub [https://github.com/pedroaggil/calculator-tinkercad]
 */

#include <LiquidCrystal.h>
#include <Keypad.h>

const byte row = 4;
const byte column = 4;

char Key[row][column] = {
  {'1','2','3','+'},
  {'4','5','6','-'},
  {'7','8','9','*'},
  {'C','0','=','/'}
};

// Connect the buttons to the motherboard outputs
byte pinRow[row] = {7, 6, 5, 4};
byte pinColumn[column] = {3, 2, A5, A4};


Keypad keypad = Keypad(makeKeymap(Key), pinRow, pinColumn, row, column);
LiquidCrystal lcd(8, 9, 10, 11, 12, 13); //RS, E, D4, D5, D6, D7

String reedOrder_01,reedOrder_02;
byte calc = 0;

char a;
long data1,data2,rpt1;
double data3,data4,rpt2;

int count = 0;

void setup(){
  lcd.begin(16, 2); //LCD (16 COL, 2 ROW)
}

void loop(){
  char key = keypad.getKey();
  
  if (key == '0' || key == '1' || key == '2' || key == '3' || key == '4' || key == '5' || key == '6' || key == '7' || key == '8' || key == '9'){
    
      if(calc == 0){
        lcd.print(key);
        reedOrder_01 += key;
        data1 = reedOrder_01.toInt();
        
      } else if(calc == 1){
        lcd.print(key);
        reedOrder_02+=key;
        data2 = reedOrder_02.toInt();
        
      }
  }

  if(key == 'C'){

      reedOrder_02 = "";
      reedOrder_01 = "";
    
      data1 = 0;
      data2 = 0;
      data3 = 0;
      data4 = 0;
      calc  = 0;
      rpt1  = 0;
      rpt2  = 0;
    
	  count++;
    
      lcd.clear();
    
      if (count == 7) {
      
      	lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Developed by");
        lcd.setCursor(0, 1);
        lcd.print("Pedro Gil");
        
        delay(7000); // Keep message on screen for 7s
        lcd.clear();
        
        lcd.print("0--||=====>");
        
        delay(7000); // Keep message on screen for 7s
        lcd.clear();
      
      }
    
      /*for (int egg = 0; egg <= 7; egg++) {

        lcd.print('Developed by Pedro Gil');

      }*/
    
  } else if(key == '=' && a == '+'){
    
    calc++;
    
    lcd.setCursor(0,2);
    rpt1 = data1+data2;
    
    lcd.print(rpt1);
    
  } else if(key == '='&& a == '-'){
    
    calc++;
    
    lcd.setCursor(0,2);
    rpt1 = data1 - data2;
    
    lcd.print(rpt1);
    
  } else if(key == '=' && a == '*'){
    
    calc++;
    
    lcd.setCursor(0,2);
    rpt1 = data1 * data2;
    
    lcd.print(rpt1);
    
  } else if(key == '=' && a == '/'){
    
    calc++;
    
    lcd.setCursor(0,2);
    data3 = data1;
    data4 = data2;
    
    rpt2 = (data3 / data4);
    lcd.print(rpt2);
    
  } else if((key == '+' || key == '-' || key == '*' || key == '/') && (calc == 0)){
    
    calc++;
    
    a = key;
    lcd.print(a);
  }
}

/* End system */
