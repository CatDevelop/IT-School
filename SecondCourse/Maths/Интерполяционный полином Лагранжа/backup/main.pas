unit Main;

{$mode objfpc}{$H+}

interface

uses
  Classes, SysUtils, Forms, Controls, Graphics, Dialogs, ComCtrls, StdCtrls,
  ExtCtrls, Grids, Types, Math;

type

  { TForm1 }

  TForm1 = class(TForm)
    Button1: TButton;
    Button2: TButton;
    Button3: TButton;
    GroupBox1: TGroupBox;
    Image1: TImage;
    Label1: TLabel;
    PageControl1: TPageControl;
    PaintBox1: TPaintBox;
    StringGrid1: TStringGrid;
    StringGrid2: TStringGrid;
    StringGrid3: TStringGrid;
    StringGrid4: TStringGrid;
    TabSheet1: TTabSheet;
    TabSheet2: TTabSheet;
    procedure Button1Click(Sender: TObject);
    procedure Button2Click(Sender: TObject);
    procedure Button3Click(Sender: TObject);
    procedure FormCreate(Sender: TObject);
    procedure PaintBox1MouseDown(Sender: TObject; Button: TMouseButton;
      Shift: TShiftState; X, Y: Integer);
  private

  public

  end;

const
  eps = 0.00001;

var
  Form1: TForm1;
  lastPointX, countPoint: integer;
  i, j: integer;

  polinom:real;
  isDraw: boolean;

  n: integer;
  k, index: integer;
  temp: real;

  max: double;

  FirstArray: array[1..10, 1..10] of extended;
  SecondArray: array[1..10] of extended;
  ThirdArray: array[1..10] of extended;
  FourthArray: array[1..10] of extended;

implementation

{$R *.lfm}

{ TForm1 }

procedure TForm1.PaintBox1MouseDown(Sender: TObject; Button: TMouseButton;
  Shift: TShiftState; X, Y: Integer);
begin
     if isDraw = false then
     begin
          PaintBox1.Canvas.Pen.Color := clRed;

          if (X > lastPointX) and (StringGrid1.RowCount < 10) then
          begin
               FourthArray[countPoint]:= X;
               //StringGrid2.Cells[1, countPoint+1]:= IntToStr(FourthArray[countPoint]);
               PaintBox1.Canvas.Brush.Color := clRed;
               PaintBox1.Canvas.Pen.Width:= 3;
               PaintBox1.Canvas.Ellipse(X-4, Y-4, X+4, Y+4);

               if StringGrid1.RowCount > 1 then
                  PaintBox1.Canvas.LineTo(X, Y)
               else
                   PaintBox1.Canvas.MoveTo(X, Y);

               StringGrid1.RowCount := StringGrid1.RowCount+1;
               StringGrid1.Cells[0, StringGrid1.RowCount-1] := IntToStr(StringGrid1.RowCount-1);
               StringGrid1.Cells[1, StringGrid1.RowCount-1] := IntToStr(X-35);
               StringGrid1.Cells[2, StringGrid1.RowCount-1] := IntToStr((Y-306)*(-1));
               lastPointX := X;
               countPoint := countPoint+1;
          end;
     end;

end;

procedure TForm1.FormCreate(Sender: TObject);
begin
     StringGrid1.RowCount := 1;
     StringGrid1.ColCount := 3;

     StringGrid1.Cells[0, 0] := '№ точки';
     StringGrid1.Cells[1, 0] := 'X';
     StringGrid1.Cells[2, 0] := 'Y';

     lastPointX := 35;
     countPoint := 0;
end;

