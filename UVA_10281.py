#   created bY: nomyspy
#   date :
#   complexity:
i = 1
previous_time = 0
previous_dis = 0.0
prev_speed = 0
while True:

    try:
        x = input()
        Len = len(x)
        if (Len==8):
            h , m , s = x.split(":")
            h = int (h)
            m = int (m)
            s = int (s)
            new_time = ( h * 60 + m ) * 60 + s
            #new_time += s
            diffrence = new_time - previous_time
            #print("diff = " , diffrence)
            previous_dis = previous_dis + (prev_speed * diffrence)/3600
            previous_time = new_time
            print(x,"{0:.2f}".format(previous_dis) , "km")
        else:
            h , m, s = x.split(":")
            s , speed  = s.split(" ")
            h = int (h)
            m = int (m)
            s = int (s)
            speed = int (speed)
            if (i==1):
                previous_time = ( h * 60 + m ) * 60 + s;
                prev_speed = speed
            else:
                new_time = ( h * 60 + m ) * 60 + s;
                #print("new time = " , new_time)
                diffrence = new_time - previous_time
                #print("diff = " , diffrence)
                previous_dis = previous_dis + (prev_speed * diffrence)/3600
                previous_time = ( h * 60 + m ) * 60 + s;
                prev_speed = speed
            '''print(h)
            print(m)
            print(s)
            print(q)'''
        i = i + 1
    except EOFError:
        break
