//---------------------------------------------------------------------------

#ifndef MainUnitH
#define MainUnitH
//---------------------------------------------------------------------------
#define NUM 16
#define MAX_ROUTE 1000
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Buttons.hpp>
#include "Dial.h"
#include "Help.h"

//---------------------------------------------------------------------------

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
  TSpeedButton *CalcBtn;
  TLabel *Label;
  TButton *HelpBtn;
  void __fastcall ImageMouseDown(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y);
  void __fastcall ImageMouseUp(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y);
  void __fastcall ClearBtnClick(TObject *Sender);
  void __fastcall ClsBtnClick(TObject *Sender);
  void __fastcall AddVertexBtnClick(TObject *Sender);
  void __fastcall DeleteVertexBtnClick(TObject *Sender);
  void __fastcall AddRibBtnClick(TObject *Sender);
  void __fastcall DeleteRibBtnClick(TObject *Sender);
  void __fastcall HelpBtnClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
  VertexPrs Coord[NUM];
  int Way; //���� �� �������
  int Length[NUM][NUM];   //����� ����� ����� ���������
  AnsiString Ways[NUM];   //����
  short NumAll;           // ����� ���������� ������
  bool DownFlag; // ���� ��� ���������� ��� �������� �����
  int CurrentWeight, CurrX, CurrY; // ��� ������� ��� ������� ����� � ���������� ��������� ����� ��� ������� � �������� �����
  __fastcall TMainForm(TComponent* Owner);
  void Setup();
  void DrawVertex(int x, int y);
  void ReDrawVertex(int i);
  void DeleteVertex(int x, int y);
  void AddRib(int x1, int y1, int x2, int y2);
  void DeleteRib(int x1, int y1, int x2, int y2);
  void FindRoute(int Start, int End);
  void Calculate(int x1, int y1, int x2, int y2);
  void ReDrawRib(int Start, int End, TColor Colour);
  void ReDrawAll();
};
//---------------------------------------------------------------------------
extern PACKAGE TMainForm *MainForm;
//---------------------------------------------------------------------------
#endif
