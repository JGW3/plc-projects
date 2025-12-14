void LOGGER_init__(LOGGER *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->TRIG,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->MSG,__STRING_LITERAL(0,""),retain)
  __INIT_VAR(data__->LEVEL,LOGLEVEL__INFO,retain)
  __INIT_VAR(data__->TRIG0,__BOOL_LITERAL(FALSE),retain)
}

// Code part
void LOGGER_body__(LOGGER *data__) {
  // Control execution
  if (!__GET_VAR(data__->EN)) {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(FALSE));
    return;
  }
  else {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(TRUE));
  }
  // Initialise TEMP variables

  if ((__GET_VAR(data__->TRIG,) && !(__GET_VAR(data__->TRIG0,)))) {
    #define GetFbVar(var,...) __GET_VAR(data__->var,__VA_ARGS__)
    #define SetFbVar(var,val,...) __SET_VAR(data__->,var,__VA_ARGS__,val)

   LogMessage(GetFbVar(LEVEL),(char*)GetFbVar(MSG, .body),GetFbVar(MSG, .len));
  
    #undef GetFbVar
    #undef SetFbVar
;
  };
  __SET_VAR(data__->,TRIG0,,__GET_VAR(data__->TRIG,));

  goto __end;

__end:
  return;
} // LOGGER_body__() 





void PROGRAM3_init__(PROGRAM3 *data__, BOOL retain) {
  __INIT_VAR(data__->ET_TON,__time_to_timespec(1, 0, 0, 0, 0, 0),retain)
  TON_init__(&data__->TIMER1_TON,retain);
  __INIT_VAR(data__->PRESET_TIME,__time_to_timespec(1, 1667, 0, 0, 0, 0),retain)
  __INIT_LOCATED(BOOL,__QX0_1,data__->TIMER2_TOF_LED,retain)
  __INIT_LOCATED_VALUE(data__->TIMER2_TOF_LED,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__QX0_0,data__->TIMER1_TON_LED,retain)
  __INIT_LOCATED_VALUE(data__->TIMER1_TON_LED,__BOOL_LITERAL(FALSE))
  TOF_init__(&data__->TIMER2_TOF,retain);
  __INIT_VAR(data__->ET_TOF,__time_to_timespec(1, 0, 0, 0, 0, 0),retain)
  TP_init__(&data__->TIMER3_TP,retain);
  __INIT_VAR(data__->ET_TP,__time_to_timespec(1, 0, 0, 0, 0, 0),retain)
  __INIT_LOCATED(BOOL,__QX0_2,data__->TIMER3_TP_LED,retain)
  __INIT_LOCATED_VALUE(data__->TIMER3_TP_LED,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__IX0_0,data__->BUTTON_IN,retain)
  __INIT_LOCATED_VALUE(data__->BUTTON_IN,__BOOL_LITERAL(FALSE))
}

// Code part
void PROGRAM3_body__(PROGRAM3 *data__) {
  // Initialise TEMP variables

  __SET_VAR(data__->TIMER1_TON.,IN,,__GET_LOCATED(data__->BUTTON_IN,));
  __SET_VAR(data__->TIMER1_TON.,PT,,__GET_VAR(data__->PRESET_TIME,));
  TON_body__(&data__->TIMER1_TON);
  __SET_VAR(data__->,ET_TON,,__GET_VAR(data__->TIMER1_TON.ET,));
  __SET_LOCATED(data__->,TIMER1_TON_LED,,__GET_VAR(data__->TIMER1_TON.Q,));
  __SET_VAR(data__->TIMER2_TOF.,IN,,__GET_LOCATED(data__->BUTTON_IN,));
  __SET_VAR(data__->TIMER2_TOF.,PT,,__GET_VAR(data__->PRESET_TIME,));
  TOF_body__(&data__->TIMER2_TOF);
  __SET_LOCATED(data__->,TIMER2_TOF_LED,,__GET_VAR(data__->TIMER2_TOF.Q,));
  __SET_VAR(data__->,ET_TOF,,__GET_VAR(data__->TIMER2_TOF.ET,));
  __SET_VAR(data__->TIMER3_TP.,IN,,__GET_LOCATED(data__->BUTTON_IN,));
  __SET_VAR(data__->TIMER3_TP.,PT,,__GET_VAR(data__->PRESET_TIME,));
  TP_body__(&data__->TIMER3_TP);
  __SET_VAR(data__->,ET_TP,,__GET_VAR(data__->TIMER3_TP.ET,));
  __SET_LOCATED(data__->,TIMER3_TP_LED,,__GET_VAR(data__->TIMER3_TP.Q,));

  goto __end;

__end:
  return;
} // PROGRAM3_body__() 





