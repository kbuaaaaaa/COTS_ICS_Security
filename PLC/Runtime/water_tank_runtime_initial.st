PROGRAM water_tank
  VAR
    High AT %IX0.0 : BOOL;
    Low AT %IX0.1 : BOOL;
    Start AT %IX0.2 : BOOL := TRUE;
    Stop AT %IX0.3 : BOOL := FALSE;
  END_VAR
  VAR
    Master : BOOL;
  END_VAR
  VAR
    Valve_In AT %QX0.0 : BOOL;
    Valve_Out AT %QX0.1 : BOOL;
  END_VAR

  Master := NOT(Stop) AND (Master OR Start);
  Valve_Out := Low AND (High OR Valve_Out) AND Master;
  Valve_In := NOT(High) AND (NOT(Low) OR Start OR Valve_In) AND Master;
END_PROGRAM


CONFIGURATION Config0

  RESOURCE Res0 ON PLC
    TASK task0(INTERVAL := T#20ms,PRIORITY := 0);
    PROGRAM instance0 WITH task0 : water_tank;
  END_RESOURCE
END_CONFIGURATION
