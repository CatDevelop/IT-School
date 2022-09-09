unit Unit1;

{$mode objfpc}{$H+}

interface

uses
  Classes, SysUtils, Forms, Controls, Graphics, Dialogs, StdCtrls, ExtCtrls,
  Grids, ActnList, Crt;

type

  { TForm1 }

  TForm1 = class(TForm)
    Button1: TButton;
    Button2: TButton;
    Button3: TButton;
    Button4: TButton;
    Button5: TButton;
    Button6: TButton;
    Edit1: TEdit;
    Edit2: TEdit;
    Edit3: TEdit;
    Edit4: TEdit;
    GroupBox1: TGroupBox;
    GroupBox2: TGroupBox;
    GroupBox3: TGroupBox;
    Label1: TLabel;
    Label10: TLabel;
    Label11: TLabel;
    Label2: TLabel;
    Label3: TLabel;
    Label4: TLabel;
    Label5: TLabel;
    Label6: TLabel;
    Label7: TLabel;
    Label8: TLabel;
    Label9: TLabel;
    StaticText1: TStaticText;
    StaticText2: TStaticText;
    StaticText3: TStaticText;
    StringGrid1: TStringGrid;
    StringGrid2: TStringGrid;
    StringGrid3: TStringGrid;

    procedure Button1Click(Sender: TObject);
    procedure Button2Click(Sender: TObject);
    procedure Button4Click(Sender: TObject);
    procedure Button5Click(Sender: TObject);
    procedure Button6Click(Sender: TObject);
    procedure Edit1Change(Sender: TObject);
    procedure Edit2Change(Sender: TObject);
    procedure Edit3Change(Sender: TObject);
    procedure Edit4Change(Sender: TObject);

    procedure StaticText2Click(Sender: TObject);
    procedure StaticText3Click(Sender: TObject);

    procedure Button3Click(Sender: TObject);


  private

  public

  end;

var
  Form1: TForm1;
  Form2: TForm1;
  Form3: TForm1;
  Form4: TForm1;

  Lines1, Lines2, Lines3: integer;
  Columns1, Columns2, Columns3: integer;

  i, j, k: integer;
  FirstArray: array[1..1000, 1..1000] of real;
  SecondArray: array[1..1000, 1..1000] of real;
  ThirdArray: array[1..1000, 1..1000] of real;


implementation

{$R *.lfm}

{ TForm1 }




///////////Ограничение форм///////////

procedure TForm1.Edit1Change(Sender: TObject);
begin
     Edit1.NumbersOnly := true;
end;

procedure TForm1.Edit2Change(Sender: TObject);
begin
     Edit2.NumbersOnly := true;
end;

procedure TForm1.Edit3Change(Sender: TObject);
begin
     Edit3.NumbersOnly := true;
end;

procedure TForm1.Edit4Change(Sender: TObject);
begin
     Edit4.NumbersOnly := true;
end;

//////////////////////////////////////



////////////Задание матриц////////////

procedure TForm1.Button1Click(Sender: TObject);   //Массив №1
begin
     Lines1 := StrToInt(edit1.text)+1;    //Кол-во строк
     Columns1 := StrToInt(edit2.text)+1;  //Кол-во столбцов

     StringGrid1.RowCount := Lines1;
     StringGrid1.ColCount := Columns1;

     randomize;

     for i := 2 to Lines1 do              //Заполнение массива рандомными значениями
         for j := 2 to Columns1 do
             begin
                  FirstArray[i, j] := random(2000)-1000;
                  StringGrid1.Cells[j-1, i-1] := FloatToStr(FirstArray[i, j]);
             end;
end;

procedure TForm1.Button2Click(Sender: TObject);   //Массив №2
begin
     Lines2 := StrToInt(edit3.text)+1;
     Columns2 := StrToInt(edit4.text)+1;

     StringGrid2.RowCount := Lines2;      //Кол-во строк
     StringGrid2.ColCount := Columns2;    //Кол-во столбцов

     randomize;

     for i := 2 to Lines2 do              //Заполнение массива рандомными значениями
         for j := 2 to Columns2 do
             begin
                  SecondArray[i, j] := random(2000)-1000;
                  StringGrid2.Cells[j-1, i-1] := FloatToStr(SecondArray[i, j]);
             end;
end;

//////////////////////////////////////



/////////Действя с матрицами//////////

procedure TForm1.Button4Click(Sender: TObject);  //Сложение матриц №1 и №2
begin
     if (StringGrid1.RowCount = StringGrid2.RowCount) and (StringGrid1.ColCount = StringGrid2.ColCount) then
        begin
             Lines3 := StringGrid2.RowCount;
             Columns3 := StringGrid2.ColCount;

             StringGrid3.RowCount := Lines3;      //Кол-во строк
             StringGrid3.ColCount := Columns3;    //Кол-во столбцов

             for i := 2 to Lines3 do
                 for j := 2 to Columns3 do
                     begin
                          ThirdArray[i, j] := FirstArray[i, j] + SecondArray[i, j];
                          StringGrid3.Cells[j-1, i-1] := FloatToStr(ThirdArray[i, j]);
                     end;
        end
     else
        begin
             StaticText2.Visible := true;
        end;
end;

procedure TForm1.Button5Click(Sender: TObject);  //Умножение матриц №1 и №2
begin
     if (StringGrid1.ColCount = StringGrid2.RowCount) then
        begin
             Lines3 := StringGrid1.RowCount;
             Columns3 := StringGrid2.ColCount;

             StringGrid3.RowCount := Lines3;      //Кол-во строк
             StringGrid3.ColCount := Columns3;    //Кол-во столбцов

             for i := 2 to Lines3 do
                 for j := 2 to Columns3 do
                     begin
                          ThirdArray[i, j] := 0;
                          for k := 1 to Columns3+1 do
                              begin
                                   ThirdArray[i, j] := ThirdArray[i, j] + FirstArray[i, k] * SecondArray[k, j];
                              end;
                          StringGrid3.Cells[j-1, i-1] := FloatToStr(ThirdArray[i, j]);
                     end;
        end
     else
        begin
             StaticText3.Visible := true;
        end;


end;

procedure TForm1.Button6Click(Sender: TObject);  //Транспонирование матрицы №1
begin
     if (StringGrid1.RowCount = StringGrid1.ColCount) then
        begin
             Lines3 := StringGrid1.RowCount;
             Columns3 := StringGrid1.ColCount;

             StringGrid3.RowCount := Lines3;      //Кол-во строк
             StringGrid3.ColCount := Columns3;    //Кол-во столбцов

             for i := 2 to Lines3 do
                 for j := 2 to Columns3 do
                     begin
                          ThirdArray[i, j] := FirstArray[j, i];
                          StringGrid3.Cells[j-1, i-1] := FloatToStr(ThirdArray[i, j]);
                     end;
        end;
end;

//////////////////////////////////////

procedure TForm1.StaticText2Click(Sender: TObject); //Ошибка сложения
begin
     StaticText2.Visible := False;
end;

procedure TForm1.StaticText3Click(Sender: TObject); //Ошибка умножения
begin
     StaticText3.Visible := False;
end;


procedure TForm1.Button3Click(Sender: TObject); //Кнопка "Выход"
begin
     Application.Terminate;
end;

end.

