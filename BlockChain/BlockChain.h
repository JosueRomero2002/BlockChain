#pragma once

#include <cstdint>
#include <vector>
#include "Block.h"

using namespace std;

class CBlockChain {
public:
	CBlockChain();

	void AgregarGenesis();

	void AgregarBloque(CBlock newBlock);

	void ImprimirBloques();

private:
	uint32_t m_difficulty;
	vector<CBlock> m_chain;

	const CBlock VerUltimoBloque() const;

	const uint32_t TamanoCadena() const;


};