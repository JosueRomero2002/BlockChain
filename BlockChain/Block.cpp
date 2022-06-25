#include <ctime>
#include <sstream>
#include "Block.h"
#include "SHA256.h"

CBlock::CBlock(uint32_t indexIn, const string& dataIn) : INDICE(indexIn), DATO(dataIn) {
	this->m_nonce = -1;
	this->TIME = time(nullptr);
}

uint32_t CBlock::GetIndice() const {
	return this->INDICE;
}

time_t CBlock::GetTime() const {
	return this->TIME;
}


string CBlock::GetHash() const {
	return this->HASH;
}

string CBlock::GetDato() const {
	return this->DATO;
}


void CBlock::EstablecerGenesis() {
	this->m_nonce = -1;
	this->TIME = time(nullptr);
	this->INDICE = 0;
	this->DATO = "";
	this->HASH = "Genesis";
}

void CBlock::MinarBloque(uint32_t dificultad) {  //La dificultad es 10
	char* cstr = new char[dificultad + 1];

	for (uint32_t i = 0; i < dificultad; ++i) {
		cstr[i] = '0';
	}
	cstr[dificultad] = '\0';

	string str(cstr);

	do {
		this->m_nonce++;
		this->HASH = CalcularHash();
	} while (!str.compare(this->HASH.substr(0, dificultad)));    //Se repite hasta encontrar un HASH valido

	cout << "Bloque Minado: " << this->HASH << endl;
}


inline const string CBlock::CalcularHash() const {
	stringstream ss;
	ss << this->INDICE << this->TIME << this->DATO << this->m_nonce << this->HashPrevio;
	return sha256(ss.str());
}