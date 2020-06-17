#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define MAX_IP_LEN 16

struct IP_ADDR{
	const char* ip_addr;
	short int mask;

};

void get_broadcast_address(char*ip_addr,char mask,char* output_buffer){

/*
	Input : 192.168.63.2(ip_addr) and 24(mask)
	Output: 192.168.63.255(Broadcast Address)

	Given the IP Address and Mask value Output the Broadcast Address.
*/

}


unsigned int get_ip_integral_equivalent(char* ip_address){

/*
	Input :192.168.63.2
	Return Value:Decimal form of above IP Address

	Given the IP Address return the Decimal form of the IP Address.
*/
	return 0;
}

void get_abcd_ip_format(unsigned int ip_address,char* output_buffer){

/*
	Input :Decimal form of IP Address
	Output:192.168.63.2
	
	Given the Decimal form of IP Output the IP Adrress.
*/

}

void get_network_id(char* ip_address,char mask,char* output_buffer){

/*
	Input :192.168.63.2(IP Address) and Mask(24)
	Output:192.168.63.0(Network Address)

	Given the IP Address Output the Network Address. 
*/

}


unsigned int get_subnet_cardinality(char mask){

/*
	Input :24(Mask)
	Return Value:254(Cardinality)

	Given the mask value return the cardinality that is the maximum number
	of assignable IP Addresses.
*/
	return 0;
}

int check_ip_subnet_membership(char* network_id,char mask,char* check_ip){

/*
	Input :192.168.63.0(Network Address) , 24(Mask) and 192.168.63.2(IP Address)
	Return Value:0 or 1

	Given the Netowork Address and mask value with an IP Address return 
		0 if the IP Address belongs to that Network Address
		1 if the IP Address does not belong to Network Address   
*/
	return 0;
}

void seperate_ip_and_mask(char* ip_addr,int len,struct IP_ADDR* ip){
	
/*
	Input :192.168.63.5(IP Address) and (18) length of IP Adress with mask value 
	Output:Fills the values of the IP_ADDR Struct
*/	
	short int mask=0;

	//case : 192.168.63.5/2
	if((*(ip_addr+(len-2)))=='/'){
		mask=*(ip_addr+(len-2))-48;
		*(ip_addr+(len-2))='\0';
	}
	//case : 192.16.63.5/24
	else{
		mask=(*(ip_addr+(len-2))-48)*10 + (*(ip_addr+(len-1))-48);
		*(ip_addr+(len-3))='\0';
	}
	
	//Filling the values into the struct
	ip->ip_addr=ip_addr;
	ip->mask=mask;
}

int main(int argc,char *argv[])
{
	short int len=strlen(argv[1]);
	struct IP_ADDR ip_addr_struct;
	if(len>18)
		printf("Invalid IPV4 Address ,Enter the format in the following x.y.z.a/mask\n");
	else
	{
		seperate_ip_and_mask(argv[1],len,&ip_addr_struct);
		printf("\nIP_ADDR is : %s\nMask Value : %d\n\n",ip_addr_struct.ip_addr,ip_addr_struct.mask);
	}
	return 0;
}


