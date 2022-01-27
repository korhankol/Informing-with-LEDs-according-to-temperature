int ledpin=2;
int ledpiny=4;

int butonpin=3;

int sensorpin=0;

int buzzerpin=5;

int okunandurum=0;
int leddurum=0;

int buzsay1=0;
int buzsay2=0;

void setup() {

Serial.begin(9600);

pinMode(ledpin,OUTPUT),
pinMode(ledpiny,OUTPUT),
pinMode(butonpin,INPUT);
pinMode(buzzerpin,OUTPUT);

}

void loop() { 
  
//int okunandurum=butonoku(butonpin);  //fonksiyon çağrıldı.0 veya 1 dönder buraya fonksiyondan

float sensordegeri=analogRead(sensorpin);
float sicaklik=((sensordegeri/1023)*5000)/10;
Serial.print("Sicaklik değeri=");
Serial.println(sicaklik);

  if(sicaklik<23)
  {
    
    digitalWrite(ledpin,HIGH);
    digitalWrite(ledpiny,LOW);
    if(buzsay1<1)
    {
        ses1();
        buzsay1=buzsay1+1;
        buzsay2=0;
    }
        
    }
    
      
  else if(sicaklik>22)
  {
    digitalWrite(ledpiny,HIGH); 
    digitalWrite(ledpin,LOW);
    if(buzsay2<1)
    {
        ses2();
        buzsay2=buzsay2+1;
        buzsay1=0;
    }    
    }

    delay(30000);
}  



//buton okuma burada gerçekleşiyor ve çağrıldığı yere 0 veya 1 dönüyor.


/*boolean butonoku(int butonpin)   //boolean fonksiyonu 1 veya 0 döner. böyle işlerde kullanışlı.
{
  int okunandeger=digitalRead(butonpin); // okunandeger bu fonksiyon için tanımlandı sadecde. yukarıda yok.
  delay(1000);
    if(okunandeger==digitalRead(butonpin)) // hala basılıysa demek.buton sorgulanır
    { 
      return okunandeger;
      }
      else
      {
        return false;
        }
  }
  */

  void ses1()
  {
      digitalWrite(buzzerpin,HIGH);
      delay(50);
      digitalWrite(buzzerpin,LOW);
      delay(50);
      digitalWrite(buzzerpin,HIGH);
      delay(50);
      digitalWrite(buzzerpin,LOW);
      delay(50);
      digitalWrite(buzzerpin,HIGH);
      delay(50);
      digitalWrite(buzzerpin,LOW);
       
    }

    void ses2()
  {
      digitalWrite(buzzerpin,HIGH);
      delay(1000);
      digitalWrite(buzzerpin,LOW);
      
      
    
    }
