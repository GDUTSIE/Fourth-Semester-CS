//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "jinchengdiaodu.h"
#include <ctime>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
Tmianform *mianform;

//---------------------------------------------------------------------------
__fastcall Tmianform::Tmianform(TComponent* Owner)
	: TForm(Owner)
{

}
//---------------------------------------------------------------------------
void __fastcall Tmianform::clearClick(TObject *Sender)
{
 this-> Edit_new->Text = "";
 this->combo_new->ItemIndex = -1;
 this->Combo_newSourse->ItemIndex = -1;
}
//---------------------------------------------------------------------------
void __fastcall Tmianform::FormCreate(TObject *Sender)
{
 this->done->Enabled = FALSE;
 this->ready_queue->Cells[0][0] = "ID";
 this->ready_queue->Cells[1][0] = "进程名称";
 this->ready_queue->Cells[2][0] = "提交时间";
 this->ready_queue->Cells[3][0] = "服务时间";
 this->ready_queue->Cells[4][0] = "所需资源";
 this->ready_queue->Cells[5][0] = "状态";
 this->grid_FCFS->Cells[0][0] = "ID";
 this->grid_FCFS->Cells[1][0] = "进程名称";
 this->grid_FCFS->Cells[2][0] = "开始时间";
 this->grid_FCFS->Cells[3][0] = "服务时间";
 this->grid_FCFS->Cells[4][0] = "完成时间";
 this->grid_FCFS->Cells[5][0] = "所需资源";
 this->grid_FCFS->Cells[6][0] = "状态";
 this->grid_FCFS->Cells[7][0] = "周转时间";
 this->grid_FCFS->Cells[8][0] = "带权周转时间";
 this->grid_SPF->Cells[0][0] = "ID";
 this->grid_SPF->Cells[1][0] = "进程名称";
 this->grid_SPF->Cells[2][0] = "开始时间";
 this->grid_SPF->Cells[3][0] = "服务时间";
 this->grid_SPF->Cells[4][0] = "完成时间";
 this->grid_SPF->Cells[5][0] = "所需资源";
 this->grid_SPF->Cells[6][0] = "状态";
 this->grid_SPF->Cells[7][0] = "周转时间";
 this->grid_SPF->Cells[8][0] = "带权周转时间";
 sum = 0;
}
//---------------------------------------------------------------------------
void __fastcall Tmianform::doneClick(TObject *Sender)
{
  int i,j;
  for(i = 1;this->ready_queue->Cells[0][i] != "";i++)
  {
	;
  }
  this->ready_queue->Cells[0][i] = i;
  this->ready_queue->Cells[1][i] = this->Edit_new->Text;
  this->ready_queue->Cells[2][i] = i;
  this->ready_queue->Cells[3][i] = this->combo_new->Text;
  this->ready_queue->Cells[4][i] = this->Combo_newSourse->Text;
  this->ready_queue->Cells[5][i] = "W";
  ready[i].id = i;
  ready[i].name =  this->Edit_new->Text;
  ready[i].submit_time = i;
  ready[i].service_time = StrToInt(this->combo_new->Text);
  ready[i].source = StrToInt(this->Combo_newSourse->Text);
  ready[i].status = 'W';
  this-> Edit_new->Text = "";
  this->combo_new->ItemIndex = -1;
  this->Combo_newSourse->ItemIndex = -1;
  sum++;
  this->done->Enabled = FALSE;
}
//---------------------------------------------------------------------------
void __fastcall Tmianform::runClick(TObject *Sender)
{
	int i;
	this->Label2->Caption = sum;
	//运行的同时开始计时
	this->Timer1->Enabled = TRUE;
	//将就绪队列队首的进程移动到正在执行队列中（代表调度进CPU）
	this->run_id->Caption = this->ready_queue->Cells[0][1];
	this->run_name->Caption = this->ready_queue->Cells[1][1];
	this->run_service_time->Caption = this->ready_queue->Cells[3][1];
	this->run_source->Caption = this->ready_queue->Cells[4][1];
	this->run_status->Caption = 'R';
	this->run_start_time->Caption = this->Label2->Caption;
	this->run_rest_time->Caption = this->run_service_time->Caption;
	this->run_finish_time->Caption = 0;
	sum--;


   //就绪队列调整
	  for(i=2;this->ready_queue->Cells[0][i]!="";i++)
	  {
		this->ready_queue->Cells[0][i-1] = this->ready_queue->Cells[0][i];
		this->ready_queue->Cells[1][i-1] = this->ready_queue->Cells[1][i];
		this->ready_queue->Cells[2][i-1] = this->ready_queue->Cells[2][i];
		this->ready_queue->Cells[3][i-1] = this->ready_queue->Cells[3][i];
		this->ready_queue->Cells[4][i-1] = this->ready_queue->Cells[4][i];
		this->ready_queue->Cells[5][i-1] = this->ready_queue->Cells[5][i];
	  }
	 this->ready_queue->Cells[0][i-1] = "";
	 this->ready_queue->Cells[1][i-1] = "";
	 this->ready_queue->Cells[2][i-1] = "";
	 this->ready_queue->Cells[3][i-1] = "";
	 this->ready_queue->Cells[4][i-1] = "";
	 this->ready_queue->Cells[5][i-1] = "";


	}





