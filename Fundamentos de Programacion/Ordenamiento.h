void Burbuja(Elem a[], int n){
   int i,j;

    for(j=0;j<n-1;j++)
      for(i=n-1;i>j;i--)
         if(EsMenor(a[i],a[i-1]))
           Intercambia(a+i,a+i-1);

}
