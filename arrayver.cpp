#include <iostream>
using namespace std;

#define MAX 30

struct Pilha {
	int qtde;
	float elementos[MAX];
};

Pilha* init() {
	Pilha *p = new Pilha;
	p->qtde = 0;
	return p;
};

int push(Pilha *p, int v) {
	int podeEmpilhar = (p->qtde < MAX);
	if (podeEmpilhar) {
		p->elementos[p->qtde++] = v;
	}
	return podeEmpilhar;
}

float pop(Pilha *p) {
	int podeDesempilhar = (p->qtde > 0);
	int ret;
	if (podeDesempilhar) {
		ret = p->elementos[p->qtde-1];
		p->qtde--;
	}
	else
	{
		ret = NULL;
	}
	return ret;
}

void print(Pilha *p) {
	cout << "----------" << endl;
	for(int i = p->qtde-1; i>=0; --i) {
		cout << p->elementos[i] << endl;
	}
	cout << "----------" << endl;
}

int main(int argc, char** argv)
{
	Pilha *pilhaIntEven;
	Pilha *pilhaIntOdd;
	pilhaIntEven = init();
	pilhaIntOdd = init();
	int arr[30];
	for(int i=0;i<30;i++){
		cin >> arr[i];
		if(arr[i]%2 == 0){
			push(pilhaIntEven, arr[i]);
		}
		else if(arr[i]%2!=0){
			push(pilhaIntOdd, arr[i]);
		}
	}
	print(pilhaIntEven);
	pop(pilhaIntEven);
	print(pilhaIntOdd);
	pop(pilhaIntOdd);
}
