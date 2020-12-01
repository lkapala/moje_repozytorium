#include <LiquidCrystal.h> 

//! \defgroup  LCD_1 Praca wyświetlacza
//! \{      
//!\(Inicjacja danych w bibliotece LiquidCrystal oraz deklaracja poszczegónych pinów odpwiedzialnych za swery zasilania i wyswietlania.)
//!\attention   PIN 12 - Wybór rejestru danych - pinRS.  PIN 11 -  Właczenie trybu zapisu Pin - ENABLE.  PINY 6,7,8,9  Magistrala danych - (Piny D1,D2,D3,D4).
  LiquidCrystal lcd(12,11,6,7,8,9); 
//! \}

//! \defgroup  Zz_1 Zadeklarowane zmienne
//! \{  
//!  Deklaracja zmiennej integer o nazwie data.
//!\attention Do zmiennej przypisywane są wartości z portu szeregowego.
//!\warning Wartości przypisywanie działają w oparciu o strukturę kodowania ASCII.
  int data; 
//! \} 

//! \defgroup Arduino_function1 Funkcje
//! \{
//!  Funkcje inicjujące działanie programu.  
   //! \{
  void setup() {  

   //Deklaracja PIN2-wyjscie.
   pinMode(2,OUTPUT);    
   //Deklaracja PIN3-wyjscie.      
   pinMode(3,OUTPUT);
   //Deklaracja PIN4-wyjscie.
   pinMode(4,OUTPUT);
   //Deklaracja PIN5-wyjscie.
   pinMode(5,OUTPUT);
   
//! Funkcja \b SETUP odnosi się do zainicjowania zmiennych oraz do określenia pinów. W jej skład wchodzą takie lementy jak:.  

//! Określenie prędkości transferu danych na porcie szeregowym.  
   Serial.begin(9600);
//! Określenie zakresu roboczego wyświetlacza.
   lcd.begin(16,2);
//! Ustawienie kursora w  określonym punkcie.
   lcd.setCursor(0,0);
//! Pierwotne wypisanie napisu na wyświetlacz.
   lcd.print("AUTOR:PAWEL GOLA");  
   lcd.setCursor(0,1);
   lcd.print("LUKASZ KAPALA");
 }
  //! \} 

//!  Funkcja \b  LOOP wykonująca się w pętli przez cały czas i w jej skład wchodzą takie elemety  jak: .
//! \{
void loop() 
    {
//!Przypisanie do zmiennej data  danych wysyłanych z portu szeregowego.        
  data=Serial.read(); 
//!Wyświetlenie danych przypisanych do zmiennej data na porcie szeregowym odpowiedzialnych za sterowanie robotem.
  Serial.println(data); 
//!Przerwa w wykonywaniu programu (100ms)       
  delay(100);                  
  
//!Jazda do przodu.
 if(data==49)
  { 
//Ustawienie stanu niskiego na pin 3 .     
   digitalWrite(3,LOW);  
//Ustawienie stanu wysokiego na pin 2 .       
   digitalWrite(2,HIGH);      
//Ustawienie stanu niskiego na pin 4.
   digitalWrite(4,LOW);       
//Ustawienie stanu wysokiego na pin 5.
   digitalWrite(5,HIGH);      
//Czyszczenie ekranu.    
   lcd.clear(); 
//Ustawienie kursora.                 
   lcd.setCursor(3,0);
//Wypisanie napisu.      
   lcd.print("!!NAPRZOD!!");
  }
  
 //!Stop.
 else if(data==50)
 { 
//Ustawienie stanu wysokiego na pin 3 .             
  digitalWrite(3,HIGH);
//Ustawienie stanu wysokiego na pin 2 .     
  digitalWrite(2,HIGH);
//Ustawienie stanu wysokiego na pin 4 .     
  digitalWrite(4,HIGH);
//Ustawienie stanu wysokiego na pin 5 .     
  digitalWrite(5,HIGH);
//Czyszczenie ekranu.  
  lcd.clear();
//Ustawienie kursora.  
  lcd.setCursor(4,0);
//WYpisanie napisu.      
  lcd.print("!!STOP!!");
//Opuźnienie wykonywania programu.
  delay(2000);
//Czyszczenie ekranu.   
  lcd.clear();
//Ustawienie kursora.    
  lcd.setCursor(0,0);
//Wypisanie napisu na wyświetlacz.
  lcd.print("AUTOR:PAWEL GOLA");  
//Ustawienie kursora.  
  lcd.setCursor(0,1);
//Wypisanie napisu na wyświetlacz.
  lcd.print("LUKASZ KAPALA");
 }
   
//!Skręcanie w lewo.
  else if(data==51)
  {  
//Ustawienie stanu wysokiego na pin 3 .              
  digitalWrite(3,LOW);
//Ustawienie stanu niskiego na pin 2 .   
  digitalWrite(2,HIGH);
//Ustawienie stanu  niskiego na pin 4 . 
  digitalWrite(4,HIGH);
//Ustawienie stanu wysokiego na pin 5 .  
  digitalWrite(5,HIGH);
//Czyszczenie ekranu.    
  lcd.clear();  
//Ustawienie kursora.  
  lcd.setCursor(3,0); 
//Wypisanie napisu na wyświetlacz.
  lcd.print("!!W LEWO!!");
 }
 
//!Skręcanie w prawo.
  else if(data==52)
  {   
//Ustawienie stanu wysokiego na pin 3. 
  digitalWrite(3,HIGH);
//Ustawienie stanu wysokiego na pin 2.  
  digitalWrite(2,HIGH);
//Ustawienie stanu niskiego na pin 4. 
  digitalWrite(4,LOW);
//Ustawienie stanu wysokiego na pin 3. 
  digitalWrite(5,HIGH);
//Czyszczenie ekranu.   
  lcd.clear(); 
//Ustawienie kursora.    
  lcd.setCursor(3,0); 
//Wypisanie napisu na wyświetlacz.    
  lcd.print("!!W PRAWO!!");       
  }

//!Jazda do tyłu.
  else if(data==53)
  {   
//Ustawienie stanu niskiego na pin 2.         
  digitalWrite(2,LOW);
//Ustawienie stanu wysokiego na pin 3.         
  digitalWrite(3,HIGH);
//Ustawienie stanu niskiego na pin 5. 
  digitalWrite(5,LOW);
//Ustawienie stanu wysokiego na pin 4.   
  digitalWrite(4,HIGH);
//Czyszczenie ekranu.     
  lcd.clear();
//Ustawienie kursora.       
  lcd.setCursor(3,0); 
//Wypisanie napisu na wyświetlacz.    
  lcd.print("!!DO TYLU!!"); 
  }
  //! \}
}

