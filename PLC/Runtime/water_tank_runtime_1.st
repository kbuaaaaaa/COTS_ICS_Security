PROGRAM water_tank
  VAR_INPUT
    High : BOOL;
    Low : BOOL;
  END_VAR
  VAR_OUTPUT
    Valve_In : BOOL;
    Valve_Out : BOOL;
  END_VAR
  VAR_INPUT
    Start : BOOL;
    Stop : BOOL;
  END_VAR
  VAR
    Master : BOOL;
  END_VAR

  Master := NOT(Stop) AND (Master OR Start);
  Valve_Out := NOT(Low) AND (High OR Valve_Out) AND Master;
  Valve_In := NOT(High) AND (Low OR Start OR Valve_In) AND Master;
END_PROGRAM


CONFIGURATION Config0

  RESOURCE Res0 ON PLC
    TASK task0(INTERVAL := T#20ms,PRIORITY := 0);
    PROGRAM instance0 WITH task0 : water_tank;
  END_RESOURCE
END_CONFIGURATION
