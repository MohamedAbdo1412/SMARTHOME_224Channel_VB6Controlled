VERSION 5.00
Object = "{648A5603-2C6E-101B-82B6-000000000014}#1.1#0"; "MSCOMM32.OCX"
Begin VB.Form Form1 
   BackColor       =   &H00C0C0C0&
   BorderStyle     =   1  'Fixed Single
   Caption         =   "SMART_HOME MADE BY MOHAMED ABDELHAMID"
   ClientHeight    =   9375
   ClientLeft      =   150
   ClientTop       =   495
   ClientWidth     =   13500
   LinkTopic       =   "Form1"
   MaxButton       =   0   'False
   MinButton       =   0   'False
   ScaleHeight     =   9375
   ScaleMode       =   0  'User
   ScaleWidth      =   16443.36
   Begin VB.Timer TimerSensors 
      Interval        =   2370
      Left            =   8640
      Top             =   120
   End
   Begin VB.ListBox UARTWriteList 
      Height          =   1035
      Left            =   3000
      TabIndex        =   45
      Top             =   8280
      Width           =   2655
   End
   Begin VB.ListBox UARTReadList 
      Height          =   1035
      Left            =   120
      TabIndex        =   42
      Top             =   8280
      Width           =   2655
   End
   Begin VB.CommandButton cmd_Ser 
      Caption         =   "SET_ANGEL_B"
      BeginProperty Font 
         Name            =   "Bookman Old Style"
         Size            =   12
         Charset         =   0
         Weight          =   600
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   615
      Index           =   1
      Left            =   10920
      TabIndex        =   41
      Top             =   6120
      Width           =   2175
   End
   Begin VB.CommandButton cmd_Ser 
      Caption         =   "SET_ANGEL_A"
      BeginProperty Font 
         Name            =   "Bookman Old Style"
         Size            =   12
         Charset         =   0
         Weight          =   600
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   615
      Index           =   0
      Left            =   8400
      TabIndex        =   40
      Top             =   6120
      Width           =   2175
   End
   Begin VB.TextBox Servo_Text 
      BeginProperty Font 
         Name            =   "MS Sans Serif"
         Size            =   12
         Charset         =   0
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   405
      Index           =   1
      Left            =   10920
      TabIndex        =   39
      Text            =   "wait for connection"
      Top             =   5490
      Width           =   2175
   End
   Begin VB.TextBox Servo_Text 
      BeginProperty Font 
         Name            =   "MS Sans Serif"
         Size            =   12
         Charset         =   0
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   405
      Index           =   0
      Left            =   8400
      TabIndex        =   38
      Text            =   "wait for connection"
      Top             =   5520
      Width           =   2175
   End
   Begin VB.TextBox Sensors_Text 
      Enabled         =   0   'False
      BeginProperty Font 
         Name            =   "MS Sans Serif"
         Size            =   12
         Charset         =   0
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   375
      Index           =   3
      Left            =   10800
      TabIndex        =   37
      Text            =   "wait for connection"
      Top             =   3840
      Width           =   2295
   End
   Begin VB.TextBox Sensors_Text 
      Enabled         =   0   'False
      BeginProperty Font 
         Name            =   "MS Sans Serif"
         Size            =   12
         Charset         =   0
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      ForeColor       =   &H80000007&
      Height          =   375
      Index           =   2
      Left            =   10800
      TabIndex        =   36
      Text            =   "wait for connection"
      Top             =   3240
      Width           =   2295
   End
   Begin VB.TextBox Sensors_Text 
      Enabled         =   0   'False
      BeginProperty Font 
         Name            =   "MS Sans Serif"
         Size            =   12
         Charset         =   0
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   375
      Index           =   1
      Left            =   10800
      TabIndex        =   35
      Text            =   "wait for connection"
      Top             =   2640
      Width           =   2295
   End
   Begin VB.TextBox Sensors_Text 
      Enabled         =   0   'False
      BeginProperty Font 
         Name            =   "MS Sans Serif"
         Size            =   12
         Charset         =   0
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   375
      Index           =   0
      Left            =   10800
      TabIndex        =   34
      Text            =   "wait for connection"
      Top             =   2040
      Width           =   2295
   End
   Begin VB.CommandButton cmd_UpdateTog 
      BackColor       =   &H00FF80FF&
      Caption         =   "STOP UPDATE REQUESTS (FOR DEVELOPERS)"
      BeginProperty Font 
         Name            =   "Bookman Old Style"
         Size            =   8.25
         Charset         =   0
         Weight          =   600
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   495
      Left            =   120
      MaskColor       =   &H000000FF&
      Style           =   1  'Graphical
      TabIndex        =   27
      Top             =   7080
      UseMaskColor    =   -1  'True
      Width           =   5535
   End
   Begin VB.Timer TimerUpdate 
      Interval        =   8000
      Left            =   9120
      Top             =   120
   End
   Begin VB.CommandButton cmd_Tog 
      BackColor       =   &H80000002&
      Caption         =   "Toggle"
      BeginProperty Font 
         Name            =   "Bookman Old Style"
         Size            =   14.25
         Charset         =   0
         Weight          =   600
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   500
      Index           =   7
      Left            =   5520
      MaskColor       =   &H00FFFFFF&
      Style           =   1  'Graphical
      TabIndex        =   15
      Top             =   6240
      Width           =   1335
   End
   Begin VB.CommandButton cmd_Tog 
      BackColor       =   &H80000002&
      Caption         =   "Toggle"
      BeginProperty Font 
         Name            =   "Bookman Old Style"
         Size            =   14.25
         Charset         =   0
         Weight          =   600
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   495
      Index           =   6
      Left            =   5520
      MaskColor       =   &H00FFFFFF&
      Style           =   1  'Graphical
      TabIndex        =   14
      Top             =   5640
      Width           =   1335
   End
   Begin VB.CommandButton cmd_Tog 
      BackColor       =   &H80000002&
      Caption         =   "Toggle"
      BeginProperty Font 
         Name            =   "Bookman Old Style"
         Size            =   14.25
         Charset         =   0
         Weight          =   600
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   500
      Index           =   5
      Left            =   5520
      MaskColor       =   &H00FFFFFF&
      Style           =   1  'Graphical
      TabIndex        =   13
      Top             =   5040
      Width           =   1335
   End
   Begin VB.CommandButton cmd_Tog 
      BackColor       =   &H80000002&
      Caption         =   "Toggle"
      BeginProperty Font 
         Name            =   "Bookman Old Style"
         Size            =   14.25
         Charset         =   0
         Weight          =   600
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   500
      Index           =   4
      Left            =   5520
      MaskColor       =   &H00FFFFFF&
      Style           =   1  'Graphical
      TabIndex        =   12
      Top             =   4440
      Width           =   1335
   End
   Begin VB.CommandButton cmd_Tog 
      BackColor       =   &H80000002&
      Caption         =   "Toggle"
      BeginProperty Font 
         Name            =   "Bookman Old Style"
         Size            =   14.25
         Charset         =   0
         Weight          =   600
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   500
      Index           =   3
      Left            =   5520
      MaskColor       =   &H00FFFFFF&
      Style           =   1  'Graphical
      TabIndex        =   11
      Top             =   3840
      Width           =   1335
   End
   Begin VB.CommandButton cmd_Tog 
      BackColor       =   &H80000002&
      Caption         =   "Toggle"
      BeginProperty Font 
         Name            =   "Bookman Old Style"
         Size            =   14.25
         Charset         =   0
         Weight          =   600
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   500
      Index           =   2
      Left            =   5520
      MaskColor       =   &H00FFFFFF&
      Style           =   1  'Graphical
      TabIndex        =   10
      Top             =   3240
      Width           =   1335
   End
   Begin VB.CommandButton cmd_Tog 
      BackColor       =   &H80000002&
      Caption         =   "Toggle"
      BeginProperty Font 
         Name            =   "Bookman Old Style"
         Size            =   14.25
         Charset         =   0
         Weight          =   600
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   500
      Index           =   1
      Left            =   5520
      MaskColor       =   &H00FFFFFF&
      Style           =   1  'Graphical
      TabIndex        =   9
      Top             =   2640
      Width           =   1335
   End
   Begin VB.CommandButton cmd_Tog 
      BackColor       =   &H80000002&
      Caption         =   "Toggle"
      BeginProperty Font 
         Name            =   "Bookman Old Style"
         Size            =   14.25
         Charset         =   0
         Weight          =   600
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   495
      Index           =   0
      Left            =   5520
      MaskColor       =   &H00FFFFFF&
      Style           =   1  'Graphical
      TabIndex        =   8
      Top             =   2040
      Width           =   1335
   End
   Begin MSCommLib.MSComm MSComm1 
      Left            =   9720
      Top             =   120
      _ExtentX        =   1005
      _ExtentY        =   1005
      _Version        =   393216
      DTREnable       =   -1  'True
   End
   Begin VB.ListBox Rooms_List 
      BeginProperty Font 
         Name            =   "Bookman Old Style"
         Size            =   17.25
         Charset         =   0
         Weight          =   600
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   5100
      ItemData        =   "SmartHome.frx":0000
      Left            =   240
      List            =   "SmartHome.frx":0034
      TabIndex        =   24
      Top             =   1800
      Width           =   2415
   End
   Begin VB.Label Label5 
      BeginProperty Font 
         Name            =   "MS Sans Serif"
         Size            =   13.5
         Charset         =   0
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   1095
      Left            =   6240
      TabIndex        =   47
      Top             =   7200
      Width           =   6255
   End
   Begin VB.Label Label4 
      Alignment       =   2  'Center
      BackColor       =   &H00FF80FF&
      BorderStyle     =   1  'Fixed Single
      Caption         =   "SERIAL REQUEST"
      BeginProperty Font 
         Name            =   "MS Sans Serif"
         Size            =   12
         Charset         =   0
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   495
      Left            =   3000
      TabIndex        =   46
      Top             =   7680
      Width           =   2655
   End
   Begin VB.Line Line26 
      BorderColor     =   &H8000000D&
      BorderWidth     =   6
      X1              =   3361.754
      X2              =   146.163
      Y1              =   1800
      Y2              =   1800
   End
   Begin VB.Label Label3 
      Alignment       =   2  'Center
      BackColor       =   &H00FF80FF&
      BorderStyle     =   1  'Fixed Single
      Caption         =   "SERIAL RESPONCE"
      BeginProperty Font 
         Name            =   "MS Sans Serif"
         Size            =   12
         Charset         =   0
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   495
      Left            =   120
      TabIndex        =   44
      Top             =   7680
      Width           =   2655
   End
   Begin VB.Line Line22 
      BorderColor     =   &H8000000D&
      BorderWidth     =   6
      X1              =   3361.754
      X2              =   146.163
      Y1              =   6960
      Y2              =   6960
   End
   Begin VB.Line Line24 
      BorderColor     =   &H8000000D&
      BorderWidth     =   6
      X1              =   146.163
      X2              =   146.163
      Y1              =   1200
      Y2              =   6960
   End
   Begin VB.Line Line23 
      BorderColor     =   &H8000000D&
      BorderWidth     =   6
      X1              =   3361.754
      X2              =   3361.754
      Y1              =   1200
      Y2              =   6960
   End
   Begin VB.Line Line18 
      BorderColor     =   &H8000000D&
      BorderWidth     =   6
      X1              =   16224.12
      X2              =   3654.08
      Y1              =   1200
      Y2              =   1200
   End
   Begin VB.Line Line25 
      BorderColor     =   &H8000000D&
      BorderWidth     =   6
      X1              =   3361.754
      X2              =   146.163
      Y1              =   1200
      Y2              =   1200
   End
   Begin VB.Label Label2 
      Alignment       =   2  'Center
      BorderStyle     =   1  'Fixed Single
      Caption         =   "ROOMS"
      BeginProperty Font 
         Name            =   "MS UI Gothic"
         Size            =   18
         Charset         =   0
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      ForeColor       =   &H80000007&
      Height          =   375
      Left            =   240
      TabIndex        =   43
      Top             =   1320
      Width           =   2415
   End
   Begin VB.Line Line21 
      BorderWidth     =   7
      X1              =   9792.935
      X2              =   3800.243
      Y1              =   1920
      Y2              =   1920
   End
   Begin VB.Line Line12 
      BorderWidth     =   7
      X1              =   16077.95
      X2              =   10085.26
      Y1              =   1920
      Y2              =   1920
   End
   Begin VB.Line Line1 
      BorderColor     =   &H8000000D&
      BorderWidth     =   6
      X1              =   9939.098
      X2              =   9939.098
      Y1              =   1800
      Y2              =   6960
   End
   Begin VB.Line Line20 
      BorderColor     =   &H8000000D&
      BorderWidth     =   6
      X1              =   16224.12
      X2              =   3654.08
      Y1              =   1800
      Y2              =   1800
   End
   Begin VB.Line Line19 
      BorderWidth     =   7
      X1              =   9792.935
      X2              =   3800.243
      Y1              =   6840
      Y2              =   6840
   End
   Begin VB.Line Line17 
      BorderWidth     =   7
      X1              =   9792.935
      X2              =   9792.935
      Y1              =   1920
      Y2              =   6840
   End
   Begin VB.Line Line16 
      BorderWidth     =   7
      X1              =   3800.243
      X2              =   3800.243
      Y1              =   1920
      Y2              =   6840
   End
   Begin VB.Line Line15 
      BorderWidth     =   7
      X1              =   16077.95
      X2              =   16077.95
      Y1              =   1920
      Y2              =   4320
   End
   Begin VB.Line Line14 
      BorderWidth     =   7
      X1              =   16077.95
      X2              =   10085.26
      Y1              =   4320
      Y2              =   4320
   End
   Begin VB.Line Line13 
      BorderWidth     =   7
      X1              =   10085.26
      X2              =   10085.26
      Y1              =   1920
      Y2              =   4320
   End
   Begin VB.Line Line11 
      BorderWidth     =   7
      X1              =   16077.95
      X2              =   16077.95
      Y1              =   4560
      Y2              =   6840
   End
   Begin VB.Line Line10 
      BorderWidth     =   7
      X1              =   10085.26
      X2              =   10085.26
      Y1              =   4560
      Y2              =   6840
   End
   Begin VB.Line Line9 
      BorderWidth     =   7
      X1              =   16077.95
      X2              =   10085.26
      Y1              =   6840
      Y2              =   6840
   End
   Begin VB.Line Line8 
      BorderWidth     =   7
      X1              =   16077.95
      X2              =   10085.26
      Y1              =   4560
      Y2              =   4560
   End
   Begin VB.Line Line7 
      BorderWidth     =   7
      X1              =   13008.52
      X2              =   13008.52
      Y1              =   4560
      Y2              =   6840
   End
   Begin VB.Line Line6 
      BorderWidth     =   7
      X1              =   13154.69
      X2              =   13154.69
      Y1              =   4560
      Y2              =   6840
   End
   Begin VB.Line Line3 
      BorderColor     =   &H8000000D&
      BorderWidth     =   6
      X1              =   16224.12
      X2              =   16224.12
      Y1              =   1200
      Y2              =   6960
   End
   Begin VB.Line Line2 
      BorderColor     =   &H8000000D&
      BorderWidth     =   6
      X1              =   9939.098
      X2              =   16224.12
      Y1              =   4440
      Y2              =   4440
   End
   Begin VB.Line Line5 
      BorderColor     =   &H8000000D&
      BorderWidth     =   6
      X1              =   16224.12
      X2              =   3654.08
      Y1              =   6960
      Y2              =   6960
   End
   Begin VB.Line Line4 
      BorderColor     =   &H8000000D&
      BorderWidth     =   6
      X1              =   3654.08
      X2              =   3654.08
      Y1              =   1200
      Y2              =   6960
   End
   Begin VB.Label Label1 
      Alignment       =   2  'Center
      Caption         =   "SERVO_B"
      BeginProperty Font 
         Name            =   "Bookman Old Style"
         Size            =   14.25
         Charset         =   0
         Weight          =   600
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   615
      Index           =   5
      Left            =   10920
      TabIndex        =   33
      Top             =   4680
      Width           =   2175
   End
   Begin VB.Label Label1 
      Alignment       =   2  'Center
      Caption         =   "SERVO_A"
      BeginProperty Font 
         Name            =   "Bookman Old Style"
         Size            =   14.25
         Charset         =   0
         Weight          =   600
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   615
      Index           =   4
      Left            =   8400
      TabIndex        =   32
      Top             =   4680
      Width           =   2175
   End
   Begin VB.Label Label1 
      Alignment       =   2  'Center
      Caption         =   "PIR Sensor"
      BeginProperty Font 
         Name            =   "Bookman Old Style"
         Size            =   14.25
         Charset         =   0
         Weight          =   600
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   375
      Index           =   3
      Left            =   8400
      TabIndex        =   31
      Top             =   3840
      Width           =   2295
   End
   Begin VB.Label Label1 
      Alignment       =   2  'Center
      Caption         =   "GAS Sensor"
      BeginProperty Font 
         Name            =   "Bookman Old Style"
         Size            =   14.25
         Charset         =   0
         Weight          =   600
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   375
      Index           =   2
      Left            =   8400
      TabIndex        =   30
      Top             =   3240
      Width           =   2295
   End
   Begin VB.Label Label1 
      Alignment       =   2  'Center
      Caption         =   "FLAME Sensor"
      BeginProperty Font 
         Name            =   "Bookman Old Style"
         Size            =   14.25
         Charset         =   0
         Weight          =   600
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   375
      Index           =   1
      Left            =   8400
      TabIndex        =   29
      Top             =   2640
      Width           =   2295
   End
   Begin VB.Label Label1 
      Alignment       =   2  'Center
      Caption         =   "Temperature`c"
      BeginProperty Font 
         Name            =   "Bookman Old Style"
         Size            =   14.25
         Charset         =   0
         Weight          =   600
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   375
      Index           =   0
      Left            =   8400
      TabIndex        =   28
      Top             =   2040
      Width           =   2295
   End
   Begin VB.Label ControlTitle 
      Alignment       =   2  'Center
      BorderStyle     =   1  'Fixed Single
      Caption         =   "ROOM_1"
      BeginProperty Font 
         Name            =   "MS UI Gothic"
         Size            =   18
         Charset         =   0
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      ForeColor       =   &H80000007&
      Height          =   375
      Left            =   3060
      TabIndex        =   26
      Top             =   1320
      Width           =   10215
   End
   Begin VB.Label Title 
      Alignment       =   2  'Center
      BorderStyle     =   1  'Fixed Single
      Caption         =   "SMART HOME"
      BeginProperty Font 
         Name            =   "MS UI Gothic"
         Size            =   24
         Charset         =   0
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      ForeColor       =   &H80000007&
      Height          =   495
      Left            =   240
      TabIndex        =   25
      Top             =   240
      Width           =   3855
   End
   Begin VB.Label Ch 
      Caption         =   " CHANNEL_2"
      BeginProperty Font 
         Name            =   "Bookman Old Style"
         Size            =   15.75
         Charset         =   0
         Weight          =   600
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   495
      Index           =   1
      Left            =   3180
      TabIndex        =   23
      Top             =   2640
      Width           =   2130
   End
   Begin VB.Label Ch 
      Caption         =   " CHANNEL_1"
      BeginProperty Font 
         Name            =   "Bookman Old Style"
         Size            =   15.75
         Charset         =   0
         Weight          =   600
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   495
      Index           =   0
      Left            =   3180
      TabIndex        =   22
      Top             =   2040
      Width           =   2130
   End
   Begin VB.Label Ch 
      Caption         =   " CHANNEL_8"
      BeginProperty Font 
         Name            =   "Bookman Old Style"
         Size            =   15.75
         Charset         =   0
         Weight          =   600
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   495
      Index           =   7
      Left            =   3180
      TabIndex        =   21
      Top             =   6240
      Width           =   2130
   End
   Begin VB.Label Ch 
      Caption         =   " CHANNEL_7"
      BeginProperty Font 
         Name            =   "Bookman Old Style"
         Size            =   15.75
         Charset         =   0
         Weight          =   600
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   495
      Index           =   6
      Left            =   3180
      TabIndex        =   20
      Top             =   5640
      Width           =   2130
   End
   Begin VB.Label Ch 
      Caption         =   " CHANNEL_6"
      BeginProperty Font 
         Name            =   "Bookman Old Style"
         Size            =   15.75
         Charset         =   0
         Weight          =   600
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   495
      Index           =   5
      Left            =   3180
      TabIndex        =   19
      Top             =   5040
      Width           =   2130
   End
   Begin VB.Label Ch 
      Caption         =   " CHANNEL_5"
      BeginProperty Font 
         Name            =   "Bookman Old Style"
         Size            =   15.75
         Charset         =   0
         Weight          =   600
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   495
      Index           =   4
      Left            =   3180
      TabIndex        =   18
      Top             =   4440
      Width           =   2130
   End
   Begin VB.Label Ch 
      Caption         =   " CHANNEL_4"
      BeginProperty Font 
         Name            =   "Bookman Old Style"
         Size            =   15.75
         Charset         =   0
         Weight          =   600
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   495
      Index           =   3
      Left            =   3180
      TabIndex        =   17
      Top             =   3840
      Width           =   2130
   End
   Begin VB.Label Ch 
      Caption         =   " CHANNEL_3"
      BeginProperty Font 
         Name            =   "Bookman Old Style"
         Size            =   15.75
         Charset         =   0
         Weight          =   600
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   495
      Index           =   2
      Left            =   3180
      TabIndex        =   16
      Top             =   3240
      Width           =   2130
   End
   Begin VB.Label State_Label 
      Alignment       =   2  'Center
      BackColor       =   &H8000000D&
      Caption         =   "WAIT"
      BeginProperty Font 
         Name            =   "Bookman Old Style"
         Size            =   15.75
         Charset         =   0
         Weight          =   600
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   495
      Index           =   7
      Left            =   7080
      TabIndex        =   7
      Top             =   6240
      Width           =   855
   End
   Begin VB.Label State_Label 
      Alignment       =   2  'Center
      BackColor       =   &H8000000D&
      Caption         =   "WAIT"
      BeginProperty Font 
         Name            =   "Bookman Old Style"
         Size            =   15.75
         Charset         =   0
         Weight          =   600
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   495
      Index           =   6
      Left            =   7080
      TabIndex        =   6
      Top             =   5640
      Width           =   855
   End
   Begin VB.Label State_Label 
      Alignment       =   2  'Center
      BackColor       =   &H8000000D&
      Caption         =   "WAIT"
      BeginProperty Font 
         Name            =   "Bookman Old Style"
         Size            =   15.75
         Charset         =   0
         Weight          =   600
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   495
      Index           =   5
      Left            =   7080
      TabIndex        =   5
      Top             =   5040
      Width           =   855
   End
   Begin VB.Label State_Label 
      Alignment       =   2  'Center
      BackColor       =   &H8000000D&
      Caption         =   "WAIT"
      BeginProperty Font 
         Name            =   "Bookman Old Style"
         Size            =   15.75
         Charset         =   0
         Weight          =   600
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   495
      Index           =   4
      Left            =   7080
      TabIndex        =   4
      Top             =   4440
      Width           =   855
   End
   Begin VB.Label State_Label 
      Alignment       =   2  'Center
      BackColor       =   &H8000000D&
      Caption         =   "WAIT"
      BeginProperty Font 
         Name            =   "Bookman Old Style"
         Size            =   15.75
         Charset         =   0
         Weight          =   600
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   495
      Index           =   3
      Left            =   7080
      TabIndex        =   3
      Top             =   3840
      Width           =   855
   End
   Begin VB.Label State_Label 
      Alignment       =   2  'Center
      BackColor       =   &H8000000D&
      Caption         =   "WAIT"
      BeginProperty Font 
         Name            =   "Bookman Old Style"
         Size            =   15.75
         Charset         =   0
         Weight          =   600
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   495
      Index           =   2
      Left            =   7080
      TabIndex        =   2
      Top             =   3240
      Width           =   855
   End
   Begin VB.Label State_Label 
      Alignment       =   2  'Center
      BackColor       =   &H8000000D&
      Caption         =   "WAIT"
      BeginProperty Font 
         Name            =   "Bookman Old Style"
         Size            =   15.75
         Charset         =   0
         Weight          =   600
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   495
      Index           =   1
      Left            =   7080
      TabIndex        =   1
      Top             =   2640
      Width           =   855
   End
   Begin VB.Label State_Label 
      Alignment       =   2  'Center
      BackColor       =   &H8000000D&
      Caption         =   "WAIT"
      BeginProperty Font 
         Name            =   "Bookman Old Style"
         Size            =   15.75
         Charset         =   0
         Weight          =   600
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   495
      Index           =   0
      Left            =   7080
      TabIndex        =   0
      Top             =   2040
      Width           =   855
   End
