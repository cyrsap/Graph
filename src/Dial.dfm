object DialogueForm: TDialogueForm
  Left = 522
  Top = 186
  Width = 218
  Height = 141
  BorderIcons = []
  Caption = #1042#1074#1077#1076#1080#1090#1077' '#1074#1077#1089' '#1088#1077#1073#1088#1072
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  DesignSize = (
    210
    114)
  PixelsPerInch = 96
  TextHeight = 13
  object WeightEdit: TEdit
    Left = 40
    Top = 24
    Width = 121
    Height = 21
    TabOrder = 0
    Text = '5'
  end
  object ConfirmBtn: TButton
    Left = 64
    Top = 66
    Width = 75
    Height = 25
    Anchors = []
    Caption = #1054#1050
    TabOrder = 1
    OnClick = ConfirmBtnClick
  end
end
