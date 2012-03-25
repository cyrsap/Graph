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
  if (Flag && ((MainForm->CurrentWeight < 1 ) || (MainForm->CurrentWeight > 100)) ){
    Flag = false;
    MessageBox(0, "Допустимый диапазон ввода веса ребра от 1 до 100", "Внимание!", MB_OK);
  }
  Close();
}
//---------------------------------------------------------------------------
