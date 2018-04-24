#include <iostream>

using namespace std;


int main()
{
  //inicializo las varibales a usar
  int c =1;
  double dt = 0.01;
  int nt = 700;
  double x = -2.0;
  double dx = c*dt;
  int n = 0;
  while(x<=2)
    {
      x = x + dx;
      n+1;
    }
  x = -2.0;
  double u0[n];
  double u1[n];
  double r;
  //defino r dx es el numero de pasos de -2 a 2 que sean 700 puntos
  r = c*dt/dx;
  
  int i;
  //primer valor de u
  u0[0] = 0.0;
  //se agregan los valores de u
  for (i=1;i<n;i++)
    {
      x = x+dx;
      
      if(x<=0.5 && x>= -0.5)
	{
	  u0[i]= 0.5;
	}
      else
	{
	  u0[i]=0.0;
	}
    }

  //valores a imprimmir
  int k;
  double up1[n];
  double up2[n];
  double up3[n];
  double up4[n];
  double up5[n];
  
  //inserta u1
  for(i=1; i<n-1; i++)
    {
      u1[i]= u0[i]+((r*r)/2)*(u0[i+1]-2*u0[i]+u0[i-1]);
       
    }
  //por frontera es tiene estos
  u1[0]= u1[1];
  u1[n-1]= u1[n-2];

  int j;
  double usig[n];
  //ahora si el ciclo para 5 snapshots cada 700 pasos de tiempo
    for (k=0;k<5;k++)
    {
  for (j=1; j<n-1;j++)
    {
      //valor de uj y todos sus i
      for (i=1; i<n-1;i++)
	{
	  usig[i] = 2*(1-r*r)*u1[i]-u0[i]+(r*r)*(u1[i+1]+u1[i-1]);
	}
      usig[0]=usig[1];
      usig[n-1]=usig[n-2];
      //se remplazan valores para continuar
      for(i=0;i<n;i++)
	{
	  u0[i]= u1[i];
	  u1[i]= usig[i];
       
	}
    }
  //se guardan valores a imprimir
  for(i=0;i<n;i++)
    {
      if(k==1)
	{
	  up1[i]=u1[i];
	}
      else if(k==2)
	{
	  up2[i]=u1[i];
	}
      else if(k==3)
	{
	  up3[i]=u1[i];	  
	}
      else if(k==4)
	{
	  up4[i]=u1[i];
	}
      else if(k==5)
	{
	  up5[i]=u1[i];
	}
    }
  
    }

    int s;
    for (s = 0;s<700;s++)
      {
	cout << up1[s] << " " << up2[s] << " " << up3[s] << " "<< up4[s] << " "<< up5[s] << "\n";
      }
    
}
