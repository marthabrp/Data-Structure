/*
  Uma maneira usual de se representar um conjunto é pela  lista de seus elementos. Supondo esta representação,  escreva um programa que use nosso TAD Lista e       implemente   as operações usuais de conjunto: 
 * (a) União: C = (A∪B)
 * (b) Interseção: C = (A∩B)
 * (c) Diferença: C = (A-B)
 * (d) Pertinência: (A⊂B)
 * A e B são listas. 
 * Neste caso, vocês criarão novos nós para compor a lista C.
 */

#include <cstdlib>
#include <iostream>
#include "ListaLigada.h"

using namespace std;

// Testes:
// Lista A: 1 0 2 4 
// Lista B: 1 2 3

int main() {
  
  ListaLigada lista;
  
  No* head1 = NULL;
  No* head2 = NULL;
  No* uniao = NULL;
  No* intersecao = NULL;
	No* diferenca = NULL;

	bool estaContido;
  int elementoA;
  int qtdeElementoA;

  // cria listaA
  cout << "\nDigite o número de elementos da Lista A: ";
  cin >> qtdeElementoA;
  for(int i = 0; i < qtdeElementoA; i++) {
    cout << "\nInforme o elemento a ser inserido: ";
    cin >> elementoA;
    lista.adicionar(&head1, elementoA);
    cout << "\nLista A = [ ";
    lista.imprimir(head1);
    cout << "]\n";
  }  

  //cria listaB
  int qtdeElementoB;
  int elementoB;
  cout << "\nDigite o número de elementos da Lista B: ";
  cin >> qtdeElementoB;
  for(int i=0;i<qtdeElementoB;i++) {
    cout << "\nInforme o elemento a ser inserido: ";
    cin >> elementoB;
    lista.adicionar(&head2, elementoB);
    cout << "\nLista B = [ ";
    lista.imprimir(head2);
    cout << "]\n";
  }

  cout << "\033[1;34m\n\n\n\n=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\033[m\n\n\n";
  cout << "\n\033[1mLista A = [ ";
  lista.imprimir(head1);
  cout << "]\033[0m";
  cout << "\n\033[1mLista B = [ ";
  lista.imprimir(head2);
  cout << "]\n\n\033[0m";

  // União
  uniao = lista.opUniao(head1, head2);
	cout << "\n\033[1;32m(a) União: C = (A ∪ B) = [ ";
  lista.imprimir(uniao);
  cout << "]\n\n";
  
  // Interseção
  intersecao = lista.opIntersecao(head1, head2);
  cout << "\n\033[1;33m(b) Interseção: C = (A ∩ B) = [ ";
	lista.imprimir(intersecao);
  cout << "]\n\n\033[0m";
  
	// Diferença
	diferenca = lista.opDiferenca(head1, head2);
	cout << "\n\033[1;96m(c) Diferença: C = (A - B) = [ ";
	lista.imprimir(diferenca);
  cout << "]\n\n\033[0m";

  // Pertinência
  estaContido = lista.estaContido(head1, head2);
  if(estaContido == true) {
    cout << "\n\033[1;94m(d) Pertinência: (A ⊂ B) = A está contido em B.\n\n";
  } else {
    cout << "\n\033[1;93m(d) Pertinência: (A ⊄ B) = A não está contido em B.\n\n";
  }

	return 0;
}