End
Attribute VB_Name = "Form1"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Public room_num As Integer
Public ServosUpdateFlag As Integer
Private Function Format_Rooms(num As Integer) As String
    Format_Rooms = Format$(num, "00")
End Function

Private Function Format_Angels(angel As Integer) As String
    If (angel < 0) Then
        angel = 100 + angel * -1
    End If
    Format_Angels = Format$(angel, "000")
End Function

Private Sub AddLogLine(msg As String)
    
    comList.AddItem msg, 0
    
    If comList.ListCount > 50 Then
        comList.RemoveItem comList.ListCount - 1
    End If
End Sub


Private Sub ChStateHandler(ChState As String)
    For i = 0 To 7
        bitValue = Mid$(ChState, Len(ChState) - i, 1)
        If bitValue = "0" Then
            State_Label(i).BackColor = &HFF&
            State_Label(i).Caption = "OFF"
        ElseIf bitValue = "1" Then
            State_Label(i).BackColor = &HFF00&
            State_Label(i).Caption = "ON"
        End If
    Next i
End Sub

Private Sub SensorsHandler(SensState As String)
        Sensors_Text(0).Text = Mid$(SensState, 1, 2) & " `C"
        If Mid$(SensState, 3, 1) = 1 Then
            Sensors_Text(1).Text = "FIRE HERE"
            Sensors_Text(1).BackColor = vbRed
        ElseIf Mid$(SensState, 3, 1) = 0 Then
            Sensors_Text(1).Text = "GOOD"
            Sensors_Text(1).BackColor = vbGreen
        End If
        If Mid$(SensState, 4, 1) = 1 Then
            Sensors_Text(2).Text = "GAS HERE"
            Sensors_Text(2).BackColor = vbRed
            
        ElseIf Mid$(SensState, 4, 1) = 0 Then
            Sensors_Text(2).Text = "GOOD"
            Sensors_Text(2).BackColor = vbGreen
        End If
        If Mid$(SensState, 5, 1) = 1 Then
            Sensors_Text(3).Text = "PERSONS HERE"
            Sensors_Text(3).BackColor = vbRed
        ElseIf Mid$(SensState, 5, 1) = 0 Then
            Sensors_Text(3).Text = "GOOD"
            Sensors_Text(3).BackColor = vbGreen
        End If
