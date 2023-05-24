#include <pcap.h> 
#include <stdio.h> 
#include <stdlib.h> 
#include <errno.h> 
#include <sys/socket.h> 
#include <netinet/in.h> 
#include <arpa/inet.h> 
#include <netinet/if_ether.h>
#include <ctype.h>
#include <string.h>

int i;
char *dev; 
char errbuf[PCAP_ERRBUF_SIZE]; 
pcap_t* descr; 
const u_char *packet; 
struct pcap_pkthdr hdr;
struct ether_header *eptr;    
struct bpf_program fp;        
bpf_u_int32 maskp;            
bpf_u_int32 netp;   
struct in_addr address;
char ip[13];
char subnet_mask[13]; 

void pac_process(u_char *args, const struct pcap_pkthdr* pkthdr, const u_char* packet){ 

    int i=0; 
    static int count=0; 

    address.s_addr = netp;
    strcpy(ip, inet_ntoa(address));
    if (ip == NULL) {
        perror("inet_ntoa"); 
        
    }
    
    address.s_addr = maskp;
    strcpy(subnet_mask, inet_ntoa(address));
    if (subnet_mask == NULL) {
        perror("inet_ntoa");
        
    }

    printf("Interface: %s\n", dev);
    printf("Network IP address: %s\n", ip);
    printf("Network Subnet mask: %s\n", subnet_mask);
 
    printf("Packet Count: %d\n", ++count);    
    printf("Recieved Packet Size: %d\n", pkthdr->len);    
    printf("Payload:\n");                     
    for(i=0;i<pkthdr->len;i++) { 
        if(isprint(packet[i]))                
            printf("%c ",packet[i]);          
        else
            printf(" . ");         
        if((i%16==0 && i!=0) || i==pkthdr->len-1) 
            printf("\n"); 
    }

    printf("\n");
    printf("\n");

}


int main(int argc,char **argv) 
{          
 
    if(argc != 2){
        fprintf(stdout, "Usage: %s \"expression\"\n"
            ,argv[0]);
        return 0;
    } 

    dev = argv[1];
     
    if(dev == NULL) {
        fprintf(stderr, "Could not find interface: %s\n", errbuf);
        exit(1);
    } 
    
    pcap_lookupnet(dev, &netp, &maskp, errbuf);

    descr = pcap_open_live(dev, BUFSIZ, 1,1000, errbuf); 

    if(descr == NULL) {
        printf("pcap_open_live(): %s\n", errbuf);
        exit(1);
    } 
   
    pcap_loop(descr, -1, pac_process, NULL); 
    
    return 0; 
}
