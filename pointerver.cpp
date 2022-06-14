#include <iostream>
using namespace std;

struct No {
	float dado;
	No *prox;
};

struct Pilha
{
	No *topo;
};

Pilha* init() {
	Pilha *p = new Pilha;
	p->topo = NULL;
	return p;
}

void push(Pilha *p, float v) {
	No *no = new No;
	no->dado = v;
	no->prox = p->topo;
	p->topo = no;
}

float pop(Pilha *p) {
	float ret;
	int podeDesempilhar = (p->topo != NULL);
	if (podeDesempilhar) {
		No *no = p->topo;
		ret = no->dado;
		p->topo = p->topo->prox;
		free(no);
	}
	else
	{
		ret = NULL;
	}
	return ret;
}

int isEmpty(Pilha *p) {
	return (p->topo == NULL);
}

int count(Pilha *p) {
	int i=0;
	No *no;
	no = p->topo;
	while (no != NULL) {
		i++;
		no = no->prox;
	}
	return i;
}

void print(Pilha *p) {
	No *no;
	no = p->topo;
	cout << "Qtde: " << count(p) << endl;
	cout << "------" << endl;
	while (no != NULL) {
		cout << no->dado << endl;
		no = no->prox;
	}
	cout << "------" << endl;
}

void freePilha(Pilha *p) {
	No *no = p->topo;
	while (no != NULL) {
		No *aux = no->prox;
		free(no);
		no = aux;
	}
	
}

int main(int argc, char** argv)
{
	Pilha *pilhaIntEven;
	Pilha *pilhaIntOdd;
	pilhaIntEven = init();
	pilhaIntOdd = init();
	int arr[30];
	int ult = 0;
	for(int i=0;i<30;i++){
		cin >> arr[i];
		if(ult != 0){
		while(arr[i]<ult){
			cout << "Números devem seguir em ordem crescente. Tente de novo: ";
			cin >> arr[i];
			}
		}
		if(arr[i]%2 == 0){
			push(pilhaIntEven, arr[i]);
		}
		else if(arr[i]%2!=0){
			push(pilhaIntOdd, arr[i]);
		}
		ult = arr[i];
	}
	print(pilhaIntEven);
	pop(pilhaIntEven);
	print(pilhaIntOdd);
	pop(pilhaIntOdd);
	return 0;
}
