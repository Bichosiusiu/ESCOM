#include<stdio.h>
typedef struct{
        int e;
        int n;
        int d;
} Fraccion;

void ImpFrac(Fraccion);
Fraccion LeeFrac();
Fraccion SumaFrac(Fraccion,Fraccion);
Fraccion RestaFrac(Fraccion,Fraccion);
Fraccion MultFrac(Fraccion,Fraccion);
Fraccion DivFrac(Fraccion,Fraccion);
Fraccion ReducFrac(Fraccion);
int mcm(int,int);
int mcd(int,int);

int main(){
    Fraccion a, b, c;
    a=LeeFrac();
    b=LeeFrac();

    ImpFrac(SumaFrac(a,b));
    ImpFrac(RestaFrac(a,b));
    ImpFrac(MultFrac(a,b));


    return 0;
}
void ImpFrac(Fraccion f){printf("%d[%d|%d]\n",f.e,f.n,f.d);};
Fraccion LeeFrac(){
    Fraccion r;
    scanf("%d%d%d",&r.e,&r.n,&r.d);
    return r;
};

Fraccion SumaFrac(Fraccion f1, Fraccion f2){
    Fraccion r;
    r.d=mcm(f1.d,f2.d);
    f1.n=f1.e*f1.d+f1.n;
    f2.n=f2.e*f2.d+f2.n;
    r.n=f1.n*(r.d/f1.d)+f2.n*(r.d/f2.d);
    return ReducFrac(r);
};
Fraccion RestaFrac(Fraccion f1, Fraccion f2){
    Fraccion r;
    r.d=mcm(f1.d,f2.d);
    f1.n=f1.e*f1.d+f1.n;
    f2.n=f2.e*f2.d+f2.n;
    r.n=f1.n*(r.d/f1.d)-f2.n*(r.d/f2.d);
    return ReducFrac(r);
};
Fraccion ReducFrac(Fraccion f){
    Fraccion r;
    int x;

    r.e=f.n/f.d;
    f.n=f.n%f.d;
    x=mcd(f.n,f.d);
    r.n=f.n/x;
    r.d=f.d/x;
    return r;
};
Fraccion MultFrac(Fraccion f1, Fraccion f2){
    Fraccion r;
    r.d=mcm(f1.d,f2.d);
    f1.n=f1.e*f1.d+f1.n;
    f2.n=f2.e*f2.d+f2.n;
    r.n=f1.n*f2.n;
    r.d=f1.d*f2.d;
    return ReducFrac(r);
};
Fraccion DivFrac(Fraccion f1, Fraccion f2){
     return f1;
};
int mcm(int a, int b){return (a*b)/mcd(a,b);};
int mcd(int a, int b){
    if(b==1)
        return 1;
    else if(a==b)
            return a;
         else if(a<b)
               return mcd(b,a);
              else
                return mcd(a-b,b);
};
