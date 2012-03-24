//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "MainUnit.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TMainForm *MainForm;
//---------------------------------------------------------------------------
__fastcall TMainForm::TMainForm(TComponent* Owner)
  : TForm(Owner)
{
  Setup();
}
//---------------------------------------------------------------------------
void TMainForm::Setup()
{
  NumAll = 0;
  for ( int i = 1; i < NUM; i++ ){
    Coord[ i ].x = -1;
    Coord[ i ].y = -1;
    Coord[ i ].act = false;
    for ( int j = 1; j < NUM; j++ ){
      Length[ i ][ j ] = -1;
      Checked[i ][ j ] = false;
    } 
  }//for
  // очистка канвы
  Image->Canvas->Pen->Color = clWhite;
  Image->Canvas->Brush->Color = clWhite;
  Image->Canvas->Rectangle(0, 0, 1000, 1000);//Image->Height, Image->Width);
  Image->Canvas->Pen->Color = clBlack;
  Image->Canvas->Brush->Color = clYellow;
  Image->Canvas->Font->Color = clBlack;
  DownFlag = false;
  return;
}
//---------------------------------------------------------------------------
void TMainForm::ReDrawVertex(int i)
{
  Image->Canvas->Pen->Color = clBlack;
  Image->Canvas->Brush->Color = clYellow;
  Image->Canvas->Font->Color = clBlack;
  Image->Canvas->Ellipse(Coord[i].x-12, Coord[i].y-12, Coord[i].x+12, Coord[i].y+12);
  Image->Canvas->TextOutA(Coord[i].x-4, Coord[i].y-7, IntToStr( i ));
}
//---------------------------------------------------------------------------

void TMainForm::DrawVertex(int x, int y){
  if ( NumAll >= NUM-1 ){
    MessageBox(0, "Количество вершин превысило максимально возможное", "Внимание!", MB_OK);
    return;
  }//if

  int CurrVert = 0;
  for ( int i = 1; i < NUM; i++){ // проверка свободного номера вершины
    if (!Coord[ i ].act){
      CurrVert = i;
      break;
    }//if
  }//for

  // флаг проверка на близость вершин
  for ( int j = 1; j < NUM; j++ ){
    if ( ( x > Coord[j].x-50 ) && ( x < Coord[j].x+50 ) && ( y < Coord[j].y+50 ) && ( y > Coord[j].y-50 ) && (Coord[j].act)){
      MessageBox(0, "Соседняя вершина слишком близко расположена\n\rВыберите другое место", "Внимание!", MB_OK);
      return;
    }//if
  }//for
  Image->Canvas->Pen->Color = clBlack;
  Image->Canvas->Brush->Color = clYellow;
  Image->Canvas->Font->Color = clBlack;
  Image->Canvas->Ellipse(x-12, y-12, x+12, y+12);
  Image->Canvas->TextOutA(x-4, y-7, IntToStr( CurrVert ));
  NumAll++;
  Coord[CurrVert].x = x;
  Coord[CurrVert].y = y;
  Coord[CurrVert].act = true;
}

//---------------------------------------------------------------------------

void TMainForm::DeleteVertex(int x, int y){
  int i,j;
  for ( i = 1; i < NUM; i++ ){
    if ( ( x > Coord[i].x-12 ) && ( x < Coord[i].x+12 ) && ( y < Coord[i].y+12 ) && ( y > Coord[i].y-12 ) && (Coord[i].act) ){
      Coord[i].act = false;
      NumAll--;
      for (j = 1; j < NUM; j++){
        if ( Length[i][j] > 0 ){  // удаление ребер
          Image->Canvas->Pen->Color = clWhite;
          Image->Canvas->Brush->Color = clWhite;
          Image->Canvas->Font->Color = clWhite;
          Image->Canvas->MoveTo(Coord[i].x, Coord[i].y);
          Image->Canvas->LineTo(Coord[j].x, Coord[j].y);
          Image->Canvas->TextOutA(Coord[i].x + (Coord[j].x - Coord[i].x)/2, Coord[i].y + (Coord[j].y - Coord[i].y)/2, IntToStr(Length[i][j]) );
          if ( Coord[j].act ){
            ReDrawVertex(j);
          }//if
          /*Checked[i][j] = false;
          Checked[j][i] = false;*/
          Length[i][j] = -1;
          Length[j][i] = -1;
        }//if
      }//for
      Image->Canvas->Pen->Color = clWhite;
      Image->Canvas->Brush->Color = clWhite;
      Image->Canvas->Font->Color = clWhite;
      Image->Canvas->Ellipse(Coord[i].x-12, Coord[i].y-12, Coord[i].x+12, Coord[i].y+12);
      Image->Canvas->TextOutA(Coord[i].x-4, Coord[i].y-7, IntToStr( i ));
      return;
    }//if
  }//for
}

