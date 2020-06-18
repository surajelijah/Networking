#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define MAX_IP_LEN 16

struct IP_ADDR{
	
	const char* ip_addr;
	int * seperated_units;
	short int mask;

};


int split_char_array(char* ip_addr,int* seperated_units){

/*
	Input : 192.168.63.2(ip_addr)
	Output: [192,168,63,2,24](seperated_units) and the (5) lenght of the units
*/
	
	int len=0,value=0;
	
	while((*ip_addr)!='\0'){
		        	
		if((*ip_addr)>47 && (*ip_addr)<58){
			value=(value*10) + ((*ip_addr)-48);
		}
		else if((*ip_addr)=='.' || (*ip_addr)=='/'){
			seperated_units[len++]=value;
			value=0;
		}
		else
			return -1;

		ip_addr++;	
	}
	if((*ip_addr)=='\0')
		seperated_units[len++]=value; //Addding the mask value

	return len;	
}


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
	unsigned int m=1;
	
	m=(m<<(32-(int)mask));
	
	return m-2;
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

int fill_ip_addr_struct_details(struct IP_ADDR* ip_addr_struct,char* ip_addr)
{

/*
	Input : IP Adddress and Stucture pointer
	Output : Length of the seperated units of IP Address 	
*/
	short int len=0;

	ip_addr_struct->seperated_units=(int*)malloc(5*sizeof(int));

	len = split_char_array(ip_addr,ip_addr_struct->seperated_units);
	
	ip_addr_struct->ip_addr = ip_addr;
	
	ip_addr_struct->mask = (*(ip_addr_struct->seperated_units+(len-1)));

	return len;	
}



int main(int argc,char *argv[])
{
	short int len=0;
					
        struct IP_ADDR *ip_addr=(struct IP_ADDR*)malloc(sizeof(struct IP_ADDR));
	
	len = fill_ip_addr_struct_details(ip_addr,argv[1]);

	if(len>5 || len==-1)
		printf("Invalid IPV4 Address ,Enter the format in the following x.y.z.a/mask\n");
	else
	{
		printf("\nIP_ADDR is : %s\nMask Value : %d\n",ip_addr->ip_addr,ip_addr->mask);
		printf("Subnet Cardinality : %u\n",get_subnet_cardinality(ip_addr->mask));
		
	}
	return 0;
}


