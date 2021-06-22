#include <iostream>
using namespace std;

struct No {
	float dado;
	struct No *prox;
};

struct Fila {
	No *ini;
	No *fim;
};

Fila* init() {
	Fila *f = new Fila;
	f->ini = NULL;
	f->fim = NULL;
	return f;
}

int isEmpty(Fila *f) {
	return (f->ini == NULL);
}

int count(Fila *f) {
	int qtde = 0;
	No *no;
	no = f->ini;
	while (no != NULL) {
		qtde++;
		no = no->prox;
	}
	return qtde;
}

void print(Fila *f) {
	No *no;
	no = f->ini;
	cout << "----------------------------------" << endl;
	while (no != NULL) {
		cout << no->dado << endl;
		no = no->prox;
	}
	cout << "----------------------------------" << endl;
}

// Colocar na fila (Queue) - ou: enfileirar
void enqueue(Fila *f, float v) {
	No *no = new No;
	no->dado = v;
	no->prox = NULL;
	if (isEmpty(f)) {
		f->ini = no;
	}
	else {
		f->fim->prox = no;
	}
	f->fim = no;
}

// Retirar da fila (Queue) - ou: desenfileirar
float dequeue(Fila *f) {
	float ret;
	if (isEmpty(f)) {
		ret = -1;
	}
	else {
		No *no = f->ini;
		ret = no->dado;
		f->ini = no->prox;
		if (f->ini == NULL) {
			f->fim = NULL;
		}
		free(no);
	}
	return ret;
}

void freeFila(Fila *f) {
	No *no = f->ini;
	while (no != NULL) {
		No *temp = no->prox;
		free(no);
		no = temp;
	}
	free(f);
}


int main(int argc, char** argv)
{
	Fila *filaFloat;
	filaFloat = new Fila();
	
	cout << "Fila vazia: " << (isEmpty(filaFloat)?"SIM":"NAO") << endl;
	cout << "Qtde de elementos na fila: " << count(filaFloat) << endl;
	
	enqueue(filaFloat, 11.11);
	enqueue(filaFloat, 22.22);
	enqueue(filaFloat, 33.33);
	enqueue(filaFloat, 44.44);
	enqueue(filaFloat, 55.55);
	enqueue(filaFloat, 66.66);

	
	print(filaFloat);
	
	cout << "Fila vazia: " << (isEmpty(filaFloat)?"SIM":"NAO") << endl;
	cout << "Qtde de elementos na fila: " << count(filaFloat) << endl;
	
	cout << "Valor desenfileirado: " << dequeue(filaFloat) << endl;
	cout << "Valor desenfileirado: " << dequeue(filaFloat) << endl;
	cout << "Valor desenfileirado: " << dequeue(filaFloat) << endl;
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