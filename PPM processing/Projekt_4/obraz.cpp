#include "obraz.h"
#include "ppm.h"
#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
#include <set>

bool check(int i, int j) {
	return (i == j);
}

Obraz::Obraz() : bufferSize(0)
{
	fileName = new char[0];
}


Obraz::~Obraz()
{
	delete[]fileName;

}

int Obraz::uniqueColors()
{

	auto start = std::chrono::system_clock::now();

	std::ifstream file(fileName, std::ios::in);
	
		std::string text;
		file.seekg(0, std::ios::end);
		text.resize(file.tellg());
		file.seekg(0, std::ios::beg);
		file.read(&text[0], text.size());
	//	printf(&text[0]);

		char *tab = new char[text.length() + 1];
		strcpy_s(tab,text.length() + 1, text.c_str());
	
		int iterator = 0;
		bool FileTypeSet = false;
		bool MainCommentSet = false;
		bool wAndHSet = false;
		bool HeaderDone = false;
		int cols, rows;
		int range;
		
		// binarnie zoperowaæ

		while (HeaderDone != true) {

			if ( (tab[iterator] == '\n') && (FileTypeSet == false)) {
				while (tab[iterator] == '\n') {
					iterator++;
				}
			}
			if ( (tab[iterator] != '\n') && (FileTypeSet == false) ) {
				printf("Plik typu: ");
				for (iterator; tab[iterator] != '\n'; iterator++) {
					printf("%c", tab[iterator]);
				}
				FileTypeSet = true;
				iterator++;
				printf("\n");
			}

			if ( (tab[iterator] == '\n' ) && (MainCommentSet == false)) {
				while (tab[iterator] == '\n') {
					iterator++;
				}
			}

			if ((tab[iterator] != '\n') && (MainCommentSet == false)) {
				printf("Komentarz z pliku: ");
				for (iterator; tab[iterator] != '\n'; iterator++) {
					printf("%c", tab[iterator]);
				} 
				MainCommentSet = true;
				iterator++;
				printf("\n");
			}

			if ((tab[iterator] == '\n') && (wAndHSet == false)) {
				while (tab[iterator] == '\n') {
					iterator++;
				}
			}

			if ((tab[iterator] != '\n') && (wAndHSet == false)) {
				int temp = iterator;
				while (tab[temp] != ' ') {
					temp++;
				}
				char *temporary = new char[temp + 1];
				temp = 0;
				for (iterator; tab[iterator] != ' '; iterator++) {
					temporary[temp] = tab[iterator];
					temp++;
				}
				iterator++;

				cols = atoi(temporary);
				delete[]temporary;

				temp = iterator;
				while ( (tab[temp] != '\n') && (tab[temp] != ' ') ) {
					temp++;
				}
				temporary = new char[temp + 1];
				temp = 0;
				for (iterator; (tab[iterator] != ' ') && (tab[iterator] != '\n'); iterator++) {
					temporary[temp] = tab[iterator];
					temp++;
				}
				iterator++;

				rows = atoi(temporary);
				delete[]temporary;

				wAndHSet = true;
			}

			while ((tab[iterator] == ' ') || (tab[iterator] == '\n')) {
				iterator++;
			}

			int temp = iterator;
			while ((tab[temp] != '\n') && (tab[temp] != ' ')) {
				temp++;
			}
			char *temporary = new char[temp + 1];
			temp = 0;
			for (iterator; (tab[iterator] != ' ') && (tab[iterator] != '\n'); iterator++) {
				temporary[temp] = tab[iterator];
				temp++;
			}
			iterator++;

			range = atoi(temporary);
			delete[]temporary;

			HeaderDone = true;
		}

			int ***colors = new int **[cols];
		for (int i = 0; i < cols; i++) {
			colors[i] = new int *[rows];
		}

		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < rows; j++) {
				colors[i][j] = new int[3];
			}
		}

		int checker = 0;
			for (int i = 0; i < cols; i++) {
				for (int j = 0; j < rows; j++) {
					for (int k = 0; k < 3; k++) {
						
					
					while ((tab[iterator + checker] != ' ') && (tab[iterator + checker] != '\n')) {
						checker++;
					}
						

						if (checker == 3) {
							colors[i][j][k] = (tab[iterator] - '0') * 100;
							colors[i][j][k] += (tab[iterator+1] - '0') * 10;
							colors[i][j][k] += (tab[iterator+2] - '0') * 1;
							iterator += 3;
						}
						else if (checker == 2) {
							colors[i][j][k] = (tab[iterator] - '0') * 10;
							colors[i][j][k] += (tab[iterator+1] - '0') * 1;
							iterator += 2;
						}
						else if (checker == 1) {
							colors[i][j][k] = (tab[iterator] - '0') * 1;
							iterator++;
						}
						while ((tab[iterator] == '\n') || (tab[iterator] == ' ')) {
							iterator++;
						}
						checker = 0;
					}
				}
			}
			
			int *nums = new int[cols*rows + 1];

			for (int i = 0; i < cols*rows; i++) {
				nums[i] = 0;
			}
			int iter = 0; 
			for (int i = 0; i < cols; i++) {
				for (int j = 0; j < rows; j++) {
					for (int k = 0; k < 3; k++) {

						if (k == 2) {
							nums[iter] += (colors[i][j][k] * 256 * 256);
						}
						else if (k == 1) {
							nums[iter] += (colors[i][j][k] * 256);
						}
						else if (k == 0) {
							nums[iter] += (colors[i][j][k] * 1);
						}

					}
					iter++;
				}
			}

			std::set<int> second(nums, nums + (cols*rows));

	auto end = std::chrono::system_clock::now();
	std::chrono::duration<double> diff = end - start;
	std::cout << diff.count();

	return second.size();
}

void Obraz::setFileName(char* name)
{
	fileName = name;
}

void Obraz::setBufferSize(int size)
{
	bufferSize = size;
}

char * Obraz::getFileName()
{
	return fileName;
}

int Obraz::getBufferSize()
{
	return bufferSize;
}

Obraz::Obraz(Obraz & copy)
{
	this->fileName = new char[bufferSize + 1];
	this->bufferSize = copy.bufferSize;

	for (int i = 0; i < bufferSize; i++) {
		fileName[i] = copy.fileName[i];
	}
}

Obraz::Obraz(const char * plikName)
{
	delete[]fileName;
	int iterator = 0;
	while (plikName[iterator] != '\0') {
		iterator++;
	}
	iterator++;
	bufferSize = iterator;
	fileName = new char[bufferSize];

	for (int i = 0; i < bufferSize; i++) {
		fileName[i] = plikName[i];
	}
}
