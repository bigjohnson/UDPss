# UDPss
[Serial Studio](https://github.com/Serial-Studio/Serial-Studio) UDP sender with esp8266

Start sending data with + stop sending -

It creates an acess point with network name 

UDPss

and password

udpsspassword

then you can connect to it with [Serial Studio](https://github.com/Serial-Studio/Serial-Studio) at address 192.168.42.254 port 6977 UDP protocol.

Send from [Serial Studio](https://github.com/Serial-Studio/Serial-Studio) the + character and you yill receive data.

To stop data flow send - character.

The sketch autodiscover the udp port and the ip adress of the [Serial Studio](https://github.com/Serial-Studio/Serial-Studio) running PC from the last received udp packet.
