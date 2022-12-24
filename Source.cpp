#include <iostream>
#include <clocale>
#include <string>
#include <sstream>
#include <fstream>
#include <stdexcept>
#include <Windows.h>
using namespace std;

void yükleniyor() {

	system("CLS");
	for (int i = 0; i < 15; i++)
	{
		for (int j = 0; j < i; j++)
		{
			cout << " ";
		}
		cout << "-->";

		system("CLS");

	}
}

class Film {

private:
	string film1;
	string film2;
	string film3;
	string mesage;

public:
	Film() {
		film1 = "PREDESTINATION";
		film2 = "AVATAR 2";
		film3 = "THE BATMAN";
		mesage = "  ";
	}

	Film(string film1, string film2, string film3, string mesage) {
		this->film1 = film1;
		this->film2 = film2;
		this->film3 = film3;
		this->mesage = mesage;
	}
	~Film() {
		cout << " " << endl;
	}

	friend void mesaj(Film mesaj);
	friend class Yazdir;
};


void mesaj(Film mesaj) {
	cout << mesaj.mesage << endl;
}


class Yazdir {
public:
	static void showInfos(Film filmbilgi) {
		cout << endl;
		cout << " -----------------------------" << endl;
		cout << "<<< VÝZYONDAKÝ FÝLMLER >>>" << endl;
		cout << " -----------------------------" << endl;
		cout << filmbilgi.film1 << endl;
		cout << filmbilgi.film2 << endl;
		cout << filmbilgi.film3 << endl;

	}

};


class UcretSaat : public Yazdir {
private:
	int ucretfilm;
	int saat;



public:
	UcretSaat(int ucretfilm, double saat) {
		this->ucretfilm = ucretfilm;
		this->saat = saat;
	}

	friend class Yazdir2;

};


class Yazdir2 {
public:
	static void showInf(UcretSaat ucretBilgi) {
		cout << "<<< BÝLET FÝYAT LÝSTESÝ>>>" << endl;
		cout << " -----------------------------------------------------------------" << endl;
		cout << "   1 ->\t PREDESTINATION  - \t " << ucretBilgi.ucretfilm << " TL" << endl;
		cout << "   2 ->\t AVATAR 2: \t - \t " << ucretBilgi.ucretfilm << " TL" << endl;
		cout << "   3 ->\t THE BATMAN: \t - \t " << ucretBilgi.ucretfilm << " TL" << endl;
		cout << " -----------------------------------------------------------------" << endl;
	}

};

int bilet_ucret;
class Musteri {
private:
	int toplamBiletSayisi;

public:
	int biletSayisi;

	int al;
	string* bilet;

	Musteri() {}

	Musteri(int toplamBiletSayisi, int bilet_ucret) {
		this->toplamBiletSayisi = toplamBiletSayisi;



		biletSayisi = 0;
		bilet = new string[toplamBiletSayisi];
		for (int i = 0; i < toplamBiletSayisi; i++) {
			bilet[i] = "";
		}
	}


	void biletArtir() {
		biletSayisi++;
	}

	void koltukSay() {
		cout << "Toplam Koltuk Sayýsý : " << toplamBiletSayisi << endl;
		int bosBiletSayisi = toplamBiletSayisi - biletSayisi;
		cout << "Dolu Koltuk Sayýsý : " << biletSayisi << endl;
		cout << "Boþ Koltuk Sayýsý: " << bosBiletSayisi << endl;
	};


	void biletSatýnAl(int koltukNo, string adSoyad) {
		if (koltukNo <= toplamBiletSayisi) {
			if (bilet[koltukNo - 1] == "") {
				bilet[koltukNo - 1] = adSoyad;
				biletArtir();
			}
			else {
				cout << "Bu Koltuk Dolu." << endl;
			}
		}
		else {
			cout << toplamBiletSayisi << " Koltuk Bulunmaktadýr..." << endl;
		}

	}

