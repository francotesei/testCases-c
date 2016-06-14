#include <stdio.h>
#include <stdlib.h>
#include "testCases.h"

//######################################//

//  ARCHIVOS //

int abrirArchivo(FILE **pf ,const char *nomArch, const char *mt , int msg){

    if(*pf = fopen(nomArch,mt)){

        if(msg)
            printf("el archivo < %s > fue abierto en modo < %s > correctamente\n",nomArch,mt);
        return 1;

    }
    if(msg)
        printf("el archivo < %s > en modo < %s > NO PUDO ABRIRSE\n");
    return 0;
}

int cerrarArchivo(FILE **pf,int msg){

    if(!fclose(*pf)){
        if(msg)
            printf("El archivo se cerro corectamente \n");
        return 1;
    }
    if(msg)
        printf("ERROR : El archivo no pudo cerrarse\n");
    return 0;

}

int setArchivo(FILE **pf,const tsce_t_info *info){

    fwrite(info,sizeof(*info),1,*pf);
    return 1;

}

int  getArchivo(FILE **pf,tsce_t_info *info){

 return (fread(info,sizeof(*info),1,*pf))? 1:0;

}

int showArchivo(FILE **pf){
tsce_t_info info;

    if(*pf == NULL)
        return 0;
    printf("\n");
    while(fread(&info,sizeof(info),1,*pf))
        printf("%d\n",info.x);
    return 1;

}
//#####################################//

int tsce_init(){

    FILE *pf;
    int i = 100;
    tsce_t_info info;
    srand48(time(NULL)); //solo linux

    if(!abrirArchivo(&pf,TSCE_DATOS,"wb",1))
        return 0;

    while(i){
        info.x  = rand() % (3+1);
        setArchivo(&pf,&info);
        i--;
    }
    cerrarArchivo(&pf,1);
    return 1;


}
