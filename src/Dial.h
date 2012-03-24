//---------------------------------------------------------------------------

#ifndef DialH
#define DialH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "MainUnit.h"
//---------------------------------------------------------------------------
class TDialogueForm : public TForm
{
__published:	// IDE-managed Components
  TEdit *WeightEdit;
  TButton *ConfirmBtn;
  void __fastcall ConfirmBtnClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
  bool Flag;// была ошибка или нет
  __fastcall TDialogueForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TDialogueForm *DialogueForm;
//---------------------------------------------------------------------------
#endif
