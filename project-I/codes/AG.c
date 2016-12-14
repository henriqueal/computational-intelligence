#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include "functions.c"

#define T 3

int main(int argc, char *argv[]){
  //sendmory
  //01234567

  int crossover, selecao, reinsercao, criptoaritmetica;

  crossover = atoi(argv[1]);
  selecao = atoi(argv[2]);
  reinsercao = atoi(argv[3]);
  criptoaritmetica = atoi(argv[4]);



  int semente = 50;
  int i,j,k,cont=0;
  int numero, qtdM0=0, qtdM1=0, qtdM02=0, qtdM12=0;
  long long int sumFitPop0=0, sumBestFitPop0=0, sumNroIndUnder100=0, sumFitIndUnder100=0;
  long long int sumFitPop02=0, sumBestFitPop02=0, sumNroIndUnder1002=0, sumFitIndUnder1002=0;
  long long int mediaFitnessInt =0, mediaFitnessMelhorInd=0;
  double mediaFitness=0;
	Individuo pai1,pai2;
  int indice1, indice2;
  int c;

  srand(time(NULL));

  for(k=0;k<1000; k++){
  //printf("k: %d\n", k);
    for(semente =1;semente<=100; semente++){ 
    //srand(semente);
      //printf("semente: %d", semente);
      if(semente==1){
	    GerarPopulacaoInicial();
	    qtdM0 += CalcularDistribuicao(0);
	    qtdM1 += CalcularDistribuicao(1);
    }
    //Calcular Fit
    for(j=0;j<P;j++)
      populacao[j].fitness=CalcularFit(j, criptoaritmetica);

	  Ordena(P);

    if(crossover == 0 && selecao ==0){
      for(i=0;i<F/2;i++){
        indice1 = Torneio(T);
        for(c=0;c<100;c++){
          indice2 = Torneio(T);
          if(indice2 != indice1) break; 
        }
        pai1 = populacao[indice1];
        pai2 = populacao[indice2];

        CrossOver(pai1,pai2,i);
      }
    }
    else if(crossover == 0 && selecao ==1){
      for(i=0;i<F/2;i++){
        indice1 = Roleta();
        for(c=0;c<100;c++){
          indice2 = Roleta();
          if(indice2 != indice1) break; 
        }
        pai1 = populacao[indice1];
        pai2 = populacao[indice2];

        CrossOver(pai1,pai2,i);
      }
    }
    else if(crossover == 1 && selecao ==0){
      for(i=0;i<F/2;i++){
        indice1 = Torneio(T);
        for(c=0;c<100;c++){
          indice2 = Torneio(T);
          if(indice2 != indice1) break; 
        }
        CrossOverPMX(indice1,indice2,i);
      }
    }
    else if(crossover == 1 && selecao ==1){
      for(i=0;i<F/2;i++){
        indice1 = Roleta();
        for(c=0;c<100;c++){
          indice2 = Roleta();
          if(indice2 != indice1) break; 
        }
        CrossOverPMX(indice1,indice2,i);
      }
    }

    Mutacao();

    //Calcular Fit
    for(j=P;j<P+F;j++)
      populacao[j].fitness=CalcularFit(j,criptoaritmetica);	

    if(reinsercao == 0){
      Ordena(P+F);
    }
    else {
      Elite();
    }

  //ExibirPopulacao(P+F);

    for(i=0;i<P+F;i++){
	    mediaFitnessInt+=populacao[i].fitness;
		  }
	  }
    mediaFitness += mediaFitnessInt/((P+F)*50.0);
    mediaFitnessInt = 0;
    mediaFitnessMelhorInd += populacao[0].fitness;
  
    if(populacao[0].fitness == 1000000 && (criptoaritmetica == 3 || criptoaritmetica ==5))
	    cont++;
    else if(populacao[0].fitness == 100000){
      cont++;
    }
  } 
 
  printf("***Estatisticas***\n"); 
  printf("Media fitness: %.2lf\n",mediaFitness/1000.0);
  printf("Melhor fitness media: %.2f\n",mediaFitnessMelhorInd/1000.0);
  printf("Nro ind com M=0: %.2f\n",qtdM0/1000.0);
  printf("Nro ind com M=1: %.2f\n",qtdM1/1000.0);
  printf("-------------------------\n");

  printf("\nCont:%d\n",cont);
  return 0;
}
