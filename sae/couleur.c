#include <stdio.h>
#include <windows.h>

#include "fonctions.h"

void Couleur(int ForgC)
 {
 WORD wColor;

  HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
  CONSOLE_SCREEN_BUFFER_INFO csbi;

                       //On utilise csbi pour les attributs mots
 if(GetConsoleScreenBufferInfo(hStdOut, &csbi))
 {
                 // On masque les attributs du fond et on ajoute de la couleur au texte
      wColor = (csbi.wAttributes & 0xF0) + (ForgC & 0x0F);
      SetConsoleTextAttribute(hStdOut, wColor);
 }
 return;
}
