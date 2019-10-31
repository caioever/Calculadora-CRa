#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <time.h>

typedef struct reg {
    float notas;
    int horas;
} REGISTRO;

#define MAX_LINE 100

int main() {

    FILE *fp;
    char buf[100];
    char *pstr;
    REGISTRO vetReg[MAX_LINE];
    time_t localtime;
    int i,j,cont=0;        
    setlocale(LC_ALL, "Portuguese");

    j=i=0;
    float crsomacima;
    float crsomabaixo;
    float cra=0;

    fp = fopen("dados.txt","r");
    if(!fp)
      exit(1);
     
     // Pula o cabecalho.
     fseek(fp,13,SEEK_SET); 
      
         
     while((fgets(buf,100,fp)!=NULL) && (i<MAX_LINE)) {
     	
     	
        pstr = strtok(buf,":");
        vetReg[i].notas = atof(pstr);
        
        pstr = strtok(NULL,":");
        vetReg[i].horas = atoi(pstr); 
        
        crsomacima+= vetReg[i].notas * vetReg[i].horas;
        crsomabaixo+=vetReg[i].horas;

        ++i;
    }
    
    cra = crsomacima / crsomabaixo;
  
    fclose(fp);

    localtime = time(NULL);
    printf("%s", ctime(&localtime));
    printf("\n");

    printf("%s%10s\n","Notas","Horas");
    printf("%s%10s\n","------","-------");
    
	cont++;
	printf("\n %dº Período\n",cont);
    for(j=0; j<i; j++) { 
	   if(vetReg[j].notas==0.0)
	   {
	   		cont++;
	   		printf("\n %dº Período\n",cont);
	   }
	   else
	   {
	   		printf("%3.01f",vetReg[j].notas);
       		printf("%10d\n",vetReg[j].horas);
	   }
    }
    printf("----------------------------------------------\n");
    printf("%42s%.2f\n","CRa: ",cra);
    printf("\n");
    
	system("pause");
	return 0;
}