End Sub

Private Sub ServosHandler(ServosState As String)
    If (ServosUpdateFlag = 1) Then
        Dim A_Sign, B_Sign As Integer
        
        If Val(Mid$(ServosState, 1, 1)) = 0 Then
            A_Sign = 1
        ElseIf Val(Mid$(ServosState, 1, 1)) = 1 Then
            A_Sign = -1
        End If
        
        If Val(Mid$(ServosState, 4, 1)) = 0 Then
            B_Sign = 1
        ElseIf Val(Mid$(ServosState, 4, 1)) = 1 Then
            B_Sign = -1
        End If
        
        Servo_Text(0).Text = Val(Mid$(ServosState, 2, 2)) * A_Sign
        Servo_Text(1).Text = Val(Mid$(ServosState, 5, 2)) * B_Sign
    End If
End Sub

Private Sub cmd_Ser_Click(Index As Integer)
    Dim angel_String As String
    Dim angel_Integer As Integer
    angel_Integer = Val(Servo_Text(Index).Text)
    angel_String = Format_Angels(angel_Integer)
    UARTWriteList.AddItem "SER" & Format_Rooms(room_num) & Index & angel_String, 0
    MSComm1.Output = "SER" & Format_Rooms(room_num) & Index & angel_String & vbCrLf
    ServosUpdateFlag = 1
    TimerSensors_Timer
    TimerUpdate_Timer
