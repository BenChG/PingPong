//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Graphics.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
        TShape *background;
        TImage *ball;
        TTimer *Timer_ball;
        TImage *left_bat;
        TImage *right_bat;
        TTimer *timer_left_bat_up;
        TTimer *timer_left_bat_down;
        TTimer *timer_right_bat_up;
        TTimer *timer_right_bat_down;
        TButton *Button1;
        TLabel *Label1;
        TButton *Button2;
        TLabel *Label2;
        TButton *Button3;
        void __fastcall Timer_ballTimer(TObject *Sender);
        void __fastcall timer_left_bat_upTimer(TObject *Sender);
        void __fastcall timer_left_bat_downTimer(TObject *Sender);
        void __fastcall FormKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
        void __fastcall FormKeyUp(TObject *Sender, WORD &Key,
          TShiftState Shift);
        void __fastcall timer_right_bat_upTimer(TObject *Sender);
        void __fastcall timer_right_bat_downTimer(TObject *Sender);
        void __fastcall Button1Click(TObject *Sender);
        void __fastcall Button2Click(TObject *Sender);
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall Button3Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
