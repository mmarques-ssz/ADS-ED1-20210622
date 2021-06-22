#include <iostream>
using namespace std;

#define MAX 5

struct Fila {
   int ini;
   int fim;     
   float nos[MAX];	
};

Fila* init() {
	Fila *f = new Fila;
	f->ini = 0;
	f->fim = 0;
	return f;
}

int incrementa(int i) {
	int ret;
	if (i == MAX) {
		ret = 0;
	} 
	else {
		ret = i+1;
	}
	return ret;
}

int isEmpty(Fila *f) {
	return (f->ini == f->fim);
}

int count(Fila *f) {
	int qtde = 0;
	int i = f->ini;
	while (i != f->fim) {
		qtde++;
		i = incrementa(i);
	}
    return qtde;	
}

void print(Fila *f) {
	int i = f->ini;
	cout << "----------------------------------" << endl;
	while (i != f->fim) {
		cout << f->nos[i] << endl;
		i = incrementa(i);
	}
	cout << "----------------------------------" << endl;
}

void freeFila(Fila *f) {
	free(f);
}

// Colocar na fila (Queue) - ou: enfileirar
int enqueue(Fila *f, float v) {
	int podeEnfileirar = (incrementa(f->fim) != f->ini);
	if (podeEnfileirar) {
		f->nos[f->fim] = v;
		f->fim = incrementa(f->fim);
	}
	return podeEnfileirar;
}

// Retirar da fila (Queue) - ou: desenfileirar
float dequeue(Fila *f) {
	float ret;
	if (isEmpty(f)) {
		ret = -1;
	}
	else {
		ret = f->nos[f->ini];
		f->ini = incrementa(f->ini);
	}
	return ret;
}


int main(int argc, char** argv)
{
	Fila *filaFloat = new Fila;
	filaFloat = init();
	
	cout << "Fila vazia: " << (isEmpty(filaFloat)?"SIM":"NAO") << endl;
	cout << "Qtde de elementos na fila: " << count(filaFloat) << endl;
	
	cout << "Conseguiu enfileirar: " << (enqueue(filaFloat, 11.11)?"SIM":"NAO") << endl;
	cout << "Conseguiu enfileirar: " << (enqueue(filaFloat, 22.22)?"SIM":"NAO") << endl;
	cout << "Conseguiu enfileirar: " << (enqueue(filaFloat, 33.33)?"SIM":"NAO") << endl;
	cout << "Conseguiu enfileirar: " << (enqueue(filaFloat, 44.44)?"SIM":"NAO") << endl;
	cout << "Conseguiu enfileirar: " << (enqueue(filaFloat, 55.55)?"SIM":"NAO") << endl;

	
	cout << "Fila vazia: " << (isEmpty(filaFloat)?"SIM":"NAO") << endl;
	cout << "Qtde de elementos na fila: " << count(filaFloat) << endl;
	
	print(filaFloat);
	
	cout << "Valor desenfileirado: " << dequeue(filaFloat) << endl;
	cout << "Valor desenfileirado: " << dequeue(filaFloat) << endl;
	cout << "Valor desenfileirado: " << dequeue(filaFloat) << endl;
	cout << "Valor desenfileirado: " << dequeue(filaFloat) << endl;
	
	print(filaFloat);
	
	cout << "Fila vazia: " << (isEmpty(filaFloat)?"SIM":"NAO") << endl;
	cout << "Qtde de elementos na fila: " << count(filaFloat) << endl;
	
	freeFila(filaFloat);
	
	
	return 0;
}