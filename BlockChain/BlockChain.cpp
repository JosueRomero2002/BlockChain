#include "BlockChain.h"
#include <string>

CBlockChain::CBlockChain() {

	this->m_difficulty = 10;
}

void CBlockChain::AgregarGenesis() {
	CBlock genesis(0, "");
	genesis.EstablecerGenesis();
	this->m_chain.emplace_back(genesis);
}

void CBlockChain::AgregarBloque(CBlock NuevoBloque) {
	NuevoBloque.HashPrevio = VerUltimoBloque().GetHash();
	NuevoBloque.MinarBloque(this->m_difficulty);
	this->m_chain.push_back(NuevoBloque);
}

void CBlockChain::ImprimirBloques() {


	for (const auto& bloque : this->m_chain) {
		cout << endl << "=====================BLOQUE=" << bloque.GetIndice() << "==================" << endl;

		cout << " Dato: " << bloque.GetDato()
			<< " Time: " << bloque.GetTime()
			<< " Hash: " << bloque.GetHash()
			<< endl;
	}
	cout << endl;
}

const CBlock CBlockChain::VerUltimoBloque() const {
	return this->m_chain.back();
}

const uint32_t CBlockChain::TamanoCadena() const {
	return this->m_chain.size();
}

