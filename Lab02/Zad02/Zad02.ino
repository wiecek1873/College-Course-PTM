#define przycisk 7
char tablicaLedow[6] = {8,9,10,11,12,13};  //Przypisuje odpowiednie porty ledom
boolean wezykRosnaco = true; //Okresla kierunek wezyka, true - rosnaco, false - malejaco
int licznik = 0; //Numer diory ktora przewodzi wezykowi

void setup() 
{
  pinMode(przycisk,INPUT_PULLUP);
  
  for(int i = 0; i < 6; i++) //Ustawia ledy na wyjscie
    pinMode(tablicaLedow[i],OUTPUT); 
  for(int i = 0; i < 6; i++) //Gasi wszystkie ledy
    digitalWrite(tablicaLedow[i],LOW);
}

void loop() 
{
 if(wezykRosnaco == true)
 {
  digitalWrite(tablicaLedow[licznik],HIGH);
  delay(250);
  digitalWrite(tablicaLedow[licznik],LOW);
  ++licznik;
 }
 else
 {
  digitalWrite(tablicaLedow[licznik],HIGH);
  delay(250);
  digitalWrite(tablicaLedow[licznik],LOW);
  --licznik;
 }

 
 if(digitalRead(przycisk) == LOW) //Zamienia kierunek wezyka
 {
  delay(100); //Zabezpiecza przed zakloceniami
  wezykRosnaco = !wezykRosnaco;
 }

//Obroty wezyka na koncach
  if(licznik == 5 && wezykRosnaco)
 wezykRosnaco = false;
 
 if(licznik == 0 && !wezykRosnaco)
 wezykRosnaco = true;
 
}
