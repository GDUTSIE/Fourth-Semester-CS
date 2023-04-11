//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "storage.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
int rand1[10],rand2[10],rand3[10];
Tmianform *mianform;
//---------------------------------------------------------------------------
__fastcall Tmianform::Tmianform(TComponent* Owner)
	: TForm(Owner)
{
  this->Button3->Enabled = FALSE;
  this->Button4->Enabled = FALSE;
  this->Button5->Enabled = FALSE;
  this->StringGrid_memory->Cells[0][0] = "ID";
  this->StringGrid_memory->Cells[1][0] = "原始空间大小";
  this->StringGrid_memory->Cells[2][0] = "剩余空间大小";
  this->StringGrid_memory->Cells[3][0] = "首地址";
  this->StringGrid_memory->Cells[4][0] = "分配的作业";
  this->StringGrid_work->Cells[0][0] = "ID";
  this->StringGrid_work->Cells[1][0] = "作业大小";
  this->StringGrid_work->Cells[2][0] = "对应区块";
  this->StringGrid_work->Cells[3][0] = "状态";
}
//---------------------------------------------------------------------------
void __fastcall Tmianform::Button1Click(TObject *Sender)
{
	this->Button5->Enabled = TRUE;
	int x=1,y=100,i,j;
	srand((unsigned)time(NULL));
	for(i=1;i<=10;i++)
	{
		rand1[i] = rand()%(y-x+1)+x;
		rand2[i] = rand()%(y-x+1)+x;
	}
	for(j=1;j<=10;j++)
	{
		this->StringGrid_memory->Cells[0][j] = j;
		this->StringGrid_memory->Cells[1][j] = rand1[j];
		this->StringGrid_memory->Cells[2][j] = rand1[j];
		this->StringGrid_memory->Cells[3][j] = rand2[j];
		this->memory[j].id = j;
		this->memory[j].original_size = rand1[j];
		this->memory[j].rest_size = rand1[j];
		this->memory[j].head_address = rand2[j];
		this->memory[j].work = this->StringGrid_work->Cells[4][j];

	}
}
//---------------------------------------------------------------------------
void __fastcall Tmianform::Button2Click(TObject *Sender)
{
   this->Button5->Enabled = TRUE;
   int x=1,y=100,i,j;
   srand((unsigned)time(NULL));
   for(i=1;i<=10;i++)
   {
	 rand3[i] = rand()%(y-x+1)+x;
   }
   for(j=1;j<=10;j++)
   {
	 this->StringGrid_work->Cells[0][j] = j;
	 this->StringGrid_work->Cells[1][j] = rand3[j];
	 this->StringGrid_work->Cells[3][j] = "N";

   }
}
//---------------------------------------------------------------------------

