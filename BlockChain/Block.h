
#pragma once

#include <cstdint>
#include <iostream>


using namespace std;

class CBlock final {

public:
	string HashPrevio;

	CBlock(std::uint32_t indexIn, const string& dataIn);

	void EstablecerGenesis();

	uint32_t GetIndice() const;

	time_t GetTime() const;

	string GetHash() const;
	string GetDato() const;

	void MinarBloque(uint32_t difficulty);

private:
	uint32_t INDICE;
	int64_t m_nonce;
	string DATO;
	string HASH;
	time_t TIME;

	const string CalcularHash() const;
};