procedure TForm1.Button1Click(Sender: TObject);
begin
     isDraw:=true;
     StringGrid2.ColCount := countPoint+2;
     StringGrid2.RowCount := countPoint+1;

     StringGrid3.ColCount := 2;
     StringGrid3.RowCount := countPoint+1;

     StringGrid4.ColCount := 2;
     StringGrid4.RowCount := countPoint+1;

     for i := 1 to countPoint do
         for j := 1 to countPoint+1 do
             begin
                  FirstArray[i, j] := Power(StrToInt(StringGrid1.Cells[1, i]), j-1);
             end;

     for i := 1 to countPoint do
         begin
         SecondArray[i] := StrToInt(StringGrid1.Cells[2, i]);
         end;



     k := 1;
     n := countPoint+1;
     while k < n do
     begin
          // Поиск строки с максимальным a[i][k]
          max := abs(FirstArray[k][k]);
          index := k;

          for i := k+1 to n do
          begin
            if abs(FirstArray[i][k]) > max then
            begin
              max := abs(FirstArray[i][k]);
              index := i;
            end;
          end;

          // Перестановка строк
          //Label4.Caption := FloatToStr(max);
          if max < eps then
          begin
             //Label4.Caption := 'Решение получить невозможно из-за нулевого столбца ' + IntToStr(index) + ' матрицы A';
             exit;
          end
          else
              //Label4.Caption := FloatToStr(max);

          for j := 0 to n do
          begin
            temp := FirstArray[k][j];
            FirstArray[k][j] := FirstArray[index][j];
            FirstArray[index][j] := temp;
          end;

          temp := SecondArray[k];
          SecondArray[k] := SecondArray[index];
          SecondArray[index] := temp;

          // Нормализация уравнений
          for i := k to n do
          begin
               temp := FirstArray[i][k];
               if abs(temp) < eps then continue; // для нулевого коэффициента пропустить
               for j := 0 to n do
                   FirstArray[i][j] := FirstArray[i][j]/temp;
               SecondArray[i] := SecondArray[i]/temp;
               if i = k then continue; // уравнение не вычитать само из себя
               for j := 0 to n do
                   FirstArray[i][j] := FirstArray[i][j] - FirstArray[k][j];
               SecondArray[i] := SecondArray[i] - SecondArray[k];
          end;
          k:=k+1;
     end;

     // обратная подстановка
     for k := n-1 downto 0 do
     begin
          ThirdArray[k] := SecondArray[k];
          for i := 0 to k do
              SecondArray[i] := SecondArray[i] - FirstArray[i][k] * ThirdArray[k];
     end;

     for i := 1 to StringGrid1.RowCount-1 do
         StringGrid4.Cells[1,i] := FloatToStr(ThirdArray[i]);

     PaintBox1.Canvas.MoveTo(StrToInt(StringGrid1.Cells[1, 1])+35,StrToInt(StringGrid1.Cells[2, 1])*(-1)+306);
     PaintBox1.Canvas.Pen.Color := clGreen;
     //PaintBox1.Canvas.Pen.Width := 3;
     polinom := 0;

     for i := StrToInt(StringGrid1.Cells[1,1])+35 to StrToInt(StringGrid1.Cells[1,countPoint])+35 do //FourthArray[countPoint-1] downto FourthArray[0] do
         begin
              for j := 0 to countPoint do
                  begin
                       polinom := polinom+ThirdArray[j]*Power((i-35), j-1);
                  end;
              PaintBox1.Canvas.Pen.Width:= 3;
              PaintBox1.Canvas.LineTo(i, (round(polinom))*(-1)+306);
              polinom := 0;
         end;
end;

procedure TForm1.Button2Click(Sender: TObject);
begin
     isDraw:=false;
     lastPointX := 35;
     countPoint := 0;

     PaintBox1.Invalidate();
     PaintBox1.Canvas.MoveTo(0, 0);

     StringGrid1.RowCount := 1;
     StringGrid1.ColCount := 3;
     StringGrid1.Cells[0, 0] := '№ точки';
     StringGrid1.Cells[1, 0] := 'X';
     StringGrid1.Cells[2, 0] := 'Y';
end;

procedure TForm1.Button3Click(Sender: TObject);
begin
     Application.Terminate;
end;

end.

