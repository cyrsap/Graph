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
  for ( int i = 0; i < NUM; i++ ){
    Coord[ i ].x = -1;
    Coord[ i ].y = -1;
    Coord[ i ].act = false;
    for ( int j = 1; j < NUM; j++ ){
      Length[ i ][ j ] = MAX_ROUTE;
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
  Label->Visible = false;
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
      if (MessageBox(0, "Вы действительно хотите удалить данную вершину?", "Внимание!", MB_YESNO) == IDYES){
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
          Length[i][j] = MAX_ROUTE;
          Length[j][i] = MAX_ROUTE;
        }//if
      }//for
      Image->Canvas->Pen->Color = clWhite;
      Image->Canvas->Brush->Color = clWhite;
      Image->Canvas->Font->Color = clWhite;
      Image->Canvas->Ellipse(Coord[i].x-12, Coord[i].y-12, Coord[i].x+12, Coord[i].y+12);
      Image->Canvas->TextOutA(Coord[i].x-4, Coord[i].y-7, IntToStr( i ));
      return;
      }
    }//if
  }//for
  ReDrawAll();
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
  if (Length[i][j]<MAX_ROUTE){
    return;
  }
  if ( (Flag) && Coord[j].act && Coord[i].act ){
    DialogueForm->ShowModal();
    DialogueForm->WeightEdit->Text = "5";
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
  bool Flag1, Flag2 = false;
  for ( i = 1; i < NUM; i++){//поиск первой вершиины
    if (( x1 > Coord[i].x-12 ) && ( x1 < Coord[i].x+12 ) && ( y1 < Coord[i].y+12 ) && ( y1 > Coord[i].y-12 ) && (Coord[i].act) ){
      Flag1 = true;
      break;
    }//if
  }//for
  for ( j = 1; j < NUM; j++){// поиск второй вершины
    if (( x2 > Coord[j].x-12 ) && ( x2 < Coord[j].x+12 ) && ( y2 < Coord[j].y+12 ) && ( y2 > Coord[j].y-12 ) && (Coord[j].act) ){
      Flag2 = true;
      break;
    }//if
  }//for
  if ( i == j ){
    return;
  }//if
  if (Flag1 && Flag2){
   if (Length[i][j]<MAX_ROUTE)
    if (MessageBox(0, "Вы действительно хотите удалить данное ребро?", "Внимание!", MB_YESNO) == IDYES ){
      Length[i][j] = MAX_ROUTE;
      Length[j][i] = MAX_ROUTE;
      Image->Canvas->Pen->Color = clWhite;
      Image->Canvas->Brush->Color = clWhite;
      Image->Canvas->Font->Color = clWhite;
      Image->Canvas->MoveTo(Coord[i].x, Coord[i].y);
      Image->Canvas->LineTo(Coord[j].x, Coord[j].y);
      Image->Canvas->TextOutA(Coord[i].x + (Coord[j].x - Coord[i].x)/2, Coord[i].y + (Coord[j].y - Coord[i].y)/2, IntToStr(CurrentWeight) );
      ReDrawVertex(i);
      ReDrawVertex(j);
    }
  }//if
  ReDrawAll();
  return;
}

//---------------------------------------------------------------------------

void TMainForm::Calculate(int x1, int y1, int x2, int y2)
{
  int i,j,k;
  bool Flag1 = false, Flag2 = false;
  for ( i = 1; i < NUM; i++){//поиск первой вершиины
    if (( x1 > Coord[i].x-12 ) && ( x1 < Coord[i].x+12 ) && ( y1 < Coord[i].y+12 ) && ( y1 > Coord[i].y-12 ) && (Coord[i].act) ){
      Flag1 = true;
      break;
    }//if
  }//for
  for ( j = 1; j < NUM; j++){// поиск второй вершины
    if (( x2 > Coord[j].x-12 ) && ( x2 < Coord[j].x+12 ) && ( y2 < Coord[j].y+12 ) && ( y2 > Coord[j].y-12 ) && (Coord[j].act) ){
      Flag2 = true;
      break;
    }//if
  }//for
  
  if ( i == j ){
    return;
  }//if
  if (Flag1 && Flag2){
    FindRoute( i, j );
    if ( (Way < 1000) && (Way > 0) ){
      Label->Caption = "Минимальное расстояние \r\nот вершины №"+IntToStr(i)+" \r\nдо вершины №"+IntToStr(j)+"\r\nравно "+IntToStr(Way);
      Label->Caption += "\r\n";
      //Label->Caption += Ways[j];
      ReDrawRib(i, StrToInt(Ways[j][1]), clRed);
      for (k = 2; k <= Ways[j].Length(); k++){
        ReDrawRib(StrToInt(Ways[j][k-1]), StrToInt(Ways[j][k]), clRed);                      
      }
    }//if
    else{
      Label->Caption = "Из вершины №"+IntToStr(i)+"\r\nнельзя достичь \r\nвершины №"+IntToStr(j);
    }
    Label->Visible = true;
  }//if
  else{
    MessageBox(0, "Вы не выбрали вершины", "Внимание!", MB_OK);
  }//else
}

