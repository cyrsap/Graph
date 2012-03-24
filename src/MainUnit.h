//---------------------------------------------------------------------------

#ifndef MainUnitH
#define MainUnitH
//---------------------------------------------------------------------------
#define NUM 16
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Buttons.hpp>
#include "Dial.h"
//---------------------------------------------------------------------------
struct VertexPrs{
  int x; //���������� ����� �� �������
  int y;
  bool act;
};
//---------------------------------------------------------------------------
class TMainForm : public TForm
{
__published:	// IDE-managed Components
  TGroupBox *GroupBox1;
  TSpeedButton *AddVertexBtn;
  TSpeedButton *DeleteVertexBtn;
  TSpeedButton *AddRibBtn;
  TSpeedButton *DeleteRibBtn;
  TPanel *Panel1;
  TImage *Image;
  TButton *ClearBtn;
  TButton *ClsBtn;
  void __fastcall ImageMouseDown(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y);
  void __fastcall ImageMouseUp(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y);
  void __fastcall ClearBtnClick(TObject *Sender);
  void __fastcall ClsBtnClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
  VertexPrs Coord[NUM];
  bool Checked[NUM][NUM];
  int Length[NUM][NUM];
  short NumAll;
  bool DownFlag; // ���� ��� ���������� ��� �������� �����
  int CurrentWeight, CurrX, CurrY; // ��� ������� ��� ������� ����� � ���������� ��������� ����� ��� ������� � �������� �����
  __fastcall TMainForm(TComponent* Owner);
  void Setup();
  void DrawVertex(int x, int y);
  void DeleteVertex(int x, int y);
  void AddRib(int x1, int y1, int x2, int y2);
  void DeleteRib(int x1, int y1, int x2, int y2);
};
//---------------------------------------------------------------------------
extern PACKAGE TMainForm *MainForm;
//---------------------------------------------------------------------------
#endif
