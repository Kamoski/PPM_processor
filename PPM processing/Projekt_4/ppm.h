//*******************
//
// ppm
//
//  Klasa pozwalaj¹ca na wczytanie z pliku obrazu formatu ppm
//
// Autor: 
// Kamil Krêcichwost 03 grudzieñ
//
// Autor:						Descp.																Dnia:
// Kamil Krêcichwost			Wersja Beta klasy -> do sprawdzenia przez Dr. Hab. Kowalczyka		03.12.2018
//
//*******************

#ifndef _PPM_
#define _PPM_

#include "obraz.h"

class ppm : public Obraz
{
public:
	// Konstruktory (klasa nie potrzebuje operatora = b¹dŸ konstr kopy poniewa¿ nie posiada
	// w³asnych pól
	ppm();
	~ppm();
	ppm(const char *name); 


private:
};

#endif // !_PPM_

