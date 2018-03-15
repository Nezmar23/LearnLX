#include <stdio.h>
#include <stdlib.h>

// Vlozeni hlavickoveho souboru sqlite
#include <sqlite3.h>

int main() {
    sqlite3 * data;
    int r;
    int pcisloC;
   const unsigned char * slovyC;
   const unsigned char * popisC;
   sqlite3_stmt * s;




   // const unsigned char * datumDB;

    // Otevreni databaze
    r = sqlite3_open("data.db", &data);
    if (r != SQLITE_OK) {
        printf("Chyba pri otevirani db!\n");
        exit(EXIT_FAILURE);
    }
    else {

        printf("DB uspesne otevrena.\n");
    }

    // Zpracovani vracenych zaznamu z databaze
        
    r = sqlite3_prepare(data,"select pcislo, slovy, NULL, popis from tabulka1",-1, &s,NULL);
      if (r != SQLITE_OK) {
    	    printf("Chyba pri priprave db statement!\n");
     	    exit(EXIT_FAILURE);
  			  }


    printf("Seznam osob v tabulce persons\n=====\n");
    while (sqlite3_step(s) == SQLITE_ROW) {
	    pcisloC = sqlite3_column_int(s, 0);
	    slovyC = sqlite3_column_text(s, 1);
            popisC = sqlite3_column_text(s, 3);
            printf("cislo: %d %s %s \n",pcisloC ,slovyC ,popisC);
                                           }			



    // Zavreni db statement
    r = sqlite3_finalize(s);
    if (r != SQLITE_OK) {
        printf("Chyba pri uzavreni db statement!\n");
        exit(EXIT_FAILURE);
    }

    // Zavreni databaze
    sqlite3_close(data);
    printf("=====\nUzavreni db statement!\n");
    return EXIT_SUCCESS;

    
}
