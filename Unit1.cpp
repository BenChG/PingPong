//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
#include "Winuser.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
int x=-5;
int y=-5;
int points_left = 0;
int points_right = 0;
int start_new_game =0;
AnsiString points_L;
AnsiString points_R;
AnsiString round = "even";



//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{

}
//---------------------------------------------------------------------------

void __fastcall TForm1::Timer_ballTimer(TObject *Sender)
{
  if (start_new_game==0)
   {
    Button1->Caption= "Start new game!";
    Button1->Visible = true;
    Button1->Enabled = true;
   }

   else
   {

    ball->Left+=x;
    ball->Top+=y;

 //bounce from the top wall
 if (ball->Top-5 <= background->Top) y =-y;

 //bounce from the bottom wall
 if (ball->Top+ball->Height+5 >= background->Height) y =-y;



 //losing the point by left bat

 if (ball->Left+ball ->Width <= left_bat->Left)
    {
     Timer_ball->Enabled = false;
     ball->Visible = false;
     points_right++;
     points_L = IntToStr(points_left);
     points_R = IntToStr(points_right);

     if (points_right < 5)
     {
     Button2->Caption= "Play another round!";
     Label1->Caption = points_L + ":" + points_R;
     Button2->Visible = true;
     Label1->Visible = true;
     Button3->Visible = true;
     Button2->Enabled = true;
     Button3->Enabled = true;
     }
    }
    else if
    ((ball->Top > left_bat->Top-ball->Height/2) &&
   (ball->Top < left_bat -> Top+left_bat->Height) &&
   (ball->Left < left_bat ->Left + left_bat -> Width) &&
   (ball->Left > left_bat ->Left + left_bat -> Width - 5))
   {
    if (x<0) x=-x;
   }

    //losing the point by right bat

 else if (ball->Left-ball->Width >= right_bat->Left+right_bat->Width)
    {
     Timer_ball->Enabled = false;
     ball->Visible = false;
     points_left++;
     points_L = IntToStr(points_left);
     points_R = IntToStr(points_right);

     if (points_left < 5)
     {
     Button2->Caption= "Play another round!";
     Label1->Caption = points_L + ":" + points_R;
     Button2->Visible = true;
     Button3->Visible = true;
     Label1->Visible = true;
     Button2->Enabled = true;
     Button3->Enabled = true;
     }
    }
    else if
    ((ball->Top > right_bat->Top-ball->Height/2) &&
   (ball->Top < right_bat -> Top+right_bat->Height) &&
   (ball->Left + ball ->Width > right_bat ->Left)&&
   (ball->Left + ball ->Width < right_bat ->Left + 5))
   {
      if (x>0) x=-x;
   }
       points_L = IntToStr(points_left);
       points_R = IntToStr(points_right);


    if (points_left == 5||points_right == 5)
   {
    if (points_left == 5)
    {Label2->Caption = "Left player Wins!!!";}

    if (points_right == 5)
    {Label2->Caption = "Right player Wins!!!";}

    Label1->Caption = "Final score " + points_L + ":" + points_R;
    Button1->Caption= "Play another game!";

    Button1->Visible = false;
    Button1->Visible = true;
    Label1->Visible = true;
    Label2->Visible = true;
    Button1->Enabled = true;
   }
   }
}

//---------------------------------------------------------------------------


void __fastcall TForm1::timer_left_bat_upTimer(TObject *Sender)
{
  if (left_bat->Top > 10) left_bat->Top -= 10;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::timer_left_bat_downTimer(TObject *Sender)
{
  if(left_bat->Top+left_bat->Height < background->Height-10)left_bat->Top += 10;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::timer_right_bat_upTimer(TObject *Sender)
{
    if (right_bat->Top > 10) right_bat->Top -= 10;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::timer_right_bat_downTimer(TObject *Sender)
{
  if(right_bat->Top+right_bat->Height < background->Height-10) right_bat->Top += 10;
}
//---------------------------------------------------------------------------


void __fastcall TForm1::FormKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
 if (Key == 'W') timer_left_bat_up->Enabled = true;
 if (Key == 'S') timer_left_bat_down->Enabled = true;
 if (Key == VK_UP) timer_right_bat_up->Enabled = true;
 if (Key == VK_DOWN) timer_right_bat_down->Enabled = true;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormKeyUp(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
 if (Key == 'W') timer_left_bat_up->Enabled = false;
 if (Key == 'S') timer_left_bat_down->Enabled = false;
 if (Key == VK_UP) timer_right_bat_up->Enabled = false;
 if (Key == VK_DOWN) timer_right_bat_down->Enabled = false;
 }
//---------------------------------------------------------------------------

void __fastcall TForm1::Button2Click(TObject *Sender)
{
 ball->Left = 453;
 ball->Top = 184;
 ball->Visible = true;
 Timer_ball->Enabled = true;
 Button2->Visible = false;
 Label1->Visible = false;
 Button3->Visible = false;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button1Click(TObject *Sender)
{
 ball->Left = 453;
 ball->Top = 184;
 ball->Visible = true;
 points_left = 0;
 points_right = 0;
 Timer_ball->Enabled = true;
 Button1->Visible = false;
 Label1->Visible = false;
 Label2->Visible = false;
 start_new_game++;
}
void __fastcall TForm1::FormCreate(TObject *Sender)
{
AnsiString strWelcome = "Welcome to PingPong game :-)";
AnsiString strCtr = "Controls in the game:";
AnsiString strCtrLeft = "Left player - keys W and S.";
AnsiString strCtrRight = "Right player - arrows up and down.";
AnsiString strAdd = "Additional information:";
AnsiString strBall = "Ball at the begining of the round goes to pointw loser direction.";
AnsiString strEnd = "Good Luck! may the better win!!!";

AnsiString text = strWelcome + sLineBreak + sLineBreak + strCtr + sLineBreak +
			strCtrLeft + sLineBreak + strCtrRight
                       + sLineBreak + sLineBreak + strAdd + sLineBreak +
                       strBall + sLineBreak + sLineBreak + strEnd;

 char* t = text.c_str();
 Application->MessageBox(t, "PingPong", MB_OK);

}
//---------------------------------------------------------------------------



void __fastcall TForm1::Button3Click(TObject *Sender)
{
  if(Application->MessageBox("Do you really want to start new game?", "NewGame",
 MB_YESNOCANCEL | MB_ICONQUESTION) == IDYES)
 {
 ball->Left = 453;
 ball->Top = 184;
 ball->Visible = true;
 points_left = 0;
 points_right = 0;
 Timer_ball->Enabled = true;
 Button2->Visible = false;
 Button3->Visible = false;
 Label1->Visible = false;
 Label2->Visible = false;
 start_new_game++;
 }
}