	void biletSatým() {

		cout << endl;
		Film film(" 1 -)PREDESTINATION", " 2 -)AVATAR 2", " 3 -)THE BATMAN", "ÝYÝ SEYÝRLER DÝLERÝZ!!!");


		UcretSaat ucret(50, 19.30);
		ucret.showInfos(film);
		mesaj(film);
		cout << endl << endl;
		Yazdir2::showInf(ucret);

		cout << endl << endl;
		int filmsec;
		do {

			cout << " Film Seçiniz -> : " << endl;
			cin >> filmsec;


		} while (filmsec > 3 || filmsec < 0);


		double saat;
		cout << "Saat Seçiniz :  " << endl;
		cin >> saat;


		while (saat < 7 || saat > 24) {

			cout << "O saatlerde seansýmýz yoktur ..." << endl;
			cout << "Lütfen Geçerli Saat Giriniz : " << endl;
			cin >> saat;

		}

		int kapasite = 20;
		do {
			cout << " ~~ Kaç Bilet Almak Ýstiyorsunuz :  ";
			cin >> al;

		} while (al >= 21 || al <= 0);

		bilet_ucret = 50 * al;



		Musteri musteri(kapasite, al);
		cout << endl;
		cout << "Koltuk Durumlarý " << endl;
		musteri.biletSatýnAl(1, "DOLU");
		musteri.biletSatýnAl(13, "DOLU");
		musteri.biletSatýnAl(7, "DOLU");
		musteri.biletSatýnAl(9, "DOLU");
		musteri.biletSatýnAl(15, "DOLU");
		musteri.biletSatýnAl(4, "DOLU");

		musteri.biletListele();
		musteri.koltukSay();


		for (int i = 1; i <= al; i++) {

			cout << endl;
			int koltuksec = 1;
			cout << "Koltuk Seçiniz : ";


			cin >> koltuksec;
			string isimGir;
			cout << "Ýsim Giriniz: ";
			cin >> isimGir;

			musteri.biletSatýnAl(koltuksec, isimGir);

			cout << endl << endl;

		}
	}

	void biletListele() {
		for (int i = 0; i < toplamBiletSayisi; i++) {
			cout << i + 1 << ". Koltuk : " << bilet[i] << endl;
		}
	}

};

class LinkedList
{
	friend class Film;
	friend class Musteri;

private:
	struct Node
	{
		int data;
		Node* next;
	};
	Node* head;

public:
	LinkedList()
	{
		head = nullptr;

	}

	void append(int data)
	{
		if (head == nullptr)
		{
			head = new Node{ data, nullptr };
		}
		else
		{
			Node* temp = head;
			while (temp->next != nullptr)
			{
				temp = temp->next;
			}
			temp->next = new Node{ data, nullptr };
		}
	}

	int print()
	{
		int count = 0;

		Node* temp = head;
		while (temp != nullptr)
		{

			count += temp->data;
			temp = temp->next;
		}

		return count;
	}
};

string text = "";
void receipt(string a) {
	text = text + a;
	cout << text;
	cout << " " << endl;
}


class Snack {
protected:
	string name;
	int price;
	LinkedList l;
public:
	int sum = 0;
	Snack(string name1, int price1) {
		name = name1;
		price = price1;
	}
	virtual void list() = 0;
	virtual void order() = 0;
	virtual string deliver() = 0;

	int printList() {
		return l.print();
	}

	~Snack() {}
};

class Popcorn :public Snack {

public:
	Popcorn() :Snack("", 0) {

	}
	void order();
	void list();
	string deliver();
	~Popcorn() {}
};

void Popcorn::order() {
	int n;
	cout << " ~ Seçim Yapýnýz : " << endl;
	cin >> n;
	switch (n) {
	case 1:
		name = "Kucuk Boy Patlamis Misir";
		price = 10;
		sum += price;
		l.append(price);
		break;
	case 2:
		name = "Orta Boy Patlamis Misir";
		price = 16;
		sum += price;
		l.append(price);
		break;
	case 3:
		name = "Buyuk Boy Patlamis Misir";
		price = 24;
		sum += price;
		l.append(price);
		break;
	default:
		cout << "Gecersiz Deger." << endl;

	}
}
void Popcorn::list() {
	cout << " \t~~ ATISTIRMALIK MENU ~~ " << endl;
	cout << "-------------------------------------------------" << endl;
	cout << " 1 -> Kucuk Boy Patlamis Misir\t - 10 TL" << endl;
	cout << " 2 -> Orta Boy Patlamis Misir\t - 16 TL" << endl;
	cout << " 3 -> Buyuk Boy Patlamis Misir\t - 24 TL" << endl;
	cout << "-------------------------------------------------" << endl;
}
string Popcorn::deliver() {
	stringstream ss;
	ss << price;
	string str = ss.str();
	cout << name << " " << str << " TL  Siparisinize Eklendi." << endl;
	return name + "  " + str + " TL\n";
}

