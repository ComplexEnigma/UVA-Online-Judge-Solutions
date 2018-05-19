# created by : nomyspy
# date :
# complexity :

while True:
    try:
        x = input();
        n , r = x.split(" ")
        '''print(n)
        print(r)'''
        n = int (n)
        r = int (r)
        a = n  - r
        hor = 1
        lob = 1
        if (a > r):
            lv = a
            lv2 = r
        else:
            lv = r
            lv2 = a
        for i in range (lv+1,n+1):
            #print(i)
            hor *= i
        for i in range (1,lv2+1):
            lob *= i
        #print(hor)
        #print(lob)
        #print(hor/lob)
        ans = int (hor/lob)
        print(len(str(ans)))
    except EOFError:
        break
