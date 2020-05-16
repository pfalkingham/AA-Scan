# AAScan: Open source, minimalist, fully automated 3D scanner based on Arduino and Android!

# Server program - To be run on computer (I recommend LINUX)

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

import androidhelper
import time
import socket


droid = androidhelper.Android()
droid.wakeLockAcquireDim()

dataReceived=""
fileName="image"
i=1
serverAddress="192.168.8.100"    # Put your Phone IP here
serverPort=2021
bufferSize=12
photoStoragePath='/storage/emulated/0/photog/' # You can change where the photos are stored here!

socketSendCommands = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
socketSendCommands.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
try:
    socketSendCommands.bind((serverAddress,serverPort))
except:
    print("already connected")
socketSendCommands.listen(1)
print("Sever {ip} opened at port {port}\n".format(ip=serverAddress,port=serverPort))
(connection, address) = socketSendCommands.accept()
print("Connection established {addr}\n".format(addr=address))

try:
    while True:
        dataReceived=connection.recv(bufferSize).decode()
        if dataReceived!="":
            if dataReceived=="chez":
                #print("chezrecieved") # debug message
                path = photoStoragePath
                path += fileName
                path += '_'+str(i)
                path += '.jpg'          #20/3/20 can this be jpg?  any difference? 16/5/20 yes it can, and then thigns display properly.
                droid.cameraCapturePicture(path, True)
                print("{count} photos taken!".format(count=i))
                i=i+1
            elif dataReceived=="quit":
                #print("break")          # debug message
                break
            else:
                fileName = dataReceived
                print("fiename is {fnam}".format(fnam=fileName))  #debug message
except:
    pass

socketSendCommands.close()
droid.wakeLockRelease()
print("DONE! The photos are stored at {path}!".format(path=photoStoragePath))
