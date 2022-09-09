unit Unit1;

{$mode objfpc}{$H+}

interface

uses
  Classes, SysUtils, Forms, Controls, Graphics, Dialogs, StdCtrls, Grids;

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
    StringGrid1: TStringGrid;
    procedure Button1Click(Sender: TObject);
    procedure Button2Click(Sender: TObject);
    procedure CreateMagic_nch(N: integer);
    procedure CreateMagic_ch(n: Integer);
  private

  public

  end;

var
  Form1: TForm1;

implementation

{$R *.lfm}

{ TForm1 }
procedure TForm1.CreateMagic_nch(N: integer);
Var
  a: array [0..16,0..16] of Word;
  ss: word;
  nn: word;
  i,j: word;
  x,y: word;
Begin
  ss := ((N-1) div 2);
  nn := 1;
  for i:=0 to N-1 do
    for j:=0 to N-1 do
    begin
      x := (-ss+i+j+N) mod N;
      y := (ss+i-j+N) mod N;
      a[x,y] := nn;
      inc(nn);
    end;
    for i := 0 to N-1 do
      for j := 0 to N-1 do
        StringGrid1.Cells[j+1, i+1] := IntToStr(a[i,j]);
end;

procedure TForm1.CreateMagic_ch(n: integer);
var
  i, j, k, s, b, r, m: integer;
  a: array[1..13, 1..13] of integer;
  t: integer;
begin
  if odd(n) Then
  begin
    i := 1; j := Succ(n div 2);
    for k := 1 To sqr(n) do
    begin
      a[i,j] := k;
      If k mod n = 0 Then Inc(i)
      else
      begin
        dec(i);
        inc(j);
        if i = 0 then i := n;
        if j > n then j := 1
      end
    end;
  end
  else
    if n mod 4 = 0 then
    begin
      k := 1;
      for i := 1 to n do
        for j := 1 to n do
        begin
          a[i, j] := k;
          inc(k)
        end;
      j := 2;
      m := n div 2;
      for i := 1 to m do
        for k := 1 to m div 2 do
        begin
          if j = Succ(m) then j := 2
          else
            if j = (m + 2) Then j := 1;
          s := Succ(n - i);
          b := Succ(n - j);

          t:= a[i, j];
          a[i, j] := a[s, b];
          a[s, b] := t;

          t:= a[i, b];
          a[i, b] := a[s, j];
          a[s, j] := t;
          inc(j, 2);
        end
    end
    else
      If n <> 2 Then
      begin
        k := 1;
        for i := 1 to n do
          for j := 1 to n do
          begin
            a[i, j] := k;
            Inc(k)
          end;
        r := Pred(n div 2) div 2;
        m := n div 2;

        For i := 1 To m Do
        begin
          j := i;
          for k := 1 to r do
          begin
            if j > m then j := 1;
            s := Succ(n - i); b := Succ(n - j);
            t:= a[i, j];
            a[i, j] := a[s, b];
            a[s, b] := t;

            t:= a[i, b];
            a[i, b] := a[s, j];
            a[s, j] := t;
            Inc(j)
          end
        end;

        i := 1; j := Succ(r);
        for k := 1 to m do
        begin
          if j > m then j := 1;
          s := Succ(n - i);
          t:= a[i, j];
          a[i, j] := a[s, j];
          a[s, j] := t;

          inc(i);
          inc(j)
        end;

        i := 1;
        j := r + 2;
        for k := 1 to m Do
        begin
          if j > m then j := 1;
          b := Succ(n - j);

          t:= a[i, j];
          a[i, j] := a[i, b];
          a[i, b] := t;

          inc(i);
          inc(j)
        end
      end

    for i := 1 to n Do
      for j := 1 to n Do
        StringGrid1.Cells[j, i] := IntToStr(a[i, j]);
end;



procedure TForm1.Button1Click(Sender: TObject);
var
  qq: integer;
begin
  if (StrToInt(Edit1.Text) >= 3) and (StrToInt(Edit1.Text) <= 12) then
    if StrToInt(Edit1.Text) mod 2 = 0 then
      begin
        qq := StrToInt(Edit1.Text);
        StringGrid1.RowCount := qq+1;
        StringGrid1.ColCount := qq+1;
        CreateMagic_ch(qq);
      end
      else
      begin
        qq := StrToInt(Edit1.Text);
        StringGrid1.RowCount := qq+1;
        StringGrid1.ColCount := qq+1;
        CreateMagic_nch(qq);
      end;
end;

procedure TForm1.Button2Click(Sender: TObject);
begin
  Application.terminate;
end;

end.

