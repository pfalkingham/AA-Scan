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

serverAddressList=["192.168.8.100"]    # Put your Phone IP here, multiple IPs are supported now (untested)!
serverPort=2021
bufferSize=12
nPhotos=180                      # How many photos do you want? (~180 for best quality)
fileName='image'
if len(sys.argv) >= 2:
    fileName = sys.argv[1]

print("using Filename {fname}".format(fname=fileName))


serialConnection = serial.Serial('COM3',9600)   # Change this to COMx if you are on Windows, COMx is the port where Arduino serial is connected
print("Serial connection established on {name}".format(name=serialConnection.name))
time.sleep(3)
serialConnection.write((str(nPhotos)+"\n").encode())
time.sleep(1)

#print("server? {server}")

socketList=[]
for server in serverAddressList:
    print("about to connect on {this}".format(this=server))
    socketSendCommands = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    socketSendCommands.connect((server,serverPort))
    socketList.append(socketSendCommands)
    socketSendCommands.send(fileName.encode())

for i in range(nPhotos):
    for socketSendCommands in socketList:
        socketSendCommands.send("chez".encode())
    time.sleep(1.5)
    serialConnection.write("go\n".encode())
    time.sleep(1.5)
    print("Progress: {count}/{total}".format(count=i+1,total=nPhotos))

print("DONE!")
time.sleep(1)
serialConnection.close()
for socketSendCommands in socketList:
    socketSendCommands.send("quit".encode())
    socketSendCommands.close()