End Sub




Private Sub cmdEME_Click()
    MSComm1.Output = "BUZ" & Format_Rooms(room_num) & vbCrLf
    UARTWriteList.AddItem "BUZ" & Format_Rooms(room_num), 0
End Sub

Private Sub Form_Load()
    Label5.Caption = "Made By MOHAMED ABDELHAMID AHMED" & vbCrLf & "Email :trapcloud8@gmail.com" & vbCrLf & "Linkedin :mohamedabdelhamid2005"
    MSComm1.CommPort = 7
    MSComm1.Settings = "9600,n,8,1"
    MSComm1.InputLen = 24
    MSComm1.RThreshold = 24
    MSComm1.PortOpen = True
    room_num = 1
    ServosUpdateFlag = 1
End Sub


Private Sub Rooms_List_Click()
    room_num = (Rooms_List.ListIndex + 1)
    ControlTitle.Caption = "ROOM_" & room_num
    ServosUpdateFlag = 1
    TimerSensors_Timer
    TimerUpdate_Timer
End Sub

Private Sub cmd_Tog_Click(Ch_Num As Integer)
    MSComm1.Output = "TOG" & Format_Rooms(room_num) & (Ch_Num + 1) & vbCrLf
    UARTWriteList.AddItem "TOG" & Format_Rooms(room_num) & (Ch_Num + 1), 0
    TimerSensors_Timer
    TimerUpdate_Timer
End Sub


Private Sub Servo_Text_Change(Index As Integer)
    ServosUpdateFlag = 0
End Sub

Private Sub TimerSensors_Timer()
    MSComm1.Output = "SEN" & Format_Rooms(room_num) & vbCrLf
    UARTWriteList.AddItem "SEN" & Format_Rooms(room_num), 0
End Sub

Private Sub TimerUpdate_Timer()
    MSComm1.Output = "UPT" & Format_Rooms(room_num) & vbCrLf
End Sub


Private Sub MSComm1_OnComm()
    Dim Data, DataStateOnly, DataSensorsOnly, DataServosOnly As String
    If MSComm1.CommEvent = comEvReceive Then
        Data = MSComm1.Input
        OrderOnly = Mid(Data, 1, 3)
        DataStateOnly = Mid(Data, 4, 8)
        DataSensorsOnly = Mid(Data, 12, 5)
        DataServosOnly = Mid(Data, 17, 6)
        UARTReadList.AddItem Data, 0
        If OrderOnly = "RES" Then
            TimerUpdate.Enabled = True
            ChStateHandler (DataStateOnly)
            SensorsHandler (DataSensorsOnly)
            ServosHandler (DataServosOnly)
        End If
    End If
End Sub
