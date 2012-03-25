//---------------------------------------------------------------------------

#ifndef HelpH
#define HelpH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
//---------------------------------------------------------------------------
class THelpForm : public TForm
{
__published:	// IDE-managed Components
  TMemo *Memo1;
  TButton *ClsBtn;
  void __fastcall ClsBtnClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
  __fastcall THelpForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE THelpForm *HelpForm;
//---------------------------------------------------------------------------
#endif
