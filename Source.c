#include <stdio.h>
#include <stdlib.h>

struct yolcu
{
    char ad[10];
    char soyad[10];
    struct yolcu* oncekiYolcu;
    struct yolcu* sonrakiYolcu;
};


struct yolcu* sira = NULL;
struct yolcu* IlkYolcu = NULL;

struct otobus
{
    struct yolcu* sonrakiyolcu;
    struct yolcu* oncekiyolcu;
};

struct otobus* Bus = NULL;

int YolcuNumara = 0;
int OtobusNumara = 1;

void YolcuEkle()
{
    struct yolcu* Yolcu = NULL;
    Yolcu = (struct yolcu*)malloc(sizeof(struct yolcu));

    if (YolcuNumara % 5 == 0)
    {

        printf("\n******* %d.Otobus ********\n", OtobusNumara);
        OtobusNumara++;

        Bus = (struct otobus*)malloc(sizeof(struct otobus));

        if (sira == NULL)
        {
            Bus->sonrakiyolcu = Yolcu;
            Bus->oncekiyolcu = NULL;
        }
        else
        {
            Bus->oncekiyolcu = sira;
            Bus->sonrakiyolcu = Yolcu;
            sira->sonrakiYolcu = Yolcu;
            sira = Yolcu;
        }
        YolcuNumara = 0;
    }


    printf("%d.Yolcunun Adi Giriniz :", (YolcuNumara + 1));
    scanf("%s", Yolcu->ad);
    printf("%d.Yolcunun Soyadi Giriniz :", (YolcuNumara + 1));
    scanf("%s", Yolcu->soyad);


    if (sira == NULL)
    {
        IlkYolcu = Yolcu;
        sira = Yolcu;
        Yolcu->oncekiYolcu = Bus;
        Yolcu->sonrakiYolcu = NULL;
        YolcuNumara++;
    }
    else
    {
        Yolcu->oncekiYolcu = sira;
        sira->sonrakiYolcu = Yolcu;
        sira = Yolcu;
        Yolcu->sonrakiYolcu = NULL;
        YolcuNumara++;
    }

}

void YolcularListele()
{
    struct yolcu* temp = NULL;
    temp = IlkYolcu;

    int i = 0;
    int k = 1;

    while (temp != NULL)
    {


        if (i % 5 == 0)
        {
            printf("********%d.otobus*********\n", k);
            k++;
            i = 0;
        }
        printf("%d.Yolcu Adi :%s ---- Soyad   : %s \n", (i + 1), temp->ad, temp->soyad);
        printf("\n");
        temp = temp->sonrakiYolcu;
        i++;
    }
}



int main()
{

    int secim;
    int contro = 0;
    printf("\n1-Yolcu Ekleme\n");
    printf("2-Yolcular Listele\n");
    printf("3-Cikis\n");

    while (1)
    {
        if (contro == 25)
        {
            printf("Otobus Bitti\n");
            YolcularListele();
            break;
        }
        else
        {
            printf("\nSeciminiz Giriniz :\n");
            scanf("%d", &secim);

            switch (secim)
            {
            case 1: contro++; YolcuEkle(); break;
            case 2: YolcularListele(); break;
            case 3:break; break;

            default: printf("Yanlis Girdiniz"); break;
            }
        }
    }

    return 0;
}
