

#include "pch.h"
#include <iostream>
#include <string>

using namespace std;

class Student {
private:
	const int codStudent;
	static int nrStudenti;
	int an;
	string nume;
	unsigned int nrmaterii;
	float* note;
	int codFacultate;
	bool taxa;
	static  int valoareTaxa;
public:
	void afisareStudent() {
		cout << "Student " << endl;
		cout << "Cod student: " << codStudent << endl;
		cout << "An: " << an << endl;
		cout << "Nume :" << nume << endl;
		cout << "Numar materii: " << nrmaterii << endl;
		for (int i = 0; i < nrmaterii; i++)
			cout << "Nota " << i + 1 << " este " << note[i] << endl;
		cout << "Cod faculate " << codFacultate << endl;
		if (taxa == 0)
			cout << "Studentul este la taxa ";
		else
			cout << "Studentul este la buget";
		cout << endl;
	}
	void citesteStudent()
	{
		cout << "Studentul cu codul : " << codStudent << endl;
		cout << "An: ";
		cin >> an;
		cout << "Nume: ";
		cin >> nume;
		cout << "Nr materii: ";
		cin >> nrmaterii;
		note = new float[nrmaterii];
		for (int i = 0; i < nrmaterii; i++)
		{
			cout << " Nota " << i + 1 << " este: ";
			cin >> note[i];
		}
		cout << "Cod facultate: ";
		cin >> codFacultate;
		cout << "0-Studentul este la buget /1-Nu este: ";
		cin >> taxa;
		if (taxa == true)
			cout << "Studentul este la taxa";
		else
			cout << "Studentul este la buget";

	}

	void initializareStudent(int an, string nume, unsigned int nrmaterii, float* note, int codF, bool t)
	{

		this->an = an;
		this->nume = nume;
		this->nrmaterii = nrmaterii;
		this->note = new float[nrmaterii];
		for (int i = 0; i < this->nrmaterii; i++)
			this->note[i] = note[i];
		this->codFacultate = codF;
		this->taxa = t;
	}
	Student() :codStudent(++nrStudenti)
	{

		this->an = -1;
		this->nume = "Anonim";
		this->nrmaterii = 0;
		this->note = NULL;
		this->codFacultate = -1;
		this->taxa = 0;
	}

	Student(int an, string nume, unsigned int nrmaterii, float* note, int codF, bool t) :codStudent(++nrStudenti)
	{

		this->an = an;
		this->nume = nume;
		this->nrmaterii = nrmaterii;
		this->note = new float[nrmaterii];
		for (int i = 0; i < this->nrmaterii; i++)
			this->note[i] = note[i];
		this->codFacultate = codF;
		this->taxa = t;
	}
	Student(int an, string nume, int codF) :codStudent(++nrStudenti)
	{

		this->an = an;
		this->nume = nume;
		this->nrmaterii = 0;
		this->note = NULL;
		this->codFacultate = codF;
		this->taxa = 0;
	}

	int getAn() {
		return an;
	}
	void setAn(int _an) {
		if (_an > 0)
			an = _an;

	}
	string getNume() {
		return nume;
	}
	void setNume(string _nume) {
		if (_nume.length() > 0)
			nume = _nume;
	}

	unsigned int getNrMaterii() {
		return nrmaterii;
	}

	void setNrMaterii(unsigned int nr) {
		if (nr > 0)
			nrmaterii = nr;

	}

	float* getNote() {
		return note;
	}

	float getNota(int index)
	{
		if (index >= 0 && index < nrmaterii)
		{
			return note[index];
		}
		else throw - 1;
	}

	void setNote(float* _note, int nr)
	{
		if (note != NULL)
			delete[]  note;
		note = new float[nr + 1];
		if (_note != NULL && nr > 0)
		{
			for (int i = 0; i < nr; i++)
				note[i] = _note[i];
		}
	}

	bool getTaxa()
	{
		return taxa;
	}
	void setTaxa(bool t) {
		taxa = t;
	}

	Student(const Student &s) :codStudent(++nrStudenti)
	{
		this->an = s.an;
		this->nume = s.nume;
		this->nrmaterii = s.nrmaterii;

		this->note = new float[s.nrmaterii + 1];
		for (int i = 0; i < s.nrmaterii; i++)
			this->note[i] = s.note[i];

		this->codFacultate = s.codFacultate;
		this->taxa = s.taxa;
	}




	Student& operator=(const Student &s) {
		this->an = s.an;
		this->nume = s.nume;
		this->nrmaterii = s.nrmaterii;

		this->note = new float[s.nrmaterii + 1];
		for (int i = 0; i < s.nrmaterii; i++)
			this->note[i] = s.note[i];

		this->codFacultate = s.codFacultate;
		this->taxa = s.taxa;
		return *this;
	}

	~Student() {
		if (this->note != NULL)
		{
			delete[] this->note;
		}
	}

	int getNrStudenti() {
		return nrStudenti;
	}

	bool operator==(int n) {
		if (this->an == n) {
			return 1;
		}
		else return 0;
	}

	bool operator!() {
		if (this->note != NULL) {
			return true;
		}
		else return false;
	}


	bool operator!=(int nr) {
		if (this->taxa != nr) return 0;
		else return 1;
	}

