#include "BlockChain.h"

#pragma warning(disable:4996)

int main(int argc, char* argv[]) {
	CBlockChain CadenaBloques = CBlockChain();

	cout << "Genesis" << endl;
	CadenaBloques.AgregarGenesis();

	cout << "Minando Bloque 1..." << endl;
	CadenaBloques.AgregarBloque(CBlock(1, "Jesus"));

	cout << "Minando Bloque 2..." << endl;
	CadenaBloques.AgregarBloque(CBlock(2, "Josue"));

	cout << "Minando Bloque 3..." << endl;
	CadenaBloques.AgregarBloque(CBlock(3, "Alejandro"));



	cout << "Minando Bloque 4..." << endl;
	CadenaBloques.AgregarBloque(CBlock(4, "Jorge"));




	cout << "Minando Bloque 5..." << endl;
	CadenaBloques.AgregarBloque(CBlock(5, "Miguel"));


	CadenaBloques.ImprimirBloques();

	system("pause");

	return 0;
}