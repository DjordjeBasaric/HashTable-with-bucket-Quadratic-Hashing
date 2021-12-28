#define _CRT_SECURE_NO_WARNINGS 1
#include "HeshTable.h"
#include "QuadriaticHashing.h"


//#include<iostream>
#include<fstream>
#include <stdio.h>
#include <string>
#include <iomanip>
#include <cstring>

//using namespace std;


bool Tabela::deleteKey(int ind2) {
	int i = 0;
	int j;
	j = ind2 % (vel);
	for (i = 0; i < bucket; i++) {
		if (kljucevi[j][i].indeks == ind2 && strcmp(kljucevi[j][i].tip, "FULL") == 0) {
				strcpy(kljucevi[j][i].tip, "DELETED");
				return true;
		}
	}
	i = 1;
	int h = getAddress(ind2, j, i, vel);
	if (h == -1) {
		string info5;
		info5 = "Ne postoji taj kljuc";
		return false;

	}
	for (i = 0; i < bucket; i++) {
		if (kljucevi[h][i].indeks == ind2 && strcmp(kljucevi[h][i].tip, "FULL") == 0) {
				strcpy(kljucevi[h][i].tip, "DELETED");
				return true;
			
		}
	}
	cout<< "Ne postoji takav kljuc";
	return false;
}

int Tabela::getAddress(int ind1, int a, int i, int n) {
	int c;
	int j1=-1;
	int br = 0;
	
	while (i<=vel*bucket) {
		j1 = ((a)+konstanta * int(pow(i, 2))) % vel;
		for (br = 0; br < bucket; br++) {
			if (strcmp(kljucevi[j1][br].tip, "EMPTY") == 0)	return j1;
			if (kljucevi[j1][br].indeks == ind1 && strcmp(kljucevi[j1][i].tip, "FULL")) {
				return j1;
			}
			
		}
		i++;
	}
	return -1;
}

bool Tabela::insertPredmet(int ind, char* pred) {
	int i = 0;
	int j;
	j = ind % (vel);
	for (i = 0; i < bucket; i++) {
		if (kljucevi[j][i].indeks == ind && strcmp(kljucevi[j][i].tip, "FULL") == 0) {
			strcat(kljucevi[j][i].predmeti, " ");
			strcat(kljucevi[j][i].predmeti, pred);
			return true;
		}
	}
	i = 1;
	int h = getAddress(ind, j, i, vel);
	if (h == -1) {
		string info5;
		info5 = "Ne postoji taj kljuc";
		return false;

	}
	for (i = 0; i < bucket; i++) {
		if (kljucevi[h][i].indeks == ind && strcmp(kljucevi[h][i].tip, "FULL") == 0) {
			strcat(kljucevi[h][i].predmeti, " ");
			strcat(kljucevi[h][i].predmeti, pred);
			return true;

		}
	}
	cout << "Ne postoji takav kljuc";
	return false;
}

