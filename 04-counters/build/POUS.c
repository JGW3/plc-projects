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





void PROGRAM4_init__(PROGRAM4 *data__, BOOL retain) {
  __INIT_LOCATED(BOOL,__IX0_1,data__->RESET_BTN,retain)
  __INIT_LOCATED_VALUE(data__->RESET_BTN,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__IX0_0,data__->COUNT_BTN,retain)
  __INIT_LOCATED_VALUE(data__->COUNT_BTN,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__QX0_0,data__->LED,retain)
  __INIT_LOCATED_VALUE(data__->LED,__BOOL_LITERAL(FALSE))
  CTU_init__(&data__->COUNTER1,retain);
  R_TRIG_init__(&data__->COUNT_EDGE,retain);
  __INIT_VAR(data__->PRESET,5,retain)
  R_TRIG_init__(&data__->R_TRIG1,retain);
}

// Code part
void PROGRAM4_body__(PROGRAM4 *data__) {
  // Initialise TEMP variables

  __SET_VAR(data__->COUNT_EDGE.,CLK,,__GET_LOCATED(data__->COUNT_BTN,));
  R_TRIG_body__(&data__->COUNT_EDGE);
  __SET_VAR(data__->R_TRIG1.,CLK,,__GET_VAR(data__->COUNT_EDGE.Q,));
  R_TRIG_body__(&data__->R_TRIG1);
  __SET_VAR(data__->COUNTER1.,CU,,__GET_VAR(data__->R_TRIG1.Q,));
  __SET_VAR(data__->COUNTER1.,R,,__GET_LOCATED(data__->RESET_BTN,));
  __SET_VAR(data__->COUNTER1.,PV,,__GET_VAR(data__->PRESET,));
  CTU_body__(&data__->COUNTER1);
  __SET_LOCATED(data__->,LED,,__GET_VAR(data__->COUNTER1.Q,));

  goto __end;

__end:
  return;
} // PROGRAM4_body__() 





