//---------------------------------------------------------------------------

#ifndef jinchengdiaoduH
#define jinchengdiaoduH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.Grids.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <String.h>
#include <iostream>
//---------------------------------------------------------------------------
class Tmianform : public TForm
{
__published:	// IDE-managed Components

	TLabel *Label1;
	TLabel *Label2;
	TGroupBox *select_method;
	TButton *run;
	TGroupBox *add_new_pro;
	TLabel *Label3;
	TLabel *Label4;
	TLabel *Label5;
	TEdit *Edit_new;
	TComboBox *combo_new;
	TComboBox *Combo_newSourse;
	TButton *done;
	TButton *clear;
	TGroupBox *running_pro;
	TGroupBox *ready_pro;
	TLabel *名称;
	TLabel *ID;
	TLabel *开始运行时间;
	TLabel *已运行时间;
	TLabel *还需运行时间;
	TLabel *所需资源;
	TLabel *状态;
	TStringGrid *ready_queue;
	TTimer *Timer1;
	TGroupBox *GroupBox_FCFS;
	TStringGrid *grid_FCFS;
	TStringGrid *grid_SPF;
	TGroupBox *GroupBox_SPF;
	TLabel *run_id;
	TLabel *run_name;
	TLabel *run_start_time;
	TLabel *run_finish_time;
	TLabel *run_rest_time;
	TLabel *run_source;
	TLabel *run_status;
	TRadioButton *radio_FCFS;
	TRadioButton *radio_SPF;
	TButton *button_clear;
	TLabel *Label6;
	TLabel *run_service_time;
	void __fastcall clearClick(TObject *Sender);
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall doneClick(TObject *Sender);
	void __fastcall runClick(TObject *Sender);
	void __fastcall Timer1Timer(TObject *Sender);
	void __fastcall radio_FCFSClick(TObject *Sender);
	void __fastcall radio_SPFClick(TObject *Sender);
	void __fastcall button_clearClick(TObject *Sender);
	void __fastcall Edit_newChange(TObject *Sender);
	void __fastcall combo_newChange(TObject *Sender);
	void __fastcall Combo_newSourseChange(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall Tmianform(TComponent* Owner);
	struct PCB{
	  int id;
	  String name;
	  int submit_time;
	  int service_time;
	  int source;
	  char status;
	} ready[50];
	int sum;//全局变量，记录进程个数
	void ChangeSubmit();
};
//---------------------------------------------------------------------------
extern PACKAGE Tmianform *mianform;
//---------------------------------------------------------------------------
#endif