	float operator()() {
		float media = 0;
		if (this->note != NULL && this->nrmaterii > 0) {
			for (int i = 0; i < this->nrmaterii; i++)
				media = media + note[i];

		}
		media = media / nrmaterii;
		return media;
	}

	float& operator[](int index) {
		if (index >= 0 && index <= this->nrmaterii && this->note != NULL) {
			return this->note[index];
		}

	}

	Student operator++() {
		this->nrmaterii++;
		return *this;
	}

	Student operator++(int) {
		Student copie = *this;
		this->nrmaterii++;
		return copie;
	}

};

int Student::nrStudenti = 0;
int Student::valoareTaxa = 4000;
class Profesor {
private:
	const int IdProfesor;
	static int nrProfesori;
	static int nrMateriiPredate;
	char *nume;
	int codfac;
	bool doctor;
	int sCoordonatiLicenta;
	int cartiPublicate;
public:
	void afisareProfesor() {
		cout << "Profesorul: " << endl;
		cout << "Id: " << IdProfesor << endl;
		cout << "Nume: " << nume << endl;
		cout << "Cod facultate: " << codfac << endl;
		if (doctor == 0)
			cout << "Este prof. dr. univ. " << endl;
		else
			cout << "Este asist. univ. " << endl;
		cout << "Coordoneaza pentru licenta " << sCoordonatiLicenta << endl;
		cout << "Nr carti publicate: " << cartiPublicate << endl;
	}

	void citireProfesor() {
		cout << "Profesorul: " << endl;
		cout << "Nume: ";
		char temp[20];
		cin >> temp;
		nume = new char[strlen(temp) + 1];
		strcpy(nume, temp);
		cout << "Cod facultate: ";
		cin >> codfac;
		cout << "0-Este prof. dr. univ./1-Este asist. univ.";
		cin >> doctor;
		cout << "Nr studenti coordonati la licenta: ";
		cin >> sCoordonatiLicenta;
		cout << "Nr carti publicate: ";
		cin >> cartiPublicate;

	}

	void initializareProfesor(char* _nume, int _cod, bool _doctor, int coord, int carti)
	{
		this->nume = new char[strlen(_nume) + 1];
		strcpy(this->nume, _nume);
		this->codfac = _cod;
		this->doctor = _doctor;
		this->sCoordonatiLicenta = coord;
		this->cartiPublicate = carti;

	}

	void setNume(char* _nume) {
		if (_nume != NULL) {
			if (nume != NULL) {
				delete[] nume;
			}
			nume = new char[strlen(_nume) + 1];
			strcpy(nume, _nume);
		}
		else {
			throw - 1;
		}
	}

	char* getNume() {
		return nume;
	}

	void setCodFac(int codFac) {
		codfac = codFac;
	}

	int getCodFac() {
		return codfac;
	}

	void setDoctor(bool valoare) {
		doctor = valoare;
	}

	bool getDoctor() {
		return doctor;
	}

	void setsCoo(int nr) {
		sCoordonatiLicenta = nr;
	}

	int getsCoo() {
		return sCoordonatiLicenta;
	}

	void setCarti(int nr) {
		cartiPublicate = nr;
	}

	int getCarti() {
		return cartiPublicate;
	}


	Profesor() :IdProfesor(++nrProfesori) {
		this->nume = new char[strlen("Anonim") + 1];
		strcpy(this->nume, "Anonim");
		this->codfac = -1;
		this->doctor = true;
		this->sCoordonatiLicenta = -1;
		this->cartiPublicate = -1;

	}
	Profesor(char* _nume, int cod, bool _doctor, int sCoo, int carti) :IdProfesor(++nrProfesori) {
		this->nume = new char[strlen(_nume) + 1];
		strcpy(this->nume, _nume);
		this->codfac = cod;
		this->doctor = _doctor;
		this->sCoordonatiLicenta = sCoo;
		this->cartiPublicate = carti;

	}
	Profesor(char* _nume, int cod, bool _doctor) :IdProfesor(++nrProfesori) {
		this->nume = new char[strlen(_nume) + 1];
		strcpy(this->nume, _nume);
		this->codfac = cod;
		this->doctor = _doctor;
		this->sCoordonatiLicenta = -1;
		this->cartiPublicate = -1;

	}

	Profesor& operator=(const Profesor &p) {

		this->nume = new char[strlen(p.nume) + 1];
		strcpy(this->nume, p.nume);
		this->codfac = p.codfac;
		this->doctor = p.doctor;
		this->sCoordonatiLicenta = p.sCoordonatiLicenta;
		this->cartiPublicate = p.cartiPublicate;

		return *this;
	}

	Profesor(Profesor &p) :IdProfesor(nrProfesori++) {

		this->nume = new char[strlen(p.nume) + 1];
		strcpy(this->nume, p.nume);
		this->codfac = p.codfac;
		this->doctor = p.doctor;
		this->sCoordonatiLicenta = p.sCoordonatiLicenta;
		this->cartiPublicate = p.cartiPublicate;
	}


	Profesor operator++() {
		this->sCoordonatiLicenta++;
		return *this;
	}

	Profesor operator++(int) {
		Profesor copie = *this;
		copie.sCoordonatiLicenta++;
		return copie;
	}