bool Tabela::deletePredmet(int ind, char* pred) {
	int i = 0;
	int j;
	int cc;
	j = ind % (vel);
	for (i = 0; i < bucket; i++) {
		if (kljucevi[j][i].indeks == ind && strcmp(kljucevi[j][i].tip, "FULL") == 0) {
			int velpredm = strlen(kljucevi[j][i].predmeti);
			int veluno = strlen(pred);
			int q = 0;
			int t = 0;
			char space = ' ';
			if (veluno > velpredm) {
				return false;
			}
			for (int p = 0; p < velpredm;) {
				cc = 0;
				int brojacslova = 0;
				t = p;
				int pocetak = p;
				while (kljucevi[j][i].predmeti[t] != space) {
					brojacslova++;
					t++;
				}
				if (veluno == brojacslova) {
					for (q = 0; q < veluno; q++, p++) {
						if (kljucevi[j][i].predmeti[p] == pred[q]) {
							cc++;
						}
					}
					int kraj = p;
					if (cc == veluno) {
						char* strtemp = new char[velpredm-(pocetak+veluno)];
						for (int v = 0; v < velpredm - (pocetak + veluno); v++) {
							strtemp[v] = kljucevi[j][i].predmeti[kraj];
							kraj++;
						}
						memmove(kljucevi[j][i].predmeti+pocetak,"", kraj);
						strcat(kljucevi[j][i].predmeti, strtemp);
						cout << "\nNasaoooooooooooooooooooooooooo\n";
						return true;
					}
					p++;
				}
				else p += brojacslova+1;
			}			
		}
	}
	i = 1;
	int h = getAddress(ind, j, i, vel);
	if (h == -1) {
		string info5;
		info5 = "Ne postoji taj kljuc";
		return false;

	}


	for (i = 0; i < bucket; i++) {
		if (kljucevi[h][i].indeks == ind && strcmp(kljucevi[h][i].tip, "FULL") == 0) {
			int velpredm = sizeof(kljucevi[h][i].predmeti);
			int veluno = sizeof(pred);
			int q = 0;
			if (veluno > velpredm) {
				return false;
			}
			for (int p = 0; p < velpredm; p++) {
				cc = 0;
				for (q = 0; q < veluno; q++) {
					if (kljucevi[h][i].predmeti[q] == pred[q]) {
						cc++;
					}
					else break;
				}
				q++;
				
			}
			if (cc == veluno) {
				cout << "\nNasaoooooooooooooooooooooooooo\n";
				return true;
			}
			else return false;
		}
	}
	cout << "Ne postoji takav kljuc";
	return false;
}

char* izbrisiDeo(string &pred, int beg, int end)
{
	pred.erase(pred.begin() + beg, pred.begin() + end);
	const int n = pred.length();
	char* pred1 = new char[n + 1];
	strcpy(pred1, pred.c_str());
	return pred1;
}

char* pretvoriuchar(string str) {
	const int n = str.length();
	char* str1 = new char[n + 1];
	strcpy(str1, str.c_str());
	return str1;
}

bool Tabela::insertKey(Kljuc P) {
	int i = 0;
	int j;
	j = P.indeks % (vel);
	if (popunjenih > vel * bucket) {
		cout << "popunjena";
		return false;
	}
	for (i = 0; i < bucket; i++) {
		if (strcmp(kljucevi[j][i].tip, "EMPTY") == 0) {
			kljucevi[j][i] = P;
			popunjenih++;
			return true;
		}
		
		else if (strcmp(kljucevi[j][i].imePrezime, P.imePrezime) == 0 && strcmp(kljucevi[j][i].predmeti, P.predmeti) == 0) {
			cout << "Ovaj kljuc vec postoji";
			return false;
		}
	}
	int h=j;
	i = 1;
	h = getAddress(P.indeks, h, i, vel);
	
	if (h == -1) { 
		//printf("HES TABELA POPUNJENA\n");
		return false; 
	}

	for (i = 0; i < bucket; i++) {
		
		if (strcmp(kljucevi[h][i].tip, "EMPTY") == 0) {
			kljucevi[h][i] = P;
			popunjenih++;
			return true;
		}
	   	
		if (strcmp(kljucevi[h][i].imePrezime, P.imePrezime) == 0 && strcmp(kljucevi[h][i].predmeti, P.predmeti) == 0) {
			return false;
		}
	}
}

string Tabela::findKey(int ind) {
	int i = 0;
	int j;
	j = ind % (vel);
	for (i = 0; i < bucket; i++) {
		if (kljucevi[j][i].indeks == ind && strcmp(kljucevi[j][i].tip, "FULL") == 0) {
				string info5;
				string a = kljucevi[j][i].imePrezime;
				string b = kljucevi[j][i].predmeti;
				info5 = a + ", " + b;
				return info5;
			
		}
	}
	i = 1;
	int h = getAddress(ind, j, i, vel);
	if (h == -1) {
		string info5;
		info5 = "Ne postoji taj kljuc";
		return info5;

	}
	for (i = 0; i < bucket; i++) {
		if (kljucevi[h][i].indeks == ind && strcmp(kljucevi[h][i].tip, "FULL") == 0) {
				string info5;
				string a = kljucevi[h][i].imePrezime;
				string b = kljucevi[h][i].predmeti;
				info5 = a + ", " + b;
				return info5;
			
		}
	}
	return "Ne postoji takav kljuc";
}

