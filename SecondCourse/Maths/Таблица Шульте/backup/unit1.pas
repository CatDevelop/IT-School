unit Unit1;

{$mode objfpc}{$H+}

interface

uses
  Classes, Math, SysUtils, Forms, Controls, Graphics, Dialogs, StdCtrls, Grids,
  ExtCtrls, Types;

type

  { TForm1 }

  TForm1 = class(TForm)
    Button1: TButton;
    Button2: TButton;
    Button3: TButton;
    Button4: TButton;
    Button5: TButton;
    Button6: TButton;
    Button7: TButton;
    Button8: TButton;
    CheckBox1: TCheckBox;
    Edit1: TEdit;
    GroupBox1: TGroupBox;
    GroupBox2: TGroupBox;
    GroupBox3: TGroupBox;
    Label1: TLabel;
    Label2: TLabel;
    Label3: TLabel;
    Label4: TLabel;
    Label5: TLabel;
    StringGrid1: TStringGrid;
    Timer1: TTimer;
    procedure Button1Click(Sender: TObject);
    procedure Button2Click(Sender: TObject);
    procedure Button3Click(Sender: TObject);
    procedure Button4Click(Sender: TObject);
    procedure Button5Click(Sender: TObject);
    procedure Button6Click(Sender: TObject);
    procedure Button7Click(Sender: TObject);
    procedure Button8Click(Sender: TObject);
    procedure best_result(Sender: TObject);
    procedure set_best_result(Sender: TObject);
    procedure FormCreate(Sender: TObject);
    procedure StringGrid1Click(Sender: TObject);
    procedure StringGrid1DrawCell(Sender: TObject; aCol, aRow: Integer;
      aRect: TRect; aState: TGridDrawState);
    procedure Timer1Timer(Sender: TObject);
  private

  public

  end;

var
  Form1: TForm1;

  Arr: array[1..170] of integer;
  SelectArr: array[1..13,1..13] of integer;
  i, j, k, a, b: integer;
  numbers, select: integer;
  milsec, sec, min, alltime: integer;
  Smilsec, Ssec, Smin, salltime: string;
  fmilsec, fsec, fmin, falltime, tmp: integer;
  fsmilsec, fssec, fsmin, fsalltime, stmp: string;
  bestresult: TextFile;
implementation

{$R *.lfm}

{ TForm1 }
procedure TForm1.Button1Click(Sender: TObject);
begin
  best_result(Sender);
  if Edit1.Text <> '' then
  begin
    if (StrToInt(Edit1.Text) >= 3) and (StrToInt(Edit1.Text) <= 13) then
    begin
      StringGrid1.RowCount := StrToInt(Edit1.Text);
      StringGrid1.ColCount := StrToInt(Edit1.Text);
      for i := 0 to StringGrid1.ColCount-1 do
          for j := 0 to StringGrid1.RowCount-1 do
              StringGrid1.Cells[i, j] := '';

      for i := 0 to StringGrid1.ColCount do
      for j := 0 to StringGrid1.RowCount do
          SelectArr[i, j] := 0;

    end;
  end;
end;

procedure TForm1.Button2Click(Sender: TObject);
begin
  randomize;
  best_result(Sender);
  numbers := 1;
  select:=1;
  for i := 0 to (StringGrid1.ColCount*StringGrid1.RowCount)-1 do
  begin
    Arr[i] := numbers;
    inc(numbers);
    Label3.Caption := Label3.Caption + ' ' +IntToStr(Arr[i]);
  end;
  Arr[StringGrid1.ColCount*StringGrid1.RowCount] := 170;


  for i := 0 to StringGrid1.ColCount do
  for j := 0 to StringGrid1.RowCount do
      SelectArr[i, j] := 0;

  for i := 0 to StringGrid1.ColCount-1 do
      for j := 0 to StringGrid1.RowCount-1 do
      begin
        k := (StringGrid1.RowCount*StringGrid1.RowCount);
        while (k = (StringGrid1.RowCount*StringGrid1.RowCount)) or (Arr[k] = 170) do
        begin
          k := RandomRange(0, StringGrid1.ColCount*StringGrid1.RowCount);
          if (Arr[k] <> 170) then
          begin
            StringGrid1.Cells[i, j] := IntToStr(Arr[k]);
            Arr[k] := 170;
            break;
          end;
        end;
      end;
end;

procedure TForm1.Button3Click(Sender: TObject);
begin
  best_result(Sender);
  for i:= 0 to 169 do
      Arr[i] := i+1;
  select := 1;

  a := StringGrid1.RowCount;
  b := StringGrid1.ColCount;
  StringGrid1.Clear();
  StringGrid1.RowCount := a;
  StringGrid1.ColCount := b;

  for i := 0 to StringGrid1.ColCount do
  for j := 0 to StringGrid1.RowCount do
      SelectArr[i, j] := 0;
  StringGrid1.invalidate();
end;

procedure TForm1.Button4Click(Sender: TObject);
begin
  best_result(Sender);
  alltime := 0;
  min := 0;
  sec := 0;
  milsec := 0;
  Smin := '00';
  Ssec := '00';
  Smilsec := '000';
  Timer1.Enabled := True;
end;

procedure TForm1.Button5Click(Sender: TObject);
begin
  best_result(Sender);
  Timer1.Enabled := False;