	bool operator!=(Profesor p) {
		if (this->sCoordonatiLicenta != p.sCoordonatiLicenta) return 1;
		else return 0;
	}
	bool operator>(Profesor p) {
		if (this->sCoordonatiLicenta > p.sCoordonatiLicenta) return 1;
		else return 0;
	}
	operator int() {
		return this->IdProfesor;
	}

	bool operator!() {
		if (this->nume == NULL) {
			return 0;
		}
		else return 1;
	}

	Profesor operator-(int nr) {
		Profesor copie = *this;
		if (nr > 0)
		{
			copie.sCoordonatiLicenta = copie.sCoordonatiLicenta - nr;
		}
		return copie;
	}

	~Profesor() {
		if (this->nume != NULL)
			delete[] this->nume;
	}
};

int Profesor::nrProfesori = 0;
int Profesor::nrMateriiPredate = 3;

class Materie {
private:
	const int codMaterie;
	static int nrMaterii;
	static int credite;
	string denumire;
	int nrCursanti;
	float* noteStudenti;
	int anPredare;
	bool optional;

public:
	void afisareMaterie() {
		cout << "Materia:" << endl;
		cout << "Id: " << codMaterie << endl;
		cout << "Denumire: " << denumire << endl;
		cout << "Numar cursanti: " << nrCursanti << endl;
		for (int i = 0; i < nrCursanti; i++)
			cout << "Nota " << i + 1 << " este " << noteStudenti[i] << endl;
		cout << "Anul in care se preda: " << anPredare << endl;
		if (optional == 1)
			cout << "Materie optionala" << endl;
		else
			cout << "Materie obigatorie " << endl;
	}

	void citireMaterie() {
		cout << "Materia:" << endl;
		cout << "Denumire: ";
		cin >> denumire;
		cout << "Numar cursanti: ";
		cin >> nrCursanti;
		noteStudenti = new float[nrCursanti + 1];
		for (int i = 0; i < nrCursanti; i++)
		{
			cout << "Nota " << i + 1 << " este: ";
			cin >> noteStudenti[i];
		}
		cout << "Anul in care se preda: ";
		cin >> anPredare;
		cout << "1-Materie optionala/0-Materie obigatorie";
		cin >> optional;
	}

	void initializareMaterie(string _den, int nrc, float* note, int an, bool op) {
		this->denumire = _den;
		this->nrCursanti = nrc;
		this->noteStudenti = new float[nrc + 1];
		for (int i = 0; i < nrc; i++) {
			this->noteStudenti[i] = note[i];

		}
		this->anPredare = an;
		this->optional = op;
	}

	void setDenumire(string den) {
		denumire = den;
	}

	string getDenumire() {
		return denumire;
	}

	void setNrCursanti(int nr) {
		if (nr > 0)
			nrCursanti = nr;
	}

	int getNrCursanti() {
		return nrCursanti;
	}

	void setNoteStudenti(float* n, int nr) {
		if (noteStudenti != NULL)
			delete[] noteStudenti;
		noteStudenti = new float[nr];
		for (int i = 0; i < nr; i++)
			noteStudenti[i] = n[i];

	}

	float getNota(int index) {
		if (index >= 0 && index < nrCursanti)
		{
			return noteStudenti[index];
		}
	}

	void setAn(int an) {
		anPredare = an;
	}

	int getAn() {
		return anPredare;
	}

	void setOptional(bool o) {
		optional = o;

	}

	bool getOptional() {
		return optional;
	}
	Materie() :codMaterie(++nrMaterii) {
		this->denumire = "Anonim";
		this->nrCursanti = 0;
		this->noteStudenti = NULL;
		this->anPredare = -1;
		this->optional = true;
	}

	Materie(string _den, int nrc, float* note, int an, bool op) :codMaterie(++nrMaterii) {
		this->denumire = _den;
		this->nrCursanti = nrc;
		this->noteStudenti = new float[nrc + 1];
		for (int i = 0; i < nrc; i++) {
			this->noteStudenti[i] = note[i];

		}
		this->anPredare = an;
		this->optional = op;
	}

	Materie(string _den, int an, bool op) :codMaterie(++nrMaterii) {
		this->denumire = _den;
		this->nrCursanti = 0;
		this->noteStudenti = NULL;
		this->anPredare = an;
		this->optional = op;
	}
	Materie(Materie& m) :codMaterie(++nrMaterii) {
		this->denumire = m.denumire;
		this->nrCursanti = m.nrCursanti;
		this->noteStudenti = new float[m.nrCursanti + 1];
		for (int i = 0; i < m.nrCursanti; i++) {
			this->noteStudenti[i] = m.noteStudenti[i];

		}
		this->anPredare = m.anPredare;
		this->optional = m.optional;


	}

	Materie& operator=(const Materie& m) {
		this->denumire = m.denumire;
		this->nrCursanti = m.nrCursanti;
		this->noteStudenti = new float[m.nrCursanti + 1];
		for (int i = 0; i < m.nrCursanti; i++) {
			this->noteStudenti[i] = m.noteStudenti[i];

		}
		this->anPredare = m.anPredare;
		this->optional = m.optional;
		return *this;

	}
	~Materie() {
		if (noteStudenti != NULL)
			delete[] noteStudenti;
	}

	Materie operator++() {
		this->nrCursanti++;
		return *this;
	}
	Materie operator++(int) {
		Materie copie = *this;
		copie.nrCursanti++;
		return copie;
	}

