#include <stdio.h>
#include <stdlib.h>
#include "declarations.h"

#define P 200
#define C 10
#define F 160
#define E 40
#define M 50


struct individuo{
  int cromossomo[C];
  int fitness;
  int cromossomoDecimal;
};

int vetorVisitados[C];
Individuo populacao[P+F];

int compare (const Individuo * a, const Individuo * b)
{
  return ((b->fitness - a->fitness));
}

int SortearNumero(int divisor){
  return (rand()%divisor);
}

void ZerarVetorVisitados(){
  int i;
  for(i=0;i<C;i++)
    vetorVisitados[i]=0;
}

void GerarPopulacaoInicial(){
  int i,j,numero;
  for(j=0;j<P;j++){
    i=0;
    ZerarVetorVisitados();
    while(1){
      if(i==C) break;
      numero = SortearNumero(C);
      if(vetorVisitados[numero] == 0){
        vetorVisitados[numero] = 1;
        populacao[j].cromossomo[i] = numero;
        i++;
      }
    }
  }
}

int CalcularFit(int n, int escolha){
  int money; 
  int send;
  int more;
  int eat;
  int that;
  int apple;
  int cross;
  int roads;
  int danger;
  int coca;
  int cola;
  int oasis;
  int donald;
  int gerald;
  int robert;

  switch (escolha){
  	case 1: 
   		//sendmorny
 
  		money = populacao[n].cromossomo[4]*10000;
  		money += populacao[n].cromossomo[5]*1000;
  		money += populacao[n].cromossomo[2]*100;
  		money += populacao[n].cromossomo[1]*10;
  		money += populacao[n].cromossomo[7];

  		send = populacao[n].cromossomo[0]*1000;
  		send += populacao[n].cromossomo[1]*100;
  		send += populacao[n].cromossomo[2]*10;
  		send += populacao[n].cromossomo[3];

  		more = populacao[n].cromossomo[4]*1000;
  		more += populacao[n].cromossomo[5]*100;
  		more += populacao[n].cromossomo[6]*10;
  		more += populacao[n].cromossomo[1];

 		return 100000-abs(send+more-money);

	case 2: 
		//eathpl
		
		eat = populacao[n].cromossomo[0]*100;
		eat += populacao[n].cromossomo[1]*10;
		eat += populacao[n].cromossomo[2];

		that = populacao[n].cromossomo[2]*1000;
		that += populacao[n].cromossomo[3]*100;
		that += populacao[n].cromossomo[1]*10;
		that += populacao[n].cromossomo[2];

		apple = populacao[n].cromossomo[1]*10000;
		apple += populacao[n].cromossomo[4]*1000;
		apple += populacao[n].cromossomo[4]*100;
		apple += populacao[n].cromossomo[5]*10;
		apple += populacao[n].cromossomo[0];

		return 100000-abs(eat+that-apple);

  	case 3: 
		//c0 r1 o2 s3 a4 d5 n6 g7 e8
		
		cross = populacao[n].cromossomo[0]*10000;
		cross += populacao[n].cromossomo[1]*1000;
		cross += populacao[n].cromossomo[2]*100;
		cross += populacao[n].cromossomo[3]*10;
		cross += populacao[n].cromossomo[3];

		roads = populacao[n].cromossomo[1]*10000;
		roads += populacao[n].cromossomo[2]*1000;
		roads += populacao[n].cromossomo[4]*100;
		roads += populacao[n].cromossomo[5]*10;
		roads += populacao[n].cromossomo[3];

		danger = populacao[n].cromossomo[5]*100000;
		danger += populacao[n].cromossomo[4]*10000;
		danger += populacao[n].cromossomo[6]*1000;
		danger += populacao[n].cromossomo[7]*100;
		danger += populacao[n].cromossomo[8]*10;
		danger += populacao[n].cromossomo[1];

		return 1000000-abs(cross+roads-danger);

	case 4:	
		//c0 o1 a2 l3 s4 i5
		
		coca = populacao[n].cromossomo[0]*1000;
		coca += populacao[n].cromossomo[1]*100;
		coca += populacao[n].cromossomo[0]*10;
		coca += populacao[n].cromossomo[2];

		cola = populacao[n].cromossomo[0]*1000;
		cola += populacao[n].cromossomo[1]*100;
		cola += populacao[n].cromossomo[3]*10;
		cola += populacao[n].cromossomo[2];

		oasis = populacao[n].cromossomo[1]*10000;
		oasis += populacao[n].cromossomo[2]*1000;
		oasis += populacao[n].cromossomo[4]*100;
		oasis += populacao[n].cromossomo[5]*10;
		oasis += populacao[n].cromossomo[4]; 

		return 100000-abs(coca+cola-oasis);

	case 5:
		//d0 o1 n2 a3 l4 g5 e6 r7 b8 t9
		
		donald = populacao[n].cromossomo[0]*100000;
		donald += populacao[n].cromossomo[1]*10000;
		donald += populacao[n].cromossomo[2]*1000;
		donald += populacao[n].cromossomo[3]*100;
		donald += populacao[n].cromossomo[4]*10;
		donald += populacao[n].cromossomo[0];

		gerald = populacao[n].cromossomo[5]*100000;
		gerald += populacao[n].cromossomo[6]*10000;
		gerald += populacao[n].cromossomo[7]*1000;
		gerald += populacao[n].cromossomo[3]*100;
		gerald += populacao[n].cromossomo[4]*10;
		gerald += populacao[n].cromossomo[0];

		robert = populacao[n].cromossomo[7]*100000;
		robert += populacao[n].cromossomo[1]*10000;
		robert += populacao[n].cromossomo[8]*1000;
		robert += populacao[n].cromossomo[6]*100;
		robert += populacao[n].cromossomo[7]*10;
		robert += populacao[n].cromossomo[9];

		return 1000000-abs(donald+gerald-robert);
  }
}

