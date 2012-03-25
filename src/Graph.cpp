//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
//---------------------------------------------------------------------------
USEFORM("MainUnit.cpp", MainForm);
USEFORM("Dial.cpp", DialogueForm);
USEFORM("Help.cpp", HelpForm);
//---------------------------------------------------------------------------
WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
  try
  {
     Application->Initialize();
     Application->CreateForm(__classid(TMainForm), &MainForm);
     Application->CreateForm(__classid(TDialogueForm), &DialogueForm);
     Application->CreateForm(__classid(THelpForm), &HelpForm);
     Application->Run();
  }
  catch (Exception &exception)
  {
     Application->ShowException(&exception);
  }
  catch (...)
  {
     try
     {
       throw Exception("");
     }
     catch (Exception &exception)
     {
       Application->ShowException(&exception);
     }
  }
  return 0;
}
//---------------------------------------------------------------------------
