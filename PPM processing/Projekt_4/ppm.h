//*******************
//
// ppm
//
//  Klasa pozwalaj�ca na wczytanie z pliku obrazu formatu ppm
//
// Autor: 
// Kamil Kr�cichwost 03 grudzie�
//
// Autor:						Descp.																Dnia:
// Kamil Kr�cichwost			Wersja Beta klasy -> do sprawdzenia przez Dr. Hab. Kowalczyka		03.12.2018
//
//*******************

#ifndef _PPM_
#define _PPM_

#include "obraz.h"

class ppm : public Obraz
{
public:
	// Konstruktory (klasa nie potrzebuje operatora = b�d� konstr kopy poniewa� nie posiada
	// w�asnych p�l
	ppm();
	~ppm();
	ppm(const char *name); 


private:
};

#endif // !_PPM_