//---------------------------------------------------------------------------

void TMainForm::AddRib(int x1, int y1, int x2, int y2)
{
  int i,j;
  bool Flag = false;
  for ( i = 1; i < NUM; i++){
    if (( x1 > Coord[i].x-12 ) && ( x1 < Coord[i].x+12 ) && ( y1 < Coord[i].y+12 ) && ( y1 > Coord[i].y-12 ) && (Coord[i].act) ){
      Flag = true;
      break;
    }//if
  }//for
  for ( j = 1; j < NUM; j++){
    if (( x2 > Coord[j].x-12 ) && ( x2 < Coord[j].x+12 ) && ( y2 < Coord[j].y+12 ) && ( y2 > Coord[j].y-12 ) && (Coord[j].act) ){
      Flag = true;
      break;
    }//if
  }//for
  if ( i == j ){
    return;
  }//if
  if ( (Flag) && Coord[j].act && Coord[i].act ){
    DialogueForm->ShowModal();
    if (DialogueForm->Flag){
      Length[i][j] = CurrentWeight;
      Length[j][i] = CurrentWeight;
      /*Checked[i][j] = true;
      Checked[j][i] = true;*/
      Image->Canvas->Pen->Color = clBlack;
      Image->Canvas->Brush->Color = clWhite;
      Image->Canvas->Font->Color = clBlack;
      Image->Canvas->MoveTo(Coord[i].x, Coord[i].y);
      Image->Canvas->LineTo(Coord[j].x, Coord[j].y);
      Image->Canvas->TextOutA(Coord[i].x + (Coord[j].x - Coord[i].x)/2, Coord[i].y + (Coord[j].y - Coord[i].y)/2, IntToStr(CurrentWeight) );
      ReDrawVertex(i);
      ReDrawVertex(j);
    }//if
  }//if
}

//---------------------------------------------------------------------------

void TMainForm::DeleteRib(int x1, int y1, int x2, int y2)
{
  int i,j;
  bool Flag = false;
  for ( i = 1; i < NUM; i++){//поиск первой вершиины
    if (( x1 > Coord[i].x-12 ) && ( x1 < Coord[i].x+12 ) && ( y1 < Coord[i].y+12 ) && ( y1 > Coord[i].y-12 ) && (Coord[i].act) ){
      Flag = true;
      break;
    }//if
  }//for
  for ( j = 1; j < NUM; j++){// поиск второй вершины
    if (( x2 > Coord[j].x-12 ) && ( x2 < Coord[j].x+12 ) && ( y2 < Coord[j].y+12 ) && ( y2 > Coord[j].y-12 ) && (Coord[j].act) ){
      Flag = true;
      break;
    }//if
  }//for
  if ( i == j ){
    return;
  }//if
  if (Flag){
    Length[i][j] = -1;
    Length[j][i] = -1;
    /*Checked[i][j] = false;
    Checked[j][i] = false;*/
    Image->Canvas->Pen->Color = clWhite;
    Image->Canvas->Brush->Color = clWhite;
    Image->Canvas->Font->Color = clWhite;
    Image->Canvas->MoveTo(Coord[i].x, Coord[i].y);
    Image->Canvas->LineTo(Coord[j].x, Coord[j].y);
    Image->Canvas->TextOutA(Coord[i].x + (Coord[j].x - Coord[i].x)/2, Coord[i].y + (Coord[j].y - Coord[i].y)/2, IntToStr(CurrentWeight) );
    ReDrawVertex(i);
    ReDrawVertex(j);
  }//if
  return;
}

//---------------------------------------------------------------------------

void __fastcall TMainForm::ImageMouseDown(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
  if ( AddVertexBtn->Down ){
    DrawVertex( X, Y );
    return;
  }
  if (DeleteVertexBtn->Down){
    DeleteVertex( X, Y );
    return;
  }
  if (AddRibBtn->Down){
    CurrX = X;
    CurrY = Y;
    DownFlag = true;
  }//if
  if (DeleteRibBtn->Down){
    CurrX = X;
    CurrY = Y;
    DownFlag = true;
  }//if
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::ImageMouseUp(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
  if (AddRibBtn->Down && DownFlag){
    AddRib( CurrX, CurrY, X, Y );
  }
  if (DeleteRibBtn->Down && DownFlag){
    DeleteRib( CurrX, CurrY, X, Y );
  }
  DownFlag = false;
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::ClearBtnClick(TObject *Sender)
{
  Setup();  
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::ClsBtnClick(TObject *Sender)
{
  Close();  
}
//---------------------------------------------------------------------------


