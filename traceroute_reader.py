import os

n = 0

for file in os.listdir('processed_6/'):
    open_file = 'processed_6/'+file
    routes = []
    with open(open_file) as f:
        next(f)
        lines = f.readlines()
        for line in lines:
            l = line.strip().split(' ')
            if l[2] != '*':
                routes.append(l[2])
        f.close()

    srtd = routes
    i = 0
    trace_route = 'traceroutes_6/traceroute_'+ str(n)+'.txt'
    trace = open(trace_route,"w")
    for i in range(len(srtd)):
        print('"'+srtd[i]+'"', '--', '"'+srtd[i+1]+'"','\n',file = trace)
        if i+2 == len(srtd):
            break
        else:
            i += 1
    n += 1