void ExibirPopulacao(int tam){
  int i,j;
  for(i=0;i<tam;i++){
    for(j=0;j<C;j++){
      printf("%d | ", populacao[i].cromossomo[j]);
    }
    printf("%d |", populacao[i].fitness);
    printf("\n");
  }
}


int Torneio(int n){
  int aux,i;
  int melhor = SortearNumero(P);
  for(i=1;i<n;i++){
     aux = SortearNumero(P);
     if(populacao[aux].fitness > populacao[melhor].fitness){
       melhor=aux;
     }
  }
  return melhor;
}

int Roleta(){
	long int maximo_roleta=0, random;
	int *roleta, i;

	for (i=0; i<P; i++){
		maximo_roleta += populacao[i].fitness;
	}

	
	roleta = (int*) malloc(P*sizeof(int));
	random = rand()%maximo_roleta;

	roleta[0] = populacao[0].fitness;
	for (i=1; i<P; i++){
		roleta[i] = roleta[i-1] + populacao[i].fitness;
	}

	i=0;
	while(random > roleta[i]){
		i++;
	}
	if (random == roleta[i]){
		free(roleta);
		return i;
	}
	else{
		if (i==0){
			free(roleta);
			return 0;
		}
		else{
			free(roleta);
			return i-1;
		}
	}

}


void CrossOver(Individuo pai1, Individuo pai2, int i){
  int aux,j,pontoAleatorio;
  int inicioCiclo;
  pontoAleatorio = SortearNumero(C);
  inicioCiclo = pai1.cromossomo[pontoAleatorio];

  while(1){
    aux = pai1.cromossomo[pontoAleatorio];
    pai1.cromossomo[pontoAleatorio] = pai2.cromossomo[pontoAleatorio];
    pai2.cromossomo[pontoAleatorio] = aux;
    
    if(pai1.cromossomo[pontoAleatorio] == inicioCiclo) break;
    
    for(j=0;j<C;j++){
      if(j == pontoAleatorio) continue;
      if(pai1.cromossomo[j] == pai1.cromossomo[pontoAleatorio]) break;
    }
    
    pontoAleatorio = j;
  }
  populacao[P+(2*i)] = pai1;  
  populacao[P+1+(2*i)] = pai2;  
}

void Mutacao(){
  int filhoMutante, pos1, pos2,i;

  for(i=0;i<M;i++){
	  filhoMutante = SortearNumero(F);
	  pos1 = SortearNumero(C);
	  pos2 = pos1;
	  while(pos2 == pos1){
	    pos2 = SortearNumero(C);
    	  }
	  int aux = populacao[P+filhoMutante].cromossomo[pos1];
	  populacao[P+filhoMutante].cromossomo[pos1] = populacao[P+filhoMutante].cromossomo[pos2];
	  populacao[P+filhoMutante].cromossomo[pos2] = aux;
  }
}

void Ordena(int a){
  qsort(populacao, a, sizeof(Individuo), (void*)compare);
}

void Elite(){
	int i;
	for(i = E; i<P;i++){
		populacao[i] = populacao[P+i-E];
	}
}


