# Packet_sniffer_C
Network Packet Sniffer
# Descrption:
This is a simple network packet sniffer implemented in C using the libpcap library. The program captures network packets flowing through a specified network interface and provides a foundation for analyzing packet data.
### Getting Started:
1. Clone the repository: `git clone https://github.com/orzooman/Packet_sniffer_C.git`
2. Navigate to the project directory: `cd Packet_sniffer_C`
3. Compile the program: `gcc -o sniffer packet_sniffer.c -lpcap`
4. Run the packet sniffer: `sudo ./sniffer <interface>`
### Usage:
- Replace `<interface>` with the name of the network interface you want to capture packets from (e.g., eth0, wlan0, etc.).
- The program will start capturing packets and display relevant information for each packet.
### Note:
- Root/superuser privileges are required to capture network packets, hence the `sudo` command in the usage.
