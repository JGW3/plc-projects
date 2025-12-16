TYPE
  LOGLEVEL : (CRITICAL, WARNING, INFO, DEBUG) := INFO;
END_TYPE

FUNCTION_BLOCK LOGGER
  VAR_INPUT
    TRIG : BOOL;
    MSG : STRING;
    LEVEL : LOGLEVEL := INFO;
  END_VAR
  VAR
    TRIG0 : BOOL;
  END_VAR

  IF TRIG AND NOT TRIG0 THEN
  {{
   LogMessage(GetFbVar(LEVEL),(char*)GetFbVar(MSG, .body),GetFbVar(MSG, .len));
  }}
  END_IF;
  TRIG0:=TRIG;
END_FUNCTION_BLOCK


PROGRAM program4
  VAR
    Reset_Btn AT %IX0.1 : BOOL;
    Count_Btn AT %IX0.0 : BOOL;
    LED AT %QX0.0 : BOOL;
  END_VAR
  VAR
    Counter1 : CTU;
    Count_Edge : R_TRIG;
  END_VAR
  VAR CONSTANT
    Preset : INT := 5;
  END_VAR
  VAR
    R_TRIG1 : R_TRIG;
  END_VAR

  Count_Edge(CLK := Count_Btn);
  R_TRIG1(CLK := Count_Edge.Q);
  Counter1(CU := R_TRIG1.Q, R := Reset_Btn, PV := Preset);
  LED := Counter1.Q;
END_PROGRAM


CONFIGURATION Config0

  RESOURCE Res0 ON PLC
    TASK task0(INTERVAL := T#20ms,PRIORITY := 0);
    PROGRAM instance0 WITH task0 : program4;
  END_RESOURCE
END_CONFIGURATION
