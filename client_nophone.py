# AAScan: Open source, minimalist, fully automated 3D scanner based on Arduino and Android!

# Client program - To be run on computer (I recommend LINUX) 

# Copyright (C) 2020 redditNewUser2017
# Check out my page https://www.reddit.com/user/redditNewUser2017 and my subreddit https://www.reddit.com/r/Simulations/

"""     This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU Affero General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU Affero General Public License
    along with this program.  If not, see <https://www.gnu.org/licenses/agpl-3.0.en.html>. """

import serial,time
import socket
import sys

serverAddressList=["192.168.8.102"]    # Put your Phone IP here, multiple IPs are supported now (untested)!
serverPort=2021
bufferSize=12
nPhotos=50                      # How many photos do you want? (~180 for best quality)
fileName='image'
speed=10                        #RPM hard coded for now - make sure same as ino file.
if len(sys.argv) >= 2:
    fileName = sys.argv[1]
if len(sys.argv) >= 3:
    nPhotos = int(sys.argv[2])

print("using Filename {fname}".format(fname=fileName))      #debug message
print ("nPhotos is {np}".format(np=nPhotos))                #debug message

serialConnection = serial.Serial('COM3',9600)   # Change this to COMx if you are on Windows, COMx is the port where Arduino serial is connected
print("Serial connection established on {name}".format(name=serialConnection.name))
time.sleep(3)
serialConnection.write((str(nPhotos)+"\n").encode())
time.sleep(1)


#360 degrees takes 60/speed seconds
stepTime = ((60/(speed/4.4))/nPhotos)+2 #(the +2 gives a bit of leeway for other stuff.  4.4 comes from gear ratio)
print("step time is {st}".format(st=stepTime))      #debug message

socketList=[]
#for server in serverAddressList:
    #print("about to connect on {this}".format(this=server))
    #socketSendCommands = socket.socket(socket.AF_INET, socket.SOCK_STREAM)  #Communicate with phone
    #socketSendCommands.connect((server,serverPort))                         #Communicate with phone
    #socketList.append(socketSendCommands)                                   #Communicate with phone
    #socketSendCommands.send(fileName.encode())                              #Communicate with phone

#serialConnection.write(nPhotos) 

for i in range(nPhotos):
    #for socketSendCommands in socketList:                                   #Communicate with phone
     #   socketSendCommands.send("chez".encode())                            #Communicate with phone
        #print("sent chez\n")                                               #debug message
    time.sleep(0.5)                                                         #wait
    serialConnection.write("go\n".encode())                                 #communicate ith arduino
    time.sleep(stepTime)
    print("Progress: {count}/{total}".format(count=i+1,total=nPhotos))      #output

print("DONE!")
time.sleep(1)
serialConnection.close()
#for socketSendCommands in socketList:
#    socketSendCommands.send("quit".encode())
 #   socketSendCommands.close()
