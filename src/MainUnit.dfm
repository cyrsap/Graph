object MainForm: TMainForm
  Left = 218
  Top = 129
  Width = 961
  Height = 595
  Caption = 'MainForm'
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
    end
    object DeleteVertexBtn: TSpeedButton
      Left = 24
      Top = 64
      Width = 161
      Height = 33
      GroupIndex = 1
      Caption = #1059#1076#1072#1083#1080#1090#1100' '#1074#1077#1088#1096#1080#1085#1091
    end
    object AddRibBtn: TSpeedButton
      Left = 24
      Top = 104
      Width = 161
      Height = 33
      GroupIndex = 1
      Caption = #1044#1086#1073#1072#1074#1080#1090#1100' '#1088#1077#1073#1088#1086
    end
    object DeleteRibBtn: TSpeedButton
      Left = 24
      Top = 144
      Width = 161
      Height = 33
      GroupIndex = 1
      Caption = #1059#1076#1072#1083#1080#1090#1100' '#1088#1077#1073#1088#1086
    end
    object ClearBtn: TButton
      Left = 24
      Top = 272
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
end