end;

procedure TForm1.Button6Click(Sender: TObject);
begin
  best_result(Sender);
  Timer1.Enabled := True;
end;

procedure TForm1.Button7Click(Sender: TObject);
begin
  best_result(Sender);
  alltime := 0;
  min := 0;
  sec := 0;
  milsec := 0;
  Smin := '00';
  Ssec := '00';
  Smilsec := '000';
  Label5.Caption := '00:00:00';
  Timer1.Enabled := False;
end;

procedure TForm1.Button8Click(Sender: TObject);
begin
  Application.terminate;
end;

//milsec, sec, min, alltime: integer;
//Smilsec, Ssec, Smin: string;
//fmilsec, fsec, fmin, falltime: integer;
//fsmilsec, fssec, fsmin, fsalltime: string;

procedure TForm1.best_result(Sender: TObject);
begin
  AssignFile(bestresult, 'best_result.txt');
  if FileExists('best_result.txt') then
    begin
      Label5.Visible := True;
      try
        reset(bestresult);
        readln(bestresult, fsalltime);
        CloseFile(bestresult);
        falltime := StrToInt(fsalltime);
        fmin := (falltime div 60) div 60;
        fsec :=  (falltime mod 3600) div 60;
        fmilsec := (falltime mod 3600) mod 60;
        fsmilsec:= IntToStr(fmilsec);
        if fmilsec < 10 then
           fsmilsec := '0' + fsmilsec;
        fssec := IntToStr(fsec);
        if fsec < 10 then
           fssec := '0' + IntToStr(fsec);
        fsmin := IntToStr(fmin);
        if fmin < 10 then
           fsmin := '0' + IntToStr(fmin);
        Label5.Caption := 'Лучший результат: ' + fsmin + ':' + fssec + ':' + fsmilsec;
      except
        on E: EInOutError do
         ShowMessage('Ошибка обработки файла. Детали: '+E.Message);
      end;
    end
    else
        Label5.Visible := False;
end;

procedure TForm1.set_best_result(Sender: TObject);
begin
  AssignFile(bestresult, 'best_result.txt');
  try
      stmp := '0';
      if FileExists('best_result.txt') then
      begin
           reset(bestresult);
           readln(bestresult, stmp);
           CloseFile(bestresult);
           tmp := StrToInt(stmp);
           if tmp>alltime then
           begin
              rewrite(bestresult);
              writeln(bestresult, IntToStr(alltime-1));
              CloseFile(bestresult);
           end;
      end
      else
      begin
           rewrite(bestresult);
           writeln(bestresult, IntToStr(alltime-1));
           CloseFile(bestresult);
      end;

    except
      on E: EInOutError do
       ShowMessage('Ошибка обработки файла. Детали: '+E.Message);
    end;
end;

procedure TForm1.FormCreate(Sender: TObject);
begin
  best_result(Sender);
end;

procedure TForm1.StringGrid1Click(Sender: TObject);
begin
  if StringGrid1.Cells[StringGrid1.Col, StringGrid1.Row] = IntToStr(select) then
    begin
      SelectArr[StringGrid1.Col,StringGrid1.Row] := 1;
      inc(select);
    end;
  if (select = StringGrid1.ColCount*StringGrid1.RowCount+1) and (CheckBox1.Checked = True)  then
  begin
    set_best_result(Sender);
    best_result(Sender);
    Timer1.Enabled := False;
  end;
end;

procedure TForm1.StringGrid1DrawCell(Sender: TObject; aCol, aRow: Integer;
  aRect: TRect; aState: TGridDrawState);
begin
  for i := 0 to StringGrid1.ColCount do
  for j := 0 to StringGrid1.RowCount do
    if SelectArr[i, j] = 1 then
    begin
      StringGrid1.Canvas.Brush.Color := clGreen;
      StringGrid1.Canvas.Pen.Color := clWhite;
      StringGrid1.Canvas.FillRect(StringGrid1.CellRect(i, j));
      StringGrid1.Canvas.TextOut(StringGrid1.CellRect(i,j).Left+15,StringGrid1.CellRect(i,j).Top+15,StringGrid1.Cells[ACol,Arow]);
    end
    else
    begin
      StringGrid1.Canvas.Brush.Color := clWhite;
      StringGrid1.Canvas.FillRect(StringGrid1.CellRect(i, j));
      StringGrid1.Canvas.TextOut(StringGrid1.CellRect(i,j).Left+15,StringGrid1.CellRect(i,j).Top+15,StringGrid1.Cells[ACol,Arow]);
    end;
end;

procedure TForm1.Timer1Timer(Sender: TObject);
begin
  Smilsec:= IntToStr(milsec);
  if milsec < 10 then
     Smilsec := '0' + Smilsec;
  Ssec := IntToStr(sec);
  if sec < 10 then
     Ssec := '0' + IntToStr(sec);
  Smin := IntToStr(min);
  if min < 10 then
     Smin := '0' + IntToStr(min);

  Label4.Caption:= Smin+':'+Ssec+':'+Smilsec;
  inc(milsec);
  inc(alltime);
  if milsec >= 60 then
  begin
    milsec:=0;
    inc(sec);
  end;
  if sec >= 60 then
  begin
    sec := 0;
    inc(min);
  end;
end;

end.