void __fastcall Tmianform::RadioButton1Click(TObject *Sender)
{
 this->Button3->Enabled = TRUE;
 int i,j;
 for(i=1;i<=10;i++)
 {
	 this->StringGrid_memory->Cells[0][i] = i;
	 this->StringGrid_memory->Cells[1][i] = rand1[i];
	 this->StringGrid_memory->Cells[2][i] = rand1[i];
	 this->StringGrid_memory->Cells[3][i] = rand2[i];
	 this->StringGrid_memory->Cells[4][i] = "";

 }
  for(j=1;j<=10;j++)
   {
	 this->StringGrid_work->Cells[0][j] = j;
	 this->StringGrid_work->Cells[1][j] = rand3[j];
	 this->StringGrid_work->Cells[2][j] = "";
	 this->StringGrid_work->Cells[3][j] = "N";

   }
}
//---------------------------------------------------------------------------
void __fastcall Tmianform::RadioButton2Click(TObject *Sender)
{
this->Button3->Enabled = TRUE;
  int i,j;
 for(i=1;i<=10;i++)
 {
	 this->StringGrid_memory->Cells[0][i] = i;
	 this->StringGrid_memory->Cells[1][i] = rand1[i];
	 this->StringGrid_memory->Cells[2][i] = rand1[i];
	 this->StringGrid_memory->Cells[3][i] = rand2[i];
	 this->StringGrid_memory->Cells[4][i] = "";

 }
  for(j=1;j<=10;j++)
   {
	 this->StringGrid_work->Cells[0][j] = j;
	 this->StringGrid_work->Cells[1][j] = rand3[j];
	 this->StringGrid_work->Cells[2][j] = "";
	 this->StringGrid_work->Cells[3][j] = "N";

   }
}
//---------------------------------------------------------------------------
void __fastcall Tmianform::RadioButton3Click(TObject *Sender)
{
 this->Button3->Enabled = TRUE;
 int i,j;
 bubblesort(memory,10);
 for(i=1;i<=10;i++)
 {
	 this->StringGrid_memory->Cells[0][i] = memory[i].id;
	 this->StringGrid_memory->Cells[1][i] = memory[i].original_size;
	 this->StringGrid_memory->Cells[2][i] = memory[i].rest_size;
	 this->StringGrid_memory->Cells[3][i] = memory[i].head_address;
	 this->StringGrid_memory->Cells[4][i] = memory[i].work;
 }
 for(j=1;j<=10;j++)
 {
	 this->StringGrid_work->Cells[2][j] = "";
	 this->StringGrid_work->Cells[3][j] = "N";
	 this->StringGrid_memory->Cells[4][j] = "";
 }
}
//---------------------------------------------------------------------------
void __fastcall Tmianform::Button3Click(TObject *Sender)
{
 this->Button3->Enabled = FALSE;
 int i,j,k,temp=1;
 if(this->RadioButton1->Checked == TRUE)
 {
	for(i=1;i<=10;i++)
	{
		for(j=1;(j<=10)&&(StrToInt(this->StringGrid_memory->Cells[2][j]) < rand3[i]);j++)
		{
			 ;
		}
		if(j>10)
		{
		   this->StringGrid_work->Cells[2][i] = "未分配";
		   this->StringGrid_work->Cells[3][i] = "N";
		}
		else if(StrToInt(this->StringGrid_memory->Cells[2][j]) >= rand3[i])
		{
			this->StringGrid_memory->Cells[2][j] = StrToInt(this->StringGrid_memory->Cells[2][j]) - rand3[i];
			this->StringGrid_memory->Cells[4][j] = this->StringGrid_memory->Cells[4][j]+"|"+i;
			this->StringGrid_work->Cells[2][i] = j;
			this->StringGrid_work->Cells[3][i] = "Y";
		}
	}
 }
 else if(this->RadioButton2->Checked == TRUE)
 { int sum;
 for(i=1;i<=10;i++)
 {
	for(j=temp,sum=1;sum<10;j++)
   {
	   k=j%10;
	   if(k==0) k=k+10;
	   sum++;
	   if(StrToInt(this->StringGrid_memory->Cells[2][k]) >= rand3[i])
	   {
		   break;
	   }
   }
   if(sum==10)
   {
	   this->StringGrid_work->Cells[2][i] = "未分配";
	   this->StringGrid_work->Cells[3][i] = "N";
   }
   else if(StrToInt(this->StringGrid_memory->Cells[2][k])>=rand3[i])
   {
	  temp=k+1;
	  this->StringGrid_memory->Cells[2][k] = StrToInt(this->StringGrid_memory->Cells[2][k]) - rand3[i];
	  this->StringGrid_memory->Cells[4][k] = this->StringGrid_memory->Cells[4][k]+"|"+i;
	  this->StringGrid_work->Cells[2][i] = k;
	  this->StringGrid_work->Cells[3][i] = "Y";
   }
 }
 }
 else if(this->RadioButton3->Checked == TRUE)
 {

	  for(i=1;i<=10;i++)
	  {
		  for(j=1;j<=10&&memory[j].rest_size<rand3[i];j++)
		  {
			  ;
		  }
		  if(j>10)
		  {
			this->StringGrid_work->Cells[2][i] = "未分配";
			this->StringGrid_work->Cells[3][i] = "N"; ;
		  }
		  else if(memory[j].rest_size>=rand3[i])
		  {
			this->StringGrid_memory->Cells[2][j] = StrToInt(this->StringGrid_memory->Cells[2][j]) - rand3[i];
			this->StringGrid_memory->Cells[4][j] = this->StringGrid_memory->Cells[4][j]+"|"+i;
			this->memory[j].rest_size = StrToInt(this->StringGrid_memory->Cells[2][j]);
			this->memory[j].work = this->StringGrid_memory->Cells[4][j];
			this->StringGrid_work->Cells[2][i] = this->memory[j].id;
			this->StringGrid_work->Cells[3][i] = "Y";
			bubblesort(memory,10);
			for(int z=1;z<=10;z++)
			{
			  this->StringGrid_memory->Cells[0][z] = memory[z].id;
			  this->StringGrid_memory->Cells[1][z] = memory[z].original_size;
			  this->StringGrid_memory->Cells[2][z] = memory[z].rest_size;
			  this->StringGrid_memory->Cells[3][z] = memory[z].head_address;
			  this->StringGrid_memory->Cells[4][z] = memory[z].work;
			}
		  }
	  }


 }
 else
 {
	MessageBox(NULL,L"请选择算法",L"Tips",MB_OK);
 }

}
//---------------------------------------------------------------------------
void Tmianform::bubblesort(MCB *A,int n)
{
   int i,j;
   MCB t;
	 for(i=0;i<n-1;i++)
	{
	  for(j=n;j>i;j--)
	  {
		  if(A[j].rest_size<A[j-1].rest_size)
		  {
			 t=A[j];
			 A[j]=A[j-1];
			 A[j-1]=t;
		  }
	  }
	}


}
//
void __fastcall Tmianform::Button5Click(TObject *Sender)
{
  this->Button4->Enabled = TRUE;
  this->Button3->Enabled = TRUE;
  int i,j,k;
   for(j=1;j<=10;j++)
  {
	 this->StringGrid_memory->Cells[0][j] = j;
	 this->StringGrid_memory->Cells[1][j] = rand1[j];
	 this->StringGrid_memory->Cells[2][j] = rand1[j];
	 this->StringGrid_memory->Cells[3][j] = rand2[j];
	 this->StringGrid_memory->Cells[4][j] = "";
	 this->memory[j].id = j;
	 this->memory[j].original_size = rand1[j];
	 this->memory[j].rest_size = rand1[j];
	 this->memory[j].head_address = rand2[j];
	 this->memory[j].work = this->StringGrid_work->Cells[4][j];

  }
  for(k=1;k<=10;k++)
   {
	 this->StringGrid_work->Cells[0][k] = k;
	 this->StringGrid_work->Cells[1][k] = rand3[k];
	 this->StringGrid_work->Cells[2][k] = "";
	 if(this->StringGrid_work->Cells[3][k] == "Y")
	 {
		this->StringGrid_work->Cells[3][k] = "已完成";
	 }
	 else
	 ;

   }
}
//---------------------------------------------------------------------------
void __fastcall Tmianform::Button4Click(TObject *Sender)
{
	this->Button3->Enabled = TRUE;
	int i,j,temp=1;
	for(i=1;i<=10;i++)
	{
	  if(this->StringGrid_work->Cells[3][i]=="N")
	  {
         if(this->RadioButton1->Checked == TRUE)
		{
				for(j=1;(j<=10)&&(StrToInt(this->StringGrid_memory->Cells[2][j]) < rand3[i]);j++)
				  {
						;
				  }
				if(j>10)
				{
					this->StringGrid_work->Cells[2][i] = "未分配";
					this->StringGrid_work->Cells[3][i] = "N";
				}
				else if(StrToInt(this->StringGrid_memory->Cells[2][j]) >= rand3[i])
				{
					this->StringGrid_memory->Cells[2][j] = StrToInt(this->StringGrid_memory->Cells[2][j]) - rand3[i];
					this->StringGrid_memory->Cells[4][j] = this->StringGrid_memory->Cells[4][j]+"|"+i;
					this->StringGrid_work->Cells[2][i] = j;
					this->StringGrid_work->Cells[3][i] = "Y";
				}
		}
		 else if(this->RadioButton2->Checked == TRUE)
		 {
				int sum,k;
				for(j=temp,sum=1;sum<10;j++)
				{
					k=j%10;
					if(k==0) k=k+10;
					sum++;
					if(StrToInt(this->StringGrid_memory->Cells[2][k]) >= rand3[i])
					{
						break;
					}
				}
				if(sum==10)
				{
					this->StringGrid_work->Cells[2][i] = "未分配";
					this->StringGrid_work->Cells[3][i] = "N";
				}
				 else if(StrToInt(this->StringGrid_memory->Cells[2][k])>=rand3[i])
				{
					 temp=k+1;
					 this->StringGrid_memory->Cells[2][k] = StrToInt(this->StringGrid_memory->Cells[2][k]) - rand3[i];
					 this->StringGrid_memory->Cells[4][k] = this->StringGrid_memory->Cells[4][k]+"|"+i;
					 this->StringGrid_work->Cells[2][i] = k;
					 this->StringGrid_work->Cells[3][i] = "Y";
				}

		 }
		  else if(this->RadioButton3->Checked == TRUE)
			{
					 for(j=1;j<=10&&memory[j].rest_size<rand3[i];j++)
					 {
							;
					 }
					 if(j>10)
					 {
						this->StringGrid_work->Cells[2][i] = "未分配";
						this->StringGrid_work->Cells[3][i] = "N"; ;
					 }
					 else if(memory[j].rest_size>=rand3[i])
					{
						this->StringGrid_memory->Cells[2][j] = StrToInt(this->StringGrid_memory->Cells[2][j]) - rand3[i];
						this->StringGrid_memory->Cells[4][j] = this->StringGrid_memory->Cells[4][j]+"|"+i;
						this->memory[j].rest_size = StrToInt(this->StringGrid_memory->Cells[2][j]);
						this->memory[j].work = this->StringGrid_memory->Cells[4][j];
						this->StringGrid_work->Cells[2][i] = this->memory[j].id;
						this->StringGrid_work->Cells[3][i] = "Y";
						bubblesort(memory,10);
						for(int z=1;z<=10;z++)
						{
							this->StringGrid_memory->Cells[0][z] = memory[z].id;
							this->StringGrid_memory->Cells[1][z] = memory[z].original_size;
							this->StringGrid_memory->Cells[2][z] = memory[z].rest_size;
							this->StringGrid_memory->Cells[3][z] = memory[z].head_address;
							this->StringGrid_memory->Cells[4][z] = memory[z].work;
						}
					}
			}
	  }
	}
 }

//---------------------------------------------------------------------------

void __fastcall Tmianform::Button6Click(TObject *Sender)
{
	this->RadioButton1->Checked = FALSE;
	this->RadioButton2->Checked = FALSE;
	this->RadioButton3->Checked = FALSE;
	this->Button3->Enabled = FALSE;
	this->Button4->Enabled = FALSE;
	this->Button5->Enabled = FALSE;
	int i,j;
	for(i=1;i<=10;i++)
	{
		for(j=0;j<=4;j++)
		{
			this->StringGrid_memory->Cells[j][i] = "";
		}

	}
		for(i=1;i<=10;i++)
		{
			for(j=0;j<=3;j++)
			{
				this->StringGrid_work->Cells[j][i] = "";
			}
		}

}
//---------------------------------------------------------------------------

