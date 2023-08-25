#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<Windows.h>
#include<string.h>
#include"open.h"
#include"timee.h"
#include"cutca.h"
#include"charac.h"
#include"maze.h"
#include"confuse.h"
#include"secretcode.h"
#include"win.h"

typedef struct B{
    char name[100];
    float time;
}A;
A data[100] ,data1[100] ,data2[100] ,B;

int main(void)
{
    int I=0 ,J=0 ,K=0;
    while(1){
        int chee=1;
        clock_t time_req;
        char x='A';
        char n='0';
        open();
        Sleep(2000);
        printf("\n\n\n                                                                      Press -SPACE BAR- to continue\n");
        while((x=getch())!=' ') ;
        system("cls");
        printf("\n\n\n\n\n\n\n\n\n\n\n\n\n");
        printf("                                                                   What level do you want to play?\n");
        Sleep(300);
        printf("\n                                                                             1.Easy(3)\n");
        printf("\n                                                                            2.Medium(4)\n");
        printf("\n                                                                             3.Hard(5)\n");
        while(n!='1'&&n!='2'&&n!='3')
        n=getch();
        if(n=='1'){
            printf("                                                                                __ \n");
            printf("                                                                               /  |\n");
            printf("                                                                              /   |\n");
            printf("                                                                             / /| |\n");
            printf("                                                                            /_/ | |\n");
            printf("                                                                                | |\n");
            printf("                                                                                | |\n");
            printf("                                                                                | |\n");
            printf("                                                                                | |\n");
            printf("                                                                                | |\n");
            printf("                                                                                | |\n");
            printf("                                                                                | |\n");
            printf("                                                                            ____| |____\n");
            printf("                                                                           |___________|\n");
        }
        else if(n=='2'){
            printf("                                                                             ________ \n");
            printf("                                                                            /  ____  \\\n");
            printf("                                                                           /  /    \\  \\\n");
            printf("                                                                          /__/     |  |\n");
            printf("                                                                                   |  |\n");
            printf("                                                                                  /  /\n");
            printf("                                                                                 /  /\n");
            printf("                                                                                /  /\n");
            printf("                                                                               /  /\n");
            printf("                                                                              /  /\n");
            printf("                                                                             /  /\n");
            printf("                                                                            /  /\n");
            printf("                                                                           /  /\n");
            printf("                                                                          /  /\n");
            printf("                                                                         /  /________\n");
            printf("                                                                         | __________|\n");
        }
        else if(n=='3'){
            printf("                                                                             ________ \n");
            printf("                                                                            /  ____  \\\n");
            printf("                                                                           /  /    \\  \\\n");
            printf("                                                                          /__/      |  |\n");
            printf("                                                                                    |  |\n");
            printf("                                                                                   /  /\n");
            printf("                                                                                  /  /\n");
            printf("                                                                           ______/  /\n");
            printf("                                                                          |        /\n");
            printf("                                                                          |______  \\\n");
            printf("                                                                                 \\  \\\n");
            printf("                                                                                  \\  \\\n");
            printf("                                                                                   \\  \\\n");
            printf("                                                                          ___       |  |\n");
            printf("                                                                          \\  \\      |  |\n");
            printf("                                                                           \\  \\____/  /\n");
            printf("                                                                            \\________/\n");
        }
        Sleep(2000);
        system("cls");

        if(n=='1'){
            system("cls");
            printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n                                                                      *name must be 3-10 characters*\n\n");
            printf("                                               Enter your name : ");
            gets(data[I].name);
            while(strlen(data[I].name)>10||strlen(data[I].name)<3){
                system("cls");
                printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n                                                                      *name must be 3-10 characters*\n\n");
                printf("                                               Enter your name : ");
                gets(data[I].name);
            }
            system("cls");
            printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n                                                                      Press -SPACE BAR- to start.\n");
            x=getch();
            while(x!=' ') x=getch();
            system("cls");
            time_req = clock();
            if(!cut(random(8))){
                system("cls");
                gover();
                I--;
                chee=0;
            }
            Sleep(300);
            system("cls");
            if(chee&&chara(random(6))){
                system("cls");
                gover();
                I--;
                chee=0;
            }
            Sleep(300);
            system("cls");
            if(chee&&maze(random(6))){
                system("cls");
                gover();
                I--;
                chee=0;
            }
            if(chee){
                data[I].time = (float)(clock()- time_req)/CLOCKS_PER_SEC;
                int ii=I;
                for(int j=ii-1 ; j>=0 ; j--){
                    if(data[ii].time<data[j].time){
                        strcpy(B.name,data[ii].name);
                        B.time = data[ii].time;
                        strcpy(data[ii].name,data[j].name);
                        data[ii].time = data[j].time;
                        strcpy(data[j].name,B.name);
                        data[j].time = B.time;
                        ii--;
                    }
                }
            }
            Sleep(3000);
            if(chee) winn();
            int j;
            printf("\n\n\n\n\n\n\n\n\n                                                                            - SCORE BOARD -\n");
                              printf("                                                                      ---------------------------\n\n");
            for(j=0 ; j<=I&&j<=8 ; j++){
                              printf("                                                                %d.%s " ,j+1,data[j].name);
                for(int k=0 ; k<11-strlen(data[j].name) ; k++) printf(" ");
                printf(": %d minutes %.2f seconds\n" ,(int)data[j].time/60,(float)((int)data[j].time%60+data[j].time-(int)data[j].time));
            }
            for(int k=0 ; k<10-j ; k++) printf("\n");
            printf("                                                                    Press -SPACE BAR- to continue.\n");
            x=getch();
            while(x!=' ') x=getch();
            system("cls");
            I++;

        }

        else if(n=='2'){
            system("cls");
            printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n                                                                      *name must be 3-10 characters*\n\n");
            printf("                                               Enter your name : ");
            gets(data1[J].name);
            while(strlen(data1[J].name)>10||strlen(data1[J].name)<3){
                system("cls");
                printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n                                                                      *name must be 3-10 characters*\n\n");
                printf("                                               Enter your name : ");
                gets(data1[J].name);
            }
            system("cls");
            printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n                                                                      Press -SPACE BAR- to start.\n");
            x=getch();
            while(x!=' ') x=getch();
            system("cls");
            time_req = clock();
            if(!cut(random(13))){
                system("cls");
                gover();
                J--;
                chee=0;
            }
            Sleep(300);
            system("cls");
            if(chee&&chara(random(6))){
                system("cls");
                gover();
                J--;
                chee=0;
            }
            Sleep(300);
            system("cls");
            if(chee&&maze(random(6))){
                system("cls");
                gover();
                J--;
                chee=0;
            }
            Sleep(300);
            system("cls");
            if(chee&&con(random(6))){
                system("cls");
                gover();
                J--;
                chee=0;
            }
            Sleep(300);
            system("cls");
            if(chee){
                data1[J].time = (float)(clock()- time_req)/CLOCKS_PER_SEC;
                int jj=J;
                for(int j=jj-1 ; j>=0 ; j--){
                    if(data1[jj].time<data1[j].time){
                        strcpy(B.name,data1[jj].name);
                        B.time = data1[jj].time;
                        strcpy(data1[jj].name,data1[j].name);
                        data1[jj].time = data1[j].time;
                        strcpy(data1[j].name,B.name);
                        data1[j].time = B.time;
                        jj--;
                    }
                }
            }
            Sleep(300);
            if(chee) winn();
            int j;
            printf("\n\n\n\n\n\n\n\n\n                                                                            - SCORE BOARD -\n");
                              printf("                                                                      ---------------------------\n\n");
            for(j=0 ; j<=J&&j<=14 ; j++){
                              printf("                                                                %d.%s " ,j+1,data1[j].name);
                for(int k=0 ; k<11-strlen(data1[j].name) ; k++) printf(" ");
                printf(": %d minutes %.2f seconds\n" ,(int)data1[j].time/60,(float)((int)data1[j].time%60+data1[j].time-(int)data1[j].time));
            }
            for(int k=0 ; k<10-j ; k++) printf("\n");
            printf("                                                                    Press -SPACE BAR- to continue.\n");
            x=getch();
            while(x!=' ') x=getch();
            system("cls");
            J++;
        }

        else if(n=='3'){
            system("cls");
            printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n                                                                      *name must be 3-10 characters*\n\n");
            printf("                                               Enter your name : ");
            gets(data2[K].name);
            while(strlen(data2[K].name)>10||strlen(data2[K].name)<3){
                system("cls");
                printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n                                                                      *name must be 3-10 characters*\n\n");
                printf("                                               Enter your name : ");
                gets(data2[K].name);
            }
            system("cls");
            printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n                                                                      Press -SPACE BAR- to start.\n");
            x=getch();
            while(x!=' ') x=getch();
            system("cls");
            time_req = clock();
            if(!cut(random(19))){
                system("cls");
                gover();
                K--;
                chee=0;
            }
            Sleep(300);
            system("cls");
            if(chee&&chara(random(6))){
                system("cls");
                gover();
                K--;
                chee=0;
            }
            Sleep(300);
            system("cls");
            if(chee&&maze(random(6))){
                system("cls");
                gover();
                K--;
                chee=0;
            }
            Sleep(300);
            system("cls");
            if(chee&&con(random(6))){
                system("cls");
                gover();
                K--;
                chee=0;
            }
            Sleep(300);
            system("cls");
            if(chee&&secret(random(3))){
                system("cls");
                gover();
                K--;
                chee=0;
            }
            Sleep(300);
            system("cls");
            if(chee){
                data2[K].time = (float)(clock()- time_req)/CLOCKS_PER_SEC;
                int kk=K;
                for(int j=kk-1 ; j>=0 ; j--){
                    if(data2[kk].time<data2[j].time){
                        strcpy(B.name,data2[kk].name);
                        B.time = data2[kk].time;
                        strcpy(data2[kk].name,data2[j].name);
                        data2[kk].time = data2[j].time;
                        strcpy(data2[j].name,B.name);
                        data2[j].time = B.time;
                        kk--;
                    }
                }
            }
            Sleep(300);
            if(chee) winn();
            int j;
            printf("\n\n\n\n\n\n\n\n\n                                                                            - SCORE BOARD -\n");
                              printf("                                                                      ---------------------------\n\n");
            for(j=0 ; j<=K&&j<=14 ; j++){
                              printf("                                                                %d.%s " ,j+1,data2[j].name);
                for(int k=0 ; k<11-strlen(data2[j].name) ; k++) printf(" ");
                printf(": %d minutes %.2f seconds\n" ,(int)data2[j].time/60,(float)((int)data2[j].time%60+data2[j].time-(int)data2[j].time));
            }
            for(int k=0 ; k<10-j ; k++) printf("\n");
            printf("                                                                    Press -SPACE BAR- to continue.\n");
            x=getch();
            while(x!=' ') x=getch();
            system("cls");
            K++;
        }
    }


    return 0;
}
