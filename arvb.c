#include "arvb.h"

 struct arvb{
	int info;
	ArvB *esq;
	ArvB *dir;
};

ArvB* arvb_cria_vazia(void){
 return NULL;
}

int arvb_vazia(ArvB *a){
 return a==NULL;
}

ArvB* arvb_busca(ArvB* a, int c){
 if(arvb_vazia(a)){
 	return NULL;
 }
 else if(a->info < c){
 	return arvb_busca(a->dir,c);
 }	
 else if(a->info > c){
 	return arvb_busca(a->esq,c);
 }
 	else{ //(a->info == c)
 		return a;
	}

}

void arvb_imprime(ArvB *a){
 if(!arvb_vazia(a)){
 arvb_imprime(a->esq);
 printf("\n%d\n",a->info); //mudei para o print sair melhor 
 arvb_imprime(a->dir);
 }
}

ArvB* arvb_insere(ArvB *a, int c){
 if(arvb_vazia(a)){
 a = (ArvB*)malloc(sizeof(ArvB));
 a->info = c;
 a->esq = NULL;
 a->dir = NULL;
 }else if(a->info > c)
 a->esq = arvb_insere(a->esq,c);
 else if (a->info < c)
 a->dir = arvb_insere(a->dir,c);
 else
 printf("\nElemento Ja Pertence a Arvore");
 return a;
}

ArvB* arvb_remove(ArvB *a, int c){
if(!arvb_vazia(a)){
 if(a->info > c)
 a->esq = arvb_remove(a->esq,c);
 else if (a->info < c)
 a->dir = arvb_remove(a->dir,c);
 else{
 ArvB* t;
 if (a->esq == NULL){
 t = a; a = a->dir;
 free(t);
 }else if (a->dir == NULL){
 t = a; a = a->esq;
 free(t);
 }else{
 t = a->esq;
 while(t->dir!=NULL)
 t = t->dir;
 a->info = t->info; t->info = c;
 a->esq = arvb_remove(a->esq,c);
 }
 }
}
return a;
}

void arvb_libera(ArvB *a){
 if(!arvb_vazia(a)){
 arvb_libera(a->esq);
 arvb_libera(a->dir);
 free(a);
 }
}

int arv_altura(ArvB *a){
 if(arvb_vazia(a))
 return -1;
 else{
int hSAE = arv_altura(a->esq);
int hSAD = arv_altura(a->dir);
 if(hSAE > hSAD)
 return 1+hSAE;
 else
 return 1+hSAD;
 }
}

int folhas_primos(ArvB* a){
	if(!arvb_vazia(a)){
		int cont= folhas_primos(a->esq);
		cont= cont +folhas_primos(a->dir);
		if (a->info <= 1) {
        	return 0+cont; // não é primo então não é somado
    	}
    	int i;
    	for (i = 2; i * i <= a->info; i++) {
        	if (a->info % i == 0) {
            	return 0+cont; // não é primo então não é somado
        	}
    	}
    	return 1+cont;
	}
	else{
		return 0;
	}	
}

int dois_filhos(ArvB* a){
	if(arvb_vazia(a)){
		return 0;
	}
	else{
		int nosComDoisFilhos = 0;
    	if (a->esq != NULL && a->dir != NULL) {
        	nosComDoisFilhos = 1;
    	}
    	int nosEsquerda = dois_filhos(a->esq);
    	int nosDireita = dois_filhos(a->dir);
    	return nosComDoisFilhos + nosEsquerda + nosDireita;
	}
}

int nos_igual_altura(ArvB* a){
	if(arvb_vazia(a)){
		return 0;
	}
	int nosComAlturasIguais = 0;
    if (arv_altura(a->esq) == arv_altura(a->dir)) {
        nosComAlturasIguais = 1;
    }
    int nosEsquerda = nos_igual_altura(a->esq);
    int nosDireita = nos_igual_altura(a->dir);
    return nosComAlturasIguais + nosEsquerda + nosDireita;
}

int iguais(ArvB* a, ArvB* b){
	if (a == NULL && b == NULL) {
		return 1;
    }
    if (a == NULL || b == NULL) {
        return 0;
    }
    if (a->info != b->info) {
        return 0;
    }
    int subarvoresIguais = iguais(a->esq, b->esq) && iguais(a->dir, b->dir);
    return subarvoresIguais;
}