	float operator[](int index) {
		if (index >= 0 && index < this->nrCursanti) {
			return this->noteStudenti[index];
		}
	}

	Materie operator+=(Materie m) {
		this->optional = m.optional;
		return *this;
	}

	Materie operator-(int nr) {
		Materie copie = *this;
		if (nr > 0)
			copie.nrCursanti = nr - nrCursanti;
		return copie;
	}

	float operator()() {
		float media = 0;
		if (this->nrCursanti > 0 && this->noteStudenti != NULL)
			for (int i = 0; i < this->nrCursanti; i++)
				media = media + noteStudenti[i];
		media = media / nrCursanti;
		return media;
	}

	bool operator!=(Materie m) {
		if (this->anPredare = m.anPredare) return 1;
		else return 0;
	}

};

int Materie::nrMaterii = 0;
int Materie::credite = 5;


class Facultate {
private:
	const int idFacultate;
	static int nrSpecializari;
	static int nrFacultati;
	char *denumire;
	int nrSInmatriculati;
	float suprafata;
	int nrSali;
	bool programId;
public:

	void afisareFacultate() {
		cout << "Facultate: " << endl;
		cout << "Id: " << idFacultate << endl;
		cout << "Denumire: " << denumire << endl;
		cout << "Nr de studenti inmatriculati: " << nrSInmatriculati << endl;
		cout << "Suprafata: " << suprafata << endl;
		cout << "Nr sali: " << nrSali << endl;
		if (programId == false)
			cout << "Facultatea are program de invatamant la distanta";
		else cout << "Facultatea nu are program de invatamant la distanta";
		cout << endl;
	}

	void citireFacultate() {
		cout << "Facultate: " << endl;
		cout << "Denumire: ";
		char den[40];
		cin >> den;
		denumire = new char[strlen(den) + 1];
		strcpy(denumire, den);
		cout << "Numar de studenti inmatriculati: ";
		cin >> nrSInmatriculati;
		cout << "Suprafata: ";
		cin >> suprafata;
		cout << "Numar sali: ";
		cin >> nrSali;
		cout << "0- Are program de invatamant la distanta/1-Nu are program de invatamant la distanta";
		cin >> programId;
	}

	void initializareFacultate(char *_denumire, int nrs, float _suprafata, int nrsali, bool p) {

		this->denumire = new char[strlen(_denumire) + 1];
		strcpy(denumire, _denumire);
		this->nrSInmatriculati = nrs;
		this->suprafata = _suprafata;
		this->nrSali = nrsali;
		this->programId = p;

	}

	void setDenumire(char * den) {
		if (den != NULL)
		{
			if (denumire != NULL)
				delete[] denumire;
			denumire = new char[strlen(den) + 1];
			strcpy(denumire, den);
		}
		else throw - 1;
	}

	char* getDenumire() {
		return denumire;
	}

	void setNrSInmatriculati(int nr) {
		if (nr > 0) {
			nrSInmatriculati = nr;
		}
		else throw - 1;
	}

	int getNrSInmatriculati() {
		return nrSInmatriculati;
	}

	void setSuprafata(float nr) {
		if (nr > 0)
		{
			suprafata = nr;
		}
	}

	float getSuprafata() {
		return suprafata;
	}

	void setNrSali(int nr) {
		if (nr > 0)
			nrSali = nr;
	}

	int getNrSali() {
		return nrSali;
	}

	void setProgram(bool p) {
		programId = p;
	}
	bool getProgram() {
		return programId;
	}
	Facultate() :idFacultate(++nrFacultati)
	{
		this->denumire = new char[strlen("Anonim") + 1];
		strcpy(denumire, "Anonim");
		this->nrSInmatriculati = -1;
		this->suprafata = -1;
		this->nrSali = 0;
		this->programId = true;
	}
	Facultate(char *_denumire, int nrs, float _suprafata, int nrsali, bool p) :idFacultate(++nrFacultati)
	{
		this->denumire = new char[strlen(_denumire) + 1];
		strcpy(denumire, _denumire);
		this->nrSInmatriculati = nrs;
		this->suprafata = _suprafata;
		this->nrSali = nrsali;
		this->programId = p;
	}
	Facultate(char *_denumire, int nrs, float _suprafata) :idFacultate(++nrFacultati)
	{
		this->denumire = new char[strlen(_denumire) + 1];
		strcpy(denumire, _denumire);
		this->nrSInmatriculati = nrs;
		this->suprafata = _suprafata;
		this->nrSali = 0;
		this->programId = true;
	}

	Facultate operator=(const Facultate &f) {
		this->denumire = new char[strlen(f.denumire) + 1];
		strcpy(denumire, f.denumire);
		this->nrSInmatriculati = f.nrSInmatriculati;
		this->suprafata = f.suprafata;
		this->nrSali = f.nrSali;
		this->programId = f.programId;
		return *this;
	}
	Facultate(Facultate &f) :idFacultate(++nrFacultati) {
		this->denumire = new char[strlen(f.denumire) + 1];
		strcpy(denumire, f.denumire);
		this->nrSInmatriculati = f.nrSInmatriculati;
		this->suprafata = f.suprafata;
		this->nrSali = f.nrSali;
		this->programId = f.programId;

	}

	~Facultate() {
		if (denumire != NULL) {
			delete[] this->denumire;
		}
	}

