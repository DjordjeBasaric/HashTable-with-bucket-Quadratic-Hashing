#define _CRT_SECURE_NO_WARNINGS 1


#ifndef _HeshTable_h_
#define _HeshTable_h_
#define _CRT_SECURE_NO_WARININGS 1

#include <iostream>

using namespace std;

//enum status { DELETED, FULL, EMPTY };


class Tabela {

	struct Kljuc {
		int indeks;
		char* imePrezime;
		char* predmeti;
		char tip[7];
		Kljuc(int klj, char* inf1, char* inf2, char* t) {
			indeks = klj;
			imePrezime = inf1;
			predmeti = inf2;
			strcpy(tip, t);

		}

		Kljuc() {
			indeks = -1;
			imePrezime = nullptr;
			predmeti = nullptr;
			strcpy(tip, "EMPTY");

		};
	};
	int popunjenih = 0;
	Kljuc** kljucevi;
	int vel = 0;
	int bucket = 0;
	int konstanta;
public:

	Tabela(int vel1, int bucket1, int konstanta1) {
		vel = pow(2, vel1);
		konstanta = konstanta1;


		bucket = bucket1;
		kljucevi = new Kljuc * [vel];
		for (int i = 0; i < vel; i++) {
			kljucevi[i] = new Kljuc[bucket];
		}

	}

	void insertFile(){
		
		string c("students_1000.csv");
		FILE* podaci = fopen(c.c_str(), "r");
		int i = 0;
		int j = 0;
		char broj[8];
		char info[256];
		int brj = 0;
		string temp;
		
		while (!feof(podaci) || keyCount()<10000) {
			
			if (j>999) {
				break;
			}
			brj++;
			Kljuc P;
			char broj[8];
			char imePrezime[256];
			char predmeti[256];

			/*
			if (j == brbucket) {
				break;
			}
			*/
			char ch = getc(podaci);
			while (ch != ',') {
				broj[i] = ch;
				i++;
				ch = getc(podaci);
			}
			int x = atoi(broj);
			P.indeks = x;
			strcpy(P.tip, "FULL");


			ch = getc(podaci);
			i = 0;
			int spaces = 0;
			while (ch != ',') {
				
				info[i] = ch;
				i++;
				ch = getc(podaci);
			}
			info[i] = '\0';
			//j++;
			P.imePrezime = new char[sizeof(info)];
			int m;
			for (m = 0; m < sizeof(info) / sizeof(ch) - 1; m++) {
				P.imePrezime[m] = info[m];
			}
			P.imePrezime[m] = '\0';
			
			i = 0;
			//ch = getc(podaci);
			ch = getc(podaci);
			while (ch != '\n') {
				info[i] = ch;
				i++;
				ch = getc(podaci);
			}
			info[i] = '\0';
			//j++;
			P.predmeti = new char[sizeof(info)];
			//int m;
			for (m = 0; m < sizeof(info) / sizeof(ch) - 1; m++) {
				P.predmeti[m] = info[m];
			}
			P.predmeti[m] = '\0';

			
			
			
			if (popunjenih < vel * bucket) {
				insertKey(P);
			}
			else {
				printf("Tabela je popunjena");
				break;
			}
			i = 0;
			j++;
			
		}

		
		
	};

	bool insertPredmet(int ind, char* pred);

	bool deletePredmet(int ind, char* pred);
	
	bool deleteKey(int ind2);

	int getAddress(int ind1, int a, int i, int n);


	bool insertKey(Kljuc K);

	string findKey(int ind);

	void clear();

	int keyCount();

	double fillRatio();

	Kljuc napraviKljuc(int k1, char* inf1, char* inf2) {
		Kljuc K1;
		K1.indeks = k1;
		K1.imePrezime = inf1;
		K1.predmeti = inf2;
		strcpy(K1.tip, "FULL");
		return K1;

	}

	int tableSize() {
		return this->vel;
	};

	int getVel() {
		return vel*bucket;
	}

	
	void ispis();

	friend void operator<<(ostream& os, Tabela& T);


};




#endif