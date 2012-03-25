object MainForm: TMainForm
  Left = 210
  Top = 128
  BorderIcons = []
  BorderStyle = bsSingle
  Caption = #1056#1072#1089#1095#1077#1090' '#1084#1080#1085#1080#1084#1072#1083#1100#1085#1086#1075#1086' '#1087#1091#1090#1080' '#1085#1072' '#1075#1088#1072#1092#1077' '#1087#1086' '#1072#1083#1075#1086#1088#1080#1090#1084#1091' '#1044#1077#1081#1082#1089#1090#1088#1099
  ClientHeight = 568
  ClientWidth = 953
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object GroupBox1: TGroupBox
    Left = 704
    Top = 8
    Width = 209
    Height = 489
    TabOrder = 0
    object AddVertexBtn: TSpeedButton
      Left = 24
      Top = 24
      Width = 161
      Height = 33
      GroupIndex = 1
      Caption = #1044#1086#1073#1072#1074#1080#1090#1100' '#1074#1077#1088#1096#1080#1085#1091
      OnClick = AddVertexBtnClick
    end
    object DeleteVertexBtn: TSpeedButton
      Left = 24
      Top = 64
      Width = 161
      Height = 33
      GroupIndex = 1
      Caption = #1059#1076#1072#1083#1080#1090#1100' '#1074#1077#1088#1096#1080#1085#1091
      OnClick = DeleteVertexBtnClick
    end
    object AddRibBtn: TSpeedButton
      Left = 24
      Top = 104
      Width = 161
      Height = 33
      GroupIndex = 1
      Caption = #1044#1086#1073#1072#1074#1080#1090#1100' '#1088#1077#1073#1088#1086
      OnClick = AddRibBtnClick
    end
    object DeleteRibBtn: TSpeedButton
      Left = 24
      Top = 144
      Width = 161
      Height = 33
      GroupIndex = 1
      Caption = #1059#1076#1072#1083#1080#1090#1100' '#1088#1077#1073#1088#1086
      OnClick = DeleteRibBtnClick
    end
    object CalcBtn: TSpeedButton
      Left = 24
      Top = 192
      Width = 161
      Height = 33
      GroupIndex = 1
      Caption = #1056#1072#1089#1089#1095#1080#1090#1072#1090#1100
    end
    object Label: TLabel
      Left = 32
      Top = 248
      Width = 34
      Height = 16
      Caption = 'Label'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object ClearBtn: TButton
      Left = 24
      Top = 440
      Width = 161
      Height = 33
      Caption = #1054#1095#1080#1089#1090#1080#1090#1100
      TabOrder = 0
      OnClick = ClearBtnClick
    end
  end
  object Panel1: TPanel
    Left = 16
    Top = 14
    Width = 673
    Height = 483
    Color = clWhite
    TabOrder = 1
    object Image: TImage
      Left = 0
      Top = 0
      Width = 673
      Height = 481
      OnMouseDown = ImageMouseDown
      OnMouseUp = ImageMouseUp
    end
  end
  object ClsBtn: TButton
    Left = 728
    Top = 520
    Width = 161
    Height = 33
    Caption = #1042#1099#1093#1086#1076
    TabOrder = 2
    OnClick = ClsBtnClick
  end
  object HelpBtn: TButton
    Left = 904
    Top = 520
    Width = 33
    Height = 33
    Caption = '?'
    TabOrder = 3
    OnClick = HelpBtnClick
  end
end
