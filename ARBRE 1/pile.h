
#ifndef pile_header
#define pile_header

#include "pile.c"

void empiler(Pile *pile, t_Node* nvNombre);

t_Node* depiler(Pile *pile);

void affichage_prefix(t_Node* arbre);

#endif // pile_header
