typedef int Elem;

void ImpElem(Elem e){printf("%d",e);}
Elem LeeElem(){int e; scanf("%d",&e); return e;}
int EsMenor(Elem e1, Elem e2){return e1<e2;}
void Intercambia(Elem *e1, Elem *e2){
    Elem t;
    t=*e1; *e1=*e2; *e2=t;
}
