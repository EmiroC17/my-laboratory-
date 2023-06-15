#include <stdio.h>
#include <conio.h>
#include <iostream>
using namespace std;

struct pointer
{ int d;
  pointer *p;
};

//=====================
void FormOch(pointer **ph, int data)
{
 *ph = new pointer;
 
 (*ph) -> d = data;
 (*ph)->p = NULL;
}

//======================
void DobOch (pointer **pk, int data)
      {   
	  pointer *px=new pointer;
	  px->d=data;
	  px->p=NULL;
	  (*pk)->p=px;
	  *pk=px;
	  //(*pk)->p=NULL;
       }
//======================
void IskOch (pointer **ph, int &data)
{ data = (*ph)->d;
  *ph = (*ph)->p;
}
//======================
void FormSt(pointer **ph, int data)
{
 *ph = new pointer;
 (*ph) -> d = data;
 (*ph)->p = NULL;
}
//====================== 
void DobSt (pointer **ph, int data)
      { 
      pointer *px=new pointer;
	 px->d=data;
	 px->p=*ph;
	 *ph=px;
       }
//====================== 
void IskSt (pointer **ph, int &data)
{ data = (*ph)->d;
  *ph = (*ph)->p;
}

//======================
int main()
{
//system("cls");
// ======= Формирование очереди ======
 pointer *ph=NULL;
 cout<<"Input element -->" ;
 int data;
 cin >> data ;
 
 FormOch(&ph, data);
 pointer *pk = ph;
  int i = 1;
//cout<<"====="<<ph->d<<pk->d;
// ======= Добавление в очередь ======
while (data!=0)
 {
	cout<<"Input "<<i+1<<"element -->" ;
	cin >> data;
	DobOch(&pk, data);
	i++;
 }
 
 i=0;
 pointer *pc = ph; // дополнительный указатель на вершину списка
 // Вывод очереди на экран
 
 pointer *ph_st = NULL;	// указатель на вершину стека
 IskOch(&pc, data);
 FormSt(&ph_st, data);
 
 while (pc != NULL)
  {
      IskOch(&pc, data);
      DobSt(&ph_st, data);
      //cout<<(i+1)<<" element  = "<<data<<"\n";
      //i++;
   }
  cout<<"\nVivod invers: \n\n";
  while (ph_st!=NULL)    
  {
      IskSt(&ph_st, data);
      cout<<(i+1)<<" element  = "<<data<<"\n";
      i++;
   } 
 
getch();
 }
