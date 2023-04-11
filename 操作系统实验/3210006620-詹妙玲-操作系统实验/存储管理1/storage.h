//---------------------------------------------------------------------------

#ifndef storageH
#define storageH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.Grids.hpp>
#include <iostream>
#include "stdlib.h"
#include "time.h"
#include <String>
//---------------------------------------------------------------------------
class Tmianform : public TForm
{
__published:	// IDE-managed Components
	TGroupBox *GroupBox1;
	TGroupBox *GroupBox2;
	TStringGrid *StringGrid_memory;
	TStringGrid *StringGrid_work;
	TButton *Button1;
	TButton *Button2;
	TButton *Button3;
	TButton *Button4;
	TButton *Button5;
	TButton *Button6;
	TRadioButton *RadioButton1;
	TRadioButton *RadioButton2;
	TRadioButton *RadioButton3;
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall Button2Click(TObject *Sender);
	void __fastcall RadioButton1Click(TObject *Sender);
	void __fastcall RadioButton2Click(TObject *Sender);
	void __fastcall RadioButton3Click(TObject *Sender);
	void __fastcall Button3Click(TObject *Sender);
	void __fastcall Button5Click(TObject *Sender);
	void __fastcall Button4Click(TObject *Sender);
	void __fastcall Button6Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall Tmianform(TComponent* Owner);
	typedef struct MCB{
		int id;
		int original_size;
		int rest_size;
		int head_address;
		String work;
	}MCB;
	MCB memory[10];
	void bubblesort(MCB *A,int n);
};
//---------------------------------------------------------------------------
extern PACKAGE Tmianform *mianform;
//---------------------------------------------------------------------------
#endif
