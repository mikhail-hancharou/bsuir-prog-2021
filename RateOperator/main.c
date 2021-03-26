#include <stdio.h>
#include "src.h"


int main()
{
    int gb, inNetworkMin, otherOperatorMin, smsAmount, wants = 0;
    while (wants != 4)
    {
        wants = ShowMenu();
        if (wants == 1)
        {
            printf("Inter amount of gb\n");
            gb = GetInput();
            printf("Inter amount of minuts in network\n");
            inNetworkMin = GetInput();
            printf("Inter amount of minuts to other operators\n");
            otherOperatorMin = GetInput();
            printf("Inter amount of SMS\n");
            smsAmount = GetInput();
            switch (rate(gb, inNetworkMin, otherOperatorMin, smsAmount))
            {
            case 1:
                printf("For you preference is better to choose \"WITHOUTLIMIT+\" \n");
                break;
            case 2:
                printf("For you preference is better to choose \"SUPER MAX 50\" \n");
                break;
            case 3:
                printf("For you preference is better to choose \"SUPER 10\" \n");
                break;
            case 4:
                printf("For you preference is better to choose \"SUPER 25\" \n");
                break;
            case 5:
                printf("For you preference is better to choose \"SUPER\" \n");
                break;
            case 6:
                printf("For you preference is better to choose \"SUPER GO\" \n");
                break;
            }
            printf("Inter \"0\" to back\n");
            wants = GetInput();
            while (wants != 0)
            {
                printf("Try again\n");
                wants = GetInput();
            }
        }
        else if (wants == 2)
        {
            printf("\nUnlimited+ \nUnlimited Internet\n400 minutes to all networks\nFree subscription to and online movie theater\n25, 48 rubles per month\n\n");
            printf("Super max 50 \n50 GB, unlimited calls to all networks\nUnlimited on YouTube, VKontakte, Instagram, Viber and other popular services\n30, 4 rubles per month\n\n");
            printf("Super 10 \nUnlimited on VKontakte, Instagram, Viber and other popular services\n10 GB for other things per month\n400 minutes in all networks\nFREE subscription to and online cinema\n21, 30 rubles per month\n\n");
            printf("Super 25\n Unlimited access to YouTube, VKontakte, Instagram, Viber and other popular services\n25 GB for other services per month\nUNLIMITED minutes to all networks\nFREE subscription to and online movie theater\n30, 60 rubles per month\n\n");
            printf("Super\nUnlimited on Viber, WhatsApp, Telegram, Snapchat\n1 GB on other per month\n200 minutes on MTS\n10, 81 rubles per month\n\n");
            printf("Super Go\nSpecial tariff for wearable devices\nUnlimited Internet at speeds up to 256 Kbit / s \n100 minutes on MTS and 100 SMS\n8. 84 rubles per month\n\n");
            printf("Inter \"0\" to back\n");
            wants = GetInput();
            while (wants != 0)
            {
                printf("Try again\n");
                wants = GetInput();
            }
        }
        else if (wants == 3)
        {
            printf("\nFor A1 communication services, please call:\n150-a single contact center number(free call from all networks of operators in Belarus)\n7100 - (from mobile A1 - 0, 03 rub.)\nroaming by phone + 375 29 6 000 150 (payment according to roaming rates)\n");
            printf("Inter \"0\" to back\n");
            wants = GetInput();
            while (wants != 0)
            {
                printf("Try again\n");
                wants = GetInput();
            }
        }
        else
        {
            return 0;
        }
    }
}
