import subprocess

with open('ipv6.txt') as f:
    lines = f.readlines()
    n = 0 
    for i in lines:
        i = i.strip()
        processed = 'processed_6/processed_'+ str(n)+'.txt'
        file = open(processed,"w")
        subprocess.call(['traceroute', '-6', '-q', '1', '-n', i], stdout=file)
        n += 1
    f.close()