//! \}

//! \defgroup  Wykorzystane moduły/częśći 
//! \{
//!\param 1.  Silnik o  napędzie  D65 6V z motoreduktorem i kołem  65mm. Napięcie zasilania: 3-6V. Pobór prądu bez  obciażenia: 0,17A. Pobór prądu pod  obciażeniem: 350mA. Siła ciągu na przekładni (6V): 5,5 KG/cm. Prędkość obrotowa silnika: 100 obr / min
//![Silnik z przekładnią ](C:\Users\komputer\Desktop\silnik.jpg)
//!\param 2.  Wyświetlacz LCD 2x16 znaków,Sterownik zgodny z HD44780. Podświetlanie: żółto-zielone, czarne znaki Rozmiar modułu : 80 x 36 mm .Wymiary znaku: 2,45 x 5,00 mm .Zakres temperatur pracy : od -20 do +70 °C 
//![Wyświetlacz](C:\Users\komputer\Desktop\wyświetlacz1.jpg)
//!\param 3. Moduł Bluetooth HC-05 Moduł Blootooth v2.0 + EDR klasa 2. Pracuje z napięciem 3,3 V, komunikuje się poprzez interfejs szeregowy UART (piny RX, TX), wspiera komendy AT. Maksymalna moc nadajnika wynosi + 4 dBm, czułość odbiornika to - 85 dBm. 
//![Moduł bluetooth](C:\Users\komputer\Desktop\moduł-bloototh.jpg)
//!\param 4. L293d - dwukanałowy sterownik silników 36V/0.6A Dwukanałowy sterownik silników. Napięcie zasilania do 36 V . Średni prąd na kanał 600 mA (chwilowy do 1,2 A). Obudowa: DIP 16 (przewlekana).
//![sterownik silniów](C:\Users\komputer\Desktop\sterownik silników.jpg)
//! \}

//! \defgroup  Schematy
//! \{ 
//![Obejrzyj schemat połaczenia sterownika silników L293d](C:\Users\komputer\Desktop\schemat.jpg)
//!
//! \}
//! \defgroup author Autorzy projektu
//! \{
//![Obejrzyj model robota](C:\Users\komputer\Desktop\projekt1.jpg)
//!\author \b 1. \b Łukasz \b Kapała   
//!\author \b 2. \b Paweł  \b Gola
//! \}
