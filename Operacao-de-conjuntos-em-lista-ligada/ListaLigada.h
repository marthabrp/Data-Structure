#include <iostream>
#include <string.h>
#include "No.h"

class ListaLigada {
  private:
    No* head;
    No* tail;
  public:
  ListaLigada()
  {
    head = NULL;
    tail = NULL;
  }
	void adicionar(No** head, int valor);
	bool verificaValor(No* head, int valor);
	void imprimir(No* head);
	No* opUniao(No* head1, No* head2);
	No* opIntersecao(No* head1, No *head2);
  No* opDiferenca(No* head1,No* head2);
	bool estaContido(No* head1, No* head2);
};