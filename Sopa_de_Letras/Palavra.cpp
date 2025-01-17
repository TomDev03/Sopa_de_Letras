#include "Palavra.h"

Palavra::Palavra() {
	this->orientacao = -1;
	this->estado = -1;
	this->pIni = Ponto(-1, -1);
}

Palavra::Palavra(string palavra, int orientacao, int estado, Ponto pIni) {
	this->palavra = palavra;
	this->orientacao = orientacao;
	this->estado = estado;
	this->pIni = pIni;
}

Palavra::~Palavra() {
}

void Palavra::setOrientacao(int orientacao) {
	this->orientacao = orientacao;
}

void Palavra::setEstado(int estado) {
	this->estado = estado;
}

void Palavra::setPonto(Ponto pIni) {
	this->pIni = pIni;
}

void Palavra::showPalavra() {
	for (size_t i = 0; i < this->size(); i++) {
		cout << this->getPalavra()[i];
	}
}

void Palavra::setPalavra(string str) {
	this->palavra = str;
}

string Palavra::pedirpalavra(size_t DimX, size_t DimY) {
	Ponto::gotoxy(0, (short)DimY + 4);
	cout << "Qual � a palavra que queres advinhar?                           ";
	Ponto::gotoxy(0, (short)DimY + 5);
	cout << "                                                                ";
	Ponto::gotoxy(0, (short)DimY + 6);
	cout << "                                                                ";
	Ponto::gotoxy(0, (short)DimY + 7);
	cout << "                                                                ";
	Ponto::gotoxy(0, (short)DimY + 8);
	cout << "                                                                ";
	Ponto::gotoxy(0, (short)DimY + 5);
	cout << "->";
	string pedir;
	getline(cin, pedir);
	if (Letra::getTipo_M_m() == 0) {
		transform(pedir.begin(), pedir.end(), pedir.begin(), ::toupper);
	}
	else {
		transform(pedir.begin(), pedir.end(), pedir.begin(), ::tolower);
	}
	return pedir;
}

void Palavra::CheckWordAccents(string& str) {
	string min = "������������������";
	string mai = "������������������";

	size_t strlen = str.length();
	int tipo = Letra::getTipo_M_m();
	for (size_t i = 0; i < strlen; i++) {
		if (tipo) {
			switch (min.find(str[i])) {
				case 0:
				case 1:
				case 2:
				case 3:{
					str[i] = 'a';
					break;
				}
				case 4:
				case 5:
				case 6:{
					str[i] = 'e';
					break;
				}
				case 7:
				case 8:
				case 9:{
					str[i] = 'i';
					break;
				}
				case 10:
				case 11:
				case 12:
				case 13:{
					str[i] = 'o';
					break;
				}
				case 14:
				case 15:
				case 16:{
					str[i] = 'u';
					break;
				}
				case 17:{
					str[i] = 'c';
					break;
				}
				default:
					break;
			}
		}
		else {
			switch (mai.find(str[i])) {
				case 0:
				case 1:
				case 2:
				case 3:
				{
					str[i] = 'A';
					break;
				}
				case 4:
				case 5:
				case 6:
				{
					str[i] = 'E';
					break;
				}
				case 7:
				case 8:
				case 9:
				{
					str[i] = 'I';
					break;
				}
				case 10:
				case 11:
				case 12:
				case 13:
				{
					str[i] = 'O';
					break;
				}
				case 14:
				case 15:
				case 16:
				{
					str[i] = 'U';
					break;
				}
				case 17:
				{
					str[i] = 'C';
					break;
				}
				default:
					break;
			}
		}
	}
}

size_t Palavra::size() {
	return (palavra.size());
}

bool Palavra::operator==(string str2) {
	return (this->getPalavra() == str2);
}

bool Palavra::operator<(Palavra str) {
	return (this->getPalavra() < str.getPalavra());
}

bool Palavra::operator>(Palavra str) {
	return (this->getPalavra() > str.getPalavra());
}

void Palavra::Save(ofstream& os) {
	os << getPalavra() << ";" << getOrientacao() << ";" << getEstado() << ";";
	getPonto().Save(os);
}

bool Palavra::Load(ifstream& is) {
	bool sms = 1;
	string p = "";
	getline(is, p, ';');
	setPalavra(p);
	getline(is, p, ';');
	if (is_numeric(p)) {
		setOrientacao(stoi(p));
		getline(is, p, ';');
		if (is_numeric(p)) {
			setEstado(stoi(p));
			if (pIni.Load(is));
			else
				sms = 0;
		}
		else
			sms = 0;
	}
	else
		sms = 0;
	return sms;
}
