unit Main;

{$mode objfpc}{$H+}

interface

uses
  Classes, SysUtils, FileUtil, Forms, Controls, Graphics, Dialogs, ComCtrls,
  StdCtrls, Grids;

type

  { TForm1 }

  TForm1 = class(TForm)
    Button1: TButton;
    Button2: TButton;
    Edit1: TEdit;
    GroupBox1: TGroupBox;
    GroupBox2: TGroupBox;
    Label1: TLabel;
    Label2: TLabel;
    Label3: TLabel;
    Label4: TLabel;
    PageControl1: TPageControl;
    StringGrid1: TStringGrid;
    StringGrid2: TStringGrid;
    TabSheet1: TTabSheet;
    TabSheet2: TTabSheet;
    procedure Button1Click(Sender: TObject);
    procedure Button2Click(Sender: TObject);
    procedure Edit1Change(Sender: TObject);
    procedure Edit1Click(Sender: TObject);
    procedure StringGrid1KeyPress(Sender: TObject; var Key: char);
    procedure StringGrid1Selection(Sender: TObject; aCol, aRow: Integer);
  private

  public

  end;

const
  // eps - Точность вычислений
  eps = 0.00001;
  // SymbolArray - массив допустимых знаков
  SymbolArray:array[1..11] of char = ('0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '-');

var
  Form1: TForm1;

  // n - Количество уравнений в системе
  n: integer;

  // FirstArray - Массив коэффициентов
  FirstArray: array[1..1000, 1..1000] of real;
  // SecondArray - Массив свободных членов
  SecondArray: array[1..1000] of real;
  // ThirdArray - Массив ответов
  ThirdArray: array[1..1000] of real;

  SelectRow, SelectCol: integer;
  SelectText: string;

  k, index: integer;
  temp: real;
  i, j: integer;

  max: double;

implementation

{$R *.lfm}

{ TForm1 }

///////////Ограничение форм///////////
procedure TForm1.Edit1Change(Sender: TObject);
begin
     Edit1.NumbersOnly := true;
end;

procedure TForm1.Edit1Click(Sender: TObject);
begin
     Edit1.NumbersOnly := true;
end;

procedure TForm1.StringGrid1Selection(Sender: TObject; aCol, aRow: Integer);
begin
     SelectRow := aRow;
     SelectCol := aCol;
end;

procedure TForm1.StringGrid1KeyPress(Sender: TObject; var Key: char);
begin
     temp:=0;
     for i := 0 to 10 do
     begin
          if Key = SymbolArray[i] then temp:=temp+1;
     end;
     //ДОРАБОТАТЬ
     if temp<0 then
     begin
        Label4.Caption := 'Delete';
        //SelectText := StringGrid1.Cells[SelectRow, SelectCol];
        StringGrid1.Cells[SelectRow, SelectCol] :=  Copy(StringGrid1.Cells[SelectRow, SelectCol], 1, StringGrid1.Cells[SelectRow, SelectCol].Length - 1);
        //StringGrid1.Cells[SelectRow, SelectCol]:= SelectText;
     end;
end;



//////////////////////////////////////


procedure TForm1.Button1Click(Sender: TObject);
begin
     // Задание 1 матрицы
     StringGrid1.RowCount := StrToInt(edit1.text)+1;
     StringGrid1.ColCount := StrToInt(edit1.text)+2;

     // Задание 2 матрицы
     StringGrid2.RowCount := StrToInt(edit1.text)+1;
     StringGrid2.ColCount := 2;

     // Заполнение
     for i := 1 to StringGrid1.RowCount-1 do
     begin
          StringGrid1.Cells[i, 0] := 'A'+IntToStr(i);
     end;
     StringGrid1.Cells[StringGrid1.RowCount, 0] := 'B';
     StringGrid2.Cells[1, 0] := 'X';

     //Заполнение массива рандомными значениями
     randomize;
     for i := 2 to StringGrid1.RowCount do
         for j := 2 to StringGrid1.ColCount do
             begin
                  StringGrid1.Cells[j-1, i-1] := FloatToStr(random(200)-100);
             end;
end;

procedure TForm1.Button2Click(Sender: TObject);
begin
     // Задание массива коэффициентов
     for i := 1 to StringGrid1.RowCount-1 do
         for j := 1 to StringGrid1.ColCount-1 do
         begin
              FirstArray[i, j] := StrToInt(StringGrid1.Cells[j,i]);
         end;

     // Задание массива свободных членов
     for i := 1 to StringGrid1.RowCount-1 do
     begin
          SecondArray[i] := StrToInt(StringGrid1.Cells[StringGrid1.ColCount-1, i]);
     end;

     k := 1;
     n := StringGrid1.RowCount;
     Label4.Caption := IntToStr(n);
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
             Label4.Caption := 'Решение получить невозможно из-за нулевого столбца ' + IntToStr(index) + ' матрицы A';
             exit;
          end
          else
              Label4.Caption := FloatToStr(max);

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
         StringGrid2.Cells[1,i] := FloatToStr(ThirdArray[i]);
end;



end.

