#include "Letra.h"

int Letra::tipo_M_m{Letra::generateM_m()};

Letra::Letra() {
	this->letra = '-';
	this->ascii = -1;
	this->bold = -1;
	this->cor = -1;
}

Letra::Letra(char m_letra, Ponto m_ponto, int m_ascii, int bold, int cor) {
	this->letra = m_letra;
	this->ponto = m_ponto;
	this->ascii = m_ascii;
	this->bold = bold;
	this->cor = cor;
}

Letra::~Letra() {
}

void Letra::setLetra(char letra) {
	this->letra = letra;
}

void Letra::setPonto(Ponto ponto) {
	this->ponto = ponto;
}

void Letra::setAscii(int ascii) {
	this->ascii = ascii;
}

void Letra::setBold(int bold) {
	this->bold = bold;
}

void Letra::setCor(int cor) {
	this->cor = cor;
}

void Letra::setTipo_M_m(int ntipo_M_m) {
	Letra::tipo_M_m = ntipo_M_m;
}

int Letra::generateM_m() {
	srand((unsigned)time(nullptr));
	return (rand() % 2);
}

int Letra::verificaTipo(char c) {
	return (isupper(c)) ? 1 : (islower(c)) ? 0 : -1;
}

bool Letra::operator!=(char letra) {
	return (this->getLetra() != letra) ? true : false;
}

bool Letra::operator!=(Letra letra) {
	return (getLetra() != letra.getLetra()) ? true : false;
}
