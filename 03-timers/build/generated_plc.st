PROGRAM program3
  VAR
    ET_TON : TIME;
    Timer1_TON : TON;
    Preset_Time : TIME := T#1667ms;
  END_VAR
  VAR
    Timer2_TOF_LED AT %QX0.1 : BOOL;
    Timer1_TON_LED AT %QX0.0 : BOOL;
  END_VAR
  VAR
    Timer2_TOF : TOF;
    ET_TOF : TIME;
    Timer3_TP : TP;
    ET_TP : TIME;
  END_VAR
  VAR
    Timer3_TP_LED AT %QX0.2 : BOOL;
    Button_In AT %IX0.0 : BOOL;
  END_VAR

  Timer1_TON(IN := Button_In, PT := Preset_Time);
  ET_TON := Timer1_TON.ET;
  Timer1_TON_LED := Timer1_TON.Q;
  Timer2_TOF(IN := Button_In, PT := Preset_Time);
  Timer2_TOF_LED := Timer2_TOF.Q;
  ET_TOF := Timer2_TOF.ET;
  Timer3_TP(IN := Button_In, PT := Preset_Time);
  ET_TP := Timer3_TP.ET;
  Timer3_TP_LED := Timer3_TP.Q;
END_PROGRAM


CONFIGURATION Config0

  RESOURCE Res0 ON PLC
    TASK task0(INTERVAL := T#20ms,PRIORITY := 0);
    PROGRAM instance0 WITH task0 : program3;
  END_RESOURCE
END_CONFIGURATION
