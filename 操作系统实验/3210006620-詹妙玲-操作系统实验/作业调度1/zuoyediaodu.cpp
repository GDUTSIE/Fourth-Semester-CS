//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "zuoyediaodu.h"
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
 this->run->Enabled = FALSE;
 this->ready_queue->Cells[0][0] = "ID";
 this->ready_queue->Cells[1][0] = "进程名称";
 this->ready_queue->Cells[2][0] = "提交时间";
 this->ready_queue->Cells[3][0] = "服务时间";
 this->ready_queue->Cells[4][0] = "优先权";
 this->ready_queue->Cells[5][0] = "状态";
 this->grid_Timeround->Cells[0][0] = "ID";
 this->grid_Timeround->Cells[1][0] = "进程名称";
 this->grid_Timeround->Cells[2][0] = "开始时间";
 this->grid_Timeround->Cells[3][0] = "服务时间";
 this->grid_Timeround->Cells[4][0] = "完成时间";
 this->grid_Timeround->Cells[5][0] = "优先权";
 this->grid_Timeround->Cells[6][0] = "状态";
 this->grid_Timeround->Cells[7][0] = "周转时间";
 this->grid_Timeround->Cells[8][0] = "带权周转时间";
 this->grid_Staticrank->Cells[0][0] = "ID";
 this->grid_Staticrank->Cells[1][0] = "进程名称";
 this->grid_Staticrank->Cells[2][0] = "开始时间";
 this->grid_Staticrank->Cells[3][0] = "服务时间";
 this->grid_Staticrank->Cells[4][0] = "完成时间";
 this->grid_Staticrank->Cells[5][0] = "优先权";
 this->grid_Staticrank->Cells[6][0] = "状态";
 this->grid_Staticrank->Cells[7][0] = "周转时间";
 this->grid_Staticrank->Cells[8][0] = "带权周转时间";
 sum = 0;
}
//---------------------------------------------------------------------------
void __fastcall Tmianform::doneClick(TObject *Sender)
{
  if(this->radio_Staticrank->Checked == TRUE || this->radio_Timeround->Checked == TRUE)
	this->run->Enabled = TRUE;
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
  ready[i].finish_time = 0;
  ready[i].rest_time = StrToInt(this->combo_new->Text);
  ready[i].submit_time = i;
  ready[i].service_time = StrToInt(this->combo_new->Text);
  ready[i].degree = StrToInt(this->Combo_newSourse->Text);
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
	this->Timetip_num = sum;
	this->Label2->Caption = sum;
	//将就绪队列队首的进程移动到正在执行队列中（代表调度进CPU）
	this->run_id->Caption = this->ready_queue->Cells[0][1];
	this->run_name->Caption = this->ready_queue->Cells[1][1];
	this->run_service_time->Caption = this->ready_queue->Cells[3][1];
	this->run_source->Caption = this->ready_queue->Cells[4][1];
	this->run_status->Caption = 'R';
	this->run_start_time->Caption = this->Label2->Caption;
	this->ready[1].start_time = StrToInt(this->Label2->Caption);
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
	//运行的同时开始计时
	this->Timer1->Enabled = TRUE;
}
//---------------------------------------------------------------------------
void __fastcall Tmianform::Timer1Timer(TObject *Sender)
{
	this->Label2->Caption = IntToStr(StrToInt(this->Label2->Caption)+1);
	if(this->radio_Timeround->Checked)
	{
		static int serv_time = StrToInt(this->ComboBox_timesize->Text);
		static int count_time = 0;
		if(StrToInt(this->run_rest_time->Caption) > 0)
		{
			this->run_finish_time->Caption = StrToInt(this->run_finish_time->Caption)+1;
			this->run_rest_time->Caption = StrToInt(this->run_rest_time->Caption)-1;
		}
		count_time++;
		if(count_time != serv_time)
		{
			if(this->run_rest_time->Caption == "0")
				this->ready[StrToInt(this->run_id->Caption)].end_time = StrToInt(this->Label2->Caption);
		}
		else if(count_time == serv_time)
		{
//			this->Timer1->Enabled = FALSE;
			if(StrToInt(this->run_rest_time->Caption) != 0)
			{
				if(this->ready_queue->Cells[0][1]!="")
				{
					//把服务从新排到服务队列的队尾
					this->ready_queue->Cells[0][sum+1] = this->run_id->Caption;
					this->ready_queue->Cells[1][sum+1] = this->run_name->Caption;
					this->ready_queue->Cells[2][sum+1] = this->run_id->Caption;
					this->ready_queue->Cells[3][sum+1] = this->run_service_time->Caption;
					this->ready_queue->Cells[4][sum+1] = this->run_source->Caption;
					this->ready_queue->Cells[5][sum+1] = 'W';
					this->ready[StrToInt(this->run_id->Caption)].finish_time = StrToInt(this->run_finish_time->Caption);
					this->ready[StrToInt(this->run_id->Caption)].rest_time = StrToInt(this->run_rest_time->Caption);
					sum++;
				}
			}
			else if(StrToInt(this->run_rest_time->Caption) == 0)
			{   //还需运行时间为0时
				//记录完毕时间
				this->ready[StrToInt(this->run_id->Caption)].end_time = StrToInt(this->Label2->Caption);
				//将正在运行作业放到已完成作业表中
				int n = 1;
				while(this->grid_Timeround->Cells[0][n] != "")	n++;
				this->grid_Timeround->Cells[0][n] = this->run_id->Caption;
				this->grid_Timeround->Cells[1][n] = this->run_name->Caption;
				this->grid_Timeround->Cells[2][n] = this->run_start_time->Caption;
				this->grid_Timeround->Cells[3][n] = this->run_service_time->Caption;
				this->grid_Timeround->Cells[4][n] = this->ready[StrToInt(this->run_id->Caption)].end_time;
				this->grid_Timeround->Cells[5][n] = this->run_source->Caption;
				this->grid_Timeround->Cells[6][n] = 'F';
				this->grid_Timeround->Cells[7][n] = ready[StrToInt(this->run_id->Caption)].end_time-StrToInt(this->run_id->Caption);
				this->grid_Timeround->Cells[8][n] = (float)(StrToInt(this->grid_Timeround->Cells[7][n])) / (float)(StrToInt(this->run_service_time->Caption)) ;

				this->run_id->Caption = "";
			}
			if(this->ready_queue->Cells[0][1]!="")
			{
				//服务首次进入正在执行队列时对开始时间进行赋值
				if(ready[StrToInt(this->ready_queue->Cells[0][1])].finish_time == 0)
					ready[StrToInt(this->ready_queue->Cells[0][1])].start_time = StrToInt(this->Label2->Caption);

				 //把当前队列首个服务进入正在执行队列
				this->run_id->Caption = this->ready_queue->Cells[0][1];
				this->run_name->Caption = this->ready_queue->Cells[1][1];
				this->run_start_time->Caption = this->ready[StrToInt(this->ready_queue->Cells[0][1])].start_time;
				this->run_finish_time->Caption = this->ready[StrToInt(this->ready_queue->Cells[0][1])].finish_time;
				this->run_rest_time->Caption = this->ready[StrToInt(this->ready_queue->Cells[0][1])].rest_time;
				this->run_source->Caption = this->ready_queue->Cells[4][1];
				this->run_status->Caption = 'W';
				this->run_service_time->Caption = this->ready[StrToInt(this->ready_queue->Cells[0][1])].service_time;
				sum--;

				//就绪队列调整
				int i;
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
				this->run_finish_time->Caption = StrToInt(this->run_finish_time->Caption)+1;
				this->run_rest_time->Caption = StrToInt(this->run_rest_time->Caption)-1;
			}
				//总数sum为0时停止计时
			if(this->run_id->Caption == "")
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
					int q,p;
					float s1=0.0,s2=0.0;
					for(p=1;this->grid_Timeround->Cells[0][p] != "";p++)
					{
					   s1 = s1 + StrToFloat(this->grid_Timeround->Cells[7][p]);
					   s2 = s2 + StrToFloat(this->grid_Timeround->Cells[8][p]);
					}
					this->avrg_T2->Caption = s2/(float)(p-1);
					this->avrg_T1->Caption = s1/(float)(p-1);
					for(q=1;ready[q].id != '\0';q++)
					{
						//重置数据记录时间
						this->ready[q].start_time = 0;
						this->ready[q].finish_time = 0;
						this->ready[q].rest_time = ready[q].service_time;
						this->ready[q].end_time = 0;
						//重置等候列表
						this->ready_queue->Cells[0][q] = ready[q].id;
						this->ready_queue->Cells[1][q] = ready[q].name;
						this->ready_queue->Cells[2][q] = ready[q].submit_time;
						this->ready_queue->Cells[3][q] = ready[q].service_time;
						this->ready_queue->Cells[4][q] = ready[q].degree;
						this->ready_queue->Cells[5][q] = ready[q].status;
					}
					sum = q-1;
				}
			}
			count_time = 0;
		}
	}
	else if(this->radio_Staticrank->Checked)
	{
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
			if(this->radio_Timeround->Checked == TRUE)
			{
				int i;
				for(i=1; this->grid_Timeround->Cells[0][i]!="";i++)
				{
					;
				}
				this->grid_Timeround->Cells[0][i] =  this->run_id->Caption;
				this->grid_Timeround->Cells[1][i] =  this->run_name->Caption;
				this->grid_Timeround->Cells[2][i] =  this->run_start_time->Caption;
				this->grid_Timeround->Cells[3][i] =  this->run_service_time->Caption;
				this->grid_Timeround->Cells[4][i] =  StrToInt(this->run_start_time->Caption) + StrToInt(this->run_service_time->Caption);
				this->grid_Timeround->Cells[5][i] =  this->run_source->Caption;
				this->grid_Timeround->Cells[6][i] =  'F';
				this->grid_Timeround->Cells[7][i] =  IntToStr(StrToInt(this->grid_Timeround->Cells[4][i]) - StrToInt(this->run_id->Caption));
				this->grid_Timeround->Cells[8][i] =  (float)(StrToInt(this->grid_Timeround->Cells[7][i])) / (float)(StrToInt(this->run_service_time->Caption)) ;
			}
			else if(this->radio_Staticrank->Checked == TRUE)
			{
				int i;
				i = StrToInt(this->run_id->Caption);
				this->grid_Staticrank->Cells[0][i] =  this->run_id->Caption;
				this->grid_Staticrank->Cells[1][i] =  this->run_name->Caption;
				this->grid_Staticrank->Cells[2][i] =  this->run_start_time->Caption;
				this->grid_Staticrank->Cells[3][i] =  this->run_service_time->Caption;
				this->grid_Staticrank->Cells[4][i] =  StrToInt(this->run_start_time->Caption) + StrToInt(this->run_service_time->Caption);
				this->grid_Staticrank->Cells[5][i] =  this->run_source->Caption;
				this->grid_Staticrank->Cells[6][i] =  'F';
				this->grid_Staticrank->Cells[7][i] =  IntToStr(StrToInt(this->grid_Staticrank->Cells[4][i]) - StrToInt(this->run_id->Caption));
				this->grid_Staticrank->Cells[8][i] =  (float)(StrToInt(this->grid_Staticrank->Cells[7][i])) / (float)(StrToInt(this->run_service_time->Caption)) ;
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
					int q,p ;
					float s1=0.0,s2=0.0;
					for(p=1;this->grid_Staticrank->Cells[0][p] != "";p++)
					{
					   s1 = s1 + StrToFloat(this->grid_Staticrank->Cells[7][p]);
					   s2 = s2 + StrToFloat(this->grid_Staticrank->Cells[8][p]);
					}
					this->avrg_S2->Caption = s2/(float)(p-1);
					this->avrg_S1->Caption = s1/(float)(p-1);
					for(q=1;ready[q].id != '\0';q++)
					{
						this->ready_queue->Cells[0][q] = ready[q].id;
						this->ready_queue->Cells[1][q] = ready[q].name;
						this->ready_queue->Cells[2][q] = ready[q].submit_time;
						this->ready_queue->Cells[3][q] = ready[q].service_time;
						this->ready_queue->Cells[4][q] = ready[q].degree;
						this->ready_queue->Cells[5][q] = ready[q].status;
					}
					sum = q-1;
				}
			}
		}
	}
}
//---------------------------------------------------------------------------
void __fastcall Tmianform::radio_TimeroundClick(TObject *Sender)
{
  int i,j,k;
  this->ComboBox_timesize->Enabled = TRUE;
  if(this->ready_queue->Cells[0][1] != "")
	 this->run->Enabled = TRUE;
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
	  this->ready_queue->Cells[4][j] = ready[k].degree;
	  this->ready_queue->Cells[5][j] = ready[k].status;
   }

}

