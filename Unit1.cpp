//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
int x=-5;
int y=-5; 

//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{

}
//---------------------------------------------------------------------------

void __fastcall TForm1::Timer_ballTimer(TObject *Sender)
{
   ball->Left+=x;
  ball->Top+=y;

 //bounce from the top wall
 if (ball->Top-5 <= background->Top) y =-y;

 //bounce from the bottom wall
 if (ball->Top+ball->Height+5 >= background->Height) y =-y;

 //losing the point


  //bounce from the left wall

 if ((ball->Left-5 <= background->Left)||
    (ball->Left+ball->Width+5 >= background->Width))
    {
     Timer_ball->Enabled = false;
     ball->Visible = false;
    // Button1->Caption= "Pora¿ka! Jeszcze raz?";
     //Button1->Visible = true;
  }
}
//---------------------------------------------------------------------------

