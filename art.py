def art(m, n):
    """
    question of code jam qualifier 2022
    >>>art(2,3)
    ..+-+-+
    ..|.|.|
    +-+-+-+
    |.|.|.|
    +-+-+-+
    
    >>>art(3,4)
    ..+-+-+-+
    ..|.|.|.|
    +-+-+-+-+
    |.|.|.|.|
    +-+-+-+-+
    |.|.|.|.|
    +-+-+-+-+
    """
    for k in range(1,2*n+2):
        if k==1 or k==2:
            print('.', end='')
        elif k%2==1:
            print('+', end='')
        else:
            print('-', end='') #print first line
        
    print()                    #line separator
    
    for k in range(1,2*n+2):
        if k==1 or k==2:
            print('.', end='')
        elif k%2==1:
            print('|', end='')
        else:
            print('.', end='') #print second line
            
    print()                    #line separator
    
    #remaining lines
    
    for i in range(3,2*m+2):
        if i%2==1:
            for j in range(1,2*n+2):
                if j%2==1:
                    print('+', end='')
                else:
                    print('-', end='')
            print()
        else:
            for j in range(1,2*n+2):
                if j%2==1:
                    print('|', end='')
                else:
                    print('.', end='')
            print()
            