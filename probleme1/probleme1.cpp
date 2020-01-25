#define F_CPU 8000000UL
#include <avr/io.h>
#include <util/delay.h>

const uint8_t DELAY_20 = 20;
#define ROUGE 1
#define ETEINT 0

enum Etats
{
    INIT,		// initial
    CLICK1,		// premier click
    CLICK2,		// deuxi�me click
    CLICK3,		// troisi�me click
    CLICK4,		// quatri�me click
    ALLUME		// allumer la DEL
};
Etats etats = INIT;



// fonction qui v�rifie si le bouton a �t� appuy�
bool isclicked() { return (PIND == 0x04); }


// fonction pour le debounce
bool debounce()
{
    if (isclicked())
    {
        _delay_ms(DELAY_20);
        while (isclicked())
        {
        }
        return true;
    }
    return false;
}


int main()
{

 DDRD = 0x00;
 DDRB = 0Xff;
    for (;;)
    {

        switch (etats)
        {
        case INIT:
        {
            PORTB = ETEINT;
            _delay_ms(DELAY_20);
            if (debounce())
            {
                etats = CLICK1;
            }
            break;
        }
        case CLICK1:
        {
            _delay_ms(DELAY_20);
            if (debounce())
            {
                etats = CLICK2;
            }
            break;
        }
        case CLICK2:
        {
            _delay_ms(DELAY_20);
            if (debounce())
            {
                etats = CLICK3;
            }
            break;
        }
        case CLICK3:
        {
            _delay_ms(DELAY_20);
            if (debounce())
            {
                etats = CLICK4;
            }
            break;
        }
        case CLICK4:
        {
            _delay_ms(DELAY_20);
            if (debounce())
            {
                etats = ALLUME;
            }
            break;
        }
        case ALLUME:
        {
			// allumer en rouge et attendre une seconde avant d'�teindre et repasser � l'�tat INIT
            PORTB = ROUGE;
            _delay_ms(1000);
            etats = INIT;
            break;
        }
        }
    }
    return 0;
}
