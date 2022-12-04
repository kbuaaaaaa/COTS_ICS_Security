Case 1 : Valve In Open, Valve Out Close
    Condition :
        - Height <= Minimum Level
        or
        - Minimum Level <= Height <= Maximum Height
        - Valve In Open
    Output :
        - Tank Volume += Flow
        - Height = Tank Volume/Area

Case 2 : Valve In Close, Valve Out Open
    Condition :
        - Height >= Maximum Level
        or
        - Minimum Level <= Height <= Maximum Height
        - Valve Out Open
    Output :
        - Tank Volume -s= Flow
        - Height = Tank Volume/Area