int Repetido(int pai, int corte1, int corte2){
	int i, j;
	for (i=0; i<C; i++){
		for (j=0; j<C; j++){
			if ((populacao[pai].cromossomo[i] == populacao[pai].cromossomo[j]) && (i != j))
				return populacao[pai].cromossomo[i];
		}
	}
	return -1;
}

void ArrumaCiclo(short int trocas[20]){
	short int i, j, achou=0, trocar, indiceEncontradoInicial, temRepetido=0, vaiTrocar;
	for (i=0; i<20;i++){
		for (j=0; j<20; j++){
			if ((trocas[i] == trocas[j]) && (i != j) && (trocas[j] != -1))
				temRepetido = 1;
		}
	}
	indiceEncontradoInicial = -1;
	trocar = -1;
	while(temRepetido == 1){
		i = 0;
		achou = 0;
		while(i<20){
			if (achou == 0){
				trocar = trocas[i];
				indiceEncontradoInicial = i;
			}
			for (j=0; j<20; j++){
				if ((trocar == trocas[j]) && (i != j) && (trocas[j] != -1)){
					if (j%2 == 0){
						trocar = trocas[j+1];
						trocas[j+1] = -1;
					}else{
						trocar = trocas[j-1];
						trocas[j-1] = -1;
					}
					trocas[j] = -1;
					achou = 1;
					break;
				}
			}
			i++;
		}
		if (indiceEncontradoInicial != -1)
			trocas[indiceEncontradoInicial] = trocar;


		temRepetido = 0;
		for (i=0; i<20;i++){
			for (j=0; j<20; j++){
				if ((trocas[i] == trocas[j]) && (i != j) && (trocas[j] != -1) && (trocas[i] != -1)){
					temRepetido = 1;
					break;
				}
			}
			if (temRepetido == 1)
				break;
		}
	}
}

int substituirPor(int chave, short int vetor[20]){
	int i=0;
	for(i=0; i<20 ;i++){
		if(vetor[i] == chave){
			if(i%2==0){
				return vetor[i+1];
			}
			return vetor[i-1];
		}
	}
}

void CrossOverPMX(int pai1, int pai2, int filho1){
  	filho1*=2;
	filho1+=P;
	short int i, j, k, inicial, aleatorio, aux, mapafilho2, corte1, corte2;
	short int mapafilhos[10] = {0,0,0,0,0,0,0,0,0,0};
	short int filho2 = filho1 + 1;
	short int trocas[20] = {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1};
	short int valorRepetido;
	short int achou=0;
	short int trocar;

	aleatorio = rand()%10;
	
	corte1 = rand()%10;
	corte2 = rand()%10;
	while(corte2 < corte1)
		corte2 = rand()%10;
 
	for (i=0; i<10; i++){
		populacao[filho1].cromossomo[i] = populacao[pai1].cromossomo[i];
		populacao[filho2].cromossomo[i] = populacao[pai2].cromossomo[i];
	}


	k=0;
	for (i=corte1; i<corte2; i++){
		trocas[k] = populacao[filho1].cromossomo[i];
		trocas[k+1] = populacao[filho2].cromossomo[i];
		aux = populacao[filho1].cromossomo[i];
		populacao[filho1].cromossomo[i] = populacao[filho2].cromossomo[i];
		populacao[filho2].cromossomo[i] = aux;
		k += 2;
	}

	ArrumaCiclo(trocas);
    while(1){
		  valorRepetido = Repetido(filho1, corte1, corte2);
	
		  if (valorRepetido == -1)
			  break;

		  for(i=0; i<10; i++){
			  if(i>=corte1 && i<corte2)
				  continue;

			  if(populacao[filho1].cromossomo[i] == valorRepetido){
				  populacao[filho1].cromossomo[i] = substituirPor(valorRepetido, trocas);
			  }
		  }    	
    }	

    while(1){
		  valorRepetido = Repetido(filho2, corte1, corte2);

		  if (valorRepetido == -1)
			  break;

		  for(i=0; i<10; i++){
			  if(i>=corte1 && i<corte2)
				  continue;

			  if(populacao[filho2].cromossomo[i] == valorRepetido){
				  populacao[filho2].cromossomo[i] = substituirPor(valorRepetido, trocas);
			  }

		  }    	
    }	
}


int CalcularDistribuicao(int k){

  int cont=0;
  int i;

  for(i=0;i<P;i++){
    if(populacao[i].cromossomo[4]==k) cont++;
  }
  return cont;
}
