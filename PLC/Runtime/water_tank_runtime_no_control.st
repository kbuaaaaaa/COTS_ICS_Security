PROGRAM water_tank
  VAR
    High AT %IX0.0 : BOOL;
    Low AT %IX0.1 : BOOL;
    Valve_In AT %QX0.0 : BOOL;
    Valve_Out AT %QX0.1 : BOOL;
  END_VAR

  Valve_Out := Low AND (High OR Valve_Out);
  Valve_In := NOT(High) AND (NOT(Low) OR Valve_In);
END_PROGRAM


CONFIGURATION Config0

  RESOURCE Res0 ON PLC
    TASK task0(INTERVAL := T#20ms,PRIORITY := 0);
    PROGRAM instance0 WITH task0 : water_tank;
  END_RESOURCE
END_CONFIGURATION
