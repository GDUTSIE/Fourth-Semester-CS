object mianform: Tmianform
  Left = 293
  Top = 165
  Caption = #23384#20648#31649#29702
  ClientHeight = 421
  ClientWidth = 727
  Color = clGradientActiveCaption
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  Position = poDesigned
  PixelsPerInch = 96
  TextHeight = 13
  object GroupBox1: TGroupBox
    Left = 16
    Top = 8
    Width = 401
    Height = 121
    Caption = #25805#20316
    TabOrder = 0
    object Button1: TButton
      Left = 12
      Top = 32
      Width = 121
      Height = 25
      Caption = #38543#26426#29983#25104#31354#38386#20998#21306
      TabOrder = 0
      OnClick = Button1Click
    end
    object Button2: TButton
      Left = 147
      Top = 32
      Width = 114
      Height = 25
      Caption = #38543#26426#29983#25104#20316#19994
      TabOrder = 1
      OnClick = Button2Click
    end
    object Button3: TButton
      Left = 280
      Top = 32
      Width = 110
      Height = 25
      Caption = #24320#22987#20998#37197
      TabOrder = 2
      OnClick = Button3Click
    end
    object Button4: TButton
      Left = 12
      Top = 80
      Width = 121
      Height = 25
      Caption = #20108#27425#20998#37197
      TabOrder = 3
      OnClick = Button4Click
    end
    object Button5: TButton
      Left = 147
      Top = 80
      Width = 114
      Height = 25
      Caption = #22238#25910#25152#26377#36164#28304
      TabOrder = 4
      OnClick = Button5Click
    end
    object Button6: TButton
      Left = 280
      Top = 80
      Width = 113
      Height = 25
      Caption = #28165#31354
      TabOrder = 5
      OnClick = Button6Click
    end
  end
  object GroupBox2: TGroupBox
    Left = 423
    Top = 8
    Width = 290
    Height = 121
    Caption = #36873#25321#31639#27861
    TabOrder = 1
    object RadioButton1: TRadioButton
      Left = 85
      Top = 32
      Width = 113
      Height = 17
      Caption = #39318#27425#36866#24212#31639#27861
      TabOrder = 0
      OnClick = RadioButton1Click
    end
    object RadioButton2: TRadioButton
      Left = 85
      Top = 56
      Width = 113
      Height = 17
      Caption = #24490#29615#39318#27425#36866#24212#31639#27861
      TabOrder = 1
      OnClick = RadioButton2Click
    end
    object RadioButton3: TRadioButton
      Left = 85
      Top = 80
      Width = 113
      Height = 17
      Caption = #26368#20339#36866#24212#31639#27861
      TabOrder = 2
      OnClick = RadioButton3Click
    end
  end
  object StringGrid_memory: TStringGrid
    Left = 16
    Top = 135
    Width = 401
    Height = 290
    RowCount = 11
    TabOrder = 2
    ColWidths = (
      64
      95
      92
      62
      74)
  end
  object StringGrid_work: TStringGrid
    Left = 423
    Top = 135
    Width = 290
    Height = 290
    ColCount = 4
    RowCount = 11
    TabOrder = 3
    ColWidths = (
      64
      64
      64
      67)
    RowHeights = (
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24)
  end
end
