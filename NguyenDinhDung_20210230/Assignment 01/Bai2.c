#include<stdio.h>
#include<stdlib.h>

typedef struct Bag{
	char name;
	int g;
	int v;
}Bag;

int n, w;
Bag bag[100];
int order[100];
int opt_value = -100;
int quantity[100];
int opt_quantity[100];
int value = 0;
float p_w[100];

void swap(int* a, int* b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

void sortValue(){
	for (int i = 1; i <= n-1; i++){
		for (int j = i + 1; j <= n; j++){
			if (p_w[i] < p_w[j]){
				float temp = p_w[i];
				p_w[i] = p_w[j];
				p_w[j] = temp;
				swap(&order[i], &order[j]);
			}
		}
	}
}

void Branch(int k){
	int item = order[k];
	int num = w / bag[item].g;
	for (int i = num; i >= 0; i--){
		quantity[item] = i;
		value += bag[item].v * quantity[item];
		w -= bag[item].g * quantity[item];
		float upper_bound = value + (float) w / bag[order[k + 1]].g * bag[order[k + 1]].v;
		if (k == n){
			if (value > opt_value){
				opt_value = value;
				for (int j = 1; j <= n; j++) opt_quantity[j] = quantity[j];
			}
		}
		else if (upper_bound > (float) opt_value) Branch(k + 1);
		value -= bag[item].v * quantity[item];
		w += bag[item].g * quantity[item];
	}
}

int main(){
	FILE* read = fopen("BAG.INP", "r");
	FILE* write = fopen("BAG.OUT", "w");
	fscanf(read, "%d %d", &n, &w);
	for (int i = 1; i <= n; i++){
		fscanf(read, "%d %d %c", &bag[i].g, &bag[i].v, &bag[i].name);
	}
	for (int i = 1; i <= n; i++) order[i] = i;
	for (int i = 1; i <= n; i++){
		p_w[i] = (float) bag[i].v / (float) bag[i].g;
	}
	sortValue();
	Branch(1);
	fprintf(write, "%d\n", opt_value);
	for (int i = 1; i <= n; i++){
		if (opt_quantity[i] != 0){
			fprintf(write, "%c %d\n", bag[i].name, opt_quantity[i]);
		}
	}
	fclose(read);
	fclose(write);
	return 0;
}