class Drink :public Snack {

public:
	Drink() :Snack(" ", 0) {

	}
	void order();
	void list();
	string deliver();
	~Drink() {}
};
void Drink::order() {
	int n;
	cout << " ~ Seçim Yapýnýz : " << endl;
	cin >> n;
	switch (n) {
	case 1:
		name = "Kola";
		price = 10;
		sum += price;
		l.append(price);
		break;
	case 2:
		name = "Fanta";
		price = 9;
		sum += price;
		l.append(price);
		break;
	case 3:
		name = "Gazoz";
		price = 8;
		sum += price;
		l.append(price);
		break;
	default:
		cout << " Hatalý Seçim !!!  " << endl;
		cin >> n;

	}
}
void Drink::list() {
	cout << "\t ~~ ICECEK MENU ~~ " << endl;
	cout << "-------------------------------------------------" << endl;
	cout << " 1 -> Kola  \t -  10tl" << endl;
	cout << " 2 -> Fanta \t -  9tl" << endl;
	cout << " 3 -> Gazoz \t -  8tl" << endl;
	cout << "-------------------------------------------------" << endl;
}
string Drink::deliver() {
	stringstream ss;
	ss << price;
	string str = ss.str();
	cout << name << " " << str << " TL Sipariþinize Eklendi." << endl;
	return name + "  " + str + " TL\n";
}


void orderM(Popcorn a, Drink d) {
	int n = 3;
	while (n != 0) {
		cout << "1-Patlamis Misir." << endl;
		cout << "2-Icecek." << endl;
		cout << "0-Siparis Bitir." << endl;
		cout << "Siparis Vericeginiz Urunu Seciniz." << endl;

		cin >> n;
		switch (n) {
		case 1:
			a.list();
			a.order();
			receipt(a.deliver());
			break;
		case 2:
			d.list();
			d.order();
			receipt(d.deliver());
			break;
		case 0:

			cout << "Toplam Atistirmalik Tutari: " << (a.printList() + d.printList()) << " TL";
			d.printList();
			break;
		default:
			cout << "Tekrar Giriniz : " << endl;
			cin >> n;
		}
	}

};

class Fatura : public Musteri {
public:
	friend class Musteri;
	friend class Popcorn;
	friend class Drink;
	friend class Snack;

	Popcorn p;
	Drink d;
	Musteri m;


	int bilet_tutar;
	int snack_tutar;
	int kdv_tutar;
	double kdv_oran = 1.18;

	Fatura() {
		bilet_tutar = 0;
		snack_tutar = 0;
		kdv_tutar = 0;
	}

	Fatura(int bilet_tutar, int snack_tutar, int kdv_tutar) {
		this->bilet_tutar = bilet_tutar;
		this->snack_tutar = (p.sum) + (d.sum);
		this->kdv_tutar = (bilet_tutar + snack_tutar) * kdv_oran;
	}

	~Fatura() {

	}


