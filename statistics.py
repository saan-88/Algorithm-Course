#-----------------
#    This program reads information about all the matches given as Input and compile the following statistics for each player:
#
#    1. Number of best-of-5 set matches won
#    2. Number of best-of-3 set matches won
#    3. Number of sets won
#    4. Number of games won
#    5. Number of sets lost
#    6. Number of games lost
#
#    It prints  a summary in decreasing order of ranking, where the ranking is according to the criteria 1-6 in that order

# An Example:

#   input:

#   Zverev:Medvedev:2-6,6-7,7-6,6-3,6-1
#   Barty:Osaka:6-4,6-4
#   Medvedev:Zverev:6-3,6-3
#   Osaka:Barty:1-6,7-5,6-2
#   Zverev:Medvedev:6-0,7-6,6-3
#   Osaka:Barty:2-6,6-2,6-0
#   Medvedev:Zverev:6-3,4-6,6-3,6-4
#   Barty:Osaka:6-1,3-6,7-5
#   Zverev:Medvedev:7-6,4-6,7-6,2-6,6-2
#   Osaka:Barty:6-4,1-6,6-3
#   Medvedev:Zverev:7-5,7-5
#   Osaka:Barty:3-6,6-3,6-3

#   output:

#   Zverev 3 0 10 104 11 106
#   Medvedev 1 2 11 106 10 104
#   Osaka 0 4 9 76 8 74
#   Barty 0 2 8 74 9 76
    
    
#----------------

import re

# This function takes valid inputs untill user leaves an empty string
def getInput():
    number_read = input()
    number_list = []
    while number_read != '':
        if isValid(number_read):
            number_list.append(number_read)
        else:
            print("Invalid Input")
        number_read = input()
    return number_list


# This function checks whether the input s is valid or not
# Valid input is of the form "{won player} : {defeated player} : {scoreline}",
# {won player} and {defeated player} are name of players, string of eng letters
# {score} is valid tennis match score
# all are acse and blankspace insensitive
def isValid(s):
    if match:=re.search(r"^[A-Za-z0-9 ]+:[A-Za-z0-9 ]+:([-0-9, ]+)$",s):
        return scoreValid(match.group(1))    
    else:
        return False


# This function checks whether the score is valid tennis match score
def scoreValid(s):
    sets=s.split(',')
    if len(sets)>5 or len(sets)<2:
        return False
    if not all([re.search(r"^ *[01234567] *- *[01234567] *$", i) for i in sets]):
        return False
    for i in sets:
        game=[int(j) for j in i.split("-")]
        if (6 not in game) and (7 not in game):
            return False
        if 7 in game:
            k=game.index(7)
            if k==0:
                if game[1]>6:
                    return False
            elif k==1:
                if game[0]>6:
                    return False
        elif 6 in game:
            k=game.index(6)
            if k==0:
                if game[1]>4:
                    return False
            elif k==1:
                if game[0]>4:
                    return False
    return True


# This function takes a complete score of a match and returns 
# the number of sets for the wining player, the number of sets for the defeated player,
# the number of games for the wining player, the number of games for the defeated player
# respectively as a tuple
def wlset(l):
    (n,m,g1,g2)=(0,0,0,0)
    for i in l:
        a=i.split('-')
        g1=g1+int(a[0])
        g2=g2+int(a[1])
        if int(a[0])>int(a[1]):
            n=n+1
        else:
            m=m+1
    return (n,m,g1,g2)
        

def main():
    number_list = getInput()
    players=[]
    matches=[]
    for match in number_list:
        fcolon=match.index(':')
        lcolon=match.rindex(':')
        wp=match[:fcolon]
        dp=match[fcolon+1:lcolon]
        players.append(wp)
        players.append(dp)
        scoreline = match[lcolon+1:].split(',')
        matches.append({'won': wp, 'defeated': dp, 'score': scoreline, 
                        'detailscore': {'nsets': len(scoreline), 'wsets': wlset(scoreline)[0], 'dsets': wlset(scoreline)[1],
                                        'wgames': wlset(scoreline)[2], 'dgames': wlset(scoreline)[3]}})
    players=list(set(players))
    
    lplayers=[]
    for player in players:
        (win5, win3, nwinst, nwingm, ndefst, ndefgm) = (0,0,0,0,0,0)
        for match in matches:
            if match['won']==player:
                if match['detailscore']['wsets'] >= 3:
                    win5 = win5+1
                else:
                    win3 = win3+1
                nwinst = nwinst+match['detailscore']['wsets']
                ndefst = ndefst+match['detailscore']['dsets']
                nwingm = nwingm+match['detailscore']['wgames']
                ndefgm = ndefgm+match['detailscore']['dgames']
            elif match['defeated']==player:
                nwinst = nwinst+match['detailscore']['dsets']
                ndefst = ndefst+match['detailscore']['wsets']
                nwingm = nwingm+match['detailscore']['dgames']
                ndefgm = ndefgm+match['detailscore']['wgames']
        lplayers.append({
            'name': player,
            'w5': win5,
            'w3': win3,
            'nStW': nwinst,
            'nGmW': nwingm,
            'nStD': ndefst,
            'nGmD': ndefgm
        })

    for i in sorted(lplayers, key=lambda d: (-d['w5'], -d['w3'], -d['nStW'], -d['nGmW'], d['nStD'],d['nGmD'])):
        print(f"{i['name']} {i['w5']} {i['w3']} {i['nStW']} {i['nGmW']} {i['nStD']} {i['nGmD']}")

        
if __name__=="__main__":
    main()