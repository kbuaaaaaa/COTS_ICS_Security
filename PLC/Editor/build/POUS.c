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





void PYTHON_EVAL_init__(PYTHON_EVAL *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->TRIG,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->CODE,__STRING_LITERAL(0,""),retain)
  __INIT_VAR(data__->ACK,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->RESULT,__STRING_LITERAL(0,""),retain)
  __INIT_VAR(data__->STATE,0,retain)
  __INIT_VAR(data__->BUFFER,__STRING_LITERAL(0,""),retain)
  __INIT_VAR(data__->PREBUFFER,__STRING_LITERAL(0,""),retain)
  __INIT_VAR(data__->TRIGM1,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->TRIGGED,__BOOL_LITERAL(FALSE),retain)
}

// Code part
void PYTHON_EVAL_body__(PYTHON_EVAL *data__) {
  // Control execution
  if (!__GET_VAR(data__->EN)) {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(FALSE));
    return;
  }
  else {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(TRUE));
  }
  // Initialise TEMP variables

  __IL_DEFVAR_T __IL_DEFVAR;
  __IL_DEFVAR_T __IL_DEFVAR_BACK;
  #define GetFbVar(var,...) __GET_VAR(data__->var,__VA_ARGS__)
  #define SetFbVar(var,val,...) __SET_VAR(data__->,var,__VA_ARGS__,val)
extern void __PythonEvalFB(int, PYTHON_EVAL*);__PythonEvalFB(0, data__);
  #undef GetFbVar
  #undef SetFbVar
;

  goto __end;

__end:
  return;
} // PYTHON_EVAL_body__() 





void PYTHON_POLL_init__(PYTHON_POLL *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->TRIG,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->CODE,__STRING_LITERAL(0,""),retain)
  __INIT_VAR(data__->ACK,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->RESULT,__STRING_LITERAL(0,""),retain)
  __INIT_VAR(data__->STATE,0,retain)
  __INIT_VAR(data__->BUFFER,__STRING_LITERAL(0,""),retain)
  __INIT_VAR(data__->PREBUFFER,__STRING_LITERAL(0,""),retain)
  __INIT_VAR(data__->TRIGM1,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->TRIGGED,__BOOL_LITERAL(FALSE),retain)
}

// Code part
void PYTHON_POLL_body__(PYTHON_POLL *data__) {
  // Control execution
  if (!__GET_VAR(data__->EN)) {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(FALSE));
    return;
  }
  else {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(TRUE));
  }
  // Initialise TEMP variables

  __IL_DEFVAR_T __IL_DEFVAR;
  __IL_DEFVAR_T __IL_DEFVAR_BACK;
  #define GetFbVar(var,...) __GET_VAR(data__->var,__VA_ARGS__)
  #define SetFbVar(var,val,...) __SET_VAR(data__->,var,__VA_ARGS__,val)
extern void __PythonEvalFB(int, PYTHON_EVAL*);__PythonEvalFB(1,(PYTHON_EVAL*)(void*)data__);
  #undef GetFbVar
  #undef SetFbVar
;

  goto __end;

__end:
  return;
} // PYTHON_POLL_body__() 





void PYTHON_GEAR_init__(PYTHON_GEAR *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->N,0,retain)
  __INIT_VAR(data__->TRIG,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->CODE,__STRING_LITERAL(0,""),retain)
  __INIT_VAR(data__->ACK,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->RESULT,__STRING_LITERAL(0,""),retain)
  PYTHON_EVAL_init__(&data__->PY_EVAL,retain);
  __INIT_VAR(data__->COUNTER,0,retain)
  __INIT_VAR(data__->_TMP_ADD10_OUT,0,retain)
  __INIT_VAR(data__->_TMP_EQ13_OUT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_TMP_SEL15_OUT,0,retain)
  __INIT_VAR(data__->_TMP_AND7_OUT,__BOOL_LITERAL(FALSE),retain)
}

// Code part
void PYTHON_GEAR_body__(PYTHON_GEAR *data__) {
  // Control execution
  if (!__GET_VAR(data__->EN)) {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(FALSE));
    return;
  }
  else {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(TRUE));
  }
  // Initialise TEMP variables

  __SET_VAR(data__->,_TMP_ADD10_OUT,,ADD__UINT__UINT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)2,
    (UINT)__GET_VAR(data__->COUNTER,),
    (UINT)1));
  __SET_VAR(data__->,_TMP_EQ13_OUT,,EQ__BOOL__UINT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)2,
    (UINT)__GET_VAR(data__->N,),
    (UINT)__GET_VAR(data__->_TMP_ADD10_OUT,)));
  __SET_VAR(data__->,_TMP_SEL15_OUT,,SEL__UINT__BOOL__UINT__UINT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (BOOL)__GET_VAR(data__->_TMP_EQ13_OUT,),
    (UINT)__GET_VAR(data__->_TMP_ADD10_OUT,),
    (UINT)0));
  __SET_VAR(data__->,COUNTER,,__GET_VAR(data__->_TMP_SEL15_OUT,));
  __SET_VAR(data__->,_TMP_AND7_OUT,,AND__BOOL__BOOL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)2,
    (BOOL)__GET_VAR(data__->_TMP_EQ13_OUT,),
    (BOOL)__GET_VAR(data__->TRIG,)));
  __SET_VAR(data__->PY_EVAL.,TRIG,,__GET_VAR(data__->_TMP_AND7_OUT,));
  __SET_VAR(data__->PY_EVAL.,CODE,,__GET_VAR(data__->CODE,));
  PYTHON_EVAL_body__(&data__->PY_EVAL);
  __SET_VAR(data__->,ACK,,__GET_VAR(data__->PY_EVAL.ACK,));
  __SET_VAR(data__->,RESULT,,__GET_VAR(data__->PY_EVAL.RESULT,));

  goto __end;

