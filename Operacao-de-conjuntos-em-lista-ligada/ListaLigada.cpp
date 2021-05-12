#include <cstdlib>
#include <iostream>
#include <sstream>
#include "No.h"
#include "ListaLigada.h"

using namespace std;


void ListaLigada::adicionar(No** head, int valor)
{
  No* new_no = new No;
  new_no->valor = valor;
  new_no->next = *head;
  *head = new_no;
}


bool ListaLigada::verificaValor(No* head, int valor)
{
  while(head != NULL)
  {
    if(head->valor == valor)
    	return 1;
    head = head->next;
  }
  return 0;
}


No* ListaLigada::opUniao(No* head1, No *head2){
  No* listaC = NULL;
  No* n1 = head1, *n2 = head2;
  while(n1 != NULL)
  {
    adicionar(&listaC, n1->valor);
    n1 = n1->next;
  }
  while(n2 != NULL)
  {
    if(!verificaValor(listaC, n2->valor))
      adicionar(&listaC, n2->valor);
    n2 = n2->next;
  }
  return listaC;
}


No* ListaLigada::opIntersecao(No* head1, No* head2){
  No* n1 = head1;
  No* listaC = NULL;
  while(n1 != NULL){
    if (verificaValor(head2, n1->valor))
		{
      adicionar(&listaC, n1->valor);
		}
    n1 = n1->next;
  }
  return listaC;
}


No* ListaLigada::opDiferenca(No *head1, No *head2){
	No* n1 = head1;
	No* listaC = NULL;
	while(n1 != NULL) {
		if (!verificaValor(head2, n1->valor))
		{
			adicionar(&listaC, n1->valor);
		}
		n1 = n1->next;
	}
	return listaC;
}


void ListaLigada::imprimir(No* head)
{
  while(head!=NULL)
  {
    cout << head->valor <<" ";
    head = head->next;
  }
}


bool ListaLigada::estaContido(No* head1, No* head2){
	No* n1 = head1, *n2 = head2;
	while(n1 != NULL){
    if (verificaValor(head2, n1->valor)) {
      n1 = n1->next;
			continue;
		} else {
			return false;
		}
	}
  return true;
}