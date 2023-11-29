#include "arvb.h"

 struct arvb{
	char info;
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
 printf("%d",a->info);
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