	Facultate operator+=(Facultate f) {
		this->suprafata += f.suprafata;
		return *this;
	}

	bool operator==(Facultate f) {
		if (this->idFacultate == f.idFacultate) return 1;
		else return 0;
	}
	operator int() {
		return this->idFacultate;
	}
	bool  operator>(Facultate f) {
		if (this->suprafata > f.suprafata) return 1;
		else return 0;
	}

	bool  operator<(Facultate f) {
		if (this->suprafata < f.suprafata) return 1;
		else return 0;
	}
};

int Facultate::nrSpecializari = 3;
int Facultate::nrFacultati = 0;

Facultate operator+(Facultate f, int nr) {
	Facultate rezultat = f;
	rezultat.setNrSInmatriculati(rezultat.getNrSInmatriculati() + nr);
	return rezultat;
}
Facultate operator+(int nr, Facultate f) {
	Facultate rezultat = f;
	rezultat.setNrSInmatriculati(rezultat.getNrSInmatriculati() + nr);
	return rezultat;
}

class Biblioteca {
private:
	const int IdBiblioteca;
	static int nrBiblioteci;
	static int nrCarti;
	string adresa;
	int nrAngajati;
	char* denumire;
	int nrVizitatori;
	float suprafata;
public:
	void afisareBiblioteca() {
		cout << "Biblioteca: ";
		cout << "Id: " << IdBiblioteca << endl;
		cout << "Nr carti " << nrCarti << endl;
		cout << "Adresa: " << adresa << endl;
		cout << "Numar angajati " << nrAngajati << endl;
		cout << "Denumire: " << denumire << endl;
		cout << "Numar vizitatori: " << nrVizitatori << endl;
		cout << "Suprafata " << suprafata << endl;
		cout << endl;
	}

	void citireBiblioteca() {
		cout << "Biblioteca: " << endl;
		cout << "Adresa: ";
		cin >> adresa;
		cout << "Numar angajati ";
		cin >> nrAngajati;
		cout << "Denumire: ";
		char temp[20];
		cin >> temp;
		denumire = new char[strlen(temp) + 1];
		strcpy(denumire, temp);
		cout << "Numar vizitatori: ";
		cin >> nrVizitatori;
		cout << "Suprafata ";
		cin >> suprafata;
	}

	void initializareBiblioteca(string adr, int nr, char* den, int nv, float s) {
		this->adresa = adr;
		this->nrAngajati = nr;
		this->denumire = new char[strlen(den) + 1];
		strcpy(this->denumire, den);
		this->nrVizitatori = nv;
		this->suprafata = s;

	}

	void setAdresa(string a) {
		adresa = a;
	}

	string getAdresa() {
		return adresa;
	}

	void setNrAngajati(int nr) {
		if (nr > 0) {
			nrAngajati = nr;
		}
	}

	int getNrAngajati() {
		return nrAngajati;
	}

	void setDen(char* d) {
		if (denumire != NULL)
			delete[] denumire;
		denumire = new char[strlen(d) + 1];
		strcpy(denumire, d);

	}
	char* getDen() {
		return denumire;
	}
	void setNrVizitatori(int nr) {
		if (nr > 0)
			nrVizitatori = nr;
	}

	int getNrVizitatori() {
		return nrVizitatori;
	}

	void setSup(float s) {
		suprafata = s;
	}

	float getSup() {
		return suprafata;
	}
	Biblioteca() :IdBiblioteca(++nrBiblioteci) {
		this->adresa = "Anonim";
		this->nrAngajati = 0;
		this->denumire = new char[strlen("Anonim") + 1];
		strcpy(this->denumire, "Anonim");
		this->nrVizitatori = 0;
		this->suprafata = 0;
	}

	Biblioteca(string adr, int nr, char* den, int nv, float s) :IdBiblioteca(++nrBiblioteci) {
		this->adresa = adr;
		this->nrAngajati = nr;
		this->denumire = new char[strlen(den) + 1];
		strcpy(this->denumire, den);
		this->nrVizitatori = nv;
		this->suprafata = s;
	}

	Biblioteca(string adr, float s) :IdBiblioteca(++nrBiblioteci) {
		this->adresa = adr;
		this->nrAngajati = 0;
		this->denumire = new char[strlen("Anonim") + 1];
		strcpy(this->denumire, "Anonim");
		this->nrVizitatori = 0;
		this->suprafata = s;
	}

	Biblioteca(Biblioteca& b) :IdBiblioteca(++nrBiblioteci) {
		this->adresa = b.adresa;
		this->nrAngajati = b.nrAngajati;
		this->denumire = new char[strlen(b.denumire) + 1];
		strcpy(this->denumire, b.denumire);
		this->nrVizitatori = b.nrVizitatori;
		this->suprafata = b.suprafata;
	}

	Biblioteca& operator=(const Biblioteca& b) {
		this->adresa = b.adresa;
		this->nrAngajati = b.nrAngajati;
		this->denumire = new char[strlen(b.denumire) + 1];
		strcpy(this->denumire, b.denumire);
		this->nrVizitatori = b.nrVizitatori;
		this->suprafata = b.suprafata;
		return *this;
	}
	~Biblioteca()
	{
		if (denumire != NULL)
			delete[] denumire;
	}

	Biblioteca operator++() {
		this->nrAngajati++;
		return *this;
	}

