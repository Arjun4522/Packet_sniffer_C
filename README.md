# Packet_sniffer_C
Network Packet Sniffer in C
# Descrption:
This is a simple network packet sniffer implemented in C using the libpcap library. The program captures network packets flowing through a specified network interface and provides a foundation for analyzing packet data.
### Getting Started:
1. Install libpcap for Debian-based distributions using `sudo apt update && sudo apt-get install libpcap-dev`
3. Clone the repository: `https://github.com/Arjun4522/Packet_sniffer_C`
4. Navigate to the project directory: `cd Packet_sniffer_C`
5. Compile the program: `gcc -o sniffer packet_sniffer.c -lpcap`
6. Run the packet sniffer: `sudo ./sniffer <interface>`
### Usage:
- Replace `<interface>` with the name of the network interface you want to capture packets from (e.g., eth0, wlan0, etc.).
- The program will start capturing packets and display relevant information for each packet.
### Note:
- Root/superuser privileges are required to capture network packets, hence the `sudo` command in the usage.