//---------------------------------------------------------------------------

void TMainForm::ReDrawRib(int Start, int End, TColor Colour)
{
      Image->Canvas->Pen->Color = Colour;
      Image->Canvas->Brush->Color = clWhite;
      Image->Canvas->Font->Color = Colour;
      Image->Canvas->MoveTo(Coord[Start].x, Coord[Start].y);
      Image->Canvas->LineTo(Coord[End].x, Coord[End].y);
      Image->Canvas->TextOutA(Coord[Start].x + (Coord[End].x - Coord[Start].x)/2, Coord[Start].y + (Coord[End].y - Coord[Start].y)/2, IntToStr(Length[Start][End]) );
      ReDrawVertex(Start);
      ReDrawVertex(End);
}

//---------------------------------------------------------------------------

void TMainForm::ReDrawAll()
{
  Image->Canvas->Pen->Color = clWhite;
  Image->Canvas->Brush->Color = clWhite;
  Image->Canvas->Rectangle(0, 0, 1000, 1000);//Image->Height, Image->Width);
  int i,j;
  for (i = 1; i<NUM/2+1; i++){
    for ( j = 1; j< NUM/2+1; j++ ){
      if ( (Length[i][j]<1000) && (Length[i][j]>0) ){
        ReDrawRib(i, j, clBlack);
      }//if
    }
  }
  for (i = 1; i<NUM; i++){
    if (Coord[i].act){
      ReDrawVertex(i);
    }
  }
}

//---------------------------------------------------------------------------
void TMainForm::FindRoute(int Start, int End)
{
	//Route.push_back(Start);
  int min, imin, i, j;
  int W[NUM]; //рабочий массив
  bool Flag[NUM];// массив проверки просмотренности вершин
  for ( i = 1; i<NUM; i++) { // назначение рабочего массива длин путей и букв
		W[i]= Length[Start][i];
		Flag[i] = false;
    Ways[i] = IntToStr(i);
	}//for  
	for ( i = 1; i < NUM; i++ ) {
		min = MAX_ROUTE;
		imin = 0;
		for ( j = 1; j < NUM; j++ ) {// нахождение мин пути до j-й вершины
			if ((W[j] < min) && (!Flag[j]) && (W[j]>0)) {// если вершина не просмотрена
				min = W[j];                    // и путь минимален
				imin = j;
			}//if
		}//for
		Flag[imin] = true; // вершина просмотрена
		for ( j = 1; j < NUM; j++) {
			if (!Flag[j] && (W[j] > (W[imin] + Length[imin][j]))) {
				W[j] = W[imin] + Length[imin][j];
				Ways[j] = Ways[imin] + IntToStr(j);
			}//if
		}//for
	}//for
  Way = W[End];
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
  if (CalcBtn->Down){
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
    return;
  }
  if (DeleteRibBtn->Down && DownFlag){

      DeleteRib( CurrX, CurrY, X, Y );
      return;
  }
  if (CalcBtn->Down && DownFlag){
    ReDrawAll();
    Calculate(CurrX, CurrY, X, Y);
    return;
  }
  DownFlag = false;
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::ClearBtnClick(TObject *Sender)
{
  if (MessageBox(0, "Вы действительно хотите все удалить?", "Внимание!", MB_YESNO) == IDYES){
    Setup();
  }
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::ClsBtnClick(TObject *Sender)
{
  Close();  
}
//---------------------------------------------------------------------------



void __fastcall TMainForm::AddVertexBtnClick(TObject *Sender)
{
  ReDrawAll();  
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::DeleteVertexBtnClick(TObject *Sender)
{
  ReDrawAll();  
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::AddRibBtnClick(TObject *Sender)
{
  ReDrawAll();  
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::DeleteRibBtnClick(TObject *Sender)
{
  ReDrawAll();  
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::HelpBtnClick(TObject *Sender)
{
  HelpForm->ShowModal();  
}
//---------------------------------------------------------------------------