void Tabela::clear(){
	int brojac = 0, i;
	for (i = 0; i < vel; i++) {
		for (int j = 0; j < bucket; j++) {
			kljucevi[i][j].imePrezime = nullptr;
			kljucevi[i][j].predmeti = nullptr;
			kljucevi[i][j].indeks = -1;
			strcpy(kljucevi[i][j].tip, "EMPTY");
			
		}
	}
	popunjenih = 0;
	
}

int Tabela::keyCount() {
	int brojac=0, i;
	for (i = 0; i < vel; i++) {
		for(int j=0;j<bucket;j++)
			if (strcmp(kljucevi[i][j].tip, "FULL") == 0) {
			brojac++;
		}
	}
	return brojac;
}

double Tabela::fillRatio() {
	int brojac=0, i;
	for (i = 0; i < vel; i++) {
		for (int j = 0; j < bucket; j++)
			if (strcmp(kljucevi[i][j].tip,"FULL")==0) {
				brojac++;
			}
	}
	if (brojac == 0) {
		return 0.0;
	}
	double k = (double)brojac/ (vel * bucket);
	return k;
}

void Tabela::ispis(){
	int i;
	int j;
	int br1 = 0;
	int br2 = 0;
	int brojac = 0;
	for (i = 0; i < vel; i++) {
		cout << brojac << ". ";
		for (j = 0; j < bucket; j++) {
			
			if (strcmp(kljucevi[i][j].tip, "FULL") == 0) {
			
				//cout << kljucevi[i][j].indeks << " -> " << kljucevi[i][j].imePrezime<<", "<<kljucevi[i][j].predmeti <<" | ";
				cout<< setw(10) << kljucevi[i][j].indeks;
				br1++;

			}
			if (strcmp(kljucevi[i][j].tip, "DELETED") == 0) {
				cout<<setw(10) << "DELETED";

			}
			if (strcmp(kljucevi[i][j].tip, "EMPTY") == 0) {
				cout<<setw(10) << "EMPTY";

			}
			
			
		}

		brojac++;
		cout << endl;
	}
	putchar('\n');
	putchar('\n');
	putchar('\n');
	/*
	printf("OVOLIKOOO IMAAA ELEMENATA %d", bucket*brojac); putchar('\n');

	printf("OVOLIKOOO JE POPUNJENOOO %d:", br1); putchar('\n');

	printf("OVOLIKOOO JE OSTALOO %d: ", brojac*bucket-br1); putchar('\n');
	*/
	putchar('\n');
	putchar('\n');
	putchar('\n');
	putchar('\n');

	brojac = 0;
	for (i = 0; i < vel; i++) {
		//cout << brojac;
		for (j = 0; j < bucket; j++) {
			if (strcmp(kljucevi[i][j].tip, "FULL") == 0) {
				//cout << kljucevi[i].indeks << endl;
				cout << brojac <<". " << kljucevi[i][j].indeks << " -> " << kljucevi[i][j].imePrezime << ", " << kljucevi[i][j].predmeti;
			}
			if (strcmp(kljucevi[i][j].tip, "DELETED") == 0) {
				cout << brojac << ". " << "DELETED";

			}
			if (strcmp(kljucevi[i][j].tip, "EMPTY") == 0) {
				cout << brojac << ". " << "EMPTY";

			}
			cout << endl;
			brojac++;
		}
		
	}



}

void operator<<(ostream& os, Tabela& T) {
	T.ispis();
};
