#ifndef structs_header
#define structs_header


typedef struct t_Node {
    int info;
    struct t_Node* gauche;
    struct t_Node* droit;
} t_Node;
typedef struct Element
{
    t_Node* branche;
    struct Element *suivant;
}Element;

typedef struct Pile
{
    Element *premier;
}Pile;

typedef struct File
{
    Element *premier;
}File;

#endif // structs_header