//---------------------------------------------------------------------------

void __fastcall Tmianform::radio_StaticrankClick(TObject *Sender)
{
  int i,j,k,n;
  PCB temp;
  this->ComboBox_timesize->Enabled = FALSE;
  if(this->ready_queue->Cells[0][1] != "")
	 this->run->Enabled = TRUE;
  //算出有多少个进程
  for (n=1;ready[n].id; n++) {
		 ;
  }

  //用冒泡排序将进程按服务时间由短到长排序，并在就绪队列中显示
  for(i=0;i<n-2;i++)
  {
	  for(j=n-1;j>i;j--)
	  {
		  if(ready[j].degree<ready[j-1].degree)
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
	  this->ready_queue->Cells[4][j] = ready[j].degree;
	  this->ready_queue->Cells[5][j] = ready[j].status;
  }

}
//---------------------------------------------------------------------------

void __fastcall Tmianform::button_clearClick(TObject *Sender)
{
  this->radio_Staticrank->Checked = FALSE;
  this->radio_Timeround->Checked = FALSE;
  this->run->Enabled = FALSE;
  int i,j;
  for(i=1;this->ready_queue->Cells[0][i]!="";i++)
  {
	  for(j=0;j<6;j++)
	  {
		  this->ready_queue->Cells[j][i]="";
	  }
  }
  for(i=1;this->grid_Timeround->Cells[0][i]!="";i++)
  {
	  for(j=0;j<=8;j++)
	  {
		  this->grid_Timeround->Cells[j][i] = "";
	  }
  }
   for(i=1;this->grid_Staticrank->Cells[0][i]!="";i++)
  {
	  for(j=0;j<=8;j++)
	  {
		  this->grid_Staticrank->Cells[j][i] = "";
	  }
  }
  for(i=1;ready[i].id!='\0';i++)
  {
	  ready[i].id = '\0';
	  ready[i].name="";
	  ready[i].submit_time='\0';
	  ready[i].service_time = '\0';
	  ready[i].degree='\0';
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



