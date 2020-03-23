


while [ 1 -le 2 ]
do
    echo "copying files..."
    lftp ftp://android:android@192.168.8.100:2221/Photog/ -e "mirror --Remove-source-files; bye"
    echo "waiting 30 seconds"
    sleep 30
done