__end:
  return;
} // PYTHON_GEAR_body__() 





static inline BOOL __WATER_TANK_GE__BOOL__UINT1(BOOL EN,
  UINT __PARAM_COUNT,
  UINT IN1,
  UINT IN2,
  WATER_TANK *data__)
{
  BOOL __res;
  BOOL __TMP_ENO = __GET_VAR(data__->_TMP_GE19_ENO,);
  __res = GE__BOOL__UINT(EN,
    &__TMP_ENO,
    __PARAM_COUNT,
    IN1,
    IN2);
  __SET_VAR(,data__->_TMP_GE19_ENO,,__TMP_ENO);
  return __res;
}

static inline BOOL __WATER_TANK_GE__BOOL__UINT2(BOOL EN,
  UINT __PARAM_COUNT,
  UINT IN1,
  UINT IN2,
  WATER_TANK *data__)
{
  BOOL __res;
  BOOL __TMP_ENO = __GET_VAR(data__->_TMP_GE21_ENO,);
  __res = GE__BOOL__UINT(EN,
    &__TMP_ENO,
    __PARAM_COUNT,
    IN1,
    IN2);
  __SET_VAR(,data__->_TMP_GE21_ENO,,__TMP_ENO);
  return __res;
}

void WATER_TANK_init__(WATER_TANK *data__, BOOL retain) {
  __INIT_VAR(data__->VALVE_IN,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->VALVE_OUT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->START,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->STOP,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->HIGH,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->LOW,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->MASTER,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->HEIGHT,0,retain)
  __INIT_VAR(data__->HIGH_LIMIT,0,retain)
  __INIT_VAR(data__->LOW_LIMIT,0,retain)
  __INIT_VAR(data__->_TMP_GE19_ENO,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_TMP_GE19_OUT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_TMP_GE21_ENO,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_TMP_GE21_OUT,__BOOL_LITERAL(FALSE),retain)
}

// Code part
void WATER_TANK_body__(WATER_TANK *data__) {
  // Initialise TEMP variables

  __SET_VAR(data__->,MASTER,,(!(__GET_VAR(data__->STOP,)) && (__GET_VAR(data__->MASTER,) || __GET_VAR(data__->START,))));
  __SET_VAR(data__->,_TMP_GE19_OUT,,__WATER_TANK_GE__BOOL__UINT1(
    (BOOL)__GET_VAR(data__->MASTER,),
    (UINT)2,
    (UINT)__GET_VAR(data__->HEIGHT,),
    (UINT)__GET_VAR(data__->HIGH_LIMIT,),
    data__));
  if (__GET_VAR(data__->_TMP_GE19_ENO,)) {
    __SET_VAR(data__->,HIGH,,__GET_VAR(data__->_TMP_GE19_OUT,));
  };
  __SET_VAR(data__->,_TMP_GE21_OUT,,__WATER_TANK_GE__BOOL__UINT2(
    (BOOL)__GET_VAR(data__->MASTER,),
    (UINT)2,
    (UINT)__GET_VAR(data__->HEIGHT,),
    (UINT)__GET_VAR(data__->LOW_LIMIT,),
    data__));
  if (__GET_VAR(data__->_TMP_GE21_ENO,)) {
    __SET_VAR(data__->,LOW,,__GET_VAR(data__->_TMP_GE21_OUT,));
  };
  __SET_VAR(data__->,VALVE_OUT,,((!(__GET_VAR(data__->LOW,)) && (__GET_VAR(data__->HIGH,) || __GET_VAR(data__->VALVE_OUT,))) && __GET_VAR(data__->MASTER,)));
  __SET_VAR(data__->,VALVE_IN,,((!(__GET_VAR(data__->HIGH,)) && ((__GET_VAR(data__->LOW,) || __GET_VAR(data__->START,)) || __GET_VAR(data__->VALVE_IN,))) && __GET_VAR(data__->MASTER,)));

  goto __end;

__end:
  return;
} // WATER_TANK_body__() 





