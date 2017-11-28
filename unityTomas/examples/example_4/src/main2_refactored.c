
/*Detta program �r en r�knare som kan anv�ndas f�r ell�ra med enbart v�xelsp�nningar och v�xelstr�mmar. R�knaren
tar upp r�kning med sp�nningar i volt(U), resistanser upp till 20 000/ohm(R).
Str�m upp till 440 Ampere(I), effekter P i watt(W). 3 faser upp till 400V mellan faserna.
�ven tar denna upp Skenbar effekt vid 3-fas och enfas, aktiv effekt vid 3-fas och enfas d�r cosinus fi/cosinus() anv�nds
som effektfaktorn som �r mindre �n 1 och inte mindre �n 0.
Frekvenser i (Hz):  och totala motst�ndet i parallellkopplade kretsar med max 3 motst�nd.

50 Hertz(Hz) Finns det i v�ra uttag i sverige Vid 50 Hz byter �sp�nningen polaritet och str�mmen riktning 100 g�nger per
sekund. Sp�nningen i svenska eluttag pendlar upp och ner fr�n -325 V till +325 V. Att vi talar om 230 V beror p� att det
�r sp�nningens(v�xelstr�m ~) effektivv�rde eller roten ur. Sp�nningen V(U)=Toppv�rdet/sqrt(2)=325V/sqrt(2).

OHMS LAG: Sp�nning i volt(U)=Resistans i ohm(R)*Str�m i ampere(I)
RESISTANSTOTAL PARALLELLA RESISTANSER: Rtot=1/R1R2R3
EFFEKTLAGEN ENKEL f�r likstr�m: Effekt i watt(P)=U*I
SKENBAR EFFEKT ENFAS ~: Skenbar(S/VA)=U*I
AKTIV EFFEKT/MEDELEFFEKT ENFAS ~:P=U*I*cos()
SKENBAR EFFEKT 3-FAS ~: Skenbar S/VA=U*I*sqrt(3)
AKTIV EFFEKT 3-FAS ~: P=U*I*sqrt(3)*cos()

*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>
#include <stdbool.h>
#include "main2_functions.h"

double ohms_lag(double r, double i){

    double u = i * r;

    return u;
}

double res_tot(double r1, double r2, double r3){


    double rtot= (1/r1) + (1/r2) + (1/r3);
    rtot= 1/rtot;

    return rtot;
}

double sken_eff(double u, double i){

    double s = u * i;

    return s;

}

double aktiv_eff(double u, double i, double cos){

    double p = u * i * cos;

    return p;

}

double sken_3fas(double u, double i){

    double s = u * i * sqrt(3);

    return s;
}

double aktiv_3fas(double u, double i, double cos){

    double p = u * i * sqrt(3) * cos;

    return p;
}

void PrintTryAgain(){
  printf("F�r h�gt v�rde, f�rs�k igen: \n");
}

double GetValue(double limit) {
  double value;
  scanf("%lf", &value);

  if (value>limit) {
    PrintTryAgain();
    GetValue(limit);
  }
  return value;
}

void FirstCase()
{
  printf("Ohms lag sp�nningen(volt/V) bet�ckning U lika med Resistansen(Ohm) bet�ckning R \n");
  printf("g�nger Str�mmen(Ampere) med bet�ckningen I. Kort U=R*I. \n\n");

  printf("Skriv resistans R < 20 000ohm: \n ");
  
  double r, i;
  r = GetValue(20000);
  
  printf("Skriv str�m I < 440 Ampere: \n");
  i = GetValue(440);
  
  printf("%f V\n", ohms_lag(r, i));
  
}


void SecondCase(){
  printf("Resistans sammankopplade i parallella kretsar �r lika med 1 delat Resistans R total �r lika med\n");
  printf("Resistans 1/R1 + 1/R2 + 1/R3 d� vi h�gst anv�nder tre resistanser.\n\n");
  double r1,r2,r3;
  printf("Skriv resistans R1 < 20 000ohm: \n ");
  r1 = GetValue(20000);

  printf("Skriv resistans R2 < 20 000ohm: \n ");
  r2 = GetValue(20000);

  printf("Skriv resistans R3 < 20 000ohm: \n ");
  r3 = GetValue(20000);
  printf("%f Ohm\n", res_tot(r1, r2, r3));
}

void ThirdCase() {
  printf("Effektlagen enkel f�r likstr�m �r effekten P i Watt (W) lika med sp�nningen U i volt(V)\n");
  printf("g�nger str�mmen I i Ampere(A): \n\n");

  double u, i;
  u = GetValue(20000);
  printf("Skriv str�m Ampere I < 440A: \n");
  i = GetValue(440);
  printf("%f W\n", eff_enk(u, i));

}


void FourthCase(){
  printf("Skenbar effekt enfas r�knas med storheten VA(VoltAmpere) som �r lika med sp�nningen U i volt(V)\n");
  printf("g�nger str�mmen I i ampere(A)\n\n");
  double u, i;
  printf("Skriv Sp�nningen U i volt: \n ");
  u = GetValue(20000);
  printf("Skriv str�m Ampere I < 440A: \n");
  i = GetValue(440);
  printf("%f VA\n", sken_eff(u, i));

}

void FifthCase() {
  printf("Aktiv medelefdekt enfas �r lika med effekt P i watt(W) lika med sp�nningen U i volt(V) g�nger str�mmen I \n");
  printf("i Ampere g�nger cosinus fi/efkektfaktor < 1:\n\n");
  double u, i, cos;
  u = GetValue(20000);
  printf("Skriv str�m I: \n");
  i = GetValue(440);
  printf("Skriv in effektfaktorn cos > 0 && cos < 1:\n");
  u = GetValue(1);
  printf("%f W\n", aktiv_eff(u, i, cos));
  
}

void SixthCase(){
  printf("3-fas skenbar effekt �r v�xelsp�nning �r skenbar effekt S i voltampere(VA) lika med sp�nningen U i volt(V) \n");
  printf("g�nger str�mmen I i ampere(A) g�nger roten ur 3 SQRT(3).\n\n");
  double u, i;
  printf("Skriv sp�nning U i volt(V) < 400V: \n ");
  u = GetValue(400);

  printf("Skriv str�m I i ampere < 440: \n");
  i = GetValue(440);
  printf("%f VA\n", sken_3fas(u, i));

}

void SeventhCase(){
  printf("3-fas aktiv effekt �r effekten P i Watt(W) lika med sp�nningen U i volt(V) g�nger str�mmen I i ampere(A)\n");
  printf("g�nger cos < 1 && cos > 0 g�nger roten ur 3 SQRT(3).\n\n");
  double u, i, cos;
            printf("Skriv Sp�nningen U i volt(V): \n ");
	    u = GetValue(400);
            printf("Skriv str�m I i ampere(A): \n");
	    i = GetValue(440);

            printf("Skriv in effektfaktorn cos > 0 && cos < 1: \n");
	    cos = GetValue(1);
            printf("%f W\n", aktiv_3fas(u ,i, cos));

}

int choice(){
        printf("\n");
        int val;

        printf("V�lj vilka storheter du vill ber�kna:\n");
        printf("V�lj 1 f�r: OHMS LAG\n");
        printf("V�lj 2 f�r: Rtot\n");
        printf("V�lj 3 f�r: EFFEKTLAGEN ENKEL\n");
        printf("V�lj 4 f�r: SKENBAR EFFEKT ENFAS\n");
        printf("V�lj 5 f�r: AKTIV EFFEKT/MEDELEFFEKT ENFAS\n");
        printf("V�lj 6 f�r: SKENBAR EFFEKT 3-FAS\n");
        printf("V�lj 7 f�r: AKTIV EFFEKT 3-FAS\n");
        printf("V�lj 0 f�r: F�R ATT AVSLUTA\n");

        scanf("%d", &val);
	return val;
}
  
int main()
{
    system("chcp 1252");
    system("cls");
    bool exit = false;
    int val;
    do
    {
        val = choice();

	switch(choice()) {
	case 1:
	  FirstCase();
	  break;
	case 2:
	  SecondCase(); 
	  break;
	case 3:
	  ThirdCase();
	  break;
	case 4:
	  FourthCase();
	  break;
	case 5:
	  break;
	  FifthCase();
	case 6:
	  SixthCase();
	  break;
	case 7:
	  SeventhCase();
	  break;
	case 0:
	  break;
	default:
	  printf("Fel alternativ f�rs�k igen!: \n");
	  break;
        }
    } while (val !=0);
    
    return 0;
}
