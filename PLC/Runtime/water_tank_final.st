PROGRAM water_tank
  VAR
    Start AT %QX0.2 : BOOL;
    Stop AT %QX0.3 : BOOL;
    High AT %IX0.0 : BOOL;
    Low AT %IX0.1 : BOOL;
    Height AT %IW0 : UINT;
    High_Limit AT %QW0 : UINT;
    Low_Limit AT %QW1 : UINT;
    Master AT %IX0.2 : BOOL;
    Valve_In AT %QX0.0 : BOOL;
    Valve_Out AT %QX0.1 : BOOL;
  END_VAR
  VAR
    _TMP_GE19_ENO : BOOL;
    _TMP_GE19_OUT : BOOL;
    _TMP_GE21_ENO : BOOL;
    _TMP_GE21_OUT : BOOL;
  END_VAR

  Master := NOT(Stop) AND (Master OR Start);
  _TMP_GE19_OUT := GE(EN := Master, IN1 := Height, IN2 := High_Limit, ENO => _TMP_GE19_ENO);
  IF _TMP_GE19_ENO THEN
      High := _TMP_GE19_OUT;
  END_IF;
  _TMP_GE21_OUT := GE(EN := Master, IN1 := Height, IN2 := Low_Limit, ENO => _TMP_GE21_ENO);
  IF _TMP_GE21_ENO THEN
      Low := _TMP_GE21_OUT;
  END_IF;
  Valve_Out := NOT(Low) AND (High OR Valve_Out) AND Master;
  Valve_In := NOT(High) AND (Low OR Start OR Valve_In) AND Master;
END_PROGRAM


CONFIGURATION Config0

  RESOURCE Res0 ON PLC
    TASK task0(INTERVAL := T#20ms,PRIORITY := 0);
    PROGRAM instance0 WITH task0 : water_tank;
  END_RESOURCE
END_CONFIGURATION