	Biblioteca operator++(int) {
		Biblioteca copie = *this;
		this->nrAngajati++;
		return copie;
	}

	bool operator==(Biblioteca b) {
		if (strcmp(this->denumire, b.denumire) == 0) return true;
		else return false;
	}

	Biblioteca operator+=(Biblioteca b) {
		this->nrVizitatori += b.nrVizitatori;
		return *this;
	}

	operator int() {
		return this->IdBiblioteca;
	}

	Biblioteca operator-(float nr) {
		Biblioteca copie = *this;
		if (nr > 0)
			copie.suprafata -= nr;
		return copie;
	}


};
Biblioteca operator+(Biblioteca b, int nr) {
	Biblioteca rezultat = b;
	b.setNrVizitatori(b.getNrVizitatori() + nr);
	return rezultat;
}

int Biblioteca::nrBiblioteci = 0;
int Biblioteca::nrCarti = 1000;
void main()
{
	cout << "Testare clasa student: " << endl;
	Student s1, s2, s3;
	//s1.initializareStudent(2, "Ion", 3, new float[3]{ 2,4,5 }, 34, 0);
	s1.setNrMaterii(2);
	cout << "Nr materii: " << s1.getNrMaterii() << endl;
	s1.setAn(3);
	s1.setNume("Alex Popescu");
	s1.setNote(new float[2]{ 4,6 }, 2);
	cout << "Nota de pe pozitia 1 este: " << s1.getNota(1) << endl;
	s3 = s1;
	s1.afisareStudent();
	s3.afisareStudent();

	cout << "Anul este: " << s1.getAn() << endl;
	/*s2.citesteStudent();
	s2.afisareStudent();*/
	cout << "Nr de studenti " << s1.getNrStudenti() << endl;
	Student s4(2, "Ion", 3, new float[3]{ 2,4,5 }, 34, 0);
	s4.afisareStudent();
	Student s5(3, "Geanina", 50);
	s5.afisareStudent();

	// pointer la obiect
	Student* s6 = new Student();
	s6->afisareStudent();

	//vector de obiecte
	Student *studenti;
	studenti = new Student[2];
	studenti[0].setAn(1);
	studenti[1].setAn(2);
	cout << studenti[0].getAn() << endl;
	cout << studenti[1].getAn() << endl;


	//vector de pointeri la obiecte
	Student** vectorpointeri = new Student*[2];
	for (int i = 0; i < 2; i++)
		vectorpointeri[i] = new Student();
	vectorpointeri[1]->setAn(5);
	cout << vectorpointeri[1]->getAn();
	cout << endl;


	if (!s5 == 1) cout << "Studentul are note " << endl;
	else cout << "Studentul nu are note" << endl;

	if (s1.getAn() == 3) cout << "Studentul este in an terminal " << endl;
	else cout << "Studnetul nu este in an terminal" << endl;

	if (s1 != 4000) cout << "Studentul a fost inmatriculat in 2017 " << endl;
	else cout << "Studentul a fost inmatriculat in 2018" << endl;

	float media = s4();
	cout << "Media pentru studentul " << s4.getNume() << " este " << media << endl;
	cout << "A doua nota a studentului cu id-ul 4 este " << s4[2] << endl;

	s5 = s3++;
	cout << "Studentul are " << s5.getNrMaterii() << " materii" << endl;

	s5 = ++s3;
	cout << "Studentul are " << s5.getNrMaterii() << " materii" << endl;


	cout << "Testare clasa Profesor: " << endl;
	Profesor p1;
	char* nume;
	nume = new char[strlen("Ion") + 1];
	strcpy(nume, "Ion");
	p1.initializareProfesor(nume, 23, true, 12, 4);
	p1.afisareProfesor();

	/*Profesor p2;
	p2.citireProfesor();
	p2.afisareProfesor();*/

	Profesor p3;
	char *_nume;
	_nume = new char[strlen("Popescu ") + 1];
	strcpy(_nume, "Popescu");
	p3.setNume(_nume);
	cout << "Numele este: " << p3.getNume() << endl;
	p3.setCodFac(23);
	cout << "Codul facultatii: " << p3.getCodFac() << endl;
	p3.setDoctor(true);
	if (p3.getDoctor() == true) {
		cout << "Este prof. dr. univ. ";

	}
	else {
		cout << "Este asist.univ";
	}
	cout << endl;
	p3.setsCoo(17);
	cout << "Coordoneaza pentru licenta: " << p3.getsCoo() << " elevi" << endl;
	p3.setCarti(10);
	cout << "Numar de carti publicate: " << p3.getCarti() << endl;

	Profesor p4;
	p4.afisareProfesor();
	Profesor p5(nume, 45, true, 7, 9);
	p5.afisareProfesor();
	Profesor p6(nume, 67, false);
	p6.afisareProfesor();

	//pointer la obiect
	Profesor *p7 = new Profesor();
	p7->afisareProfesor();

	//vector de obiecte
	Profesor *profesori;
	profesori = new Profesor[2];
	profesori[0].setCodFac(45);
	profesori[1].setCodFac(56);
	for (int i = 0; i < 2; i++)
		cout << "Profesorul " << i + 1 << " preda la facultatea cu codul " << profesori[i].getCodFac() << endl;

	//vectori de pointeri la obiecte

	/*Profesor ** profesorii = new Profesor*[2];
	for (int i = 0; i < 2; i++) {
		profesorii[i] = new  Profesor();
	}
	profesorii[1]->setCarti(6);
	cout << "Profesorul 1 a publicat " << profesorii[1]->getCarti() << " carti " << endl;*/

	Profesor p8 = p3;
	p8.afisareProfesor();


	int idp = p4;
	cout << "Id-ul este " << idp << endl;
	if (p1 != p4)
		cout << "Profesorii coordoneaza un numar diferit de studenti " << endl;
	else cout << "Profesorii coordoneaza acelasi numar de studenti" << endl;
	p1 = p5++;
	cout << "Primul profesor coordoneaza pentru licenta " << p1.getsCoo() << " studenti" << endl;
	p1 = ++p5;
	cout << "Primul profesor coordoneaza pentru licenta " << p1.getsCoo() << " studenti" << endl;
	if (p1 > p4)
		cout << "Primul profesor coordoneaza mai multi studenti " << endl;
	else cout << "Primul profesor coordoneaza mai putini studenti" << endl;
	if (!p1)
		cout << "Profesorul  are un nume alocat" << endl;
	else
		cout << "Profesorul nu are un nume alocat" << endl;
	p5 = p1 - 2;
	cout << "Profesorul 5 coordoneaza " << p5.getsCoo() << endl;



	cout << "Testare clasa Materie: " << endl;
	Materie m1;
	m1.initializareMaterie("POO", 2, new float[2]{ 9,10 }, 2, false);
	m1.afisareMaterie();

	/*Materie m2;
	m2.citireMaterie();
	m2.afisareMaterie();*/

	Materie m3;
	m3.setDenumire("DAM");
	cout << "Denumirea este: " << m3.getDenumire() << endl;
	m3.setNrCursanti(2);
	cout << "Nr cursanti " << m3.getNrCursanti() << endl;
	m3.setNoteStudenti(new float[2]{ 10,8 }, 2);
	for (int i = 0; i < 2; i++)
		cout << "Nota 1" << " este " << m3.getNota(1) << endl;
	m3.setAn(3);
	cout << "Anul in care se preda " << m3.getAn() << endl;
	m3.setOptional(false);
	if (m3.getOptional() == 1)
		cout << "Materie optionala" << endl;
	else
		cout << "Materie obigatorie " << endl;

	Materie m4;
	m4.afisareMaterie();

	Materie m5("Demografie", 3, new float[3]{ 9,10,8 }, 3, true);
	m5.afisareMaterie();

	Materie m6("SDD", 2, false);
	m6.afisareMaterie();


	Materie m7 = m6;
	m7.afisareMaterie();

	m5 = m3;
	m5.afisareMaterie();

	//pointer la obiect
	Materie *m8 = new Materie();
	m8->afisareMaterie();

	//vector de obiecte
	Materie *materie;
	materie = new Materie[2];
	materie[0].setAn(3);
	materie[1].setAn(2);
	for (int i = 0; i < 2; i++)
		cout << "Materia " << i + 1 << " se preda in anul " << materie[i].getAn() << endl;

	//vectori de pointeri la obiecte

	Materie ** materii = new Materie*[2];
	for (int i = 0; i < 2; i++) {
		materii[i] = new  Materie();
	}
	materii[1]->setDenumire("ATP");
	cout << "Materia 1 se numeste " << materii[1]->getDenumire() << endl;

	m1 = ++m1;
	cout << "Numarul de cursanti este " << m1.getNrCursanti() << endl;
	m1 = m1++;
	cout << "Numarul de cursanti este " << m1.getNrCursanti() << endl;
	cout << "Prima nota este: " << m1[1] << endl;

	m4 += m5;
	if (m4.getOptional() == 0)
		cout << "Materie 4 este optionala " << endl;
	else
		cout << "Materie 4 nu este optionala " << endl;
	m5 = m6 - 1;
	cout << "Nr studenti este: " << m5.getNrCursanti() << endl;
	float mg = m3();
	cout << "Media este: " << mg << endl;
	if (m5 != m6)
		cout << "Materiile nu se predau in acelasi an" << endl;
	else cout << "Materiile se predau in acelasi an" << endl;


	cout << "Testare clasa Facultate: " << endl;
	char* denumire;
	denumire = new char[strlen("CSIE") + 1];
	strcpy(denumire, "CSIE");
	Facultate f1;
	f1.initializareFacultate(denumire, 300, 378, 40, true);
	f1.afisareFacultate();

	/*Facultate f2;
	f2.citireFacultate();
	f2.afisareFacultate();*/


	Facultate f3;
	f3.setDenumire(denumire);
	cout << "Denumirea facultatii este :" << f3.getDenumire() << endl;
	f3.setNrSInmatriculati(500);
	cout << "Numarul de studenti inmatriculati este: " << f3.getNrSInmatriculati() << endl;
	f3.setSuprafata(145.8);
	cout << "Suprafata este de :" << f3.getSuprafata() << endl;
	f3.setNrSali(39);
	cout << "Numarul de sali este: " << f3.getNrSali() << endl;
	f3.setProgram(false);
	if (f3.getProgram() == false)
		cout << "Facultatea are program de invatamant la distanta";
	else cout << "Facultatea nu are program de invatamant la distanta";
	cout << endl;

	Facultate f4;
	f4.afisareFacultate();

	Facultate f5(denumire, 390, 356.9, 20, false);
	f5.afisareFacultate();

	Facultate f6(denumire, 190, 500);
	f6.afisareFacultate();

	Facultate f7 = f6;
	f7.afisareFacultate();

	f5 = f7;
	f5.afisareFacultate();

	//pointer la obiect
	Facultate *f8 = new Facultate();
	f8->afisareFacultate();

	//vector de obiecte

	Facultate *facultati;
	facultati = new Facultate[2];
	facultati[0].setNrSali(68);
	cout << "Facultatea are " << facultati[0].getNrSali() << " sali";

	//vectori de pointeri la obiecte
	Facultate **facultatii = new Facultate*[2];
	for (int i = 0; i < 2; i++)
		facultatii[i] = new Facultate();
	facultatii[1]->setNrSali(100);
	cout << "Facultatea are " << facultatii[1]->getNrSali() << " sali" << endl;
	f4 = f1 + 200;
	cout << "Facultatea 4 are " << f4.getNrSInmatriculati() << " studenti inmatriculati" << endl;
	f4 = 200 + f1;
	cout << "Facultatea 4 are " << f4.getNrSInmatriculati() << " studenti inmatriculati" << endl;
	f1 += f3;
	cout << "Suprafata facultatii 1 este " << f1.getSuprafata() << endl;
	if ((f5 == f6) == 1)
		cout << "Fcaultatile au acelasi id" << endl;
	else
		cout << "Faculatile nu au acelasi id" << endl;
	int idFaculatate = f4;
	cout << "Codul este " << idFaculatate << endl;
	if ((f5 > f6) == 1)
		cout << "Facultatea f5 are suprafata mai mare decat f6" << endl;
	else
		cout << "Facultatea f5 are suprafata mai mica decat f6" << endl;
	if ((f5 < f6) == 1)
		cout << "Facultatea f5 are suprafata mai mare decat f6" << endl;
	else
		cout << "Facultatea f5 are suprafata mai mica decat f6" << endl;


	cout << "Testare clasa Biblioteca: " << endl;
	char *d;
	d = new char[strlen("Biblioteca Nationala") + 1];
	strcpy(d, "Biblioteca Nationala");
	Biblioteca b1;
	b1.initializareBiblioteca("Piata Romana", 5, d, 100, 350);
	b1.afisareBiblioteca();

	/*Biblioteca b2;
	b2.citireBiblioteca();
	b2.afisareBiblioteca();*/

	Biblioteca b3;
	b3.setAdresa("Bulevardul Unirii ");
	cout << "Adresa este: " << b3.getAdresa() << endl;
	b3.setDen(d);
	cout << "Denumirea este " << b3.getDen() << endl;
	b3.setNrAngajati(10);
	cout << "Numar angajati " << b3.getNrAngajati() << endl;
	b3.setNrVizitatori(300);
	cout << "Numar vizitatori " << b3.getNrVizitatori() << endl;
	b3.setSup(400);
	cout << "Suprafata este de " << b3.getSup() << endl;

	Biblioteca b4;
	b4.afisareBiblioteca();

	Biblioteca b5("Piata Romana", 5, d, 100, 350.6F);
	b5.afisareBiblioteca();

	Biblioteca b6("Universitate ", 560);
	b6.afisareBiblioteca();

	Biblioteca b7 = b6;
	b7.afisareBiblioteca();

	b5 = b4;
	b5.afisareBiblioteca();

	//pointer la obiect
	Biblioteca *b8 = new Biblioteca();
	b8->afisareBiblioteca();

	//vector de obiecte
	Biblioteca *biblioteca;
	biblioteca = new Biblioteca[2];
	biblioteca[0].setSup(390);
	biblioteca[1].setSup(289);
	for (int i = 0; i < 2; i++)
		cout << "Biblioteca" << i + 1 << " are suprafata " << biblioteca[i].getSup() << endl;

	//vectori de pointeri la obiecte

	Biblioteca ** biblioteci = new Biblioteca*[2];
	for (int i = 0; i < 2; i++) {
		biblioteci[i] = new  Biblioteca();
	}
	biblioteci[1]->setAdresa("Bulevardul Lascar Catargiu");
	cout << "Biblioteca 1 este situata " << biblioteci[1]->getAdresa() << endl;

	b1 = ++b3;
	cout << "Noul numar de angajati de la biblioteca cu id-ul 1 este de : " << b1.getNrAngajati() << endl;

	b3 = b1++;
	cout << "Noul numar de angajati de la biblioteca cu id-ul 3 este de : " << b3.getNrAngajati() << endl;
	if (b1 == b3) cout << "Bibliotecile au aceasi denumire " << endl;
	else cout << "Bibliotecile nu au aceasi denumire " << endl;


	b3 += b4;
	cout << "Biblioteca cu id-ul 3 are un numar de vziitatori pe zi de " << b3.getNrVizitatori() << " persoane" << endl;

	int id = b5;
	cout << "Cast id " << id << endl;

	b4 = b6 - 10.45F;
	cout << "Suprafata ramane de " << b4.getSup() << endl;

	b1 += b3;
	cout << "Noul numar de vizitatori este de " << b1.getNrVizitatori() << endl;

}