//---------------------------------------------------------------------------
void __fastcall Tmianform::Timer1Timer(TObject *Sender)
{
	this->Label2->Caption = IntToStr(StrToInt(this->Label2->Caption)+1);
	if(StrToInt(this->run_start_time->Caption)+StrToInt(this->run_finish_time->Caption) != StrToInt(this->run_start_time->Caption)+StrToInt(this->run_service_time->Caption))
	{
		this->run_finish_time->Caption =  IntToStr(StrToInt(this->Label2->Caption)- StrToInt(this->run_start_time->Caption));
	}
	if(this->run_rest_time->Caption != 0)
	{
		this->run_rest_time->Caption = IntToStr(StrToInt(this->run_service_time->Caption)-StrToInt(this->run_finish_time->Caption));
	}
	if(this->run_finish_time->Caption == this->run_service_time->Caption)
	{
		if(this->radio_FCFS->Checked == TRUE)
		{
		  int i;
		  for(i=1; this->grid_FCFS->Cells[0][i]!="";i++)
		  {
			  ;
		  }
		  this->grid_FCFS->Cells[0][i] =  this->run_id->Caption;
		  this->grid_FCFS->Cells[1][i] =  this->run_name->Caption;
		  this->grid_FCFS->Cells[2][i] =  this->run_start_time->Caption;
		  this->grid_FCFS->Cells[3][i] =  this->run_service_time->Caption;
		  this->grid_FCFS->Cells[4][i] =  StrToInt(this->run_start_time->Caption) + StrToInt(this->run_service_time->Caption);
		  this->grid_FCFS->Cells[5][i] =  this->run_source->Caption;
		  this->grid_FCFS->Cells[6][i] =  'F';
		  this->grid_FCFS->Cells[7][i] =  IntToStr(StrToInt(this->grid_FCFS->Cells[4][i]) - StrToInt(this->run_id->Caption));
		  this->grid_FCFS->Cells[8][i] =  (float)(StrToInt(this->grid_FCFS->Cells[7][i])) / (float)(StrToInt(this->run_service_time->Caption)) ;
		}
		else if(this->radio_SPF->Checked == TRUE)
		{
		   int i;
		   i = StrToInt(this->run_id->Caption);
//		  for(i=1; this->grid_SPF->Cells[0][i]!="";i++)
//		  {
//			  ;
//		  }
		  this->grid_SPF->Cells[0][i] =  this->run_id->Caption;
		  this->grid_SPF->Cells[1][i] =  this->run_name->Caption;
		  this->grid_SPF->Cells[2][i] =  this->run_start_time->Caption;
		  this->grid_SPF->Cells[3][i] =  this->run_service_time->Caption;
		  this->grid_SPF->Cells[4][i] =  StrToInt(this->run_start_time->Caption) + StrToInt(this->run_service_time->Caption);
		  this->grid_SPF->Cells[5][i] =  this->run_source->Caption;
		  this->grid_SPF->Cells[6][i] =  'F';
		  this->grid_SPF->Cells[7][i] =  IntToStr(StrToInt(this->grid_SPF->Cells[4][i]) - StrToInt(this->run_id->Caption));
		  this->grid_SPF->Cells[8][i] =  (float)(StrToInt(this->grid_SPF->Cells[7][i])) / (float)(StrToInt(this->run_service_time->Caption)) ;
		  }
		if(sum>0)
		{
		int i;
		//将就绪队列队首的进程移动到正在执行队列中（代表调度进CPU）
		this->run_id->Caption = this->ready_queue->Cells[0][1];
		this->run_name->Caption = this->ready_queue->Cells[1][1];
		this->run_service_time->Caption = this->ready_queue->Cells[3][1];
		this->run_source->Caption = this->ready_queue->Cells[4][1];
		this->run_status->Caption = 'R';
		this->run_start_time->Caption = this->Label2->Caption;
		this->run_rest_time->Caption = this->run_service_time->Caption;
		this->run_finish_time->Caption = 0;
		sum--;
		if(sum>=0)
		{
		 //就绪队列调整
		  for(i=2;this->ready_queue->Cells[0][i]!="";i++)
		  {
			this->ready_queue->Cells[0][i-1] = this->ready_queue->Cells[0][i];
			this->ready_queue->Cells[1][i-1] = this->ready_queue->Cells[1][i];
			this->ready_queue->Cells[2][i-1] = this->ready_queue->Cells[2][i];
			this->ready_queue->Cells[3][i-1] = this->ready_queue->Cells[3][i];
			this->ready_queue->Cells[4][i-1] = this->ready_queue->Cells[4][i];
			this->ready_queue->Cells[5][i-1] = this->ready_queue->Cells[5][i];
		  }
		 this->ready_queue->Cells[0][i-1] = "";
		 this->ready_queue->Cells[1][i-1] = "";
		 this->ready_queue->Cells[2][i-1] = "";
		 this->ready_queue->Cells[3][i-1] = "";
		 this->ready_queue->Cells[4][i-1] = "";
		 this->ready_queue->Cells[5][i-1] = "";
		}
		else
		{
		  ;
		}
		}
		else
		{
			this->Timer1->Enabled = FALSE;
			this->Label2->Caption = 0;
			this->run_id->Caption = "";
			this->run_name->Caption = "";
			this->run_rest_time->Caption = "";
			this->run_service_time->Caption = "";
			this->run_source->Caption = "";
			this->run_start_time->Caption = "";
			this->run_status->Caption = "";
			this->run_finish_time->Caption = "";
			if(MessageBox(NULL,L"进程已运行完成",L"消息",MB_OK))
			{
			  int q ;
			  for(q=1;ready[q].id != '\0';q++)
			  {
			   this->ready_queue->Cells[0][q] = ready[q].id;
			   this->ready_queue->Cells[1][q] = ready[q].name;
			   this->ready_queue->Cells[2][q] = ready[q].submit_time;
			   this->ready_queue->Cells[3][q] = ready[q].service_time;
			   this->ready_queue->Cells[4][q] = ready[q].source;
			   this->ready_queue->Cells[5][q] = ready[q].status;
			  }
			  sum = q-1;
			}


		}

	}
}
//---------------------------------------------------------------------------
void __fastcall Tmianform::radio_FCFSClick(TObject *Sender)
{
  int i,j,k;
  //算出有多少个进程
  for (i=0;ready[i+1].id; i++) {
		 ;
  }
  //将进程按提交时间先后排序，并在就绪队列中显示
   for(j=1;j<=i;j++){
	  for(k=1;ready[k].submit_time!=j;k++)
	  {
		  ;
	  }
	  this->ready_queue->Cells[0][j] = ready[k].id;
	  this->ready_queue->Cells[1][j] = ready[k].name;
	  this->ready_queue->Cells[2][j] = ready[k].submit_time;
	  this->ready_queue->Cells[3][j] = ready[k].service_time;
	  this->ready_queue->Cells[4][j] = ready[k].source;
	  this->ready_queue->Cells[5][j] = ready[k].status;
   }

}

