# AA-Scan
AAScan: Open source, minimalist, fully automated 3D scanner based on Arduino and Android

This is the source code for the software used in AAScan. You can find details of assembly and use of it from the Thingiverse page: https://www.thingiverse.com/thing:4167615

This is an open source project. Suggestions are welcome!



# Falkingham branch:
Client is now run on computer as:

$python client.py \<imagename\> \<image number\>

if the arguments are not provided, photos will be named imageX, and the system will rotate the turntable 50 times. If the arguments aer provided, images on the phone will be named \<imagename\>\<number\>, and it will take as many photos as you ask it to.

This means you can turn an object over, run the script again with a different name, and not overwrite the first files. You can also take more or less photos easily.

***

I've changed default folders - images will now go to internalStorage/Photog on the phone.

***

I've included a script that will automatically download images from the phone to another PC over wifi network.  Enable FTP server on your phone, e.g. with Wifi FTP Server (https://play.google.com/store/apps/details?id=com.medhaapps.wififtpserver), then run this script in the folder you want the images to download to.  Must be run in a linux terminal (either on linux, or using WSL on windows).  Script will download photos then delete from the phone.