	void faturaYazdýr(int d_price, int s_price) {


		cout << "==========================================================" << endl;
		cout << endl;
		cout << "\t ~~  Hesap Tutar Bilgileri  ~~ " << endl;
		cout << endl;
		cout << " ~~ \t Atistirmalik Tutari : \t" << s_price << " TL" << endl << endl;
		cout << " ~~ \t Icecek Tutari : \t" << d_price << " TL" << endl << endl;
		cout << " ~~ \t Bilet Tutari : \t" << bilet_ucret << " TL " << endl << endl;
		cout << " ~~ \t KDV Oraný : \t\t" << (s_price + d_price + bilet_ucret) * (kdv_oran)-(s_price + d_price + bilet_ucret) << " TL " << endl << endl;
		cout << " ~~ \t Toplam Tutar : \t" << (s_price + d_price + bilet_ucret) * (kdv_oran) << " TL " << endl << endl;
		cout << "==========================================================" << endl;


		ofstream fatura("fatura.txt");
		fatura << " ~~ Atistirmalik Tutari : " << s_price << " TL" << endl;
		fatura << " ~~ Icecek Tutari : " << d_price << " TL" << endl;
		fatura << " ~~ Bilet Tutari : " << bilet_ucret << " TL " << endl;
		fatura << "KDV Oraný : " << (s_price + d_price + bilet_ucret) * (kdv_oran)-(s_price + d_price + bilet_ucret) << endl;
		fatura << "Toplam Ödenecek Tutar : " << (s_price + d_price + bilet_ucret) * (kdv_oran) << " TL " << endl;
		fatura.close();



		/*	string metin;
		ifstream fatura1("fatura.txt");
		while (getline(fatura1, metin)) {
			cout << metin;
		}*/

	}
};

class girisArayuz {
public:
	friend class Musteri; friend class Film; friend class LinkedList; friend class Popcorn; friend class Drink; friend class Fatura;

	Musteri m;
	Fatura f;
	Popcorn p;
	Drink d;
	string otoname;
	girisArayuz() {
		otoname = "SINEOTO";
	}
	~girisArayuz() {

	}

	void welcome() {

		cout << endl;
		cout << " ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ " << endl;
		cout << " -   SINEOTO OTOMASYON SISTEMINE HOSGELDINIZ   - " << endl;
		cout << " ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ " << endl;
		cout << endl;

	}

	void giris() {
		yükleniyor();

		int islem;

		cout << endl << endl;
		cout << "=============================================" << endl;
		cout << " 1 - Bilet Satýn Alma Menüsü" << endl;
		cout << " 2 - Atýþtýrmalýk Satýn Alma Menüsü" << endl;
		cout << " 3 - Icecek Satýn Alma Menüsü" << endl;
		cout << " 4 - Hesap Odeme Menüsü " << endl;
		cout << "=============================================" << endl;

		cout << "" << endl << endl;
		cout << " Hangi iþlemi yapmak istersiniz : " << endl;
		cin >> islem;

		switch (islem) {
		case 1:
			cout << " Bilet satýn alma menüsüne yönlendiriliyorsunuz ..." << endl;
			m.biletSatým();
			giris();
			break;
		case 2:
			cout << " Atýþtýrmalýk satýn alma menüsüne yönlendiriliyorsunuz ..." << endl << endl;
			p.list();
			p.order();
			p.deliver();
			giris();

			break;
		case 3:
			cout << " Icecek satýn alma menüsüne yönlendiriliyorsunuz ..." << endl << endl;
			d.list();
			d.order();
			d.deliver();
			giris();
		case 4:
			cout << " Hesap Odeme menüsüne yönlendiriliyorsunuz ..." << endl;
			int dprice;
			dprice = d.printList();
			int sprice;
			sprice = p.printList();
			f.faturaYazdýr(dprice, sprice);
			break;
		default:
			cout << " Hatalý Giriþ !!! Lütfen Geçerli Bir Sayý Giriniz..." << endl;


			break;

		}
	}

};


void puanlama() {
	cout << " Hizmetimizi Deðerlendirmek Ýster Misiniz ?" << endl;
	cout << " 1 - Evet " << endl;
	cout << " 2 - Hayýr " << endl;
	int cvp;
	cin >> cvp;
	int puan;


	if (cvp == 1) {

		cout << " Hizmetimizi Puanlayýn (0 - 5) : ";
		cin >> puan;
		try {
			if (puan < 0 || puan > 5) {
				throw invalid_argument("");
			}
		}
		catch (invalid_argument& e) {
			cout << " Hatalý Girdiniz !!! " << endl;
		}
	}
	else {
		cout << " Hoþçakalýn..." << endl;
	}

}


int main()
{
	setlocale(LC_ALL, "Turkish");
	system("color 70");

	girisArayuz giris;

	giris.welcome();
	Sleep(2000);
	giris.giris();


	puanlama();

}