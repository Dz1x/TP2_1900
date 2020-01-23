


#define F_CPU 8000000UL
#include <avr/io.h>
#include <util/delay.h>
using namespace std;
const uint8_t DELAY_5 = 5;
const uint8_t DELAY_20 = 20;
#define ROUGE 1
#define VERT 2
#define ETEINT 0

enum Etats
{
    INIT,
    CLICK1,
    RELACHE1,
    CLICK2,
    RELACHE2,
    CLICK3
};
Etats etats = INIT;

bool isClicked()
{
    return(PIND == 0x04);
}
void couleurAmbre()
{
    while (isClicked())
    {
        PORTB = ROUGE;
        _delay_ms(DELAY_5);
        PORTB = VERT;
        _delay_ms(DELAY_5);
    }
}


bool debounce()
{
    if (isClicked())
    {
        _delay_ms(DELAY_20);
        if (isClicked())
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
            PORTB = ROUGE;

            if (debounce())
            {
                etats = CLICK1;
            }
            break;
        }
        case CLICK1:
        {
            while (isClicked())
            {
                couleurAmbre();
            }
            etats = RELACHE1;
            break;
        }
        case RELACHE1:
        {
            PORTB = VERT;
            if (debounce())
                etats = CLICK2;
            break;
        }
        case CLICK2:
        {
            while (isClicked())
            {
                PORTB = ROUGE;
            }
            etats = RELACHE2;
            break;
        }

        case RELACHE2:
        {
            PORTB = ETEINT;
            if (debounce())
                etats = CLICK3;
            break;
        }
        case CLICK3:
        {
            PORTB = VERT;
            if (!debounce())
            {
                etats = INIT;
            }
            break;
        }
        }
    }

    return 0;
}

