//---------------------------------------------------------------------------

#ifndef zuoyediaoduH
#define zuoyediaoduH
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
	TStringGrid *grid_Timeround;
	TStringGrid *grid_Staticrank;
	TGroupBox *GroupBox_SPF;
	TLabel *run_id;
	TLabel *run_name;
	TLabel *run_start_time;
	TLabel *run_finish_time;
	TLabel *run_rest_time;
	TLabel *run_source;
	TLabel *run_status;
	TRadioButton *radio_Timeround;
	TRadioButton *radio_Staticrank;
	TButton *button_clear;
	TLabel *Label6;
	TLabel *run_service_time;
	TLabel *Label7;
	TComboBox *ComboBox_timesize;
	TLabel *average_Timeround;
	TLabel *avrg_T1;
	TLabel *Label9;
	TLabel *avrg_T2;
	TLabel *Label8;
	TLabel *avrg_S1;
	TLabel *Label11;
	TLabel *avrg_S2;
	void __fastcall clearClick(TObject *Sender);
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall doneClick(TObject *Sender);
	void __fastcall runClick(TObject *Sender);
	void __fastcall Timer1Timer(TObject *Sender);
	void __fastcall radio_TimeroundClick(TObject *Sender);
	void __fastcall radio_StaticrankClick(TObject *Sender);
	void __fastcall button_clearClick(TObject *Sender);
	void __fastcall Edit_newChange(TObject *Sender);
	void __fastcall combo_newChange(TObject *Sender);
	void __fastcall Combo_newSourseChange(TObject *Sender);
//	void __fastcall grid_TimeroundContextPopup(TObject *Sender, TPoint &MousePos, bool &Handled);
//	void __fastcall grid_TimeroundFixedCellClick(TObject *Sender, int ACol, int ARow);
//	void __fastcall grid_TimeroundSetEditText(TObject *Sender, int ACol, int ARow, const UnicodeString Value);
//	void __fastcall grid_TimeroundTopLeftChanged(TObject *Sender);
//	void __fastcall grid_TimeroundGesture(TObject *Sender, const TGestureEventInfo &EventInfo,
//		  bool &Handled);
//	void __fastcall grid_TimeroundStartDock(TObject *Sender, TDragDockObject *&DragObject);






private:	// User declarations
public:		// User declarations
	__fastcall Tmianform(TComponent* Owner);
	struct PCB{
	  int id;
	  String name;
	  int start_time;
	  int service_time;
	  int finish_time;
	  int end_time;
	  int rest_time;
	  int submit_time;
	  int degree;
	  char status;
	} ready[50];
	int sum;//全局变量，记录进程个数
	int Timetip_num;//全局变量，记录已完成
	void ChangeSubmit();
};
//---------------------------------------------------------------------------
extern PACKAGE Tmianform *mianform;
//---------------------------------------------------------------------------
#endif
