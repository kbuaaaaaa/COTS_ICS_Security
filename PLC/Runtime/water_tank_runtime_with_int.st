PROGRAM water_tank
  VAR
    Start AT %IX0.0 : BOOL := 0;
    Stop AT %IX0.1 : BOOL := 1;
    High AT %IX0.2 : BOOL;
    Low AT %IX0.3 : BOOL;
    Height AT %IW0 : UINT;
    High_Limit AT %IW1 : UINT;
    Low_Limit AT %IW2 : UINT;
    Master AT %IX0.4 : BOOL;
    Valve_In AT %QX0.0 : BOOL;
    Valve_Out AT %QX0.1 : BOOL;
  END_VAR
  VAR
    _TMP_GE19_OUT : BOOL;
    _TMP_GE23_OUT : BOOL;
  END_VAR

  _TMP_GE19_OUT := GE(Height, High_Limit);
  High := _TMP_GE19_OUT;
  _TMP_GE23_OUT := GE(Height, Low_Limit);
  Low := _TMP_GE23_OUT;
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
