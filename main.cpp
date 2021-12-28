#define _CRT_SECURE_NO_WARNINGS 1
#include "HeshTable.h"
#include <iostream>

using namespace std;

int main() {
	int m;
	int c;
	int b;
	char ime1[] = "ImePrezime Sifra predmeta";
	char ime2[] = "Nevena Janevski";
	char predmet[] = "13S111PPK 13S114MIPS 13S082NAD 13S061OF";
	char ime3[] = "Vladimir Zagorac";
	char predmet1[] = "13S114PP1";
	
	/*
	cout << "UNESITE VELICINU TABELE: ";
	cin >> m;
	cout << "UNESITE VELICINU BUCKET-a: ";
	cin >> b;
	cout << "UNESITE KONSTANTU C: ";
	cin >> c;
	*/
	//Tabela T(4,4,3);
	//Tabela K(6);
	//cout << T;
	//putchar('\n');

	//putchar('\n');
	//putchar('\n');
	//cout<<T.findKey(T.napraviKljuc(20080141, ime2, predmet));

	//if (T.deleteKey(T.napraviKljuc(20200150, ime3, predmet1))) {
	//	printf("\nUspesno");
	//}
	//else printf("\nNeuspesno");
	//putchar('\n');

	//putchar('\n');
	//putchar('\n');
	//cout << T;
	//cout << T.findKey(T.napraviKljuc(20200150, ime3, predmet1));
	////T.clear();
	////putchar('\n');

	////putchar('\n');
	////putchar('\n');
	////cout << T;
	//putchar('\n');

	//putchar('\n');
	//cout << T.fillRatio();
	//putchar('\n');
	//cout << T.keyCount();
	//putchar('\n');
	
	cout << "1. Formiraj tabelu\n";
	cout << "UNESITE VELICINU TABELE: ";
	cin >> m;
	cout << "UNESITE VELICINU BUCKET-a: ";
	cin >> b;
	cout << "UNESITE KONSTANTU C: ";
	cin >> c;
	Tabela T(m, b, c);
	//cout << T;
	//T.insertFile();
	//cout << T;
	
	while (true) {
		cout << "\nIzaberite opciju\n";
		cout << "1. Ubaci iz fajla\n";
		cout << "2. Nadji kljuc\n";
		cout << "3. Izbrisi kljuc\n";
		cout << "4. Ubaci kljuc\n";
		cout << "5. Izbrisi tabelu\n";
		cout << "6. Prebroj kljuceve\n";
		cout << "7. Velicina tabele\n";
		cout << "8. Popunjenost tabele\n";
		cout << "9. Ispis tabele\n";
		cout << "10. Ubaci predmet\n";
		cout << "11. Brisanje predmeta\n";
		cout << "\n0. Kraj programa\n";
		int opcija;
		cin >> opcija;
		switch (opcija) {
		case 1: {
			T.insertFile();
			break;
		}
		case 2: {
			int ind;
			cout << "Unesi broj indeksa: ";
			cin >> ind;
			cout << T.findKey(ind);
			break;
		}
		case 3: {
			int ind;
			cout << "Unesi broj indeksa: ";
			cin >> ind;
			cout << T.deleteKey(ind);
			break;
			
		}
		case 4: {
			int ind;
			cout << "Unesi broj indeksa: ";
			cin >> ind;
			cout << "\nUnesi ime: ";
			char ime[256];
			cin >> ime;
			cout << "\nUnesi predmete: ";
			char predmeti[256];
			cin >> predmeti;
			if (T.insertKey(T.napraviKljuc(ind, ime, predmeti)) == true) {
				cout << "\nUspesno ubacen kljuc\n";
			}
			else {
				cout << "\nNeuspesno ubacivanje\n";
			}
			break;
	
		}
		case 5: {
			T.clear();
			break;
		}
		case 6: {
			cout << "Broj kljuceva: " << T.keyCount();
			break;
		}
		case 7: {
			cout << "Velicina tabele: " << T.getVel();
			break;
		}
		case 8: {
			cout << "Popunjenost tabele: " << T.fillRatio();
			break;
		}
		case 9: {
			cout << T;
			break;
		}
		
		case 10: {
			int ind;
			char predmet[256];
			cout << "UNESITE INDEKS";
			cin >> ind;
			cout << "UNESITE PREDET";
			cin >> predmet;
			if (T.insertPredmet(ind, predmet) == true) { cout << "\nUspesno ubacen kljuc\n"; }
			else { cout << "\nNeuspesno ubacivanje\n"; }
			break;
		}
		case 11: {
			int ind;
			char predmet[256];
			cout << "UNESITE INDEKS";
			cin >> ind;
			cout << "UNESITE PREDET";
			cin >> predmet;
			if (T.deletePredmet(ind, predmet) == true) { cout << "\nUspesno izbrisan kljuc\n"; }
			else { cout << "\nNeuspesno brisanje predmeta\n"; }
			break;
		}
		case 0: {
			exit(0);
			break;
		}
		}
			
	}

	


}
//TREBAAA DOVOJITII IME PREZIMEE OD ISPITAA
//TREBAAA URADITI CLEAR CELEE TABELEEE



//41. 20170609 -> Pavle Lukic,
//66. 20200150 -> Vladimir Zagorac,13S114PP1 |
//26. 20080141 -> Nevena Janevski,13S111PPK 13S114MIPS 13S082NAD 13S061OF
//20180321	Andrea Tonic,13S052SIS 13S112OO1 13S082NAD