//---------------------------------------------------------------------------

void __fastcall Tmianform::radio_SPFClick(TObject *Sender)
{
  int i,j,k,n;
  PCB temp;
  //算出有多少个进程
  for (n=1;ready[n].id; n++) {
		 ;
  }

  //用冒泡排序将进程按服务时间由短到长排序，并在就绪队列中显示
  for(i=0;i<n-2;i++)
  {
	  for(j=n-1;j>i;j--)
	  {
		  if(ready[j].service_time<ready[j-1].service_time)
		  {
			 temp=ready[j];
			 ready[j]=ready[j-1];
			 ready[j-1]=temp;
		  }
	  }
  }
  for(j=1;j<=n-1;j++)
  {
	  this->ready_queue->Cells[0][j] = ready[j].id;
	  this->ready_queue->Cells[1][j] = ready[j].name;
	  this->ready_queue->Cells[2][j] = ready[j].submit_time;
	  this->ready_queue->Cells[3][j] = ready[j].service_time;
	  this->ready_queue->Cells[4][j] = ready[j].source;
	  this->ready_queue->Cells[5][j] = ready[j].status;
  }

}
//---------------------------------------------------------------------------

void __fastcall Tmianform::button_clearClick(TObject *Sender)
{
  int i,j;
  for(i=1;this->ready_queue->Cells[0][i]!="";i++)
  {
	  for(j=0;j<6;j++)
	  {
		  this->ready_queue->Cells[j][i]="";
	  }
  }
  for(i=1;this->grid_FCFS->Cells[0][i]!="";i++)
  {
	  for(j=0;j<=8;j++)
	  {
		  this->grid_FCFS->Cells[j][i] = "";
	  }
  }
   for(i=1;this->grid_SPF->Cells[0][i]!="";i++)
  {
	  for(j=0;j<=8;j++)
	  {
		  this->grid_SPF->Cells[j][i] = "";
	  }
  }
  for(i=1;ready[i].id!='\0';i++)
  {
	  ready[i].id = '\0';
	  ready[i].name="";
	  ready[i].submit_time='\0';
	  ready[i].service_time = '\0';
	  ready[i].source='\0';
	  ready[i].status = 'W';
  }
  sum = 0;
}
//---------------------------------------------------------------------------
void Tmianform::ChangeSubmit()
{
	if(this->Edit_new->Text!="" && this->combo_new->ItemIndex!=-1 && this->Combo_newSourse->ItemIndex!=-1)
		this->done->Enabled = TRUE;
	else
		this->done->Enabled = FALSE;
}
//---------------------------------------------------------------------------
void __fastcall Tmianform::Edit_newChange(TObject *Sender)
{
	this->ChangeSubmit();
}
//---------------------------------------------------------------------------

void __fastcall Tmianform::combo_newChange(TObject *Sender)
{
	this->ChangeSubmit();
}
//---------------------------------------------------------------------------

void __fastcall Tmianform::Combo_newSourseChange(TObject *Sender)
{
	this->ChangeSubmit();
}
//---------------------------------------------------------------------------


