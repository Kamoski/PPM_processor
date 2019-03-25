//*******************
//
// obraz
//
// Klasa pozwalaj�ca na wyliczenie liczby unikalnych kolor�w z obraz�w jednego formatu
//
// Autor: 
// Kamil Kr�cichwost 03 grudzie�
//
// Autor:						Descp.																Dnia:
// Kamil Kr�cichwost			Wersja Beta klasy -> do sprawdzenia przez Dr. Hab. Kowalczyka		03.12.2018
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
