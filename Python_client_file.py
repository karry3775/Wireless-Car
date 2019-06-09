import httplib2
import time

http = httplib2.Http()
forward = "http://192.168.43.250/forward"
stop = "http://192.168.43.250/stop"

tic = time.time()
i = 0;
while True:
    http.request(forward,"GET")
    if i==0:
        print("Moving forward")
        print("Time stamp {}".format(time.time()-tic))
        i+=1

    if (time.time() - tic >1):
        break
print("Stopping")
print(time.time() - tic )
http.request(stop,"GET")
