def printing3d(A):
    """
    Code jam 2022 qualifier problem
    for given avalability of four colors (a list of four numbers) for three printers,
    this function returns a color(a list of four numbers) whch is avalable from each three printers and whose sum is 10^6,
    if no color is possible from given color avalability, then returns 'impossible'
    
    input should be a list of three lists each containing four numbers less than or equal to 10^6
    
    >>>A=[
        [768763, 148041, 178147, 984173],
        [699508, 515362, 534729, 714381],
        [949704, 625054, 946212, 951187]
    ]
    printing3d(A)
    
    [699508, 148041, 152451, 0] #output
    """
    color1 = min([A[i][0] for i in range(3)])
    if color1 == 1000000:
        return [color1, 0, 0, 0]
    color2 = min([A[i][1] for i in range(3)])
    if (color1 + color2) >= 1000000:
        return [color1, (1000000-color1), 0, 0]
    color3 = min([A[i][2] for i in range(3)])
    if (color1 + color2 + color3) >= 1000000:
        return [color1, color2, (1000000-(color1+color2)), 0]
    color4 = min([A[i][3] for i in range(3)])
    if (color1 + color2 + color3 + color4) >= 1000000:
        return [color1, color2, color3, (1000000-(color1+color2+color3))]
    else:
        return 'impossible'