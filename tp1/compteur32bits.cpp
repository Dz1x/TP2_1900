/*
 * Nom: compteur 32 bits
 * Copyright (C) 2005 Matthew Khouzam
 * License http://www.gnu.org/copyleft/gpl.html GNU/GPL
 * Description: Ceci est un exemple simple de programme 
 * Version: 1.1
 */
#define F_CPU 8000000UL

#include <avr/io.h> 
#include <util/delay.h>

int main()
{
  DDRA = 0xff; // PORT A est en mode sortie
  DDRB = 0xff; // PORT B est en mode sortie
  DDRC = 0xff; // PORT C est en mode sortie
  DDRD = 0x00; // PORT D est en mode sortie
  unsigned long compteur=0; // le compteur est initialise a 0.
                            // c'est un compteur de 32 bits

  for(;;)  // boucle sans fin
  {
  /*  compteur++;  // incremente le compteur
                 // si le compteur est 0xffff ffff il revient a 0
    PORTD = compteur;       // PORTD = 8 bits de large,
                            // il prend les bits de 0 a 7 du compteur
    PORTC = compteur >> 8;  // PORTC = 8 bits de large,
                            // il prend les bits de 8 a 15 du compteur
                            // en faisant un decallage de 8 bits.
    PORTB = compteur >> 16; // PORTB = 8 bits de large,
                            // il prend les bits de 16 a 23 du compteur
                            // en faisant un decallage de 16 bits
    PORTA = compteur >> 24; // PORTA = 8 bits de large,
                            // il prend les bits de 24 a 31 du compteur
                            // en faisant un decallage de 24 bits.
                            
*/


/*
               PORTB=1;     
              _delay_ms(1000);
               PORTB=2;  
              _delay_ms(1000);

      for(uint8_t  i= 0; i <100; i++){
                PORTB=1;     
              _delay_ms(10);
               PORTB=2;  
                _delay_ms(10);
              // incremente le compteur
                 // si le compteur est 0xffff ffff il revient a 0
             
      }
                
*/
              
            
           if (PIND&0X04){

            _delay_ms(10);
              
               while(PIND&0X04){
               
                PORTB=1;     
              _delay_ms(10);
               PORTB=2;  
                _delay_ms(10);
              // incremente le compteur
                 // si le compteur est 0xffff ffff il revient a 0
             
      
               }
             
           }

 PORTB=0X0;
}
 return 0; 
}


