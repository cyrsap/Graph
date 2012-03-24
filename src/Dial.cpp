//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Dial.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TDialogueForm *DialogueForm;
//---------------------------------------------------------------------------
__fastcall TDialogueForm::TDialogueForm(TComponent* Owner)
  : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TDialogueForm::ConfirmBtnClick(TObject *Sender)
{
  Flag = true;
  try{
    MainForm->CurrentWeight = StrToInt(WeightEdit->Text);
  }
  catch(...){
    Flag = false;
    MessageBox(0, "Вы ввели неправильные символы!", "Внимание!", MB_OK);
  }
  Close();    
}
//---------------------------------------------------------------------------
