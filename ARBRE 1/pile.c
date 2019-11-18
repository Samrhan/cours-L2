


t_Node* depiler(Pile *pile)
{
    t_Node* nombreDepile = NULL;
    Element *elementDepile = pile->premier;

    if (pile != NULL && pile->premier != NULL)
    {
        nombreDepile = elementDepile->branche;
        pile->premier = elementDepile->suivant;

        free(elementDepile);
    }

    return nombreDepile;
}

void empiler(Pile *pile, t_Node* nvNombre)
{
    Element *nouveau = malloc(sizeof(Element));
    nouveau->branche = nvNombre;
    nouveau->suivant = pile->premier;
    pile->premier = nouveau;
}

void affichage_prefix(t_Node* arbre){
    Pile *prefix = malloc(sizeof(Pile));
    prefix->premier = NULL;
    empiler(prefix, arbre);
    t_Node* tmp = arbre;
    while(prefix->premier){
        tmp = depiler(prefix);
        printf("%d=>", tmp->info);
        if(tmp->droit)
            empiler(prefix, tmp->droit);
        if(tmp->gauche)
            empiler(prefix, tmp->gauche);
    }

}

void enfiler(File *file, t_Node* nvNombre)
{
    Element *nouveau = malloc(sizeof(Element));

    nouveau->branche = nvNombre;
    nouveau->suivant = NULL;

    if (file->premier != NULL) /* La file n'est pas vide */
    {
        /* On se positionne à la fin de la file */
        Element *elementActuel = file->premier;
        while (elementActuel->suivant != NULL)
        {
            elementActuel = elementActuel->suivant;
        }
        elementActuel->suivant = nouveau;
    }
    else /* La file est vide, notre élément est le premier */
    {
        file->premier = nouveau;
    }
}

t_Node* defiler(File *file)
{

    t_Node* nombreDefile = NULL;

    /* On vérifie s'il y a quelque chose à défiler */
    if (file->premier != NULL)
    {
        Element *elementDefile = file->premier;

        nombreDefile = elementDefile->branche;
        file->premier = elementDefile->suivant;
        free(elementDefile);
    }

    return nombreDefile;
}

void affichage_largeur(t_Node* tree){
    File *largeur = malloc(sizeof(File));
    largeur->premier = NULL;
    t_Node* tmp = tree;
    enfiler(largeur, tmp);
    while(largeur->premier){
        tmp = defiler(largeur);
        printf("%d=>", tmp->info);
        if(tmp->droit)
            enfiler(largeur, tmp->droit);
        if(tmp->gauche)
            enfiler(largeur, tmp->gauche);


    }
}
