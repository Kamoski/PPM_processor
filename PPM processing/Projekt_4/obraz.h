//*******************
//
// obraz
//
// Klasa pozwalaj¹ca na wyliczenie liczby unikalnych kolorów z obrazów jednego formatu
//
// Autor: 
// Kamil Krêcichwost 03 grudzieñ
//
// Autor:						Descp.																Dnia:
// Kamil Krêcichwost			Wersja Beta klasy -> do sprawdzenia przez Dr. Hab. Kowalczyka		03.12.2018
//
//*******************
#ifndef _OBRAZ_
#define _OBRAZ_

class ppm;

class Obraz
{
public:
	//Konstuktory
	Obraz();
	Obraz(Obraz & copy);
	Obraz(const char * plikName);

	//Destr
	virtual ~Obraz();

	//Metody
	int uniqueColors();
	
	//Settery
	void setFileName(char* name);
	void setBufferSize(int size);

	//Gettery
	char* getFileName();
	int getBufferSize();
protected:
	char *fileName;
	int bufferSize;
};

#endif // !_OBRAZ_
