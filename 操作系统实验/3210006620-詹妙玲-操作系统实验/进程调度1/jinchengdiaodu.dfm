object mianform: Tmianform
  Left = 390
  Top = 0
  ActiveControl = run
  Caption = #36827#31243#35843#24230
  ClientHeight = 683
  ClientWidth = 677
  Color = clSkyBlue
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  Position = poDesigned
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 11
    Top = 8
    Width = 65
    Height = 13
    Caption = #24403#21069#26102#21051#65306
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Label2: TLabel
    Left = 82
    Top = 8
    Width = 6
    Height = 13
    Caption = '0'
  end
  object select_method: TGroupBox
    Left = 343
    Top = 27
    Width = 314
    Height = 110
    Caption = #35843#24230#31639#27861
    Color = clSkyBlue
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentBackground = False
    ParentColor = False
    ParentFont = False
    TabOrder = 0
    object run: TButton
      Left = 41
      Top = 76
      Width = 85
      Height = 25
      Caption = #36816#34892
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
      TabOrder = 0
      OnClick = runClick
    end
    object radio_FCFS: TRadioButton
      Left = 77
      Top = 22
      Width = 121
      Height = 17
      Caption = #20808#26469#20808#26381#21153#65288'FCFS'#65289
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
      TabOrder = 1
      OnClick = radio_FCFSClick
    end
    object radio_SPF: TRadioButton
      Left = 77
      Top = 45
      Width = 113
      Height = 17
      Caption = #30701#36827#31243#20248#20808#65288'SPF'#65289
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
      TabOrder = 2
      OnClick = radio_SPFClick
    end
  end
  object add_new_pro: TGroupBox
    Left = 8
    Top = 27
    Width = 313
    Height = 110
    Caption = #28155#21152#26032#36827#31243
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 1
    object Label3: TLabel
      Left = 20
      Top = 18
      Width = 24
      Height = 13
      Caption = #21517#31216
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
    end
    object Label4: TLabel
      Left = 123
      Top = 18
      Width = 48
      Height = 13
      Caption = #26381#21153#26102#38388
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
    end
    object Label5: TLabel
      Left = 236
      Top = 18
      Width = 48
      Height = 13
      Caption = #25152#38656#36164#28304
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
    end
    object Edit_new: TEdit
      Left = 16
      Top = 42
      Width = 43
      Height = 21
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = []
      ImeName = #20013#25991' ('#31616#20307') - '#25628#29399#25340#38899#36755#20837#27861
      ParentFont = False
      TabOrder = 0
      OnChange = Edit_newChange
    end
    object combo_new: TComboBox
      Left = 129
      Top = 42
      Width = 49
      Height = 21
      AutoDropDown = True
      Style = csDropDownList
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = []
      ImeName = #20013#25991' ('#31616#20307') - '#25628#29399#25340#38899#36755#20837#27861
      ParentFont = False
      TabOrder = 1
      OnChange = combo_newChange
      Items.Strings = (
        '1'
        '2'
        '3'
        '4'
        '5'
        '6'
        '7'
        '8'
        '9'
        '10'
        '11'
        '12'
        '13'
        '14'
        '15'
        '16'
        '17'
        '18'
        '19'
        '20')
    end
    object Combo_newSourse: TComboBox
      Left = 236
      Top = 42
      Width = 49
      Height = 21
      AutoDropDown = True
      Style = csDropDownList
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = []
      ImeName = #20013#25991' ('#31616#20307') - '#25628#29399#25340#38899#36755#20837#27861
      ParentFont = False
      ParentShowHint = False
      ShowHint = False
      TabOrder = 2
      OnChange = Combo_newSourseChange
      Items.Strings = (
        '1'
        '2'
        '3'
        '4'
        '5'
        '')
    end
    object clear: TButton
      Left = 47
      Top = 76
      Width = 92
      Height = 25
      Caption = #28165#31354
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
      TabOrder = 3
      OnClick = clearClick
    end
    object done: TButton
      Left = 180
      Top = 76
      Width = 86
      Height = 25
      Caption = #25552#20132
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
      TabOrder = 4
      OnClick = doneClick
    end
  end
  object running_pro: TGroupBox
    Left = 8
    Top = 143
    Width = 649
    Height = 73
    Caption = #27491#22312#36816#34892#30340#36827#31243
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 2
    object 名称: TLabel
      Left = 53
      Top = 19
      Width = 36
      Height = 13
      Caption = #36827#31243#21517
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
    end
    object ID: TLabel
      Left = 18
      Top = 19
      Width = 11
      Height = 13
      Caption = 'ID'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
    end
    object 开始运行时间: TLabel
      Left = 126
      Top = 19
      Width = 72
      Height = 13
      Caption = #24320#22987#36816#34892#26102#38388
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
    end
    object 已运行时间: TLabel
      Left = 233
      Top = 19
      Width = 60
      Height = 13
      Caption = #24050#36816#34892#26102#38388
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
    end
    object 还需运行时间: TLabel
      Left = 321
      Top = 19
      Width = 72
      Height = 13
      Caption = #36824#38656#36816#34892#26102#38388
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
    end
    object 所需资源: TLabel
      Left = 431
      Top = 19
      Width = 48
      Height = 13
      Caption = #25152#38656#36164#28304
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
    end
    object 状态: TLabel
      Left = 590
      Top = 19
      Width = 24
      Height = 13
      Caption = #29366#24577
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
    end
    object run_id: TLabel
      Left = 20
      Top = 48
      Width = 3
      Height = 13
    end
    object run_name: TLabel
      Left = 67
      Top = 48
      Width = 3
      Height = 13
    end
    object run_start_time: TLabel
      Left = 162
      Top = 48
      Width = 3
      Height = 13
    end
    object run_finish_time: TLabel
      Left = 251
      Top = 48
      Width = 3
      Height = 13
    end
    object run_rest_time: TLabel
      Left = 353
      Top = 48
      Width = 3
      Height = 13
    end
    object run_source: TLabel
      Left = 454
      Top = 48
      Width = 3
      Height = 13
    end
    object run_status: TLabel
      Left = 603
      Top = 48
      Width = 3
      Height = 13
    end
    object Label6: TLabel
      Left = 512
      Top = 19
      Width = 48
      Height = 13
      Caption = #26381#21153#26102#38388
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
    end
    object run_service_time: TLabel
      Left = 534
      Top = 48
      Width = 3
      Height = 13
    end
  end
  object ready_pro: TGroupBox
    Left = 8
    Top = 222
    Width = 649
    Height = 137
    Caption = #23601#32490#38431#21015
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 3
    object ready_queue: TStringGrid
      Left = 3
      Top = 15
      Width = 643
      Height = 128
      Color = clSkyBlue
      ColCount = 6
      RowCount = 50
      FixedRows = 0
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
      TabOrder = 0
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
  object GroupBox_FCFS: TGroupBox
    Left = 8
    Top = 357
    Width = 649
    Height = 164
    Caption = 'FCFS'#35843#24230#32467#26524
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 4
    object grid_FCFS: TStringGrid
      Left = 3
      Top = 14
      Width = 643
      Height = 150
      ColCount = 9
      RowCount = 50
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
      TabOrder = 0
      ColWidths = (
        64
        63
        64
        64
        64
        64
        64
        64
        64)
    end
  end
  object GroupBox_SPF: TGroupBox
    Left = 8
    Top = 519
    Width = 649
    Height = 162
    Caption = 'SPF'#35843#24230#32467#26524
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 5
    object grid_SPF: TStringGrid
      Left = 3
      Top = 14
      Width = 643
      Height = 145
      ColCount = 9
      RowCount = 50
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
      TabOrder = 0
      ColWidths = (
        64
        64
        64
        64
        64
        64
        64
        65
        64)
    end
  end
  object button_clear: TButton
    Left = 511
    Top = 103
    Width = 82
    Height = 25
    Caption = #20840#37096#28165#31354
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
    TabOrder = 6
    OnClick = button_clearClick
  end
  object Timer1: TTimer
    Enabled = False
    OnTimer = Timer1Timer
    Left = 280
    Top = 65520
  end
end
