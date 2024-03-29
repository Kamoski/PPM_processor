#include <iostream>
#include "ppm.h"

int liczkolory(Obraz ob);

int main()
{
	Obraz * ob;
	ob = new ppm("Lena.ppm");
	int kolor;
	kolor = liczkolory(*ob);
	std::cout << "kolorow: " << kolor;
	delete ob;
	return 0;
}

int liczkolory(Obraz ob) {
	return ob.uniqueColors();
}

// 74569
// Ilosc unikalnych kolorów w zdjęciu z leną

/*
P1 -> określa format
# This is an example bitmap of the letter "J" -> komentarz 
6 10 -> liczba kolumn 
000010000010000010000010000010000010100010011100000000000000 -> dane binarne	
*/

/*
P2
# Shows the word "FEEP" (example from Netpbm man page on PGM)
24 7
15 -> maksymalna intensywność koloru
0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0
0  3  3  3  3  0  0  7  7  7  7  0  0 11 11 11 11  0  0 15 15 15 15  0
0  3  0  0  0  0  0  7  0  0  0  0  0 11  0  0  0  0  0 15  0  0 15  0
0  3  3  3  0  0  0  7  7  7  0  0  0 11 11 11  0  0  0 15 15 15 15  0
0  3  0  0  0  0  0  7  0  0  0  0  0 11  0  0  0  0  0 15  0  0  0  0
0  3  0  0  0  0  0  7  7  7  7  0  0 11 11 11 11  0  0 15  0  0  0  0
0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0

TAK SAMO JAK WYŻEJ OPRÓCZ 15 która oznacza
jeśli 15 damy na 7 np. to kolory powyżej 7 będą w maksymalnym nasyceniu a nie bieli
32 powoduje np. wyszarzenie napisu gdyż zwiększamy górny próg intensywności
*/

/*
P3
3 2 -> kolumny i wiersze jedno pole to trójka liczb 
255 -> maks intensywność tonlna
# The part above is the header
# "P3" means this is a RGB color image in ASCII
# "3 2" is the width and height of the image in pixels
# "255" is the maximum value for each color
# The part below is image data: RGB triplets
255   0   0     0 255   0     0   0 255
255 255   0   255 255 255     0   0   0


*/

/*
Obraz zawiera w sobie [i][j] Pixeli
Pixel zwiera color
A color zawiera R G B

Czyli w sumie obraz składa się z i j kolorów gdzie jeden kolor to R G B

OBRAZ jest abstrakcyjny a typy obrazów pokorju jpg ppm dziedziczą

Używać dziedziczenia, ob = ppm to działa
myśleć o innych typach
np można wczytać ppm i zapisać jako tif
ogólnie obraz to wszystkie typy obrazów
kasowanie ob kasuje też ppm
*/